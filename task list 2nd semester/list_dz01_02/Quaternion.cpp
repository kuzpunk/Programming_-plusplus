#include "Quaternion.h"

// Конструктор по умолчанию
Quaternion::Quaternion() : a(1), b(0), c(0), d(0) {}

// Конструктор с параметрами
Quaternion::Quaternion(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}

// Конструктор копирования
Quaternion::Quaternion(const Quaternion& other) : a(other.a), b(other.b), c(other.c), d(other.d) {}

// Сеттеры
void Quaternion::setA(double a) { this->a = a; }
void Quaternion::setB(double b) { this->b = b; }
void Quaternion::setC(double c) { this->c = c; }
void Quaternion::setD(double d) { this->d = d; }

// Геттеры
double Quaternion::getA() const { return a; }
double Quaternion::getB() const { return b; }
double Quaternion::getC() const { return c; }
double Quaternion::getD() const { return d; }

// Печать кватерниона
void Quaternion::print() const {
    std::cout << a << " + " << b << "i + " << c << "j + " << d << "k" << std::endl;
}

// Норма кватерниона
double Quaternion::norm() const {
    return std::sqrt(a * a + b * b + c * c + d * d);
}

// Сопряжение кватерниона
Quaternion Quaternion::conjugate() const {
    return Quaternion(a, -b, -c, -d);
}

// Нормализация кватерниона
Quaternion Quaternion::normalize() const {
    double n = norm();
    return Quaternion(a / n, b / n, c / n, d / n);
}

// Инверсия кватерниона
Quaternion Quaternion::inverse() const {
    double n = norm();
    return conjugate() / (n * n);
}

// Оператор сложения
Quaternion Quaternion::operator+(const Quaternion& other) const {
    return Quaternion(a + other.a, b + other.b, c + other.c, d + other.d);
}

// Оператор вычитания
Quaternion Quaternion::operator-(const Quaternion& other) const {
    return Quaternion(a - other.a, b - other.b, c - other.c, d - other.d);
}

// Оператор умножения
Quaternion Quaternion::operator*(const Quaternion& other) const {
    double newA = a * other.a - b * other.b - c * other.c - d * other.d;
    double newB = a * other.b + b * other.a + c * other.d - d * other.c;
    double newC = a * other.c - b * other.d + c * other.a + d * other.b;
    double newD = a * other.d + b * other.c - c * other.b + d * other.a;
    return Quaternion(newA, newB, newC, newD);
}

// Оператор деления
Quaternion Quaternion::operator/(const Quaternion& other) const {
    return *this * other.inverse();
}

// Оператор деления на скаляр
Quaternion Quaternion::operator/(double scalar) const {
    return Quaternion(a / scalar, b / scalar, c / scalar, d / scalar);
}

// Скалярное произведение
double Quaternion::dot(const Quaternion& other) const {
    return a * other.a + b * other.b + c * other.c + d * other.d;
}

// Евклидово расстояние
double euclideanDistance(const Quaternion& q1, const Quaternion& q2) {
    return std::sqrt(std::pow(q1.a - q2.a, 2) + std::pow(q1.b - q2.b, 2) + std::pow(q1.c - q2.c, 2) + std::pow(q1.d - q2.d, 2));
}

// Норма Чебышева
double chebyshevNorm(const Quaternion& q1, const Quaternion& q2) {
    double diffA = std::abs(q1.a - q2.a);
    double diffB = std::abs(q1.b - q2.b);
    double diffC = std::abs(q1.c - q2.c);
    double diffD = std::abs(q1.d - q2.d);
    return std::max(std::max(diffA, diffB), std::max(diffC, diffD));
}