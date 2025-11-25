#include <iostream>
using namespace std;

bool is35(int a) {
    if ((a % 3 == 0) && (a % 5 == 0)) {
        return false;
    }
    else {
        if ((a % 3 == 0) || (a % 5 == 0)) {
            return true;
        }
        else {
            return false;
        }
    }
}

int main() {
    int a;
    cout << "Enter a:";
    cin >> a;
    if (is35(a) == 0) {
        cout << "false";
    }
    else {
        cout << "true";
    }
}