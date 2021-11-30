#include <string>

class Token
{
public:
    /*final */ int tag;
    Token(int t) : tag(t){};

    string toString()
    {
        return "" + (char)tag;
    }
};
