#include <string>
#include "Token.h"

using std::string;

string Token::toString()
{
    return "" + (char)tag;
}
