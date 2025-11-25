#include <iostream>
#include <cmath>
using namespace std;

int numLen(long x) {
    if (x == 0) return 1;
    int count = 0;
    while (x != 0) {
        count++;
        x /= 10;
    }
    return count;
}

int main() {
    int x;
    cout << "Enter x: ";
    cin >> x;
    cout << numLen(x);
}