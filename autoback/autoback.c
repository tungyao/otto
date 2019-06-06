#include "autoback.h"
#define MAXPATH 124
struct CPDIR *cpdirs;

int check_args(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("%s", "args error , you can input: --inDir --outDir --dirNum\n");
        return -1;
    }
    else
    {
        printf("it's ok! Get args(%s , %s) \n", argv[1], argv[2]);
        return 0;
    }

    return -1;
}

void set_time(int second, void (*func)())
{
    time_t start, end;
    time(&start);
    do
    {
        time(&end);
        Sleep(1000);
    } while ((end - start) != second);
    if ((end - start) >= second)
    {
        func();
        end = 0;
        start = 0;
        set_time(second, func);
    }
}
void func()
{
}
void copyfile(char *inpath, char *outpath)
{
    FILE *op, *inp;

    op = fopen(inpath, "rb");
    if (op == NULL)
    {
        exit(0);
    }
    inp = fopen(outpath, "wb");

    void *buf;

    char c;

    while (!feof(op))

    {

        fread(&buf, 1, 1, op);

        fwrite(&buf, 1, 1, inp);
    }
    fclose(inp);

    fclose(op);

    printf("over");
}
int scandirs(char *path)
{
    struct dirent *ptr;
    int n = 0;
    DIR *dir;
    dir = opendir(path);
    ptr = malloc(sizeof(struct dirent));
    if (dir == NULL)
    {
        printf("fail to open dir,now make new dir\n");
        // printf("%s",strcat("mkdir ", path));
        char mkdir[MAXPATH] = "mkdir ";
        char *cdir = strcat(mkdir, path);
        system(cdir);
        Sleep(500);
    }
    while ((ptr = readdir(dir)) != NULL)
    {
        // if (ptr->d_name)
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "…") == 0)
        {
            continue;
        }
        if (ptr->d_type == DT_DIR)
        {
            n++;
            printf("%s%s\n", path, ptr->d_name);
        }
    }
    printf("%d", n);
    closedir(dir);
    free(ptr);
    return n - 1;
}
int deletedir(int seek)
{
    return 0;
}
int copydir()
{
    // int num = scandirs(argv[2]);
    // if(num)

    return 0;
}
int main(int argc, char *argv[])
{
    if (check_args(argc, argv))
    {
        exit(0);
    }
    cpdirs = malloc(sizeof(struct CPDIR));
    memset(&cpdirs, 0, sizeof(cpdirs));

    cpdirs->inpath = argv[1];
    cpdirs->outpath = argv[2];
    cpdirs->dirnum = atoi(argv[3]);
    free(cpdirs);
    return 0;
}