#include <iostream>
#include <cmath>
using namespace std;
int main(){
int n, opt,x;
char cont;
do{
// print the menu of options

cout << "\nSelect an option from [1-6] according to the menu:";
cin>> opt;
switch(opt){
case 1:  { // OPTION 01: Enter the number
    cout << "Enter the x \t";
    cin >> x;
        do{
            cout << "Enter the number \t";
            cin >> n;
        } while (n<=2 || n>=20); }
break;
case 2: { // OPTION 02: Check if the number has repeated
        do{
            cout << "Enter the number \t";
            cin >> n;
        } while (n<=2 || n>=20); 
    double x, last_term;
    long double result=0.0;

    cout << "Enter a value for x: ";
    cin>> x;

    // term and taylor result when i = 0
    last_term = 1;
    result = last_term;

    // cycle to find each term of taylor serie
    for(int i=1; i<n; i++){
        last_term *= (x) / (i);

        result += last_term;
    }

    cout<< "\nFinal result: "<< endl;
    cout<< "e^("<<x<<") = "<< result<< endl;
}
break;

case 3:
{
      int n;
    double x, term;
    long double result = 0.0;

    // Ввод числа n, которое определяет количество членов ряда
    do {
        cout << "Enter the number of terms (between 2 and 20): ";
        cin >> n;
    } while (n <= 2 || n >= 20);

    // Ввод значения x
    cout << "Enter a value for x: ";
    cin >> x;

    // Инициализация ряда
    term = x;  // Первый член ряда - это просто x
    result = term;



    // Цикл для вычисления следующих членов ряда
    for (int i = 1; i < n; i++) {
        // Вычисление следующего члена ряда
        term *= x ; 
        term *= (-1) ; 
        result +=( term/(i+1));
       
    }

    // Вывод итогового результата
    cout << "\nFinal result: " << endl;
    cout << "ln(1+" << x << ") = " << result << endl;            
}

break;
case 4: 
{
      int n;
    double x, term;
    long double result = 0.0;

    // Ввод числа n, которое определяет количество членов ряда
    do {
        cout << "Enter the number of terms (between 2 and 20): ";
        cin >> n;
    } while (n <= 2 || n >= 20);

    // Ввод значения x
    cout << "Enter a value for x: ";
    cin >> x;

    // Инициализация ряда
    term = x;  // Первый член ряда - это просто x
    result = term;

    // Цикл для вычисления следующих членов ряда
    for (int i = 1; i < n; i++) {
        // Вычисление следующего члена ряда
        term *= -1 * (x*x) / ((2*i)*(2*i+1));
        cout<< term << " ";
        result += term;
       
    }

    // Вывод итогового результата
    cout << "\nFinal result: " << endl;
    cout << "sin(" << x << ") = " << result << endl;    
}
break;
case 5:
{ 
    int n;
    double x, term;
    long double result = 0.0;

    // Ввод числа n, которое определяет количество членов ряда
    do {
        cout << "Enter the number of terms (between 2 and 20): ";
        cin >> n;
    } while (n <= 2 || n >= 20);

    // Ввод значения x
    cout << "Enter a value for x: ";
    cin >> x;

    // Инициализация ряда
    term = 1;  // Первый член ряда - это просто x
    result = term;

    // Цикл для вычисления следующих членов ряда
    for (int i = 1; i < n; i++) {
        // Вычисление следующего члена ряда
        term *= -1 * (x*x) / ((2*i-1)*(2*i));
        cout<< term << " ";
        result += term;
       
    }

    // Вывод итогового результата
    cout << "\nFinal result: " << endl;
    cout << "cos(" << x << ") = " << result << endl;
}
break;
case 6: 
{ 
    int n;
    double x, term;
    long double result = 0.0;

    // Ввод числа n, которое определяет количество членов ряда
    do {
        cout << "Enter the number of terms (between 2 and 20): ";
        cin >> n;
    } while (n <= 2 || n >= 20);

    // Ввод значения x
    do {
    cout << "Enter a value for x: ";
    cin >> x;
    } while (abs(x)>1);
    // Инициализация ряда
    term = 1;  // Первый член ряда - это просто x
    result = term;

    // Цикл для вычисления следующих членов ряда
    for (int i = 1; i < n; i++) {
        // Вычисление следующего члена ряда
        term*=x;
        term+= pow(x,i);
        cout<< term << " ";
        result += term;
       
    }

    // Вывод итогового результата
    cout << "\nFinal result: " << endl;
    cout << "1/(1-" << x << ")^2 = " << result << endl;    
}


// write the code here
break;
}
// Request to user continue or not
cout << "\nDo you want continue [Y|N]? "<< endl;

cin>> cont;
}while(cont == 'y' || cont == 'Y');
cout << "\n The program is over!"<< endl;
return 0;
}
