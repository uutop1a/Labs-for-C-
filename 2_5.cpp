#include <iostream>
using namespace std;

int max3(int x, int y, int z) {
    int max = x;
    if (y > max) max = y;
    if (z > max) max = z;
    return max;
}

int main() {
    int x, y, z;
    cout << "Enter x:";
    cin >> x;
    cout << "Enter y:";
    cin >> y;
    cout << "Enter z:";
    cin >> z;
    cout << "The max number is:" << max3(x, y, z);
}