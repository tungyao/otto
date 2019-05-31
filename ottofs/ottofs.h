#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef OTTOFS_H
#define OTTOFS_H

void* OTTOFS_read(FILE *fp);
void* OTTOFS_readb(FILE *fp);
int OTTOFS_write(FILE *fp, char* str);
int OTTOFS_writeb(FILE *fp, char* bt);
long OTTOFS_size_file(FILE *file);
#endif