#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "lqueue.h"

typedef struct node node;

struct node {
    int elem;
    node *next;
};

struct lqueue {
    node *front;
    node *back;
    size_t size;
};

lqueue *lqueue_init() {
    // allocate the queue struct
    lqueue *q = malloc(sizeof(lqueue));
    if (!q) {
        return NULL;
    }
    // initialize members for an empty 
    q->front = NULL;
    q->back = NULL;
    q->size = 0;
    return q;
}

bool lqueue_is_empty(const lqueue *q) {
    return q->size == 0;
}

size_t lqueue_size(const lqueue *q) {
    return q->size;
}

bool lqueue_enqueue(lqueue *q, int elem) {
    // allocate storage for a new node
    node *n = malloc(sizeof(node));
    if (!n) {
        return false;
    }
    // initialize node members 
    n->elem = elem;
    n->next = NULL;
    // special case where queue is empty
    if (lqueue_is_empty(q)) {
        q->front = n;
    }
    else {
        q->back->next = n;
    }
    q->back = n;
    q->size++;
    return true;
}

int lqueue_dequeue(lqueue *q) {
    assert(!lqueue_is_empty(q));
    // get a pointer to the front node so that we can free the node later
    node *front = q->front;
    // get the element to return to the caller
    int elem = front->elem;
    // dequeue the element by moving the front pointer to the next node
    // special case where queue has one element
    if (lqueue_size(q) == 1) {
        q->back = NULL;
    }
    q->front = front->next;
    q->size--;
    // free the old front node
    free(front);

    return elem;
}

void lqueue_free(lqueue *q) {
    // free all nodes by iterating over all nodes and freeing
    // nodes as they are visited
    node *n = q->front;
    while (n) {
        node *next = n->next;
        free(n);
        n = next;
    }
    // free the queue
    free(q);
}



/* iterative version of print
void lqueue_print(const lqueue *s) {
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

void lqueue_print(const lqueue *q) {
    printf("FRONT, ");
    print_rec(q->front);
    printf("BACK\n");
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