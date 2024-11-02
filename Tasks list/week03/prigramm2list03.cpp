/*
    WEEK 03 - PROGRAM 02: Conversion of the number system.
   Convert a number based on 10 to base n.
   Convert the number to a decimal number system.
*/
#include <iostream>
using namespace std;
int main() {
    int menu,n,a;
    cout << "select an option ";
    cin >> menu;
    switch (menu)
    {
    case 1: 
    {
    cout << "\nConversion from base 10 to base n";    
    cout << "\n Define a = "; 
    cin >> a;
    cout << "\n Define n = "; 
    cin >> n;
    int aux = a; // Копия числа для преобразования
    int dig, order = 1; // dig - текущая цифра, order - разряд (1, 10, 100, ...)
    int y = 0; // Результат в целевой системе
    // Цикл для преобразования из десятичной системы в основание n
    while (aux > 0) {
        dig = aux % n;        // Находим остаток (текущую цифру в системе с основанием n)
        aux = aux / n;        // Делим на основание, чтобы перейти к следующей цифре
        y = y + dig * order;  // Формируем число в целевой системе
        order = order * 10;   // Увеличиваем разряд (сдвигаем влево на 1 позицию)
    }

    cout << "\n Value in base " << n << " = " << y << endl; // Вывод результата
    }
        break;
    
   case 2:
    cout << "\nConvert from base n to base 10";    
    cout << "\nInput the number: "; // Введите число в системе с основанием n1
    cin >> a;
    cout << "\nInput the base: "; // Введите основание системы
    cin >> n;

    int aux = a; // Копия числа для преобразования
    int dig, order = 1; // dig - текущая цифра, order - разряд (1, 10, 100, ...)
    int y = 0; // Результат в целевой системе
    // Цикл для преобразования из системы с основанием n1 в десятичную систему
    while (aux > 0) {
        dig = aux % 10;         // Извлекаем последнюю цифру числа
        y = y + dig * order;  // Добавляем её к результату, умножая на текущий порядок
        aux = aux / 10;         // Переходим к следующей цифре
        order = order * n;     // Увеличиваем порядок (переход к следующему разряду)
    }
    
    cout << "\n Value in base 10 " << " = " << y << endl; // Вывод результата
        break;
    }

}