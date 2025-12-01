#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

// Token categories
enum TokenType {
    KEYWORD,
    IDENTIFIER,
    OPERATOR,
    PUNCTUATION,
    LITERAL,
    INVALID
};

// Function to classify the token
TokenType classifyToken(const string &token) {
    // Keywords in C++
    const vector<string> keywords = {
        "int", "float", "double", "char", "if", "else", "for", "while", "return", "void",
        "namespace", "std", "using", "include", "cout", "endl"
    };

    // Operators
    const vector<string> operators = {
        "+", "-", "*", "/", "=", "<", ">", "<=", ">=", "==", "!="
    };

    // Punctuation
    const vector<string> punctuation = {
        "(", ")", "{", "}", "[", "]", ";", ",", "<", ">", "<<", ">>"
    };

    // Check if it's a keyword
    for (const auto &kw : keywords) {
        if (token == kw) {
            return KEYWORD;
        }
    }

    // Check if it's an operator
    for (const auto &op : operators) {
        if (token == op) {
            return OPERATOR;
        }
    }

    // Check if it's a punctuation
    for (const auto &punct : punctuation) {
        if (token == punct) {
            return PUNCTUATION;
        }
    }

    // Check if it's a number (literal)
    if (regex_match(token, regex("[0-9]+"))) {
        return LITERAL;
    }

    // If it doesn't match any known type, treat it as an identifier
    return IDENTIFIER;
}

// Function to tokenize the code
vector<string> tokenize(const string &code) {
    vector<string> tokens;
    stringstream ss(code);
    string word;

    // Regular expressions to match different token types
    regex tokenPattern(R"([a-zA-Z_][a-zA-Z0-9_]*|\d+|[+\-*/=<>!&|^%(){}[\],;])");

    // Match all the tokens
    auto begin = std::sregex_iterator(code.begin(), code.end(), tokenPattern);
    auto end = std::sregex_iterator();

    for (auto it = begin; it != end; ++it) {
        tokens.push_back(it->str());
    }

    return tokens;
}

void printTokens(const vector<string> &tokens) {
    cout << "Tokens: ";
    for (const auto &token : tokens) {
        cout << "<" << token << "> ";
    }
    cout << "\n\nToken types:\n";

    // Classify and print the type of each token
    for (const auto &token : tokens) {
        TokenType type = classifyToken(token);
        string typeStr;

        switch (type) {
            case KEYWORD: typeStr = "Keyword"; break;
            case IDENTIFIER: typeStr = "Identifier"; break;
            case OPERATOR: typeStr = "Operator"; break;
            case PUNCTUATION: typeStr = "Punctuation"; break;
            case LITERAL: typeStr = "Literal"; break;
            default: typeStr = "Invalid"; break;
        }

        cout << "<" << typeStr << "> " << token << "\n";
    }
}

int main() {
    // Ask user for the file name
    string fileName;
    cout << "Enter the filename (with extension, e.g. example.txt): ";
    cin >> fileName;

    // Open the file containing C++ code
    ifstream file(fileName);

    if (!file.is_open()) {
        cerr << "Error opening file\n";
        return 1;
    }

    // Read the content of the file
    stringstream buffer;
    buffer << file.rdbuf();
    string code = buffer.str();

    // Tokenize the code
    vector<string> tokens = tokenize(code);

    // Print the tokens and their types
    printTokens(tokens);

    return 0;
}
