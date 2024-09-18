/*
    PROGRAM 02: The mathematical pendulum
    Definition of variables
        - x: the value of x
        - f_x: function f
        - g_x: function g
*/

#include <iostream>
#include <cmath>

using namespace std;

int main () {
    double x, f_x, g_x;

    cout << "Enter the x"  << endl;
    cin >> x;

    // g_x
    if (x > -4 && x < - 1) {
        g_x = (abs(x - 6)) / (abs(x + 3 ) - 3);

    } else if (x == -1.5) {
        g_x = sqrt(5 - x) - 2;

    } else if (x >= 5) {
        g_x = log(x + 10) - 2;
        
    } else {
        g_x = 0.0; // default value or handle error
    }

    // f_x
    if (g_x < -2) {
        f_x = abs(g_x / (1 - x));

    } else if (g_x >= 5) {
        f_x = pow(g_x + 2, 2);

    } else {
        f_x = 0.0; // default value or handle error
    }

    cout << "the resulting value (f(x)): \t" << f_x << endl;

    return 0;
}
