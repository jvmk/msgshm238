#include<stdlib.h>
#include<stdio.h>

#define INITIAL_SIZE 32

struct Buffer {
    void *data;
    int next;
    size_t size;
}

struct Buffer *new_buffer() {
    struct Buffer *b = malloc(sizeof(Buffer));

    b->data = malloc(INITIAL_SIZE);
    b->size = INITIAL_SIZE;
    b->next = 0;
    return b;
}

void reserve_space(Buffer *b, size_t bytes) {
    if((b->next + bytes) > b->size) {
        /* double size to enforce O(lg N) reallocs */
        b->data = realloc(b->data, b->size * 2);
        b->size *= 2;
    }
}

void serialize_int(int x, Buffer *b) {
    /* assume int == long; how can this be done better? */
    x = htonl(x);
    reserve_space(b, sizeof(int));
    memcpy(((char *)b->data) + b->next, &x, sizeof(int));
    b->next += sizeof(int);
}


void serialize_string(char *x, Buffer *b) {
    /* assume int == long; how can this be done better? */
    x = htonl(x);
    reserve_space(b, (strlen(x) + 1 ) * sizeof(char));
    memcpy(((char *)b->data) + b->next, &x, sizeof(int));
    b->next += sizeof(int);
}