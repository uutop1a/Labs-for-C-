#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> readVector()
{
    int n;
    cout << "Enter a count of numbers in vector: ";
    while (!(cin >> n) || n <= 0) {
        cin.clear();
        cout << "Error! Enter a positive number: ";
    }

    vector<int> V(n);
    cout << "Enter " << n << " positive numbers:\n";
    for (int i = 0; i < n; i++) {
        while (!(cin >> V[i])) {
            cin.clear();
            cout << "Error! Enter a even number: ";
        }
    }
    return V;
}

map<int, int> countOccurrences(const vector<int>& V)
{
    map<int, int> M;

    // перебирание элементы вектора через итератор
    for (auto it = V.begin(); it != V.end(); ++it) {
        M[*it]++; // увеличение счетчик для данного ключа
    }
    return M;
}

void printOccurrences(const map<int, int>& M)
{
    cout << "\nElements of vector and count of their repetitions:\n";
    // перебор элементов карты через итератор
    for (auto it = M.begin(); it != M.end(); ++it) {
        cout << it->first << " " << it->second << "\n";
    }
}

int main()
{
    vector<int> V = readVector();
    map<int, int> M = countOccurrences(V);
    printOccurrences(M);
    return 0;
}
