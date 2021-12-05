#ifndef __MYTAR_H__
#define __MYTAR_H__

class MyTar
{
public:
    MyTar(const char *file_name)
        : fn(file_name)
    {
    }
    void start();

private:
    long pos;
    const char *fn;

    struct TarHeader
    {
        char filename[100];
        char filemode[8];
        char userid[8];
        char groupid[8];
        char filesize[12];
        char mtime[12];
        char checksum[8];
        char type;
        char lname[100];
        /* USTAR Section */
        char USTAR_id[6];
        char USTAR_ver[2];
        char username[32];
        char groupname[32];
        char devmajor[8];
        char devminor[8];
        char prefix[155];
        char pad[12];
    };

    void showDetail(TarHeader);
    long octToDec(long);
    std::string getMode(int);
    std::string getUser(uid_t);
    std::string getGroup(uid_t);
    int getSize(char *);
    char* getMode(mode_t);
    std::string getTime(long);
    int getBlock(const int &);
};

#endif
