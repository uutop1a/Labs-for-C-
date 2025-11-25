#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <algorithm>
using namespace std;

void inputVector(vector<int>& V) {
    int n;
    cout << "Enter the number of vector elements (even number): ";
    while (!(cin >> n) || n <= 0 || n % 2 != 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Enter an even positive number: ";
    }
    V.resize(n);
    cout << "Enter vector elements: ";
    for (int i = 0; i < n; ++i) {
        while (!(cin >> V[i])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Enter number: ";
        }
    }
}

void inputDeque(deque<int>& D) {
    int n;
    cout << "Enter the number of deque elements (even number): ";
    while (!(cin >> n) || n <= 0 || n % 2 != 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error. Enter    an even positive number: ";
    }
    D.resize(n);
    cout << "Enter deque elements: ";
    for (int i = 0; i < n; ++i) {
        while (!(cin >> D[i])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Enter number: ";
        }
    }
}

void manipulateContainers(vector<int>& V, deque<int>& D) {
    int halfV = static_cast<int>(V.size()) / 2;
    int halfD = static_cast<int>(D.size()) / 2;

    // исходный вектор
    vector<int> originalV = V;

    // в конец вектора первую половину дека
    V.insert(V.end(), D.begin(), D.begin() + halfD);
    // временный контейнер — вторая половина исходного вектора
    vector<int> temp(originalV.begin() + halfV, originalV.end()); // элементы [halfV .. end)
    reverse(temp.begin(), temp.end()); // обратный порядок
    // в начало дека
    D.insert(D.begin(), temp.begin(), temp.end());
}

void printVector(const vector<int>& V) {
    cout << "Vector elements: ";
    for (auto it = V.begin(); it != V.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void printDeque(const deque<int>& D) {
    cout << "Deque elements: ";
    for (auto it = D.begin(); it != D.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main() {
    vector<int> V;
    deque<int> D;
    inputVector(V);
    inputDeque(D);
    manipulateContainers(V, D);
    printVector(V);        // вектор после вставки первой половины дека
    printDeque(D);         // дек в нормальном порядке (чтобы было наглядно)
    return 0;
}
