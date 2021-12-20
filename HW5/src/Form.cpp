#include "Form.h"

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
    std::ios_base::fmtflags oriForm = output.flags();
    switch (form.type)
    {
    case 0:
        output << std::setprecision(form.prec) << form.value;
        break;
    case 1:
        output << std::scientific << std::setprecision(form.prec) << form.value;
        break;
    case 2:
        output << std::fixed << std::setprecision(form.prec) << form.value;
        break;
    default:
        break;
    }

    output.flags(oriForm);
    output << std::setprecision(6);
    return output;
}
