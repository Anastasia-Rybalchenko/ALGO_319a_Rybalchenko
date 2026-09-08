// Бібліотека та компоненти
#include <iostream>
#include <cmath>

using namespace std;

//головна функція
int main ()

{
// задача Begin11
// декларація змінних та їх значень
double L, R, pi=3.14, S;
// введення змінної
cout <<"Значення R = ";
cin >> R;
// розрахунок результату
L = 2 * R * pi;
S = pi * pow(R, 2);
// вивід результату
 cout << "L = " << L << endl;
    cout << "S = " << S << endl;
// задача ...
return 0;
}