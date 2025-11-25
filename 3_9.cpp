#include <iostream>
using namespace std;

void rightTriangle(int x) {
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < x - i; j++) {
            cout << ' ';
        }
        for (int k = 0; k < i; k++){
            cout << '*';
        }
        cout << endl;
    }
}

int main() {
    int x;
    cout << "Enter x:";
    cin >> x;
    rightTriangle(x);
}