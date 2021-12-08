#include <iostream>
#include <fstream>

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
    string line;
    string lines;

    // Read from the text file
    std::ifstream MyReadFile("try");

    // read file
    while (getline(MyReadFile, line))
        lines += line;
    // cout << lines << endl;

    Lexer lexer(lines);

    try
    {
        // for (;; readch())
        // {
        //     cout << peek << endl;
        // }
        int cnt = 10;
        int i = 0;
        // while (true)
        while(++i < cnt)
        {
            cout << "Token: ";
            Token *t;
            t = &(lexer.scan());
            cout << t->toString() << endl;
        }
    }
    catch (const char *message)
    {
        cout << message << endl;
    }
}
