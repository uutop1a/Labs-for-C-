#include <iostream>
#include <string>
using namespace std;

string chet(int x) {
    string result;
    for (int i = 0; i <= x; i += 2) {
        if (!result.empty()) {
            result += " ";
        }
        result += to_string(i);
    }
    return result;
}

int main() {
    int x;
    cout << "Enter x:";
    cin >> x;
    cout << chet(x) << endl;
}