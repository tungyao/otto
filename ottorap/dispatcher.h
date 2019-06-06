#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "regex.h"
#include "stdlib.h"

#define GET 1
#define POST 2
#define PUT 3
#define HEAD 4
#define DELETE 5

extern void (*error_handler)(const char *);

struct handler {
    void (*func)(regmatch_t[]);
    int method;
    const char *regex_str;
    regex_t regex;
    size_t nmatch;
    struct handler *next;
};
typedef struct handler handler;

#define START_HANDLER(NAME, METHOD, REGEX, RES, NUM, MATCHES) \
void NAME##_func(); \
handler NAME##_data = {NAME##_func, METHOD, REGEX, {0}, NUM, NULL}; \
handler *NAME = &NAME##_data; \
void NAME##_func(regmatch_t MATCHES[]) { \
    response *int_response = response_empty(); \
    response *RES = int_response;

#define END_HANDLER \
    response_send(int_response); \
}

void init_handlers();
void cleanup_handlers();

void dispatch();
void add_handler(handler *);

#endif
