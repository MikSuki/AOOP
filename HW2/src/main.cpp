#include <iostream>
#include "mytar.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        const char *fn = argv[1];
        MyTar mt{fn};
        mt.start();
    }
    else
    {
        cout << "command error" << endl;
    }

    return 0;
}
