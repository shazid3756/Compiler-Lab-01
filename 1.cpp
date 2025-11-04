#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string s;
    bool isNumeric = true;

    cout << "Enter input: ";
    cin >> s;   // read as string

    for (char c : s) {
        if (!isdigit(static_cast<unsigned char>(c))) {
            isNumeric = false;
            break;
        }
    }

    if (isNumeric)
        cout << "numeric constant" << endl;
    else
        cout << "not numeric" << endl;

    return 0;
}
