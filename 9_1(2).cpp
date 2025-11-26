#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> readVector(int index = -1)
{
    int n;
    if (index == -1)
        cout << "Enter a count of vector's elements: ";
    else
        cout << "Enter a count of vector L" << index << ": ";

    while (!(cin >> n) || n <= 0) {
        cin.clear();
        cout << "Error! Enter a positive number: ";
    }
    vector<int> V(n);
    cout << "Enter " << n << " positive numbers:\n";
    for (int i = 0; i < n; i++) {
        while (!(cin >> V[i])) {
            cin.clear();
            cout << "Error! Enter a positive numbers: ";
        }
    }
    return V;
}

bool containsAll(const vector<int>& V0, const vector<int>& Vi)
{
    // создание множества
    set<int> S0(V0.begin(), V0.end());
    set<int> Si(Vi.begin(), Vi.end());
    // Si должен содержать все элементы S0
    return includes(Si.begin(), Si.end(), S0.begin(), S0.end());
}

int countVectorsIncludingV0(const vector<int>& V0, const vector<vector<int>>& Vlist)
{
    int count = 0;

    for (const auto& Vi : Vlist)
        if (containsAll(V0, Vi))
            count++;

    return count;
}

int main()
{
    // Ввод V0
    cout << "Enter V0:\n";
    vector<int> V0 = readVector();

    // Ввод N
    int N;
    cout << "\nEnter a count of vectors N (> 0): ";
    while (!(cin >> N) || N <= 0) {
        cin.clear();
        cout << "Error! Enter a positive number: ";
    }
    vector<vector<int>> Vlist;
    Vlist.reserve(N);
    for (int i = 1; i <= N; i++) {
        cout << "\nEnter V" << i << ":\n";
        Vlist.push_back(readVector(i));
    }
    int result = countVectorsIncludingV0(V0, Vlist);
    cout << "\nVi, containing elements V0: " << result << endl;
    return 0;
}
