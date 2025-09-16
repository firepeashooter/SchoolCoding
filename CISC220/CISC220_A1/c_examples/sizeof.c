#include <stdio.h>
#include <string.h>

int main(void) {
    char s[] = "abc";
    printf("size   : %lu\n", sizeof(s));
    printf("length : %lu\n", strlen(s));

    char *s2 = "abc";
    printf("size   : %lu\n", sizeof(s2));  // 8
    printf("length : %lu\n", strlen(s2));

    void *p = NULL;
    printf("size   : %lu\n", sizeof(p));  // 8
}