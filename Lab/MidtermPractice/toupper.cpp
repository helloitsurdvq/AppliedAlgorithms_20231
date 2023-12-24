#include <iostream>
#include <cctype> // for toupper function
using namespace std;
int main() {
    string text;

    while (true) {
        string line;
        getline(cin, line);

        if (cin.eof()) {
            break;
        }
        text += line + '\n'; 
    }
    for (char &c : text) {
        c = toupper(c);
    }
    cout << text;

    return 0;
}
