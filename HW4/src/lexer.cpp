#include <string>
#include <iostream>
#include <ctype.h>
#include <sstream>

#include "lexer.h"

using std::string;
using std::stringstream;
using std::to_string;
using std::cin;

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
    string s;
    s = tag;
    return s;
    // return "" + (char)tag;
}

string Word::toString()
{
    return lexeme;
}

bool Type::operator==(Type p)
{
    return this->lexeme == p.lexeme &&
           this->tag == p.tag &&
           this->width == p.width;
}

bool Type::Numeric(Type p)
{
    if (p == Char || p == Int || p == Float)
        return true;
    else
        return false;
}

Type Type::max(Type p1, Type p2)
{
    if (!Type::Numeric(p1) || !Type::Numeric(p2))
        return Type("", -1, -1);
    else if (p1 == Float || p2 == Float)
        return Float;
    else if (p1 == Int || p2 == Int)
        return Int;
    else
        return Char;
}

string Num::toString()
{
    return to_string(value);
}

string Real::toString()
{
    return to_string(value);
}

int Lexer::line = 1;

void Lexer::reserve(Word w)
{
    words.insert(pair<string, Word>(w.lexeme, w));
}

Lexer::Lexer()
{
    reserve(Word("if", Tag::IF));
    reserve(Word("else", Tag::ELSE));
    reserve(Word("while", Tag::WHILE));
    reserve(Word("do", Tag::DO));
    reserve(Word("break", Tag::BREAK));
    reserve(TRUE);
    reserve(FALSE);
    reserve(Int);
    reserve(Char);
    reserve(Bool);
    reserve(Float);
}

void Lexer::readch()
{
    if (!cin.get(peek))
        throw "End of file reached";
}

bool Lexer::readch(char c)
{
    readch();
    if (peek != c)
        return false;
    peek = ' ';
    return true;
}

Token Lexer::scan()
{
    for (;; readch())
    {
        if (peek == ' ' || peek == '\t')
            continue;
        else if (peek == '\n')
            line = line + 1;
        else
            break;
    }
    switch (peek)
    {
    case '&':
        if (readch('&'))
            return AND;
        else
            return Token('&');
    case '|':
        if (readch('|'))
            return OR;
        else
            return Token('|');
    case '=':
        if (readch('='))
            return EQ;
        else
            return Token('=');
    case '!':
        if (readch('='))
            return NE;
        else
            return Token('!');
    case '<':
        if (readch('='))
            return LE;
        else
            return Token('<');
    case '>':
        if (readch('='))
            return GE;
        else
            return Token('>');
    }

    if (isdigit(peek))
    {
        int v = 0;
        return Num(peek);
        // do
        // {
        //     v = 10 * v + (peek - '0');
        //     readch();
        // } while (isdigit(peek));
        if (peek != '.')
            return Num(v);

        // peek is float
        float x = v;
        float d = 10;
        for (;;)
        {
            readch();
            if (!isdigit(peek))
                break;
            x = x + (peek - '0') / d;
            d = d * 10;
        }
        return Real(x);
    }

    if (isalpha(peek))
    {
        stringstream ss;
        do
        {
            ss << peek;
            readch();
        } while (isalnum(peek));
        string s = ss.str();
        map<string, Word>::iterator it = words.find(s);
        // if element found;
        if (it != words.end())
            return it->second;
        Word w(s, Tag::ID);
        words.insert(pair<string, Word>(s, w));
        return w;
    }

    Token tok = Token(peek);
    peek = ' ';
    return tok;
}
