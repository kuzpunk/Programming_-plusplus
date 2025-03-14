#ifndef QUATERNION_H
#define QUATERNION_H

#include <iostream>
#include <cmath>

class Quaternion {
private:
    double a, b, c, d; // a - действительная часть, b, c, d - коэффициенты при i, j, k

public:
    // Конструкторы
    Quaternion(); // Конструктор по умолчанию
    Quaternion(double a, double b, double c, double d); // Конструктор с параметрами
    Quaternion(const Quaternion& other); // Конструктор копирования

    // Сеттеры и геттеры
    void setA(double a);
    void setB(double b);
    void setC(double c);
    void setD(double d);
    double getA() const;
    double getB() const;
    double getC() const;
    double getD() const;

    // Методы
    void print() const; // Печать кватерниона
    double norm() const; // Норма кватерниона
    Quaternion conjugate() const; // Сопряжение кватерниона
    Quaternion normalize() const; // Нормализация кватерниона
    Quaternion inverse() const; // Инверсия кватерниона

    // Операторы
    Quaternion operator+(const Quaternion& other) const; // Сложение
    Quaternion operator-(const Quaternion& other) const; // Вычитание
    Quaternion operator*(const Quaternion& other) const; // Умножение
    Quaternion operator/(const Quaternion& other) const; // Деление
    Quaternion operator/(double scalar) const; // Деление на скаляр
    double dot(const Quaternion& other) const; // Скалярное произведение

    // Глобальные функции
    friend double euclideanDistance(const Quaternion& q1, const Quaternion& q2); // Евклидово расстояние
    friend double chebyshevNorm(const Quaternion& q1, const Quaternion& q2); // Норма Чебышева
};

#endif // QUATERNION_H