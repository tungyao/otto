#include "dispatcher.h"
#include "request.h"
#include "error.h"

#include "string.h"

#include "fcgi_stdio.h"

handler *head = NULL;
handler *last = NULL;

void default_error_handler(const char *msg) {
    printf("content-type: text/html\n\nerror: %s\n", msg);
}

void (*error_handler)(const char *) = default_error_handler;

void dispatch() {
    handler *cur;
    char *path_info = get_path_info();
    if (path_info == NULL) {
        error_handler("NULL path_info");
        return;
    }
    char *method_str = get_method();
    if (method_str == NULL) {
        error_handler("NULL method_str");
        return;
    }
    int method;
    if (strcmp(method_str, "GET") == 0) {
        method = GET;
    } else if (strcmp(method_str, "POST") == 0) {
        method = POST;
    } else if (strcmp(method_str, "PUT") == 0) {
        method = PUT;
    } else if (strcmp(method_str, "HEAD") == 0) {
        method = HEAD;
    } else if (strcmp(method_str, "DELETE") == 0) {
        method = DELETE;
    } else {
        error_handler("unknown request method");
        return;
    }
    for (cur = head; cur != NULL; cur = cur->next) {
        if (cur->method == method) {
            regmatch_t *matches = malloc(sizeof(regmatch_t) * cur->nmatch);
            int m = regexec(&cur->regex, path_info, cur->nmatch, matches, 0);
            if (m == 0) {
                cur->func(matches);
                free(matches);
                return;
            }
            free(matches);
        }
    }
    error_handler("no match");
}

void add_handler(handler *h) {
    if (head == NULL) {
        head = h;
    } else {
        last->next = h;
    }
    last = h;
}

void init_handlers() {
    handler *cur = head;
    while (cur != NULL) {
        if (regcomp(&cur->regex, cur->regex_str, 0) != 0) {
            FAIL_WITH_ERROR("could not compile regex");
        }
        cur = cur->next;
    }
}

void cleanup_handlers() {
    handler *cur = head;
    while (cur != NULL) {
        regfree(&cur->regex);    
        cur = cur->next;
    }
}
