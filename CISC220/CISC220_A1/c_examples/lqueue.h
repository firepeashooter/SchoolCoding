#ifndef LQUEUE_H
#define LQUEUE_H

#include <stdbool.h>

typedef struct lqueue lqueue;

lqueue *lqueue_init();

bool lqueue_is_empty(const lqueue *q);

size_t lqueue_size(const lqueue *q);

bool lqueue_enqueue(lqueue *q, int elem);

int lqueue_dequeue(lqueue *q);

void lqueue_free(lqueue *q);

void lqueue_print(const lqueue *q);

#endif // LQUEUE_H