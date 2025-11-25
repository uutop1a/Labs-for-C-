#include <iostream>
#include <vector>
#include <locale>
using namespace std;

int findAll(vector<int> arr, int x, int n) {
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        if (x == arr[i]) {
            numbers.push_back(i);
        }
    }
    cout << "Founded elements:" << endl;
    for (int num : numbers) {
        cout << num << " ";
    }
    return 0;
}

int main()
{
    int n, x;
    cout << "Enter count symbols in arr:";
    cin >> n;
    cout << "Enter x:";
    cin >> x;
    vector<int> m(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter numbers by Enter:" << endl;
        cin >> m[i];
    }
    findAll(m, x, n);
    return 0;
}