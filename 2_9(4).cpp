#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Point {
private:
    double x;
    double y;

public:
    // 1) конструктор по умолчанию
    Point() : x(0), y(0) {}

    // 2) конструктор с параметрами
    Point(double xVal, double yVal) : x(xVal), y(yVal) {}

    // 3) копирующий конструктор
    Point(const Point& p) : x(p.x), y(p.y) {}

    // сеттеры
    void setX(double xVal) { x = xVal; }
    void setY(double yVal) { y = yVal; }

    // геттеры (принимают запрещяя изменение)
    double getX() const { return x; }
    double getY() const { return y; }

    // метод расстояние до начала координат
    double distanceToOrigin() const {
        return sqrt(x * x + y * y);
    }

    // допметод расстояние до другой точки
    double distanceTo(const Point& p) const {
        double dx = x - p.x;
        double dy = y - p.y;
        return sqrt(dx * dx + dy * dy);
    }

    // унарные

    // --p : уменьшить x и y на 1 (префикс)
    Point& operator--() {
        x -= 1;
        y -= 1;
        return *this;
    }

    // -p : поменять x и y местами (унарный минус)
    Point operator-() const {
        Point tmp(*this);
        double t = tmp.x;
        tmp.x = tmp.y;
        tmp.y = t;
        return tmp;
    }

    // приведение типов


    // int (неявное): целая часть x сам изменяется
    operator int() const {
        return static_cast<int>(x);
    }

    // double (явное): координата y принуждаешь измениться
    explicit operator double() const {          //explicit — чтобы не случались случайные преобразования.
        return y;
    }

    // бинарные операции

    // p - int : уменьшается координата x
    Point operator-(int k) const {
        return Point(x - k, y);
    }

    // p - Point : расстояние до точки p ( double)
    double operator-(const Point& p) const {
        return distanceTo(p);
    }

    // вывод
    friend ostream& operator<<(ostream& out, const Point& p) {
        out << "Point(x=" << p.x << ", y=" << p.y << ")";
        return out;
    }
};

//ввод с проверкой
double inputDouble(const string& msg) {
    double value;
    while (true) {
        cout << msg;
        cin >> value;
        if (!cin.fail()) return value;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error: please enter a number.\n";
    }
}

int inputInt(const string& msg) {
    int value;
    while (true) {
        cout << msg;
        cin >> value;
        if (!cin.fail()) return value;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error: please enter an integer.\n";
    }
}

int inputMenuChoice() {
    int c;
    while (true) {
        cout << "\nSelect an action (1-7): ";
        cin >> c;
        if (!cin.fail() && c >= 1 && c <= 7) return c;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error: please enter a number from 1 to 7.\n";
    }
}

int main() {     // перегрузка операторов

    // создаём p1 по вводу
    double x1 = inputDouble("Enter x for p1: ");
    double y1 = inputDouble("Enter y for p1: ");
    Point p1(x1, y1);

    // создаём p2 по вводу
    double x2 = inputDouble("Enter x for p2: ");
    double y2 = inputDouble("Enter y for p1: ");
    Point p2(x2, y2);

    while (true) {
        cout << "\n-----------------------------\n";
        cout << "Current points:\n";
        cout << "p1 = " << p1 << "\n";
        cout << "p2 = " << p2 << "\n";
        cout << "-----------------------------\n";

        cout << "1) --p1 (decrease x and y p1 by 1)\n";
        cout << "2) -p1 (swap x and y, return the NEW point)\n";
        cout << "3) Implicit cast of p1 to int (integer part of x)\n";
        cout << "4) Explicit cast of p1 to double (y coordinate)\n";
        cout << "5) p1 - k (decrease x by an integer k, return the NEW point)\n";
        cout << "6) p1 - p2 (distance between points)\n";
        cout << "7) Exit\n";

        int choice = inputMenuChoice();

        if (choice == 1) {
            --p1;
            cout << "Completed: --p1\n";
            cout << "Now p1 = " << p1 << "\n";
        } else if (choice == 2) {
            Point swapped = -p1;
            cout << "Result -p1 (p1 does NOT change)): " << swapped << "\n";
            cout << "p1 as he was, he remained: " << p1 << "\n";
        } else if (choice == 3) {
            int ix = p1; // неявное приведение
            cout << "int(p1) implicitly: " << ix << " (whole part x)\n";
        } else if (choice == 4) {
            double dy = (double)p1; // явное (explicit)
            cout << "(double)p1 clearly: " << dy << " (this is y)\n";
        } else if (choice == 5) {
            int k = inputInt("Enter an integer k: ");
            Point res = p1 - k;
            cout << "p1 - " << k << " = " << res << " (p1 does not change)\n";
        } else if (choice == 6) {
            double dist = p1 - p2;
            cout << "Distance p1 - p2 = " << dist << "\n";
        } else { // 7
            cout << "Exit.\n";
            break;
        }
    }

    return 0;
}
