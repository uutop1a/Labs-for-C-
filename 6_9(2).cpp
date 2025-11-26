#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

void processListUsingReverseCopy(list<int>& L)
{
    if (L.size() % 2 != 0) {
        throw runtime_error("List must be even!");
    }
    auto mid = L.begin();
    advance(mid, L.size() / 2); // передвижение итератора на середину
    // копирование первой половины в конец в обратном порядке
    reverse_copy(L.begin(), mid, inserter(L, L.end()));
}

void processListUsingInsert(list<int>& L)
{
    if (L.size() % 2 != 0) {
        throw runtime_error("List must be even!");
    }
    auto mid = L.begin();
    advance(mid, L.size() / 2);
    // вставка первой половины, используя обратные итераторы
    L.insert(L.end(), make_reverse_iterator(mid), make_reverse_iterator(L.begin()));
}
list<int> readList()
{
    list<int> L;
    int n;
    cout << "Enter count of elements (even): ";
    while (!(cin >> n) || n <= 0 || n % 2 != 0) {
        cin.clear();
        cout << "Error! Enter positive even number: ";
    }
    cout << "Enter " << n << " int numbers:\n";
    for (int i = 0; i < n; i++) {
        int x;
        while (!(cin >> x)) {
            cin.clear();
            cout << "Error! Enter int number: ";
        }
        L.push_back(x);
    }
    return L;
}

void printList(const list<int>& L)
{
    for (int x : L) cout << x << " ";
    cout << endl;
}

int main()
{
    list<int> L1 = readList();
    processListUsingReverseCopy(L1);
    cout << "Result L1: ";
    printList(L1);
    list<int> L2 = readList();
    processListUsingInsert(L2);
    cout << "Result L2: ";
    printList(L2);
}
