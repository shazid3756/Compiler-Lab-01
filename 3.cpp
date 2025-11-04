#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    cout << "Enter a line: ";
    getline(cin, s);

    if (s.size() >= 2 && s[0] == '/' && s[1] == '/') {
        cout << "Single line comment" << endl;
    }
    else if (s.size() >= 4 && s[0] == '/' && s[1] == '*' &&
             s.find("*/") != string::npos) {
        cout << "Multiple line comment" << endl;
    }
    else {
        cout << "Not a comment" << endl;
    }

    return 0;
}
