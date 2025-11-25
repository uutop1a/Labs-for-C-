#include <iostream>
using namespace std;

int abs(int x) {
    if (x >= 0) {
        return x;
    } else {
        return -x;
    }
}

int main() {
    int a;
    cout << "Enter a:";
    cin >> a;
    cout << abs(a);
}