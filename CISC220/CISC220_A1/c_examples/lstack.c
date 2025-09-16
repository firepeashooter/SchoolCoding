#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "lstack.h"

typedef struct node node;

struct node {
    int elem;
    node *next;
};

struct lstack {
    node *top;
    size_t size;
};

lstack *lstack_init() {
    // allocate the stack struct
    lstack *s = malloc(sizeof(lstack));
    if (!s) {
        return NULL;
    }
    // initialize members for an empty list
    s->top = NULL;
    s->size = 0;
    return s;
}

bool lstack_is_empty(const lstack *s) {
    return s->size == 0;
}

size_t lstack_size(const lstack *s) {
    return s->size;
}

bool lstack_push(lstack *s, int elem) {
    // allocate storage for a new node
    node *n = malloc(sizeof(node));
    if (!n) {
        return false;
    }
    // initialize node members so that the node is in
    // front of the current top node
    n->elem = elem;
    n->next = s->top;
    // the top node in the stack is now n
    s->top = n;
    s->size++;
    return true;
}

int lstack_pop(lstack *s) {
    assert(!lstack_is_empty(s));
    // get a pointer to the top node so that we can free the node later
    node *top = s->top;
    // get the element to return to the caller
    int elem = top->elem;
    // pop the element by moving the top pointer to the next node
    s->top = top->next;
    s->size--;
    // free the old top node
    free(top);

    return elem;
}

void lstack_free(lstack *s) {
    // free all nodes by iterating over all nodes and freeing
    // nodes as they are visited
    node *n = s->top;
    while (n) {
        node *next = n->next;
        free(n);
        n = next;
    }
    // free the stack
    free(s);
}



/* iterative version of print
void lstack_print(const lstack *s) {
    printf("TOP, ");
    node *n = s->top;
    while (n) {
        printf("%d, ", n->elem);
        n = n->next;
    }
    printf("BOTTOM\n");
}
*/

void print_rec(const node *n);

void lstack_print(const lstack *s) {
    printf("TOP, ");
    print_rec(s->top);
    printf("BOTTOM\n");
}

/**
 * Recursive helper function to demonstrate recursion
 * on a linked structure.
 * 
 * Prints the elements in all of the nodes starting at
 * the specified node n.
 */
void print_rec(const node *n) {
    // base case
    if (!n) {
        return;
    }
    // n not NULL, recursive case
    // print the element in n
    printf("%d, ", n->elem);
    // then print the remaining elements
    print_rec(n->next);
}