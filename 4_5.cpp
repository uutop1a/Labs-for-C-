#include <iostream>
using namespace std;

int* add(int arr[], int ins[], int pos, int arrSize, int insSize) {
    int newSize = arrSize + insSize;
    int* result = new int[newSize];
    for (int i = 0; i < pos; i++) {
        result[i] = arr[i];
    }
    for (int i = 0; i < insSize; i++) {
        result[pos + i] = ins[i];
    }
    for (int i = pos; i < arrSize; i++) {
        result[insSize + i] = arr[i];
    }
    return result;
}

int main() {
    // Исходные данные
    int arr[] = {1, 2, 3, 4, 5};
    int ins[] = {7, 8, 9};
    int pos = 3;
    int arrSize = 5;
    int insSize = 3;
    int* result = add(arr, ins, pos, arrSize, insSize);
    cout << "Result: ";
    for (int i = 0; i < 8; i++) {
        cout << result[i] << " ";
    }

    return 0;
}