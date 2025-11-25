#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

void readNumbersFromFile(const string& filename, vector<int>& V) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error when opening a file!" << endl;
        return;
    }
    // чтение данных из файла
    istream_iterator<int> start(infile), end;
    V.assign(start, end);
    infile.close();
}
void printVectorInOrder(const std::vector<int>& V) {
    cout << "Vector elements:" << endl;
    for (vector<int>::const_iterator it = V.begin(); it != V.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    vector<int> V;
    string filename;
    cout << "Enter file name: ";
    cin >> filename;
    readNumbersFromFile(filename, V);
    if (V.empty()) {
        cout << "Vector is empty!" << endl;
    } else {
        printVectorInOrder(V);
    }

}
