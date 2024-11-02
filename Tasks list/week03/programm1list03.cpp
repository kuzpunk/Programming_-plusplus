/*
    WEEK 03 - PROGRAM 01: DIVISORS OF NUMBER
    Enter two integers from 100 to 1000. Calculate
    the smallest common multiple (NOC) and the largest common divisor (GCD).
    Definition of variables:
        - n0: Store initial n for LCM calculation
        - m0: Store initial m for LCM calculation
*/
#include <iostream>
using namespace std;
int main() {
    int n,m,temp,nod,nok;
    do{
        cout<< "Enter the n and m: ";
        cin>> n >>m; 
        
} while (n<99 || n >1001 || m<99 || m >1001);
    int n0=n;
    int m0=m;
while (m!=0){
     temp =m;
    m=n%m;
    n=temp;
}
    nod=n;
    nok=(n0*m0)/nod;
    cout << "nok(n,m)=" << nok <<endl;
    cout << "nod(n,m)=" << nod;
}