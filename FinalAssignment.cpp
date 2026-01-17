
#include <iostream>
using namespace std;

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;

    int state = 0;

    for (char c : input) {
        switch (state) {
        case 0:
            state = (c == 'a') ? 1 : (c == 'b') ? 2 : -1;
            break;
        case 1:
            state = (c == 'a') ? 3 : (c == 'b') ? 4 : -1;
            break;
        case 2:
            state = (c == 'a') ? 1 : (c == 'b') ? 2 : -1;
            break;
        case 3:
            state = (c == 'a') ? 3 : (c == 'b') ? 4 : -1;
            break;
        case 4:
            state = (c == 'a') ? 3 : (c == 'b') ? 4 : -1;
            break;
        }
        if (state == -1) break;
    }

    if (state == 1 || state == 3)
        cout << "String Accepted\n";
    else
        cout << "String Rejected\n";

    return 0;
}
