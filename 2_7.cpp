#include <iostream>
using namespace std;

int sum2(int x, int y) {
    int z = x + y;
    if ((z >= 10) && (z <= 19)) {
        cout << 20;
    }
    else {
        cout << x + y;
    }
    return 0;
}

int main() {
    int x, y;
    cout << "Enter x:";
    cin >> x;
    cout << "Enter y:";
    cin >> y;
    sum2(x, y);
}