#include <stdio.h>
#include <string.h>

int main(void) {
    char s[16] = { 'a', 'b', 'c', '\0' };
    printf("size   : %lu\n", sizeof(s));
    printf("length : %lu\n", strlen(s));
}