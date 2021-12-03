#include <string>

using std::string;

class Tag
{
public:
    const int static AND = 256,
                     BASIC = 257,
                     BREAK = 258,
                     DO = 259,
                     ELSE = 260,
                     EQ = 261,
                     FALSE = 262,
                     GE = 263,
                     ID = 264,
                     IF = 265,
                     INDEX = 266,
                     LE = 267,
                     MINUS = 268,
                     NE = 269,
                     NUM = 270,
                     OR = 271,
                     REAL = 272,
                     TEMP = 273,
                     TRUE = 274,
                     WHILE = 275;
};

class Token
{
public:
    /*final */ int tag;
    Token(int t) : tag(t){};
    string toString();
};

class Word : public Token
{
public:
    string lexeme = "";
    Word(string s, int t) : Token(t), lexeme(s){};
    string toString();
};

class Type : public Word
{
public:
    int width = 0;

    Type(string s, int tag, int w) : Word(s, tag), width(w){};

    static bool Numeric(Type p);

    // static Type max(Type p1, Type p2)
    // {
    //     if (!numeric(p1) || !numeric(p2))
    //         return null;
    //     else if (p1 == Type.Float || p2 == Type.Float)
    //         return Type.Float;
    //     else if (p1 == Type.Int || p2 == Type.Int)
    //         return Type.Int;
    //     else
    //         return Type.Char;
    // }
};

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


// static const Word and("&&", static_cast<int>(Tag::AND));
static const Word and ("&&", Tag::AND);
// static const Word and ("&&", Tag::AND);
// static const Word or ("||", Tag::OR);
// static const Word eq("==", Tag::EQ);
// static const Word ne("!=", Tag::NE);
// static const Word le("<=", Tag::LE);
// static const Word ge(">=", Tag::GE);
// static const Word minus("minus", Tag::MINUS);
// static const Word True("true", Tag::TRUE);
// static const Word False("false", Tag::FALSE);
// static const Word temp("t", Tag::TEMP);

