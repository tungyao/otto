#include "ottofs.h"

int main(){
    char *string = "你好世界123,Hello World.asdasdasdasdasdasdasdasdasdsa";
    FILE *fp = fopen("test.txt", "r");
    // OTTOFS_write(fp,string);
    OTTOFS_read(fp);

    return  0;
}