#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int maxAbs(vector<int> arr, int n) {
    if (n == 0) return 0;
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (abs(arr[i]) > abs(max)) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;
    cout << "Enter count of symbols in arr: ";
    cin >> n;
    vector<int> m(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> m[i];
    }
    int result = maxAbs(m, n);
    cout << "Found number: " << result;

    return 0;
}