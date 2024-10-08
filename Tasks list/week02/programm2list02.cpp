#include <iostream>
#include <cmath>
using namespace std;
int main(){
int n, opt;
char cont;
do{
// print the menu of options

cout << "\nSelect an option from [1-7] according to the menu:";
cin>> opt;
switch(opt){
case 1:  { // OPTION 01: Enter the number
        do{
            cout << "Enter the number \t";
            cin >> n;
        } while (n<1000 || n>99999999); }
break;
case 2: { // OPTION 02: Check if the number has repeated
    cout << "Enter the number \t";
    cin >> n;
    while (n>0){
        cout << n%10 << " ";
        n/=10;
    } }
break;
case 3: {// OPTION 03: Count how many digits the number has
    cout << "Enter the number \t";
    int count=0;
    cin >> n;
    while (n>0){
        count++;
        n/=10;
    }
    cout << "number of digits\t" << count;
}
break;
case 4: 
{
    cout << "Enter the number \t";
    int max=1,min=1;
    cin >> n;
    while (n>0){
        if (n%10 < min)
        min=n%10;
        if (n%10 > max)
        max=n%10;
        n/=10;
    }
    cout << "min=\t" << min << endl;
    cout << "max=\t" << max;


}
break;
case 5:
{ // OPTION 05: Return the sum of the digits of the number
    cout << "Enter the number \t";
    int count=0;
    cin >> n;
    while (n>0){
        count=count + (n%10);
        n/=10;
    }
    cout << "summ of digits\t" << count;
}
break;
case 6: 
{ // OPTION 06: Return the product of the odd digits
     cout << "Enter the number \t";
    int count=1;
    cin >> n;
    while (n>0){
        if (n%2==0)
        count=count * (n%10);
        n/=10;
    }
    cout << "the product of odd digits\t" << count;
}
break;
case 7: { // OPTION 07: Calculat
    cout << "Enter the number \t";
    cin >> n;
    while (n>0){
    cout << n%10;
    n/=10;
    }
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