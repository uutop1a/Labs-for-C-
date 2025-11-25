#include <iostream>
#include <vector>
using namespace std;

bool is2Digits(int x) {
    if (((x >= -100) && (x <= -10)) || ((x >= 10) && (x < 100))) {
        return true;
    }
    else return false;
}

int main() {

    int x;
    cout << "Enter x:";
    cin >> x;


    if (is2Digits(x)) {
        cout << "true";
    }
    else cout << "false";
}