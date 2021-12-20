#include <iostream>
#include <fstream>
#include <iomanip>

#include "lexer.h"

using std::cout;
using std::endl;

char peek = ' ';
string tok = "";
string output = "";

// void readch(){
//     if (!std::cin.get(peek))
//         throw "End of file reached";
// }

int main(int argc, char *argv[])
{
    string line;
    string lines;

    // Read from the text file
    std::ifstream MyReadFile(argv[1]);

    // read file
    while (getline(MyReadFile, line))
        lines += line;

    Lexer lexer(lines);

    try
    {
        int i = 0;
        while (true)
        {
            output = "Token: ";
            tok = "";
         
            Token t = lexer.scan();
            while (output.size() < 15)
                output += ' ';
            string tag = t.toString();
            if (tag != "-1")
            {
                output += '(' + tag + ')';
            }
            else
            {
                output += '(' + tok + ')';
            }
            cout << output << endl;
        }
    }
    catch (const char *message)
    {
        cout << message << endl;
    }
}
