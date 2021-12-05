#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <iomanip>
#include "mytar.h"

using namespace std;


void MyTar::start()
{
    streampos size;

    ifstream file(fn, ios::in | ios::binary | ios::ate);
    if (file.is_open())
    {
        size = file.tellg();
        file.seekg(0, ios::beg);

        while (++pos < size)
        {
            TarHeader th;
            file.read(th.filename, 100);
            file.read(th.filemode, 8);
            file.read(th.userid, 8);
            file.read(th.groupid, 8);
            file.read(th.filesize, 12);
            file.read(th.mtime, 12);
            file.read(th.checksum, 8);
            file.read(&th.type, 1);
            file.read(th.lname, 100);
            /* USTAR Section */
            file.read(th.USTAR_id, 6);
            file.read(th.USTAR_ver, 2);
            file.read(th.username, 32);
            file.read(th.groupname, 32);
            file.read(th.devmajor, 8);
            file.read(th.devminor, 8);
            file.read(th.prefix, 155);
            file.read(th.pad, 12);
            
            if(atol(th.filesize) == 0 && atol(th.mtime) == 0) break;
            pos += 512 + getBlock(getSize(th.filesize)) * 512;
            file.seekg(getBlock(getSize(th.filesize)) * 512, ios::cur);
            showDetail(th);
        }
        file.close();
    }
    else
        cout << "Unable to open file" << endl;
}

int MyTar::getSize(char *c)
{
    return octToDec(atol(c));
}

void MyTar::showDetail(TarHeader th)
{
    cout << getMode(atoi(th.filemode)%1000/100);
    cout << getMode(atoi(th.filemode)%100/10);
    cout << getMode(atoi(th.filemode)%10) << " ";
    cout << getUser(octToDec(atol(th.userid))) << '/' << getGroup(octToDec(atol(th.groupid))) << "   ";
    cout << setw(3) << octToDec(atol(th.filesize)) << " ";
    cout << getTime(octToDec(atol(th.mtime))) << " ";
    cout << th.filename << endl;
}

long MyTar::octToDec(long n)
{
    long result = 0,
         m = 1;
    while (n > 0)
    {
        result += n % 10 * m;
        m *= 8;
        n /= 10;
    }
    return result;
}

string MyTar::getMode(int mod)
{
    switch (mod)
    {
        case 0: return "---";
        case 1: return "--x";
        case 2: return "-w-";
        case 3: return "-wx";
        case 4: return "r--";
        case 5: return "r-x";
        case 6: return "rw-";
        case 7: return "rwx";
        default: return "---";
    }
}

string MyTar::getUser(uid_t uid)
{
    struct passwd *pws;
    pws = getpwuid(uid);
    return pws->pw_name;
}

string MyTar::getGroup(uid_t uid)
{
    struct group *grp;
    grp = getgrgid(uid);
    return grp->gr_name;
}

string MyTar::getTime(long time_date_stamp)
{
    std::time_t temp = time_date_stamp;
    std::tm *t = std::gmtime(&temp);
    std::stringstream ss;
    ss << std::put_time(t, "%Y-%m-%d %I:%M");
    std::string output = ss.str();
    return output;
}

int MyTar::getBlock(const int &size)
{
    return ceil(static_cast<double>(size) / 512);
}
