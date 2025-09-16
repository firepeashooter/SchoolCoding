#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "list_utils.h"


bool equals(const list *t1, const list *t2) {
    size_t n1 = list_size(t1);
    size_t n2 = list_size(t2);
    if (n1 != n2) {
        fprintf(stderr, "size %lu != size %lu\n", n1, n2);
        return false;
    }
    for (size_t i = 0; i < n1; i++) {
        int e1 = t1->arr[i];
        int e2 = t2->arr[i];
        if (e1 != e2) {
            fprintf(stderr, "elements at index %lu differ: %d != %d\n", i, e1, e2);
            return false;
        }
    }
    return true;
}


void test01(void) {
    puts("running test01...");
    list *t = list_join(NULL, NULL);
    if (!t) {
        fprintf(stderr, "list_join(NULL, NULL) returned NULL\n");
        return;
    }
    if (list_size(t) != 0) {
        fprintf(stderr, "list_join(NULL, NULL) returned non-empty list\n");
        return;
    }
}

void test02(void) {
    puts("running test02...");
    list *s1 = list_init_empty();
    list_add(s1, 0);
    list *exp = list_copy(s1);
    list *t = list_join(s1, NULL);
    if (!t) {
        fprintf(stderr, "list_join(s1, NULL) returned NULL\n");
        return;
    }
    if (!equals(exp, t)) {
        fprintf(stderr, "list_join(s1, NULL) returned wrong list\n");
        return;
    }
}

void test03(void) {
    puts("running test03...");
    list *s1 = list_init_empty();
    list_add(s1, 0);
    list *exp = list_copy(s1);
    list *t = list_join(NULL, s1);
    if (!t) {
        fprintf(stderr, "list_join(NULL, s1) returned NULL\n");
        return;
    }
    if (!equals(exp, t)) {
        fprintf(stderr, "list_join(NULL, s1) returned wrong list\n");
        return;
    }
}

void test04(void) {
    puts("running test04...");
    list *s1 = list_init_empty();
    list *s2 = list_init_empty();
    list *exp = list_init_empty();
    list *t = list_join(s1, s2);
    if (!t) {
        fprintf(stderr, "list_join(empty, empty) returned NULL\n");
        return;
    }
    if (!equals(exp, t)) {
        fprintf(stderr, "list_join(empty, empty) returned wrong list\n");
        return;
    }
}

void test05(void) {
    puts("running test05...");
    list *s1 = list_init_empty();
    list *s2 = list_init_empty();
    list_add(s2, 10);
    list_add(s2, 11);
    list *exp = list_copy(s2);
    list *t = list_join(s1, s2);
    if (!t) {
        fprintf(stderr, "list_join(empty, s2) returned NULL\n");
        return;
    }
    if (!equals(exp, t)) {
        fprintf(stderr, "list_join(empty, s2) returned wrong list\n");
        return;
    }
}

void test06(void) {
    puts("running test06...");
    list *s1 = list_init_empty();
    list_add(s1, 10);
    list_add(s1, 11);
    list *s2 = list_init_empty();
    list *exp = list_copy(s1);
    list *t = list_join(s1, s2);
    if (!t) {
        fprintf(stderr, "list_join(s1, empty) returned NULL\n");
        return;
    }
    if (!equals(exp, t)) {
        fprintf(stderr, "list_join(s1, empty) returned wrong list\n");
        return;
    }
}

void test07(void) {
    puts("running test07...");
    list *s1 = list_init_empty();
    list_add(s1, 10);
    list_add(s1, 11);
    list *s2 = list_init_empty();
    list_add(s2, 20);
    list_add(s2, 21);
    list *exp = list_copy(s1);
    list_add(exp, 20);
    list_add(exp, 21);
    list *t = list_join(s1, s2);
    if (!t) {
        fprintf(stderr, "list_join(s1, s2) returned NULL\n");
        return;
    }
    if (!equals(exp, t)) {
        fprintf(stderr, "list_join(s1, s2) returned wrong list\n");
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
}