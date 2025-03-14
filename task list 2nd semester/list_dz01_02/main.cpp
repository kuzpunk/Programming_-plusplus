#include "Quaternion.h"
#include <iostream>

using namespace std;

int main() {
    Quaternion q1(1, 2, 3, 4);
    Quaternion q2(2, 3, 4, 5);
    int choice;
    char exitChoice;

    do {
        cout << "\nChoose a function (1-11):" << endl;
        cout << "1. Print quaternion" << endl;
        cout << "2. Calculate norm" << endl;
        cout << "3. Get conjugate" << endl;
        cout << "4. Normalize quaternion" << endl;
        cout << "5. Get inverse" << endl;
        cout << "6. Add two quaternions" << endl;
        cout << "7. Subtract two quaternions" << endl;
        cout << "8. Multiply two quaternions" << endl;
        cout << "9. Divide two quaternions" << endl;
        cout << "10. Calculate Euclidean distance" << endl;
        cout << "11. Calculate Chebyshev norm" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Quaternion 1: ";
                q1.print();
                cout << "Quaternion 2: ";
                q2.print();
                break;
            }
            case 2: {
                cout << "Norm of q1: " << q1.norm() << endl;
                cout << "Norm of q2: " << q2.norm() << endl;
                break;
            }
            case 3: {
                cout << "Conjugate of q1: ";
                q1.conjugate().print();
                cout << "Conjugate of q2: ";
                q2.conjugate().print();
                break;
            }
            case 4: {
                cout << "Normalized q1: ";
                q1.normalize().print();
                cout << "Normalized q2: ";
                q2.normalize().print();
                break;
            }
            case 5: {
                cout << "Inverse of q1: ";
                q1.inverse().print();
                cout << "Inverse of q2: ";
                q2.inverse().print();
                break;
            }
            case 6: {
                cout << "q1 + q2: ";
                (q1 + q2).print();
                break;
            }
            case 7: {
                cout << "q1 - q2: ";
                (q1 - q2).print();
                break;
            }
            case 8: {
                cout << "q1 * q2: ";
                (q1 * q2).print();
                break;
            }
            case 9: {
                cout << "q1 / q2: ";
                (q1 / q2).print();
                break;
            }
            case 10: {
                cout << "Euclidean distance between q1 and q2: " << euclideanDistance(q1, q2) << endl;
                break;
            }
            case 11: {
                cout << "Chebyshev norm between q1 and q2: " << chebyshevNorm(q1, q2) << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Try again." << endl;
                break;
            }
        }

        cout << "Do you want to exit? (y/n): ";
        cin >> exitChoice;

    } while (exitChoice != 'y' && exitChoice != 'Y');

    return 0;
}