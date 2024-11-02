#include <iostream>
#include <cmath>
using namespace std;

// Процедура  для ввода количества элементов
void input_num_elements(int *n){
        cout<<"\nNumber of elements: ";
        cin>>*n; 
    }

// Функция для динамического выделения памяти для вектора
int *allocate_memory(int n){
    return (int *) malloc(n * sizeof(int));
}
void input_vector(int n, int *x, int *y){
    for(int i=0; i<n; i++){
        
            cout << "Point " << i + 1 << " (X Y): ";
            cin>>x[i]>>y[i];
    }
}


double calculate_average(int n, int *x) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += x[i];  // Суммируем каждый элемент вектора
    }
    return static_cast<double>(sum) / n;  // Делим на количество элементов
}

// Процедура  для вывода элементов вектора
void print_vector(int n, int *x, int *y){
    for(int i=0; i<n; i++){
        cout<<x[i]<<"  " <<y[i] << endl;
    }
    cout<<endl;
}


double calculate_beta1(int n,int *x,int *y){
    double sum_mult=0.0;
    for (int i=0;i<n;i++){
        sum_mult+=x[i]*y[i];
    }
    double sum_square=0.0;
    for (int i=0;i<n;i++){
        sum_square+=pow(x[i],2);
    }
    double sum_x=0.0;
    for (int i=0;i<n;i++){
        sum_x+=x[i];
    }
    return (sum_mult-n*calculate_average(n,x)*calculate_average(n,y))/(sum_square-(1.0 /n)*pow(sum_x,2));
}


double calculate_beta0(int n,int *x,int *y,double beta1){
    return (calculate_average(n,y)-beta1*calculate_average(n,x));
}


void Predicted(double beta0, double beta1){
    int x_new,y_new,y,error;
    cout << "New point (X Y): \t";
    cin >> x_new >> y_new;
    y=beta0+beta1*x_new;
    error=abs(y_new-y);
    cout << "predicted Y is \t" << y << endl << "error is\t" << error;

}


    int main() {
  int n,*x, *y;
  double beta1,beta0;
  input_num_elements(&n);  
  x = allocate_memory(n);  
  y = allocate_memory(n);  
  cout<<"\nInput the elements in vector: "<<endl;
  input_vector(n,x,y);          // Ввод элементов вектора A
  cout<<"\nVector A: "<<endl;
  print_vector(n,x,y);          // Вывод вектора A
  beta1=calculate_beta1(n,x,y);
  cout << "The linear coetafficient of the linear regression model is \t" << beta1 <<endl;
  beta0=calculate_beta0(n,x,y,beta1);
  cout << "An independent member is is \t" << beta0 <<endl;
  cout << "The linear regression formula is y=" << beta0<< "+"<< beta1 << "*x" <<endl;
  Predicted(beta0,beta1);
  return 0;
}