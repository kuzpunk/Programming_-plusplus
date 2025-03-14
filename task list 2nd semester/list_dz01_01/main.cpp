#include "Ellipse.h"
#include <iostream>

using namespace std; // Добавляем using namespace std

int main() {
    Ellipse ellipse; // Создаем объект с параметрами по умолчанию
    int choice;
    double x, y;
    char exitChoice;

    do {
        cout << "\nChoose a function (2-11): ";
        cin >> choice;

        switch (choice) {
            case 2: {
                // Начальная настройка эллипса
                cout << "Enter initial ellipse parameters:" << endl;
                double h, k, a, b;
                cout << "Center (h, k): ";
                cin >> h >> k;
                ellipse.setCenter(h, k); // Устанавливаем центр

                cout << "Semi-axes lengths (a, b): ";
                cin >> a >> b;
                ellipse.setAxes(a, b); // Устанавливаем полуоси
                break; // Добавлен break, чтобы избежать "проваливания"
            }
            case 3: {
                double c = ellipse.calculateC();
                cout << "Hyperparameter c: " << c << endl;
                break;
            }
            case 4: {
                double v1x, v1y, v2x, v2y;
                ellipse.getVertices(v1x, v1y, v2x, v2y);
                cout << "Vertices: (" << v1x << ", " << v1y << "), (" << v2x << ", " << v2y << ")" << endl;

                double f1x, f1y, f2x, f2y;
                ellipse.getFoci(f1x, f1y, f2x, f2y);
                cout << "Foci: (" << f1x << ", " << f1y << "), (" << f2x << ", " << f2y << ")" << endl;
                break;
            }
            case 5: {
                cout << "Latus rectum length: " << ellipse.getLatusRectum() << endl;
                cout << "Eccentricity: " << ellipse.getEccentricity() << endl;
                break;
            }
            case 6: {
                // Получаем центр и полуоси
                double centerH, centerK, axisA, axisB;
                ellipse.getCenter(centerH, centerK); // Вызов getCenter
                ellipse.getAxes(axisA, axisB);      // Вызов getAxes

                cout << "Ellipse center: (" << centerH << ", " << centerK << ")" << endl;
                cout << "Semi-axes: a = " << axisA << ", b = " << axisB << endl;
                break;
            }
            case 7: {
                ellipse.printEquation();
                break;
            }
            case 8: {
                cout << "Enter point coordinates (x, y): ";
                cin >> x >> y;
                if (ellipse.isPointInside(x, y)) {
                    cout << "The point is inside the ellipse." << endl;
                } else {
                    cout << "The point is outside the ellipse." << endl;
                }
                break;
            }
            case 9: {
                cout << "Ellipse perimeter: " << ellipse.calculatePerimeter() << endl;
                break;
            }
            case 10: {
                cout << "Ellipse area: " << ellipse.calculateArea() << endl;
                break;
            }
            case 11: {
                cout << "Enter x or y coordinate (enter 0 for the other): ";
                cin >> x >> y;
                double result = ellipse.findOtherCoordinate(x, y);
                if (x != 0) {
                    cout << "y coordinate: " << result << endl;
                } else {
                    cout << "x coordinate: " << result << endl;
                }
                break;
            }
            default: {
                cout << "Invalid choice. Try again." << endl;
                break;
            }
        }
        cout << "Do you want to exit? (y/n): ";
        cin >> exitChoice;

    } while (exitChoice != 'y' && exitChoice != 'Y'); // Выход, если введен 'y' или 'Y'

    return 0;
}