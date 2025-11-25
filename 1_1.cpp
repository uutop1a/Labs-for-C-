#include <iostream>
#include <vector>
#include <math.h>
#include <locale>
using namespace std;


double Fraction(double x) {
    double integerPart;
    double fractionalPart = modf(x, &integerPart);
    cout << "Separated part:" << fractionalPart;
    return x;
}

int main() {
    setlocale(LC_ALL, "RU");
    double x;
    cout << "Enter x:";
    cin >> x;

    Fraction(x);
}