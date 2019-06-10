#include "response.h"

#include "fcgi\fcgi_stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

struct header {
    char *name;
    char *value;
    struct header *next;
};
typedef struct header header;

struct text_segment {
    char *text;
    struct text_segment *next;
};
typedef struct text_segment text_segment;

struct response {
    header *header_head;
    header *header_tail;
    text_segment *segment_head;
    text_segment *segment_tail;
};

response *response_empty() {
    response *result = malloc(sizeof(response));
    result->header_head = NULL;
    result->header_tail = NULL;
    result->segment_head = NULL;
    result->segment_tail = NULL;
    return result;
}

void response_write(response *res, const char *text) {
    text_segment *segment = malloc(sizeof(text_segment));
    segment->text = strdup(text);
    segment->next = NULL;
    if (res->segment_head == NULL) {
        res->segment_head = segment;
    } else {
        res->segment_tail->next = segment;
    }
    res->segment_tail = segment;
}

void response_add_header(response *res, const char *name, const char *val) {
    header *h = malloc(sizeof(header));
    h->name = strdup(name);
    h->value = strdup(val);
    h->next = NULL;
    if (res->header_head == NULL) {
        res->header_head = h;
    } else {
        res->header_tail->next = h;
    }
    res->header_tail = h;
}

void response_send(response *res) {
    header *cur_h;
    for (cur_h = res->header_head; cur_h != NULL;) {
        printf("%s: %s\n", cur_h->name, cur_h->value);
        free(cur_h->name);
        free(cur_h->value);
        
        header *next = cur_h->next;
        free(cur_h);
        cur_h = next;
    }
    printf("\n");
    text_segment *cur_s;
    for (cur_s = res->segment_head; cur_s != NULL;) {
        printf("%s", cur_s->text);
        free(cur_s->text);
        
        text_segment *next = cur_s->next;
        free(cur_s);
        cur_s = next;
    }
    free(res);
}
