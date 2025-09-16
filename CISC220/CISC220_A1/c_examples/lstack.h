#ifndef LSTACK_H
#define LSTACK_H

#include <stdbool.h>

typedef struct lstack lstack;

lstack *lstack_init();

bool lstack_is_empty(const lstack *s);

size_t lstack_size(const lstack *s);

bool lstack_push(lstack *s, int elem);

int lstack_pop(lstack *s);

void lstack_free(lstack *s);

void lstack_print(const lstack *s);

#endif // LSTACK_H