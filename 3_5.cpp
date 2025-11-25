#include <iostream>
#include <string>
using namespace std;

int numLen(const string& x) {
    return x.length();
}

int main() {
    string y;
    cout << "Enter x:";
    cin >> y;
    cout << numLen(y) << endl;
    return 0;
}