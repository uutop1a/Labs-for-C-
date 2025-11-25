#include <iostream>
using namespace std;

bool isEqual(int a, int b, int c) {
    if ((a == b) && (b == c)) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int a;
    cout<< "Enter a:";
    cin>> a;

    int b;
    cout<< "Enter b:";
    cin>> b;

    int c;
    cout<< "Enter c:";
    cin>> c;

    if (isEqual(a, b, c) == 0) {
        cout<< "false";
    }
    else cout<< "true";
}