
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * DFA State Mapping:
 * A (Start) = 0
 * B (Final) = 1
 * C         = 2
 * D (Final) = 3
 * E (Final) = 4
 * F         = 5
 * G         = 6
 * H         = 7
 */

// Transition table: rows are states (0-7), columns are inputs ('a'=0, 'b'=1)
int dfa[8][2] = {
    {1, 2},  // State A: a -> B, b -> C
    {4, 5},  // State B: a -> E, b -> F
    {3, 6},  // State C: a -> D, b -> G
    {1, 2},  // State D: a -> B, b -> C
    {4, 5},  // State E: a -> E, b -> F
    {7, -1}, // State F: a -> H, b -> Trap (-1)
    {1, 6},  // State G: a -> B, b -> G
    {4, 4}   // State H: a -> E, b -> E
};

// Function to check if a state is an accepting (final) state
bool isAccepting(int state) {
    // States B, D, and E contain NFA state 27 or 12
    return (state == 1 || state == 3 || state == 4);
}

int main() {
    string input;
    cout << "--- DFA String Validator ---" << endl;
    cout << "Expression: (ba)* b* a [a + ba(a+b)]*" << endl;
    cout << "Enter a string consisting of 'a' and 'b': ";
    cin >> input;

    int currentState = 0; // Start at State A
    bool trap = false;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        int column;

        if (c == 'a') column = 0;
        else if (c == 'b') column = 1;
        else {
            cout << "Error: Invalid character '" << c << "' detected." << endl;
            trap = true;
            break;
        }

        currentState = dfa[currentState][column];

        if (currentState == -1) {
            trap = true;
            break;
        }
    }

    cout << "\n--- Result ---" << endl;
    if (!trap && isAccepting(currentState)) {
        cout << "String \"" << input << "\" is ACCEPTED" << endl;
    } else {
        cout << "String \"" << input << "\" is REJECTED" << endl;
    }

    return 0;
}
