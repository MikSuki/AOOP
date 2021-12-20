#ifndef __FORM_H_INCLUDED__
#define __FORM_H_INCLUDED__

#include <iostream>   
#include <iomanip> 

class Form
{
public:
    int prec;
    double value;
    int type = 0;

    Form(int p) : prec(p) {}

    Form& operator()(double n) ;

    Form& precision(int p);

    Form& scientific();
    
    Form& fixed();

    friend std::ostream &operator<<(std::ostream &output, const Form &form);
};

#endif
