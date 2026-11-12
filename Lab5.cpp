#include <iostream>
#include <cmath>

using namespace std;

// Figure3. Дано дійсні числа (xi, yi), i = 1,2, ... n, – координати точок на
// площині. Визначити кількість точок, що потрапляють в фігуру заданого кольору 
void Figure3(); // завдання 1 декларація функці

// Series12. Дано дійсне число х і натуральне число n. Необхідно:
// a) Обчислити значення виразу при заданих x і n для виразу з табл.2 
// b) Вивести: для парних варіантів – значення кожного третього елемента,
// для непарних – значення кожного четвертого елемента.
void Series12();// завдання 2 декларація функці

// Convergence18. Дослідити ряд на збіжність. Умова закінчення циклу  
// обчислення суми прийняти у вигляді: | un | < е або | un | > g, де е – мала величина
// для переривання циклу обчислення суми збіжного ряду (е = 10-5... 10-20); g – 
// величина для переривання циклу обчислення суми розбіжного ряду (g = 102... 105)
void Convergence18(); // завдання 3 декларація функці

// Декларації (прототипи) допоміжних функцій введення для завдання 4 (щоб main їх бачив)
int getValidInt(const string& prompt, int minVal, int maxVal);
double getValidDouble(const string& prompt);

int main() {
    
    int menu; // змінна для номера завдання[cite: 1]
    
    // Початок циклу меню[cite: 1]
    do {
        cout << "================ МЕНЮ ================" << endl;
        cout << "1 - Завдання 1" << endl;
        cout << "2 - Завдання 2" << endl;
        cout << "3 - Завдання 3" << endl;
        cout << "-1 - Вихід з програми" << endl;
        
        menu = getValidInt("Оберіть пункт меню: ", -1, 3);
        
        // Перемикання між завданнями[cite: 1, 18]
        switch (menu) {
            case 1: Figure3(); break; // 1 - завдання 1[cite: 1, 18]
            case 2: Series12(); break; // 2 - завдання 2[cite: 1, 18]
            case 3: Convergence18(); break; // 3 - завдання 3[cite: 1, 18]
            case -1: cout << "Вихід з програми..." << endl; // -1 - вихід[cite: 1]
                break;
            default: 
                cout << "Неправильний номер завдання!" << endl; // повідомлення про помилку[cite: 1, 18]
        }
    } while (menu != -1); // умова виконання: поки не -1[cite: 1]
    
    return 0;
}

// Максимальний розмір масиву для завдання 1
const int MAX_SIZE = 100;

// (Завдання 4)Функція для безпечного введення цілого числа з перевіркою обмежень
int getValidInt(const string& prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= minVal && value <= maxVal) {
            return value;
        } else {
            cout << "Помилка введення! Введіть ціле число від " << minVal << " до " << maxVal << "." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

// Функція для безпечного введення дійсного числа
double getValidDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        } else {
            cout << "Помилка введення! Введіть дійсне число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

bool isInFigure(double x, double y, double a, double r) {
    // 1. Точка має знаходитися в першій чверті (х >= 0, y >= 0)
    // 2. Усередині прямокутного трикутника: x + y <= a
    // 3. За межами кола радіуса r: x^2 + y^2 >= r^2
    bool inTriangle = (x >= 0) && (y >= 0) && (x + y <= a);
    bool outsideCircle = (x * x + y * y >= r * r);
    
    return inTriangle && outsideCircle;
}

void Figure3() {
    cout << "================ Figure.3 ================" << endl;
    
    double a = getValidDouble("Введіть сторону трикутника (a): ");
    double r = getValidDouble("Введіть радіус кола (r): ");
    int n = getValidInt("Введіть кількість точок (1-100): ", 1, MAX_SIZE);
    
    // Декларація масивів для координат 
    double x[MAX_SIZE];
    double y[MAX_SIZE];
    
    // Введення точок
    for (int i = 0; i < n; i++) {
        cout << "Точка " << i + 1 << ":" << endl;
        x[i] = getValidDouble("  x = ");
        y[i] = getValidDouble("  y = ");
    }
    
    // Підрахунок кількості точок у фігурі
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (isInFigure(x[i], y[i], a, r)) {
            count++;
        }
    }
    
    // Виведення результату
    cout << "Кількість точок, що потрапили в жовту фігуру: " << count << endl;
}

void Series12() {
    cout << "================ Series.12 ================" << endl;
    
    // Декларація змінних
    double x = getValidDouble("Введіть значення x: ");
    int n = getValidInt("Введіть натуральне число n (n >= 1): ", 1, 100);
    
    double sum = 0;
    double fact = 1; // Факторіал k!
    
    // Варіант 3 — непарний, тому виводимо значення кожного 4-го елемента
    cout << "Значення кожного 4-го елемента ряду:" << endl;
    
    // Підрахунок суми виразу: sum_{k=1..n} (x - k)^(k+1) / k!
    for (int k = 1; k <= n; k++) {
        fact *= k; // обчислюємо k! на кожному кроці
        double term = pow(x - k, k + 1) / fact; // k-й елемент
        sum += term; // сума
        
        // Виведення кожного 4-го елемента (k = 4, 8, 12...)
        if (k % 4 == 0) {
            cout << "Елемент k = " << k << ": " << term << endl;
        }
    }
    
    // Виведення загальної суми
    cout << "Загальна сума виразу: " << sum << endl;
}

void Convergence18() {
    cout << "================ Convergence.18 ================" << endl;
    
    // u_n = n^3 / n!
    // Граничні значення e (мала величина) та g (велика величина)
    double e = 1e-5; // 10^-5 для зупинки збіжного ряду
    double g = 1e5;  // 10^5 для зупинки розбіжного ряду
    
    double sum = 0;
    double un = 0;
    double fact = 1;
    int n = 1;
    
    do {
        // Обчислення n!
        fact *= n;
        
        // Поточний член ряду u_n = n^3 / n!
        un = pow(n, 3) / fact;
        sum += un;
        
        cout << "n = " << n << ", u_n = " << un << ", поточна сума = " << sum << endl;
        
        n++;
    } while (fabs(un) >= e && fabs(un) <= g); // умова продовження циклу[cite: 2]
    
    // Визначення результату збіжності
    if (fabs(un) < e) {
        cout << "Ряд ЗБІЖНИЙ. |u_n| < e (" << e << "). Сума ряду = " << sum << endl;
    } else {
        cout << "Ряд РОЗБІЖНИЙ. |u_n| > g (" << g << ")." << endl;
    }
}
