#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <random>
#include <ctime>
#include <algorithm>
#include <cmath>

using namespace std;

class FileTasks {
public:
    // ===================== Общие утилиты =====================
    static int randInt(int a, int b) {
        static std::mt19937 rng((unsigned)time(nullptr));
        std::uniform_int_distribution<int> dist(a, b);
        return dist(rng);
    }

    static double randDouble(double a, double b) {
        static std::mt19937 rng((unsigned)time(nullptr) + 12345);
        std::uniform_real_distribution<double> dist(a, b);
        return dist(rng);
    }

    // ===================== 1
    // бинарный файл с int. получить в другом файле все компоненты исходного,  кроме тех, которые кратны k.
    static void fillBinaryInts(const string& filename, int count, int minV = -50, int maxV = 50) {
        ofstream out(filename, ios::binary);
        if (!out) { cerr << "Failed to create: " << filename << "\n"; return; }

        for (int i = 0; i < count; i++) {
            int x = randInt(minV, maxV);
            out.write(reinterpret_cast<const char*>(&x), sizeof(x));
        }
        out.close();
    }

    static void task1_copyNotMultipleOfK(const string& inFile, const string& outFile, int k) {
        ifstream in(inFile, ios::binary);
        ofstream out(outFile, ios::binary);
        if (!in) { cerr << "Failed to open: " << inFile << "\n"; return; }
        if (!out) { cerr << "Failed to create: " << outFile << "\n"; return; }
        if (k == 0) { cerr << "k cannot be 0\n"; return; }

        int x;
        while (in.read(reinterpret_cast<char*>(&x), sizeof(x))) {
            if (x % k != 0) {
                out.write(reinterpret_cast<const char*>(&x), sizeof(x));
            }
        }
        in.close();
        out.close();
    }

    static void printBinaryInts(const string& filename) {
        ifstream in(filename, ios::binary);
        if (!in) { cerr << "Failed to open: " << filename << "\n"; return; }
        int x;
        while (in.read(reinterpret_cast<char*>(&x), sizeof(x))) {
            cout << x << " ";
        }
        cout << "\n";
    }

    // ===================== 2
    // cкопировать элементы заданного бинарного файла в матрицу n×n (int). если не хватает — добить нулями.
    // указать номер столбца, где произведение элементов дальше всего от нуля
    // (максимальное по модулю).
    static void task2_matrixAndColumn(const string& binFile, int n) {
        ifstream in(binFile, ios::binary);
        if (!in) { cerr << "Failed to open: " << binFile << "\n"; return; }
        if (n <= 0) { cerr << "n must be > 0\n"; return; }

        vector<vector<long long>> a(n, vector<long long>(n, 0));

        // Заполняем по строкам
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                if (in.read(reinterpret_cast<char*>(&x), sizeof(x))) {
                    a[i][j] = x;
                } else {
                    a[i][j] = 0;
                }
            }
        }
        in.close();

        cout << "Matrix " << n << "x" << n << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << setw(6) << a[i][j] << " ";
            }
            cout << "\n";
        }

        // произведение по столбцам (используем long double для оценки, и одновременно храним логарифмическую метрику, чтобы не утонуть в переполнениях)
        // т.к. числа у маленькие (randInt), можно и long double product.
        int bestCol = 0;
        long double bestAbs = -1;

        for (int col = 0; col < n; col++) {
            long double prod = 1;
            for (int row = 0; row < n; row++) {
                prod *= (long double)a[row][col];
            }
            long double absProd = fabsl(prod);

            // "дальше от нуля" => больше |prod|
            if (absProd > bestAbs) {
                bestAbs = absProd;
                bestCol = col;
            }
        }

        cout << "Column with the product farthest from zero: "
             << (bestCol + 1) << " (numbering с 1), |prod|=" << (double)bestAbs << "\n";
    }

    // ===================== 3
    // бинарный файл со struct: название, цена, возрастные границы.
    // проверка: можно ли подобрать игрушку ребенку 3 лет, любую, кроме "мяч". (ageFrom<=3<=ageTo и name != "мяч")
    struct Toy {
        char name[32];  // фиксированная строка
        int price;      // рубли
        int ageFrom;
        int ageTo;
    };

    static void fillBinaryToys(const string& filename) {
        // набор примеров часть подойдёт 3-летнему
        vector<Toy> toys;

        auto makeToy = [](const string& n, int price, int af, int at) -> Toy {
            Toy t{};
            // безопасно копировать в char[]
            size_t len = min(n.size(), sizeof(t.name) - 1);
            for (size_t i = 0; i < len; i++) t.name[i] = n[i];
            t.name[len] = '\0';
            t.price = price;
            t.ageFrom = af;
            t.ageTo = at;
            return t;
        };

        toys.push_back(makeToy("ball", 300, 3, 10));
        toys.push_back(makeToy("yoyo", 1200, 3, 7));
        toys.push_back(makeToy("monopoly", 500, 2, 5));
        toys.push_back(makeToy("lego", 2500, 5, 12));
        toys.push_back(makeToy("car", 800, 3, 6));

        ofstream out(filename, ios::binary);
        if (!out) { cerr << "Failed to create: " << filename << "\n"; return; }
        for (const auto& t : toys) {
            out.write(reinterpret_cast<const char*>(&t), sizeof(Toy));
        }
        out.close();
    }

    static void task3_canPickToyForAge3_exceptBall(const string& filename) {
        ifstream in(filename, ios::binary);
        if (!in) { cerr << "Failed to open: " << filename << "\n"; return; }

        bool found = false;
        Toy t;

        while (in.read(reinterpret_cast<char*>(&t), sizeof(Toy))) {
            string name = t.name;
            // сравнение строго с "мяч" (как в задании)
            if (name != "ball" && t.ageFrom <= 3 && 3 <= t.ageTo) {
                found = true;
                cout << "Found a suitable toy for a 3-year-old (not a ball)): "
                     << name << ", cost: " << t.price
                     << ", age: " << t.ageFrom << "-" << t.ageTo << "\n";
                // можно не прерывать, но достаточно одной
                break;
            }
        }

        if (!found) {
            cout << "It was not possible to find a suitable toy for a 3-year-old (other than a ball).\n";
        }

        in.close();
    }

    static void printToys(const string& filename) {
        ifstream in(filename, ios::binary);
        if (!in) { cerr << "Failed to open: " << filename << "\n"; return; }

        cout << "Contents of the toy file:\n";
        Toy t;
        while (in.read(reinterpret_cast<char*>(&t), sizeof(Toy))) {
            cout << "Name: " << t.name
                 << ", cost: " << t.price
                 << ", age: " << t.ageFrom << "-" << t.ageTo << "\n";
        }
        in.close();
    }

    // ===================== ЗАДАНИЕ 4 =====================
    // Текстовый файл: целые числа, по одному в строке.
    // Найти сумму max и min.
    static void fillTextOneIntPerLine(const string& filename, int count, int minV=-100, int maxV=100) {
        ofstream out(filename);
        if (!out) { cerr << "Failed to create: " << filename << "\n"; return; }

        for (int i = 0; i < count; i++) {
            out << randInt(minV, maxV) << "\n";
        }
        out.close();
    }

    static void task4_sumMinMax(const string& filename) {
        ifstream in(filename);
        if (!in) { cerr << "Failed to open: " << filename << "\n"; return; }

        long long mn = LLONG_MAX, mx = LLONG_MIN;
        long long x;
        bool any = false;

        while (in >> x) {
            any = true;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        in.close();

        if (!any) {
            cout << "The file is empty or doesnt contain any numbers.\n";
            return;
        }
        cout << "min=" << mn << ", max=" << mx << ", sum(min+max)=" << (mn + mx) << "\n";
    }

    // ===================== 5
    // целые числа, по несколько в строке.
    // вычислить сумму чётных элементов.
    static void fillTextManyIntsPerLine(const string& filename, int lines, int perLineMin=3, int perLineMax=8,
                                        int minV=-50, int maxV=50) {
        ofstream out(filename);
        if (!out) { cerr << "Failed to create: " << filename << "\n"; return; }

        for (int i = 0; i < lines; i++) {
            int cnt = randInt(perLineMin, perLineMax);
            for (int j = 0; j < cnt; j++) {
                out << randInt(minV, maxV);
                if (j + 1 < cnt) out << " ";
            }
            out << "\n";
        }
        out.close();
    }

    static void task5_sumEven(const string& filename) {
        ifstream in(filename);
        if (!in) { cerr << "Failed to open: " << filename << "\n"; return; }

        long long sum = 0;
        long long x;
        while (in >> x) {
            if (x % 2 == 0) sum += x;
        }
        in.close();

        cout << "Sum of even elements = " << sum << "\n";
    }

    // ===================== 6
    // cоздать новый текстовый файл: каждая строка содержит первый символ соответствующей строки исходного файла.
    static void task6_firstCharsPerLine(const string& inFile, const string& outFile) {
        ifstream in(inFile);
        ofstream out(outFile);
        if (!in) { cerr << "Failed to open: " << inFile << "\n"; return; }
        if (!out) { cerr << "Failed to create: " << outFile << "\n"; return; }

        string line;
        while (getline(in, line)) {
            if (!line.empty()) out << line[0] << "\n";
            else out << "\n"; // если строка пустая —  пустую строку
        }
        in.close();
        out.close();
    }

    // создать текст для 6
    static void fillTextFileSample(const string& filename) {
        ofstream out(filename);
        if (!out) { cerr << "Failed to create: " << filename << "\n"; return; }
        out << "Hello World!\n";
        out << "I'm Kirill 19yo.\n";
        out << "\n";
        out << "I wanna go home.\n";
        out.close();
    }

    // ===================== всё подряд
    static void runAll() {
        cout << "Ex 1 \n";
        string bin1 = "task1_in.bin";
        string bin1out = "task1_out.bin";
        fillBinaryInts(bin1, 30, -20, 20);
        cout << "Source file: "; printBinaryInts(bin1);
        int k = 3;
        task1_copyNotMultipleOfK(bin1, bin1out, k);
        cout << "Without multiples " << k << ": "; printBinaryInts(bin1out);

        cout << "\n Ex 2 \n";
        // используем тот же бинарный файл с числами или создадим новый:
        string bin2 = "task2_in.bin";
        fillBinaryInts(bin2, 20, -5, 5);
        cout << "Numbers (file): "; printBinaryInts(bin2);
        task2_matrixAndColumn(bin2, 4);

        cout << "\n Ex 3 \n";
        string toysFile = "task3_toys.bin";
        fillBinaryToys(toysFile);
        printToys(toysFile);
        task3_canPickToyForAge3_exceptBall(toysFile);

        cout << "\n Ex 4 \n";
        string t4 = "task4_nums.txt";
        fillTextOneIntPerLine(t4, 15, -100, 100);
        task4_sumMinMax(t4);

        cout << "\n Ex 5 \n";
        string t5 = "task5_nums.txt";
        fillTextManyIntsPerLine(t5, 5, 4, 9, -30, 30);
        task5_sumEven(t5);

        cout << "\n Ex 6 \n";
        string t6in = "task6_text.txt";
        string t6out = "task6_firstchars.txt";
        fillTextFileSample(t6in);
        task6_firstCharsPerLine(t6in, t6out);
        cout << "file created " << t6out << " (the first characters of each line).\n";
    }
};


int main() {

    cout << "1 - complete all tasks in a row\n";
    cout << "0 - exit\n";
    cout << "Choice: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        FileTasks::runAll();
    }

    return 0;
}
