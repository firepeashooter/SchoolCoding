#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack_utils.h"

bool eq_int(const void *e1, const void *e2) {
    const int *v1 = e1;
    const int *v2 = e2;
    return *v1 == *v2;
}


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


void test01(void) {
    puts("running test01...");
    stack *s1 = stack_init();
    stack *s2 = stack_init();
    bool boo = stack_equals(s1, s2, &eq_int);
    if (!boo) {
        fprintf(stderr, "stack_equals(empty, empty) returned false\n");
        return;
    }
}

void test02(void) {
    puts("running test02...");
    size_t n = 1;
    int arr[] = { 1 };
    stack *s1 = stack_init();
    stack *s2 = stack_init();
    for (int i = 0; i < n; i++) {
        stack_push(s1, &arr[i]);
        stack_push(s2, &arr[i]);
    }
    bool boo = stack_equals(s1, s2, &eq_int);
    if (!boo) {
        fprintf(stderr, "stack_equals([1], [1]) returned false\n");
        return;
    }
}

void test03(void) {
    puts("running test03...");
    size_t n = 2;
    int arr[] = { 1, 25 };
    stack *s1 = stack_init();
    stack *s2 = stack_init();
    for (int i = 0; i < n; i++) {
        stack_push(s1, &arr[i]);
        stack_push(s2, &arr[i]);
    }
    bool boo = stack_equals(s1, s2, &eq_int);
    if (!boo) {
        fprintf(stderr, "stack_equals([1, 25], [1, 25]) returned false\n");
        return;
    }
}

void test04(void) {
    puts("running test04...");
    size_t n = 10;
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    stack *s1 = stack_init();
    stack *s2 = stack_init();
    for (int i = 0; i < n; i++) {
        stack_push(s1, &arr[i]);
        stack_push(s2, &arr[i]);
    }
    bool boo = stack_equals(s1, s2, &eq_int);
    if (!boo) {
        fprintf(stderr, "stack_equals([1, 2, 3, ...], [1, 2, 3, ...]) returned false\n");
        return;
    }
}

void test05(void) {
    puts("running test05...");
    size_t n = 1;
    int arr[] = { 1 };
    stack *s1 = stack_init();
    stack *s2 = stack_init();
    for (int i = 0; i < n; i++) {
        stack_push(s1, &arr[i]);
    }
    bool boo = stack_equals(s1, s2, &eq_int);
    if (boo) {
        fprintf(stderr, "stack_equals([1], []) returned true\n");
        return;
    }
}

void test06(void) {
    puts("running test06...");
    size_t n = 1;
    int arr1[] = { 1 };
    int arr2[] = { 2 };
    stack *s1 = stack_init();
    stack *s2 = stack_init();
    for (int i = 0; i < n; i++) {
        stack_push(s1, &arr1[i]);
        stack_push(s2, &arr2[i]);
    }
    bool boo = stack_equals(s1, s2, &eq_int);
    if (boo) {
        fprintf(stderr, "stack_equals([1], [2]) returned true\n");
        return;
    }
}

void test07(void) {
    puts("running test07...");
    size_t n = 2;
    int arr1[] = { 1, 1 };
    int arr2[] = { 1, 2 };
    stack *s1 = stack_init();
    stack *s2 = stack_init();
    for (int i = 0; i < n; i++) {
        stack_push(s1, &arr1[i]);
        stack_push(s2, &arr2[i]);
    }
    bool boo = stack_equals(s1, s2, &eq_int);
    if (boo) {
        fprintf(stderr, "stack_equals([1, 1], [1, 2]) returned true\n");
        return;
    }
}

void test08(void) {
    puts("running test08...");
    size_t n = 2;
    int arr1[] = { 1, 1 };
    int arr2[] = { 2, 1 };
    stack *s1 = stack_init();
    stack *s2 = stack_init();
    for (int i = 0; i < n; i++) {
        stack_push(s1, &arr1[i]);
        stack_push(s2, &arr2[i]);
    }
    bool boo = stack_equals(s1, s2, &eq_int);
    if (boo) {
        fprintf(stderr, "stack_equals([1, 1], [2, 1]) returned true\n");
        return;
    }
}

void test09(void) {
    puts("running test09...");
    size_t n = 5;
    int arr1[] = { 1, 2, 3, 4, 5 };
    int arr2[] = { 1, 2, 3, 0, 5 };
    stack *s1 = stack_init();
    stack *s2 = stack_init();
    for (int i = 0; i < n; i++) {
        stack_push(s1, &arr1[i]);
        stack_push(s2, &arr2[i]);
    }
    bool boo = stack_equals(s1, s2, &eq_int);
    if (boo) {
        fprintf(stderr, "stack_equals([1, 2, 3, 4, 5], [1, 2, 3, 0, 5]) returned true\n");
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
    puts("");

    test06();
    puts("");

    test07();
    puts("");

    test08();
    puts("");

    test09();
}