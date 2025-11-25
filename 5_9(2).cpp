#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
struct IsPositive {
    bool operator()(int x) const {
        return x > 0;
    }
};

int inputPositiveNumber(const string& prompt) {
    int n;
    cout << prompt;
    while (!(cin >> n) || n <= 0) {
        cout << "Error! Enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return n;
}

void inputVector(vector<int>& V) {
    int n;
    cout << "Enter the number of vector elements (positive integer): ";
    while (!(cin >> n) || n <= 0) {
        cout << "Error! Enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


    V.resize(n);
    cout << "Enter vector elements: ";
    for (auto it = V.begin(); it != V.end(); ++it) {
        while (!(cin >> *it)) {
            cout << "Error! Enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void duplicateFirstKPositive(vector<int>& V, int K) {
    if (V.empty() || K <= 0) return;
    auto it = search_n(V.begin(), V.end(), K, 0,
                       [](int val, int) { return val > 0; });
    if (it != V.end()) {
        vector<int> copy(it, it + K);
        V.insert(it + K, copy.begin(), copy.end());
    }


}

void printVector(const vector<int>& V) {
    for (auto it = V.begin(); it != V.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main() {
    vector<int> V;
    inputVector(V);
    int K = inputPositiveNumber("Enter K (number of consecutive positive numbers): ");
    duplicateFirstKPositive(V, K);
    cout << "\nVector after duplicating first K positive numbers:\n";
    printVector(V);
    return 0;
}
