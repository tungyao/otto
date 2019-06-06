#include "ottofs.h"

<<<<<<< HEAD
void *OTTOFS_read(FILE *fp)
{
=======
void *OTTOFS_read(FILE *fp) {
>>>>>>> f1b477238bbd57c0fb428fcbcca7d2c175b19051

    char *buffer = NULL;
    char ch;
    int i = 0;
    if (!fp)
    {
        printf("%s: can not open\n", __func__);
        return NULL;
    }

    long len = OTTOFS_size_file(fp);

    //len bytes
    buffer = malloc(len);
    // printf("%ld\n", sizeof(char));
<<<<<<< HEAD
    if (NULL != buffer)
=======
    if(NULL != buffer)
>>>>>>> f1b477238bbd57c0fb428fcbcca7d2c175b19051
    {
        printf("success\n");
    }
    else
    {
        printf("the file is too large to load!\n");
        return NULL;
    }
<<<<<<< HEAD
    fgets(buffer, len, fp);
    return buffer;
}

void *OTTOFS_readb(FILE *fp)
{
    return NULL;
}

int OTTOFS_write(FILE *fp, char *str)
{
=======
    char * s = fgets( buffer, len, fp );

    char st[] = {'a','b'};
    for (int i = 0; i < len; i++)
    {
        if ((int)s[i] <0)
        {
       
            printf("%s\n", st);
        }
        
    }
     char *ss ="牛";
     printf("%d\n", sizeof(ss));
     printf("%s\n", s);
     return buffer;
}

void *OTTOFS_readb(FILE *fp) {
    return NULL;
}

int OTTOFS_write(FILE *fp,  char *str) {
>>>>>>> f1b477238bbd57c0fb428fcbcca7d2c175b19051
    fputs(str, fp);
    return 0;
}

<<<<<<< HEAD
int OTTOFS_writeb(FILE *fp, char *bt)
{
    if (fp == NULL)
    {
        printf("无法打开文件");
        return 0;
    }
    printf("%d %s\n", sizeof(bt), bt);
=======
int OTTOFS_writeb(FILE *fp,  char *bt) {
    if (fp == NULL) {
        printf("无法打开文件");
        return 0;
    }
    printf("%d %s\n", sizeof(bt),bt);
>>>>>>> f1b477238bbd57c0fb428fcbcca7d2c175b19051
    fwrite(bt, sizeof(char), sizeof(bt), fp);
    return -1;
}
long OTTOFS_size_file(FILE *file)
{
    /* 获取文件大小 */
<<<<<<< HEAD
    fseek(file, 0, SEEK_END);
    long lSize;
    lSize = ftell(file);
    rewind(file); //point back to the begin
    printf("the size of file is : %ld byte\n", lSize);
=======
    fseek (file, 0, SEEK_END);
    long lSize;
    lSize = ftell (file);
    rewind (file);//point back to the begin
    printf("the size of file is : %ld byte\n",  lSize);
>>>>>>> f1b477238bbd57c0fb428fcbcca7d2c175b19051
    return lSize;
}
