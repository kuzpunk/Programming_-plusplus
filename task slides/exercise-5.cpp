#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float sum, perc, perc2,tax;
    string type,type2,base,floor2;
    cout << "Enter the type coating (with roof/without roof/garden) \t";
    getline(cin, type);
    cout << "Enter the type material (high quality/samana/other) \t";
    getline(cin, type2);
    cout << "Do you have a canalization? (yes/no) \t";
    getline(cin, base);
    cout  << "Enter the floor (1/2/3/4/other) \t";
    getline(cin, floor2);
    if(type == "with roof")
    sum = 5000;
    else if(type == "without roof")
    sum = 3000;
    else if(type == "garden")
    sum = 1000;
    else 
    sum = 0;
    if(type2 == "high quality")
    perc = 0.15;
    else if(type2 == "samana")
    perc = 0.1;
    else if (type2 == "other")
    perc = 0.05;
    if (base == "yes")
    sum += 2500;
    if(floor2 == "2")
    perc2 = 0.1;
    else if(floor2 == "3")
    perc2 = 0.15;
    else if (floor2 == "4")
    perc2 = 0.15;
    else if (floor2 == "other")
    perc2 = 0.20;
    else 
    perc2=0;
    tax = sum + (sum * (perc + perc2));
    cout <<"tax =" << tax;
}
