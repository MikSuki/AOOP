#include "Form.h"

using std::setprecision;

Form &Form::operator()(double n)
{
    value = n;
    return *this;
}

Form &Form::precision(int p)
{
    prec = p;
    return *this;
}

Form &Form::scientific()
{
    type = 1;
    return *this;
}

Form &Form::fixed()
{
    type = 2;
    return *this;
}

std::ostream &operator<<(std::ostream &output, const Form &form)
{
    switch (form.type)
    {
    case 0:
        output << setprecision(form.prec) << form.value;
        break;
    case 1:
        output << std::scientific << setprecision(form.prec) << form.value;
        break;
    case 2:
        output << std::fixed << setprecision(form.prec) << form.value;
        break;
    }

    output << std::defaultfloat;
    output << setprecision(6);
    return output;
}
