#include <iostream>
#include <vector>
using namespace std;

int findAll(vector<int> arr, int x, int n) {
    for (int i = 0; i < n; i++) {
        if (x == arr[i]) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n, x;
    cout << "Enter count of symbols in arr:";
    cin >> n;
    cout << "Enter x:";
    cin >> x;
    vector<int> m(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter numbers by Enter:" << endl;
        cin >> m[i];
    }
    cout << "Found index:" << findAll(m, x, n);
}