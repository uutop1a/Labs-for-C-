#include <iostream>
using namespace std;

int charToNum(char x) {
    return x - '0';

}

int main() {
    cout << "Enter x:";
    char x;
    cin >> x;

    if ((x >= '0') && (x <= '9')) {
        int a = charToNum(x);
        cout << "Char into number:" << a;
    }
    else {
        cout << "Enter correct char";

    }
}