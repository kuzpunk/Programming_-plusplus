/*
    PROGRAM 02: The mathematical pendulum
    Definition of variables
        - H: the height of the cliff
        - V: Speed
        - Alpha: Angle
        - T: Time
        - x_T: Horizontal position of the stone
        - y_T: The vertical position of the stone
*/

#include <iostream>
#include <cmath>

using namespace std;
int main() {
    double H, V, alpha, g = 9.8, T, x_T, y_T;

    cout << "H= (in meters): \t";
    cin >> H;
    cout << "V= (in m/s): \t";
    cin >> V;

    cout << "alpha= (in degrees): \t";
    cin >> alpha;

    // Convert angle to radians
    alpha = alpha * M_PI / 180.0; 

    // Checking value constraints #1
    if (sin(alpha) == 0) {
        cout << "ERROR: sin(alpha) == 0" << endl;
        return 1;
    }
    // Checking value constraints #2
    if (V == 0) {
        cout << "ERROR: V == 0" << endl;
        return 1;
    }

    double under_sqrt = 1 + (2 * g * H) / (pow(V, 2) * pow(sin(alpha), 2));

    // Checking value constraints #3
    if (under_sqrt < 0) {
        cout << "ERROR: value under sqrt < 0" << endl;
        return 1;
    }
    
    double under_line = pow(V, 2) * pow(sin(alpha), 2);

    // Checking value constraints #4
    if (under_line == 0) {
        cout << "ERROR: value under line == 0" << endl;
        return 1;
    }

    T = (V * sin(alpha) / g) * (1 + sqrt(under_sqrt));

    x_T = V * T * cos(alpha);
    y_T = H + V * T * sin(alpha) - 0.5 * g * pow(T, 2);

    if (y_T < 0) {
        y_T = 0;
    }

    // cout << "The flight time of the stone 'T': " << T << " sec" << endl;
    cout << "x(T): " << x_T << " meters" << endl;
    cout << "y(T): " << y_T << " meters" << endl;

    return 0;
}