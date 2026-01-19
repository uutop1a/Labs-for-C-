#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x;
    double y;

public:
    // конструктор по умолчанию
    Point() {
        x = 0;
        y = 0;
    }

    // конструктор с параметрами
    Point(double xVal, double yVal) {
        x = xVal;
        y = yVal;
    }

    // копирующий конструктор
    Point(const Point& p) {
        x = p.x;
        y = p.y;
    }

    // метод вычисления расстояния до начала координат
    double distanceToOrigin() const {
        return sqrt(x * x + y * y);
    }

    // сеттеры с проверкой
    void setX(double xVal) {
        x = xVal;
    }

    void setY(double yVal) {
        y = yVal;
    }

    // перегрузка оператора вывода
    friend ostream& operator<<(ostream& out, const Point& p) {
        out << "Point(x=" << p.x << ", y=" << p.y << ")";
        return out;
    }
};

// проверка корректности ввода
double inputDouble(const string& msg) {
    double value;
    while (true) {
        cout << msg;
        cin >> value;
        if (!cin.fail()) break;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error enter! Please repeat.\n";
    }
    return value;
}

int main() {
    cout << "=== Test construct ===\n";

    // 1. конструктор по умолчанию
    Point p1;
    cout << "p1: " << p1 << endl;

    // 2. конструктор с параметрами
    double x = inputDouble("Enter x: ");
    double y = inputDouble("Enter y: ");
    Point p2(x, y);
    cout << "p2: " << p2 << endl;

    // 3. копирующий конструктор
    Point p3(p2);
    cout << "p3 (copy of p2): " << p3 << endl;

    cout << "\n=== Test methods ===\n";
    cout << "Distance from p2 to the origin: "
         << p2.distanceToOrigin() << endl;

    cout << "\n=== Test of setters ===\n";
    double newX = inputDouble("Enter new x: ");
    double newY = inputDouble("Enter new y: ");
    p1.setX(newX);
    p1.setY(newY);
    cout << "p1 after the change: " << p1 << endl;
    cout << "Distance from p1 to the origin: "
         << p1.distanceToOrigin() << endl;

    return 0;
}
