#ifndef __COMPLEX_H_INCLUDED__
#define __COMPLEX_H_INCLUDED__

#include <iostream>

using std::ostream;

class Complex
{
public:
    Complex(const double re = 0, const double im = 0);
    Complex(const Complex &c);
    Complex &operator=(const Complex &c);

    Complex polar(const double leng, const double arg);

    double real();
    double imag();
    double norm();
    double abs();
    double arg();

    Complex operator++();
    Complex operator++(int);
    Complex operator--();
    Complex operator--(int);

    ~Complex();

    friend Complex polar(const double leng, const double arg);
    friend double norm(const Complex &x);
    friend double abs(const Complex &x);
    friend double arg(const Complex &x);
    friend Complex operator+(const Complex &x, const Complex &y);
    friend Complex operator-(const Complex &x, const Complex &y);
    friend Complex operator*(const Complex &x, const Complex &y);
    friend Complex operator/(const Complex &x, const Complex &y);
    friend Complex operator+=(Complex &x, const Complex &y);
    friend Complex operator-=(Complex &x, const Complex &y);
    friend Complex operator*=(Complex &x, const Complex &y);
    friend Complex operator/=(Complex &x, const Complex &y);
    friend bool operator==(const Complex &x, const Complex &y);
    friend bool operator!=(const Complex &x, const Complex &y);
    friend ostream &operator<<(ostream &o, const Complex &x);

private:
    double re;
    double im;
};

#endif
