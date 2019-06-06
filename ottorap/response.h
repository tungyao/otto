#ifndef RESPONSE_H
#define RESPONSE_H

#include "stdbool.h"

struct response;
typedef struct response response;

response *response_empty();

void response_add_header(response *, const char *, const char *);
void response_write(response *, const char *);

#endif
