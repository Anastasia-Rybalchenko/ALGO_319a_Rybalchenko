 // Бібліотека та компоненти
#include <iostream>
#include <cmath>

using namespace std;

//головна функція
int main ()

{
//================== Begin 11 ==================
//Декларація змінних 

double S, L, R, pi=3.14 ;

//communication
cout << "================== Begin 11 ==================" << endl;

// Введення змінних
cout << "Значення L=";
cin >> L;

// розрахунок результату
   R = L / (2 * pi);
   
// вивід результату
 cout << "R = " << R << endl;
 
// розрахунок результату 
 S = pi * R * R;
 
 // вивід результату
 cout << "S = " << S << endl;
 
return 0;
}
