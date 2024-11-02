#include <iostream>
#include <cmath>
using namespace std;

// Заголовки пользовательских функций
void input_num_elements(int *n);                // Процедура для ввода количества элементов
int *allocate_memory(int n);                    // Функция для динамического выделения памяти
void input_vector(int n, int *x);               // Процедура  для ввода элементов вектора
void print_vector(int n, int *x);               // Процедура  для вывода элементов вектора
bool is_starkx(int n, int *x);                  // Функция для проверки, является ли вектор STARKX
void generate_vec_max_digits(int n, int *x, int *y);  // Процедура  для создания вектора из максимальных цифр каждого элемента
int search_highest_digit(int num);              // Функция для поиска максимальной цифры числа
long long generate_number(int n, int *x);       // Функция для генерации числа из массива цифр

// Основная функция main
int main(){
    int n, *a, *b,*x;  // Объявление переменных и указателей для динамических массивов
    long long num;               // Переменная для хранения сгенерированного числа

    input_num_elements(&n);      // Ввод количества элементов вектора

    a = allocate_memory(n);      // Выделение памяти для вектора a

    cout<<"\nInput the elements in vector: "<<endl;
    input_vector(n, a);          // Ввод элементов вектора A
    cout<<"\nVector A: "<<endl;
    print_vector(n, a);          // Вывод вектора A

    // Проверка, является ли вектор STARKX
    if(is_starkx(n, a) == true){
        cout<<"\nThe vector is STARKX"<<endl;
    }else{
        cout<<"\nThe vector is not STARKX"<<endl;
    }    

    b = allocate_memory(n);      // Выделение памяти для вектора b
    generate_vec_max_digits(n, a, b);  // Генерация вектора из максимальных цифр каждого элемента
    cout<<"\nVector of max digits: "<<endl;
    print_vector(n, b);
    num = generate_number(n, b); // Генерация числа из массива максимальных цифр
    cout<<"\nGenerated number = "<<num<<endl;
    
 

    return 0;
}

// Процедура  для ввода количества элементов
void input_num_elements(int *n){
    do{
        cout<<"\nNumber of elements: ";
        cin>>*n;
    }while(*n<=0 || *n%2 != 0);  // Проверка: количество элементов должно быть положительным и чётным
}   

// Функция для динамического выделения памяти для вектора
int *allocate_memory(int n){
    return (int *) malloc(n * sizeof(int));
}

// Процедура  для ввода элементов вектора
void input_vector(int n, int *x){
    for(int i=0; i<n; i++){
        do{
            cout<<"X["<<i<<"]: ";
            cin>>x[i];
        }while(x[i]<1000 || x[i]>10000);  // Проверка: элемент должен быть четырёхзначным
    }
}

// Процедура  для вывода элементов вектора
void print_vector(int n, int *x){
    for(int i=0; i<n; i++){
        cout<<x[i]<<"  ";
    }
    cout<<endl;
}
// Функция для проверки, является ли вектор STARKX
bool is_starkx(int n, int *x){
    int *even, *odd, counter=0;
    bool flag=true;
    even = x;
    odd = x;
    // Проверка для каждого чётного и нечётного элемента
    while(counter < n/2 && flag == true){
        if(*(even+2*counter) < *(odd+2*counter+1)){ // Если элемент на чётной позиции меньше элемента на нечётной
            flag = false;
        }
        counter++;
    }
    return flag;
}
// Процедура  для создания вектора с максимальными цифрами каждого элемента
void generate_vec_max_digits(int n, int *x, int *y){
    for(int i=0; i<n; i++){
        y[i] = search_highest_digit(x[i]);
    }
}

// Функция для поиска максимальной цифры в числе
int search_highest_digit(int num){
    int aux, dig, max_dig=-1;
    aux = num;

    while(aux>0){
        dig = aux%10;               // Получение последней цифры числа
        if(dig>max_dig){            // Проверка, является ли текущая цифра больше максимальной
            max_dig = dig;
        }
        aux = aux/10;               // Переход к следующей цифре
    }
    return max_dig;
}

// Функция для создания числа из вектора цифр
long long generate_number(int n, int *x){
    long long num = 0, order=1;

    for(int i=0; i<n; i++){
        num = num + x[i]*order;     // Добавление цифры с учётом её порядка
        order = order * 10;         // Увеличение порядка
    }
    return num;
}
