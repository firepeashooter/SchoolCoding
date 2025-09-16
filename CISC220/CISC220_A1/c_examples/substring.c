#include <stdio.h>
#include <string.h>

int main(void) {
    char s[] = "0123456789";
    char t[10];
    // copy 345 into t
    strncpy(t, s + 3, 3);
    // add the null terminator!
    // failure to do so a major source of bugs
    t[3] = '\0';
    printf("t : %s\n", t);
}