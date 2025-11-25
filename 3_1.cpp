#include <iostream>
using namespace std;

string listNums(int x) {
    string result;
    for (int i = 0; i <= x; i++) {
        result += to_string(i);
        if (i < x) {
            result += " ";
        }
    }
    return result;
}

int main() {
    int x;
    cout << "Enter x:";
    cin >> x;
    cout << listNums(x);
}