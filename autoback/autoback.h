#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <dirent.h>
struct CPDIR{
    char *inpath;
    char *outpath;
    int dirnum;
    int oldseek;
};

int check_args(int argc, char *argv[]);
void set_time(int second, void (*func)());
void copyfile(char *inpath, char *outpath);
int scandirs(char* path);
int deletedir(int seek);
int copydir();
void func();
