#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isIdentifier(const string &s) {
    if (s.empty()) return false;

    // (a) First character: alphabet or underscore (A-Z, a-z, _)
    if (!(isalpha(static_cast<unsigned char>(s[0])) || s[0] == '_'))
        return false;

    // (b) From second character: alphanumeric or underscore (A-Z, a-z, 0-9, _)
    for (size_t i = 1; i < s.size(); i++) {
        char c = s[i];
        if (!(isalnum(static_cast<unsigned char>(c)) || c == '_'))
            return false;
    }

    return true;
}

int main() {
    string s;
    cout << "Enter input: ";
    cin >> s;

    if (isIdentifier(s))
        cout << "Valid identifier" << endl;
    else
        cout << "Invalid identifier" << endl;

    return 0;
}
