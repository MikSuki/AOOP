#include <string>

#include "Token.h"
#include "Word.h"
#include "Tag.h"

using std::string;

class Type : public Word
{
public:
    int width = 0;

    Type(string s, int tag, int w) : Word(s, tag)
    {
        width = w;
    }

    static const Type Int ("int", Tag::BASIC, 4); 
    static const Word and ("&&", Tag::AND);
    // static const Type Float("float", Tag.BASIC, 8);
    // static const Type Char("char", Tag.BASIC, 1);
    // static const Type Bool("bool", Tag.BASIC, 1);

    // static bool numeric(Type p)
    // {
    //     if (p == Type.Char || p == Type.Int || p == Type.Float)
    //         return true;
    //     else
    //         return false;
    // }

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