#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>
using namespace std;

void readNumbersFromFile(const string& filename, vector<int>& numbers) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Cannot open file: " << filename << endl;
        return;
    }
    int x;
    while (infile >> x) {
        numbers.push_back(x);
    }
    infile.close();
}

void inputNumbersFromKeyboard(vector<int>& numbers) {
    int n;
    cout << "Enter the number of integers: ";
    while (!(cin >> n) || n <= 0) {
        cout << "Error! Enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    numbers.resize(n);
    cout << "Enter " << n << " integers: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        while (!(cin >> *it)) {
            cout << "Error! Enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

struct EvenPositionFilter {
    int pos;
    EvenPositionFilter() : pos(1) {}
    bool operator()(int) {
        bool remove = (pos % 2 == 0);
        pos++;
        return remove;
    }
};

vector<int> getOddPositionNumbers(const vector<int>& numbers) {
    vector<int> result;
    remove_copy_if(numbers.begin(), numbers.end(), back_inserter(result), EvenPositionFilter());
    return result;
}

// функция вывода вектора в прямом порядке
void printVector(const vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    vector<int> numbers;
    readNumbersFromFile(filename, numbers);
    if (numbers.empty()) {
        cout << "File not found or empty. Enter count of numbers from keyboard instead." << endl;
        inputNumbersFromKeyboard(numbers);
    }
    vector<int> oddPosNumbers = getOddPositionNumbers(numbers);
    cout << "\nNumbers with odd ordinal numbers (normal order): ";
    printVector(oddPosNumbers);
    return 0;
}
