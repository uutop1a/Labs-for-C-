#include <iostream>
using namespace std;

bool islnRange(int a, int b, int x) {
    if (a > b) {
        return ((x >= b) && (x <= a));
    }
    else {
        return ((x >= a) && (x <= b));
    }
}

int main() {
    int a, b, x;
    cout << "Enter a:";
    cin >> a;
    cout << "Enter b:";
    cin >> b;
    cout << "Enter x:";
    cin >> x;
    if (a == b) {
        cout << "Enter correct numbers";
        }
    else {
        islnRange(a, b, x);
    }
    if (islnRange(a, b, x) == 1)  {
        cout << "true";
    }
    else {
        cout << "false";
    }
}