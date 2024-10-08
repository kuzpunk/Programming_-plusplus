/*
    WEEK 02 - PROGRAM 01: DIVISORS OF NUMBER
    Definition of variables:
        - A,B: input number [10, 1000]
        - i: analized number as potential divisor
        - num_divisorsA(B): number of divisors
        - sum_divisorsA(B): sum of divisors
        - sum: Sum of all divisors
        - sum_mult: multiplication quantity of divisors
        - sum_event: Sum of the multiplication
        - maxA:  the largest common divisor
*/

#include <iostream>
#include <cmath>
using namespace std;
int main(){    
    int A,B, i,num_divisorsA=0,num_divisorsB=0,sum_divisorsA=0,sum_divisorsB=0,sum=0,sum_mult=0;
    int evenA=1,evenB=0,sum_even=0,maxA=0,maxB=0;
  
    do{
        cout<< "Enter the A: ";
        cin>> A;
        cout<< "Enter the B: ";
        cin>> B;
        
    }while((A<10 || A>1000) || (B<10 || B>1000) );
    for(i=1; i<=A; i++){

        if(A % i == 0){
            if(maxA<i)
            maxA=i;
            num_divisorsA++;
            sum_divisorsA += i;
              if( i%2 != 0)
            evenA*=i; 
              
        }
    
    }
    for(i=1; i<=B; i++){

        if(B % i == 0){
            if(maxB<i)
            maxB=i;
            num_divisorsB++;
            sum_divisorsB += i;
            if( i%2 == 0)
            evenB+=i;
        }
          
    }
    sum=sum_divisorsA+sum_divisorsB;
    sum_mult=num_divisorsB*num_divisorsA;
    sum_even=evenA+evenB;
    cout<< "Sum of divisors: "<<sum<< endl;
    cout<< "multiplication quantity of divisors: "<<sum_mult<< endl;
    cout<< "Sum of the multiplication: "<<sum_even<< endl;
      if (maxA==maxB){
        cout << "the largest common divisor: " << maxA;
      }
    while (B != 0) {
        int temp = B;
        B = A % B;
        A = temp;
    }
    if (A==1)
    cout << "The numbers are simple together"; 
    else
    cout << A;
    return 0;
}