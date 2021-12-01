#include <string>

#include "Token.h"
#include "Tag.h"

using std::string;

class Word : public Token
{
public:
    string lexeme = "";

    Word(string s, int t): Token(t)
    {
        tag = t;
        lexeme = s;
    }

    string toString()
    {
        return lexeme;
    }


    static const Word 
        and ("&&", Tag.AND),
        or ("||", Tag.OR),
        eq ("==", Tag.EQ),
        ne ("!=", Tag.NE),
        le ("<=", Tag.LE),
        ge (">=", Tag.GE),
        minus ("minus", Tag.MINUS),
        True ("true", Tag.TRUE),
        False ("false", Tag.FALSE),
        temp ("t", Tag.TEMP);
}