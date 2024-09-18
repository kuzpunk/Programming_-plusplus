/*
    PROGRAM 02: The mathematical pendulum
    Definition of variables
        - k: The number is how many times x is less than the amplitude
        - omega: Frequency
        - A: Amplitude
        - phi: angle
        - T: Time
        - x_T: The coordinate
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double k, omega, A, phi, T, x_T;
    cout << "Enter the k \t";
    cin >> k;
     cout << "Enter the A \t";
     cin >> A;

    if (k <= 1) {
        cout << "ERROR: k > 1" << endl;
        return 1;
    }
    
    cout << "Enter the omega frequency value (omega): \t";
    cin >> omega;

    if (omega <= 0) {
        cout << "ERROR: omega > 0" << endl;
        return 1;
    }
    phi = asin(1.0 / k);

    T = (M_PI / 2 - phi) / omega;

    x_T = A * sin(omega * T + phi);

    cout << endl << "Phi(0)= " << phi << endl << endl;
    cout << "T= \t" << T << endl << endl;
    cout << "x(T)= \t" << x_T << endl << endl;

    return 0;
}