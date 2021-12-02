#include "Token.h"
#include "Tag.h"

class Real : public Token
{
public:
    float value;

    Real(float v) : Token(Tag::REAL)
    {
        value = v;
    }

    string toString()
    {
        return std::to_string(value);
    }
};