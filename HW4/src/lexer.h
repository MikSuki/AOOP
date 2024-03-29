#ifndef __LEXER_H_INCLUDED__
#define __LEXER_H_INCLUDED__

#include <map>

using std::map;
using std::pair;
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
    static string toString(int v);
};

class Token
{
public:
    /*final */ int tag;
    Token(int t) : tag(t){};
    virtual string toString();
};

class Word : public Token
{
public:
    string lexeme = "";
    Word(string s, int t) : Token(t), lexeme(s){};
    virtual string toString() override;
};

class Type : public Word
{
public:
    int width = 0;
    Type(string s, int tag, int w) : Word(s, tag), width(w){};
    bool operator==(Type);
    static bool Numeric(Type p);
    static Type max(Type p1, Type p2);
};

class Num : public Token
{
public:
    int value;
    Num(int v) : Token(Tag::NUM), value(v){};
    virtual string toString() override;
};

class Real : public Token
{
public:
    float value;
    Real(float v) : Token(Tag::REAL), value(v){};
    virtual string toString() override;
};

class Lexer
{
public:
    static int line;
    string str;
    int i = 0;
    char peek = ' ';
    // Hashtable words = new Hashtable();
    map<string, Word> words;

    void reserve(Word w);
    Lexer(string);
    void readch();
    bool readch(char c);
    Token scan();
};

extern string tok;
extern string output;

#endif
