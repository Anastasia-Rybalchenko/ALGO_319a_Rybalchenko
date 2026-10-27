#include <iostream>
using namespace std;

// Proc10. Описати процедуру Swap (X, Y), який міняє вміст змінних X і Y
// (X і Y - дійсні параметри, які є одночасно вхідними та вихідними). З її допомогою 
// для даних змінних A, B, C, D послідовно поміняти вміст наступних п
// ар: A і B, C і D, B і C і вивести нові значення A, B, C, D.
void Proc10(); // завдання 1 декларація функці

// Proc34. Описати функцію Even (K) логічного типу, яка повертає True, якщо
// цілий параметр K є парним, і False в іншому випадку. З її допомогою знайти 
// кількість парних чисел в наборі з 5 цілих чисел.
void Proc34();// завдання 1 декларація функці

// Integer35. Дано кількість годин. Визначити кількість діб і залишок годин. 
// відповідно до варіанту визначити три функції:
// 1) функцію введення вхідних значень з консолі з перевіркою їх накоректність;
// 2) функцію підрахунку результату;
// 3) функцію виведення результату в консоль.
void Integer35(); // завдання 2 декларація функці

// Завдання 1
void Proc10(); // Виконання Proc10
void Proc34(); // Виконання Proc34
void Swap(double &X, double &Y);
bool Even(int K);

// Завдання 2
void Integer35(); // Головна процедура завдання 2
bool in_Hours(int &pH);
int calculate_Days(int pH, int &remHours);
void out_res(int days, int remHours);

   int main() {
   int menu;
   cout << "Номер завдання:";
   cin >> menu;
   // перемикання між завданнями
   switch (menu)
   {
    case 1: Proc10(); break; // Завдання 1
    case 2: Proc34(); break; // Завдання 1
    case 3: Integer35(); break; // Завдання 2
    default: cout << "Неправильне завдання! (Тільки 1-3)" << endl; //повідомлення про помилку
   }
   return 0;
}
  
// Допоміжна процедура Swap
void Swap(double &X, double &Y) {
    double temp = X;
    X = Y;
    Y = temp;
}

// Допоміжна функція Even
bool Even(int K) {
    return (K % 2 == 0);
}

// Завдання 1: Реалізація Proc10
void Proc10() {
    cout << "=================== Proc10. ===================" << endl;
    double A, B, C, D;
    cout << "Введіть 4 дійсні числа (A, B, C, D): ";
    cin >> A >> B >> C >> D;
    
// Перевірка: якщо всі числа належать діапазону [-100, 100]
    if (A >= -100 && A <= 100 && 
        B >= -100 && B <= 100 && 
        C >= -100 && C <= 100 && 
        D >= -100 && D <= 100) {
        
        // Послідовна зміна пар: A і B, C і D, B і C
        Swap(A, B);
        Swap(C, D);
        Swap(B, C);

        cout << "Нові значення після обміну:\n";
        cout << "A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << endl;
    }
    else {
        cout << "Помилка! Значення виходять за діапазон [-100, 100]." << endl;
    }
}

// Завдання 1: Реалізація Proc34
void Proc34() {
    cout << "=================== Proc34. ===================" << endl;
    int n1, n2, n3, n4, n5;
    cout << "Введіть 5 цілих чисел: ";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;

    // Підрахунок парних чисел за допомогою додавання логічних значень
    int count = Even(n1) + Even(n2) + Even(n3) + Even(n4) + Even(n5);

    cout << "Кількість парних чисел у наборі: " << count << endl;
}

// Завдання 2: Окремі функції для Integer35

// 1) Введення з перевіркою
bool in_Hours(int &pH) {
    cout << "Введіть кількість годин (від -100 до 100): ";
    cin >> pH;

    // Перевірка на помилку консольного введення
    if (cin.fail()) {
        cin.clear();
        return false;
    }

    // Перевірка приналежності діапазону [-100, 100]
    if (pH < -100 || pH > 100) {
        return false;
    }

    return true;
}

// 2) Обчислення
int calculate_Days(int pH, int &remHours) {
    int days = pH / 24;
    remHours = pH % 24;
    return days;
}

// 3) Виведення
void out_res(int days, int remHours) {
    cout << "Кількість діб: " << days << endl;
    cout << "Залишок годин: " << remHours << endl;
}

// Завдання 2: Реалізація Integer35
void Integer35() {
    cout << "=================== Integer35. ===================" << endl;
    int hours;
    
    // Перевірка введення та обчислення
    if (!in_Hours(hours)) {
        cout << "Помилка! Введено некоректні дані або значення виходить за діапазон [-100, 100]." << endl;
    } else {
        int remHours = 0;
        int days = calculate_Days(hours, remHours);
        out_res(days, remHours);
    }
}
