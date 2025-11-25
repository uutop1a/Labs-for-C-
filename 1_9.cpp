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
    cout<< "Enter a:"<< endl;
    cin>> a;

    int b;
    cout<< "Enter b:"<< endl;
    cin>> b;

    int c;
    cout<< "Enter c:"<< endl;
    cin>> c;

    if (isEqual(a, b, c) == 0) {
        cout<< "false";
    }
    else cout<< "true";
}