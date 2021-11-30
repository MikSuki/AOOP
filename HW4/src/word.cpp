#include <string>

class Word : public Token
{
public:
    string lexeme = "";

    Word(string s, int t)
    {
        tag = t;
        lexeme = s;
    }
public
    String toString()
    {
        return lexeme;
    }
public
    static final Word
        and = new Word("&&", Tag.AND),
        or = new Word("||", Tag.OR),
        eq = new Word("==", Tag.EQ),
        ne = new Word("!=", Tag.NE),
        le = new Word("<=", Tag.LE),
        ge = new Word(">=", Tag.GE),
        minus = new Word("minus", Tag.MINUS),
        True = new Word("true", Tag.TRUE),
        False = new Word("false", Tag.FALSE),
        temp = new Word("t", Tag.TEMP);
}