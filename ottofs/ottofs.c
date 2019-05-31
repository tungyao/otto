#include "ottofs.h"

void *OTTOFS_read(FILE *fp) {

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
    if(NULL != buffer)
    {
        printf("success\n");
    }
    else
    {
        printf("the file is too large to load!\n");
        return NULL;
    }
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
    fputs(str, fp);
    return 0;
}

int OTTOFS_writeb(FILE *fp,  char *bt) {
    if (fp == NULL) {
        printf("无法打开文件");
        return 0;
    }
    printf("%d %s\n", sizeof(bt),bt);
    fwrite(bt, sizeof(char), sizeof(bt), fp);
    return -1;
}
long OTTOFS_size_file(FILE *file)
{
    /* 获取文件大小 */
    fseek (file, 0, SEEK_END);
    long lSize;
    lSize = ftell (file);
    rewind (file);//point back to the begin
    printf("the size of file is : %ld byte\n",  lSize);
    return lSize;
}
