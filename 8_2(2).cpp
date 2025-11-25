#include <iostream>
#include <list>
#include <deque>
#include <string>
#include <iterator>
#include <algorithm>
#include <numeric>  // для adjacent_difference
using namespace std;

list<string> readList()
{
    list<string> L;
    int n;
    cout << "Enter a count of words in list L: ";
    while (!(cin >> n) || n < 2) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error! A count of words must be >= 2: ";
    }
    cout << "Enter " << n << " english words:\n";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        L.push_back(s);
    }
    return L;
}

struct WordCombineFixed
{
    // current = правый элемент пары, previous = левый элемент пары
    string operator()(const string& current, const string& previous) const
    {
        // первая буква левого + последняя буква правого
        char firstOfLeft = previous.front();
        char lastOfRight = current.back();

        string result;
        result.push_back(firstOfLeft);
        result.push_back(lastOfRight);
        return result;
    }
};

deque<string> buildDeque(const list<string>& L)
{
    deque<string> D;
    // adjacent_difference запишет сначала комбинацию для L0L0
    adjacent_difference(
            L.begin(), L.end(),
            inserter(D, D.end()),
            WordCombineFixed()
    );
    // удаление первого лишнего элемента
    if (!D.empty()) D.erase(D.begin());
    return D;
}

void printDeque(const deque<string>& D)
{
    for (const auto& s : D)
        cout << s << " ";
    cout << endl;
}

int main()
{
    list<string> L = readList();
    cout << "\nList L:\n";
    for (const auto& s : L) cout << s << " ";
    cout << "\n\n";
    deque<string> D = buildDeque(L);
    cout << "Dec D:\n";
    printDeque(D);
    return 0;
}
