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
    list *s = list_init_empty();
    list_remove_all(s, 1);
    if (list_size(s) != 0) {
        fprintf(stderr, "list_remove_all(empty, 1) added elements to a list?\n");
        return;
    }
}

void test02(void) {
    puts("running test02...");
    list *s = list_init_empty();
    list_add(s, 0);
    
    list *exp = list_init_empty();
    
    list_remove_all(s, 0);
    
    if (!equals(exp, s)) {
        fprintf(stderr, "list_remove_all([0], 0) did not modify s correctly\n");
        return;
    }
}

void test03(void) {
    puts("running test03...");
    list *s = list_init_empty();
    list_add(s, 0);
    list_add(s, 0);
    
    list *exp = list_init_empty();
    
    list_remove_all(s, 0);
    
    if (!equals(exp, s)) {
        fprintf(stderr, "list_remove_all([0, 0], 0) did not modify s correctly\n");
        return;
    }
}

void test04(void) {
    puts("running test04...");
    list *s = list_init_empty();
    list_add(s, 0);
    list_add(s, 1);
    list_add(s, 0);
    list_add(s, 2);
    
    list *exp = list_init_empty();
    list_add(exp, 1);
    list_add(exp, 2);
    
    list_remove_all(s, 0);
    
    if (!equals(exp, s)) {
        fprintf(stderr, "list_remove_all([0, 1, 0, 2], 0) did not modify s correctly\n");
        return;
    }
}

void test05(void) {
    puts("running test05...");
    list *s = list_init_empty();
    list_add(s, 0);
    list_add(s, 1);
    list_add(s, 0);
    list_add(s, 2);
    list_add(s, 3);
    list_add(s, 4);
    list_add(s, 5);
    
    list *exp = list_init_empty();
    list_add(exp, 0);
    list_add(exp, 1);
    list_add(exp, 0);
    list_add(exp, 2);
    list_add(exp, 3);
    list_add(exp, 4);
    
    list_remove_all(s, 5);
    
    if (!equals(exp, s)) {
        fprintf(stderr, "list_remove_all([0, 1, 0, 2, 3, 4, 5], 5) did not modify s correctly\n");
        return;
    }
}

void test06(void) {
    puts("running test06...");
    list *s = list_init_empty();
    list_add(s, 0);
    list_add(s, 1);
    list_add(s, 0);
    list_add(s, 1);
    list_add(s, 1);
    list_add(s, 1);
    list_add(s, 2);
    
    list *exp = list_init_empty();
    list_add(exp, 0);
    list_add(exp, 0);
    list_add(exp, 2);
    
    list_remove_all(s, 1);
    
    if (!equals(exp, s)) {
        fprintf(stderr, "list_remove_all([0, 1, 0, 1, 1, 1, 2], 1) did not modify s correctly\n");
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
}