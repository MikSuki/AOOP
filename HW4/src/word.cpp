#include <string>

#include "Token.h"
#include "Tag.h"

using std::string;

class Word : public Token
{
public:
    string lexeme = "";

    Word(string s, int t) : Token(t)
    {
        // tag = t;
        lexeme = s;
    }

    string toString()
    {
        return lexeme;
    }

    static const Word and ("&&", Tag::AND);
    static const Word or ("||", Tag::OR);
    static const Word eq("==", Tag::EQ);
    static const Word ne("!=", Tag::NE);
    static const Word le("<=", Tag::LE);
    static const Word ge(">=", Tag::GE);
    static const Word minus("minus", Tag::MINUS);
    static const Word True("true", Tag::TRUE);
    static const Word False("false", Tag::FALSE);
    static const Word temp("t", Tag::TEMP);
}