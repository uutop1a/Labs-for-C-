#include <iostream>
#include <vector>
using namespace std;

vector<int> reverseBack(const vector<int>& arr) {
    vector<int> reversed;
    for (int i = arr.size() - 1; i >= 0; i--) {
        reversed.push_back(arr[i]);
    }

    return reversed;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> result = reverseBack(arr);
    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
