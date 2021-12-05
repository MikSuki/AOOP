




#include <iostream>
#include "complex.h"

using std::cout;
using std::endl;

Complex polar(const double leng, const double arg);

int main()
{
    Complex a(77, 66.3);
    Complex b(a);
    int i = 1;

    cout << i++ << ": (" << a.real() << ',' << a.imag() << ')' << endl;
    cout << i++ << ": " << b << endl;
    cout << i++ << ": " << norm(b) << endl;
    cout << i++ << ": " << b.norm() << endl;
    cout << i++ << ": " << abs(b) << endl;
    cout << i++ << ": " << b.abs() << endl;
    cout << i++ << ": " << arg(b) << endl;
    cout << i++ << ": " << b.arg() << endl;

    a = Complex(12, 33.2);
    cout << i++ << ": " << a << endl;
    cout << i++ << ": " << 1 + a << endl;

    cout << i++ << ": " << a++ << endl;
    cout << i++ << ": " << ++a << endl;

    b = a.polar(5.6, 1.8);

    cout << i++ << ": " << a << endl;
    cout << i++ << ": " << b << endl;

    b = polar(6.5, 8.1);
    cout << i++ << ": " << b << endl;
    
    cout << i++ << ": " << a + b << endl;
    cout << i++ << ": " << a - b << endl;
    cout << i++ << ": " << a * b << endl;
    cout << i++ << ": " << a / b << endl;

    a /= b;
    cout << i++ << ": " << a << endl;
    a /= Complex(4, 3);
    cout << i++ << ": " << a << endl;

    a *= b;
    cout << i++ << ": " << a << endl;
    a *= polar(5.1, 5.1);
    cout << i++ << ": " << a << endl;

    a += b;
    b -= a;
    cout << i++ << ": " << b << endl;

    if (!(a == b))
        cout << i++ << ": "
             << "OK" << endl;
    if (a != b)
        cout
            << i++ << ": "
            << "OK" << endl;
}
