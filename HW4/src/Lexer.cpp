#include <string>

#include "Lexer.h"

using std::string;

static const Word AND("&&", Tag::AND);
static const Word OR("||", Tag::OR);
static const Word EQ("==", Tag::EQ);
static const Word NE("!=", Tag::NE);
static const Word LE("<=", Tag::LE);
static const Word GE(">=", Tag::GE);
static const Word MINUS("minus", Tag::MINUS);
static const Word TRUE("true", Tag::TRUE);
static const Word FALSE("false", Tag::FALSE);
static const Word TEMP("t", Tag::TEMP);

static const Type Int("int", Tag::BASIC, 4);
static const Type Float("float", Tag::BASIC, 8);
static const Type Char("char", Tag::BASIC, 1);
static const Type Bool("bool", Tag::BASIC, 1);

string Token::toString()
{
    return "" + (char)tag;
}

string Word::toString()
{
    return lexeme;
}

bool Type::Numeric(Type p)
{
    if (p == Char || p == Int || p == Float)
        return true;
    else
        return false;
}

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

class Lexer
{
public:
    static int line = 1;
    char peek = ' ';
    Hashtable words = new Hashtable();

    void reserve(Word w)
    {
        words.put(w.lexeme, w);
    }

    Lexer()
    {
        reserve(Word("if", Tag::IF));
        reserve(Word("else", Tag::ELSE));
        reserve(Word("while", Tag::WHILE));
        reserve(Word("do", Tag::DO));
        reserve(Word("break", Tag::BREAK));
        reserve(Word::True);
        reserve(Word::False);
        reserve(Type::Int);
        reserve(Type::Char);
        reserve(Type::Bool);
        reserve(Type::Float);
    }
    void readch() throws IOException
    {
        int i = System.in.read();
        if (i != -1)
            peek = (char)i;
        else
            throw new IOException("End of file reached");
    }
    boolean readch(char c) throws IOException
    {
        readch();
        if (peek != c)
            return false;
        peek = ’ ’;
        return true;
    }

    Token scan() throws IOException
    {
        for (;; readch())
        {
            if (peek == ’ ’ || peek == ’\t’)
                continue;
            else if (peek == ’\n’)
                line = line + 1;
            else
                break;
        }
        switch (peek)
        {
        case ’&’:
            if (readch(’&’))
                return Word.and;
            else
                return new Token(’&’);
        case ’|’:
            if (readch(’|’))
                return Word.or ;
            else
                return new Token(’|’);
        case ’=’:
            if (readch(’=’))
                return Word.eq;
            else
                return new Token(’=’);
        case ’!’:
            if (readch(’=’))
                return Word.ne;
            else
                return new Token(’!’);
        case ’<’:
            if (readch(’=’))
                return Word.le;
            else
                return new Token(’<’);
        case ’>’:
            if (readch(’=’))
                return Word.ge;
            else
                return new Token(’>’);
        }

        if (Character.isDigit(peek))
        {
            int v = 0;
            do
            {
                v = 10 * v + Character.digit(peek, 10);
                readch();
            } while (Character.isDigit(peek));
            if (peek != ’.’)
                return new Num(v);
            float x = v;
            float d = 10;
            for (;;)
            {
                readch();
                if (!Character.isDigit(peek))
                    break;
                x = x + Character.digit(peek, 10) / d;
                d = d * 10;
            }
            return new Real(x);
        }

        if (Character.isLetter(peek))
        {
            StringBuffer b = new StringBuffer();
            do
            {
                b.append(peek);
                readch();
            } while (Character.isLetterOrDigit(peek));
            String s = b.toString();
            Word w = (Word)words.get(s);
            if (w != null)
                return w;
            w = new Word(s, Tag.ID);
            words.put(s, w);
            return w;
        }

        Token tok = new Token(peek);
        peek = ’ ’;
        return tok;
    }
};

int main()
{
}
