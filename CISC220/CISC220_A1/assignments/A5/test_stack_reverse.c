#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack_utils.h"

stack *stack_copy(const stack *s) {
    stack *res = stack_init();
    if (stack_is_empty(s)) {
        return res;
    }
    res->top = malloc(sizeof(node));
    node *n = res->top;
    node *ns = s->top;
    while (ns) {
        // copy elem into n
        n->elem = ns->elem;
        if (ns->next) {
            n->next = malloc(sizeof(node));
            n = n->next;
        }
        ns = ns->next;
    }
    res->size = s->size;
    return res;
}

bool equals(const stack *t1, const stack *t2) {
    size_t n1 = stack_size(t1);
    size_t n2 = stack_size(t2);
    if (n1 != n2) {
        fprintf(stderr, "size %lu != size %lu\n", n1, n2);
        return false;
    }
    node *d1 = t1->top;
    node *d2 = t2->top;
    for (size_t i = 0; i < n1; i++) {
        int *e1 = d1->elem;
        int *e2 = d2->elem;
        if (*e1 != *e2) {
            fprintf(stderr, "elements at index %lu differ: %d != %d\n", i, *e1, *e2);
            return false;
        }
        d1 = d1->next;
        d2 = d2->next;
    }
    return true;
}


void test01(void) {
    puts("running test01...");
    stack *s = stack_init();
    stack_reverse(s);
    if (stack_size(s) != 0) {
        fprintf(stderr, "stack_reverse(empty) added elements to a stack?\n");
        return;
    }
}

void test02(void) {
    puts("running test02...");
    stack *s = stack_init();
    size_t n = 1;
    int arr[] = { 1 };
    stack_push(s, &arr[0]);

    stack_reverse(s);
    
    stack *exp = stack_copy(s);
    
    if (!equals(exp, s)) {
        fprintf(stderr, "stack_reverse([1]) did not modify stack correctly\n");
        return;
    }
}

void test03(void) {
    puts("running test03...");
    stack *s = stack_init();
    size_t n = 2;
    int arr[] = { 1, 100 };
    for (int i = 0; i < n; i++) {
        stack_push(s, &arr[i]);
    }

    stack_reverse(s);
    
    stack *exp = stack_init();
    for (int i = n - 1; i >= 0; i--) {
        stack_push(exp, &arr[i]);
    }
    
    if (!equals(exp, s)) {
        fprintf(stderr, "stack_reverse([1, 100]) did not modify stack correctly\n");
        return;
    }
}

void test04(void) {
    puts("running test04...");
    stack *s = stack_init();
    size_t n = 3;
    int arr[] = { 1, 100, 1000};
    for (int i = 0; i < n; i++) {
        stack_push(s, &arr[i]);
    }

    stack_reverse(s);
    
    stack *exp = stack_init();
    for (int i = n - 1; i >= 0; i--) {
        stack_push(exp, &arr[i]);
    }
    
    if (!equals(exp, s)) {
        fprintf(stderr, "stack_reverse([1, 100, 1000]) did not modify stack correctly\n");
        return;
    }
}

void test05(void) {
    puts("running test05...");
    stack *s = stack_init();
    size_t n = 10;
    int arr[] = { 1, 100, 1000, -2, 20, 200, 3, 300, -4, -40};
    for (int i = 0; i < n; i++) {
        stack_push(s, &arr[i]);
    }

    stack_reverse(s);
    
    stack *exp = stack_init();

    int tmp = 5;

    for (int i = n - 1; i >= 0; i--) {
        stack_push(exp, &arr[i]);
    }
    
    if (!equals(exp, s)) {
        fprintf(stderr, "stack_reverse([1, 100, 1000, -2, 20, 200, 3, 300, -4, -40]) did not modify stack correctly\n");
        return;
    }
}



int main(void) {
    test01();
    puts("");

    test02();
    puts("");

    test03();
    puts("");

    test04();
    puts("");

    test05();
}