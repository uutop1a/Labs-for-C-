#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void inputVector(vector<int>& V) {
    int n;
    cout << "Enter the number of vector elements (positive number): ";

    while (!(cin >> n) || n <= 0) {
        cout << "Error! Please enter a POSITIVE integer.: ";
        cin.clear();
    }

    V.resize(n);
    cout << "Enter vector elements: ";
    for (auto it = V.begin(); it != V.end(); ++it) {
        while (!(cin >> *it)) {
            cout << "Error! Please enter an integer.: ";
            cin.clear();
        }
    }
}

void removeOddPositions(vector<int>& V) {
    if (V.empty()) return;
    int pos = 1;
    for (auto i = V.begin(); i != V.end();) {
        if (pos % 2 == 1) {

            i = V.erase(i);
        } else {
            ++i;
        }

        pos++;

        if (i == V.end()) break;
    }
}

void printVector(const vector<int>& V) {
    cout << "Vector elements: ";
    for (auto it = V.begin(); it != V.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main() {
    vector<int> V;
    inputVector(V);
    removeOddPositions(V);
    cout << "\nVector after removing elements with odd ordinal numbers:\n";
    printVector(V);

    return 0;
}
