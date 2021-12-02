#include "Token.h"
#include "Tag.h"

class Num : public Token
{
public:
    int value;
    
    Num(int v) : Token(Tag::NUM)
    {
        value = v;
    }
    
    string toString()
    {
        return "" + value;
    }
};
