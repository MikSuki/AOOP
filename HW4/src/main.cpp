#include <iostream>

#include "lexer.h"

using std::cout;
using std::endl;

char peek = ' ';

// void readch(){
//     if (!std::cin.get(peek))
//         throw "End of file reached";
// }


int main()
{
    Lexer lexer;

    try
    {
        // for (;; readch())
        // {
        //     cout << peek << endl;
        // }
        while (true)
        {
            Token t = lexer.scan();
            cout << t.toString()<<endl;
        }
    }
    catch (const char* message) {
        cout << "error";
        cout << message << endl;
    }
    // catch (IOExeception &e)
    // {
    //     cout << e.what() << endl;
    // }
}
