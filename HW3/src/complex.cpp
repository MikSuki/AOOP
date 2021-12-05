
#include <iostream>
#include <math.h>
#include "complex.h"

const int DIGIT = 6;

int get_digit(double v)
{
    v = abs(v);
    int d = (int)log10(v);
    if (v < 1)
        return d;
    return d + 1;
}

double round_to_n(double v, int n)
{
    double m = pow(10, n);
    return round(v * m) / m;
}

Complex::Complex(const double re, const double im)
{
    this->re = re;
    this->im = im;
}

Complex::Complex(const Complex &c)
{
    re = c.re;
    im = c.im;
}

Complex &Complex::operator=(const Complex &c)
{
    this->re = c.re;
    this->im = c.im;
    return *this;
}

Complex Complex::polar(const double leng, const double arg)
{
    this->re = leng * cos(arg);
    this->im = leng * sin(arg);
    return *this;
}

double Complex::real()
{
    return re;
}
double Complex::imag()
{
    return im;
}
double Complex::norm()
{
    return re * re + im * im;
}
double Complex::abs()
{
    return sqrt(re * re + im * im);
}
double Complex::arg()
{
    return atan2(im, re);
}

Complex Complex::operator++()
{
    ++this->re;
    ++this->im;
    return *this;
}

Complex Complex::operator++(int)
{
    Complex tmp = *this;
    ++this->re;
    ++this->im;
    return tmp;
}
// Complex operator--();
// Complex operator--(int);

Complex::~Complex()
{
}

Complex polar(const double leng, const double arg)
{
    Complex c(
        leng * cos(arg),
        leng * sin(arg));
    return c;
}
double norm(const Complex &x)
{
    return x.re * x.re + x.im * x.im;
}
double abs(const Complex &x)
{
    return sqrt(x.re * x.re + x.im * x.im);
}
double arg(const Complex &x)
{
    return atan2(x.im, x.re);
}
Complex operator+(const Complex &x, const Complex &y)
{
    Complex res;
    res.re = x.re + y.re;
    res.im = x.im + y.im;
    return res;
}

Complex operator-(const Complex &x, const Complex &y)
{
    Complex res;
    res.re = x.re - y.re;
    res.im = x.im - y.im;
    return res;
}

Complex operator*(const Complex &x, const Complex &y)
{
    Complex res;
    res.re = x.re * y.re - x.im * y.im;
    res.im = x.re * y.im + x.im * y.re;
    return res;
}

Complex operator/(const Complex &x, const Complex &y)
{
    Complex res;
    double D = pow(y.re, 2) + pow(y.im, 2);
    res.re = (x.re * y.re + x.im * y.im) / D;
    res.im = (x.im * y.re - x.re * y.im) / D;
    return res;
}

Complex operator+=(Complex &x, const Complex &y)
{
    x = x + y;
    return x;
}

Complex operator-=(Complex &x, const Complex &y)
{
    x = x - y;
    return x;
}

Complex operator*=(Complex &x, const Complex &y)
{
    x = x * y;
    return x;
}

Complex operator/=(Complex &x, const Complex &y)
{
    x = x / y;
    return x;
}
bool operator==(const Complex &x, const Complex &y)
{
    return x.re == y.re && x.im == y.im;
}
bool operator!=(const Complex &x, const Complex &y)
{
    return x.re != y.re && x.im != y.im;
}

ostream &operator<<(ostream &o, const Complex &x)
{
    // 6位有效位數字
    double re = round_to_n(x.re, DIGIT - get_digit(x.re));
    double im = round_to_n(x.im, DIGIT - get_digit(x.im));
    return o << '(' << re << ',' << im << ')';
}
