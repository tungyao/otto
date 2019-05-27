#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef OTTOFS_H
#define OTTOFS_H
FILE *fp;

void* read(FILE *fp);
void* readb(FILE *fp);
int write(FILE *fp,void* str);
int writeb(FILE *fp,char* bt);


#endif