#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

list<int> readList()
{
    list<int> L;
    int n;

    cout << "Enter a count of numbers in list: ";
    while (!(cin >> n) || n <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error! Enter a positive number: ";
    }

    cout << "Enter " << n << " even numbers:\n";
    for (int i = 0; i < n; i++) {
        int x;
        while (!(cin >> x)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error! Enter a even number: ";
        }
        L.push_back(x);
    }

    return L;
}

void printList(const list<int>& L)
{
    for (int x : L)
        cout << x << " ";
    cout << endl;
}

void rearrangeList(list<int>& L)
{
    stable_partition(L.begin(), L.end(), [](int x) {
        return x > 0;
    });
}

int main()
{
    list<int> L = readList();
    rearrangeList(L);
    cout << "\nResult:\n";
    printList(L);

    return 0;
}
