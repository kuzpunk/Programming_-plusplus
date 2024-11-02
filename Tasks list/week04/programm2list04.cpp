
#include <iostream>
using namespace std;

void input_num_elements(int *n,int *m){
    cout <<"\nNumber of elements: (n m) ";
    cin >> *n >> *m;
} 


// Функция для динамического выделения памяти для вектора
char *allocate_memory(int n){
    return (char *) malloc(n * sizeof(char));
}


// Процедура  для ввода элементов вектора
void input_vector(int n, char *a) {
    for(int i=0; i<n; i++){
            cin>>a[i];
}
}

// Процедура  для вывода элементов вектора
void print_vector(int n, char *a) {
    for(int i=0; i<n; i++){
        cout<<a[i];
    }
    cout<<endl;
}


// Процедура  для ввода элементов вектора
void input_vectorX(int n, int m, char *x,char *a, char *b) {
    int i = 0, j = 0, k = 0;
    
    // Чередуем символы из A и B
    while (i < n || j < m) {
        if (i < n) {
            x[k++] = a[i++];
        }
        if (j < m) {
            x[k++] = b[j++];
        }
    }
}



int main() {
  int n,m;
  char *a,*b,*x;
  input_num_elements(&n,&m);  
  a = allocate_memory(n);
  b = allocate_memory(m);  
  x = allocate_memory(n+m);  

    cout<<"\nInput the elements in vector A: "<<endl;
    input_vector(n, a);          // Ввод элементов вектора A
    cout<<"\nInput the elements in vector B: "<<endl;
    input_vector(m, b);          // Ввод элементов вектора B
    cout<<"\nVector A: "<<endl;
    print_vector(n, a);          // Вывод вектора A
    cout<<"\nVector B: "<<endl;
    print_vector(m, b);          // Вывод вектора B
    input_vectorX(n,m,x,a,b);          // Ввод элементов вектора X
    cout<<"\nVector X: "<<endl;
    print_vector(n+m, x);   
    


  
}