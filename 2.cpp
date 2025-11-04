#include <iostream>
#include <string>
using namespace std;

int main() {
    string expr;
    int count = 0;

    cout << "Enter expression: ";
    cin >> expr;            // works for inputs like 2+3=5

    for (char c : expr) {
        if (c == '+' || c == '-' || c == '*' ||
            c == '/' || c == '%' || c == '=') {
            count++;
            cout << "operator" << count << ": " << c << endl;
        }
    }

    if (count == 0) {
        cout << "No arithmetic operator found" << endl;
    }

    return 0;
}
