#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <cmath>
#include <iostream>

using namespace std;

class Ellipse {
private:
    double h, k; // Координаты центра
    double a, b; // Большая и малая полуоси
    bool isMajorAxisX; // Направление большой оси

public:
    // Конструкторы
    Ellipse();
    Ellipse(double h, double k, double a, double b);
    Ellipse(const Ellipse& other);

    // Методы set и get
    void setCenter(double h, double k);
    void setAxes(double a, double b);
    void getCenter(double& h, double& k) const;
    void getAxes(double& a, double& b) const;

    // Методы для вычисления характеристик
    double calculateC() const; // [3]
    void getVertices(double& v1x, double& v1y, double& v2x, double& v2y) const; // [4]
    void getFoci(double& f1x, double& f1y, double& f2x, double& f2y) const; // [4]
    double getLatusRectum() const; // [5]
    double getEccentricity() const; // [5]

    // Методы для печати и проверки
    void printEquation() const; // [7]
    bool isPointInside(double x, double y) const; // [8]
    double calculatePerimeter() const; // [9]
    double calculateArea() const; // [10]
    double findOtherCoordinate(double x, double y) const; // [11]
};

#endif // ELLIPSE_H