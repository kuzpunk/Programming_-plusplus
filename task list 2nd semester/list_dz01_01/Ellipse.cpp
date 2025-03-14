#include "Ellipse.h"


// Конструктор по умолчанию
Ellipse::Ellipse() : h(0), k(0), a(1), b(0.5), isMajorAxisX(true) {
    if (a <= b) {
        swap(a, b);
        isMajorAxisX = true;
    }
}

// Конструктор с параметрами
Ellipse::Ellipse(double h, double k, double a, double b) : h(h), k(k), a(a), b(b) {
    if (a <= b) {
        swap(this->a, this->b);
        isMajorAxisX = true;
    } else {
        isMajorAxisX = (a > b);
    }
}

// Конструктор копирования
Ellipse::Ellipse(const Ellipse& other) : h(other.h), k(other.k), a(other.a), b(other.b), isMajorAxisX(other.isMajorAxisX) {}

// Методы set и get
void Ellipse::setCenter(double h, double k) {
    this->h = h;
    this->k = k;
}

void Ellipse::setAxes(double a, double b) {
    this->a = a;
    this->b = b;
    if (a <= b) {
        swap(this->a, this->b);
        isMajorAxisX = true;
    } else {
        isMajorAxisX = (a > b);
    }
}

void Ellipse::getCenter(double& h, double& k) const {
    h = this->h;
    k = this->k;
}

void Ellipse::getAxes(double& a, double& b) const {
    a = this->a;
    b = this->b;
}

// Вычисление гиперпараметра c [3]
double Ellipse::calculateC() const {
    return sqrt(a * a - b * b);
}

// Получение координат вершин [4]
void Ellipse::getVertices(double& v1x, double& v1y, double& v2x, double& v2y) const {
    if (isMajorAxisX) {
        v1x = h - a; v1y = k;
        v2x = h + a; v2y = k;
    } else {
        v1x = h; v1y = k - a;
        v2x = h; v2y = k + a;
    }
}

// Получение координат фокусов [4]
void Ellipse::getFoci(double& f1x, double& f1y, double& f2x, double& f2y) const {
    double c = calculateC();
    if (isMajorAxisX) {
        f1x = h - c; f1y = k;
        f2x = h + c; f2y = k;
    } else {
        f1x = h; f1y = k - c;
        f2x = h; f2y = k + c;
    }
}

// Длина фокальной хорды [5]
double Ellipse::getLatusRectum() const {
    return 2 * b * b / a;
}

// Эксцентриситет [5]
double Ellipse::getEccentricity() const {
    return calculateC() / a;
}

// Печать уравнения эллипса [7]
void Ellipse::printEquation() const {
    if (isMajorAxisX) {
        cout << "(x - " << h << ")^2 / " << a * a << " + (y - " << k << ")^2 / " << b * b << " = 1" << endl;
    } else {
        cout << "(x - " << h << ")^2 / " << b * b << " + (y - " << k << ")^2 / " << a * a << " = 1" << endl;
    }
}

// Проверка, находится ли точка внутри эллипса [8]
bool Ellipse::isPointInside(double x, double y) const {
    double dx = x - h;
    double dy = y - k;
    if (isMajorAxisX) {
        return (dx * dx) / (a * a) + (dy * dy) / (b * b) <= 1;
    } else {
        return (dx * dx) / (b * b) + (dy * dy) / (a * a) <= 1;
    }
}

// Вычисление периметра эллипса [9]
double Ellipse::calculatePerimeter() const {
    return M_PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
}

// Вычисление площади эллипса [10]
double Ellipse::calculateArea() const {
    return M_PI * a * b;
}

// Нахождение второй координаты точки на эллипсе [11]
double Ellipse::findOtherCoordinate(double x, double y) const {
    if (isMajorAxisX) {
        if (x != h) {
            return k + b * sqrt(1 - (x - h) * (x - h) / (a * a));
        } else {
            return k + b;
        }
    } else {
        if (y != k) {
            return h + b * sqrt(1 - (y - k) * (y - k) / (a * a));
        } else {
            return h + b;
        }
    }
}