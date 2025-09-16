#include <stdio.h>
#include <string.h>

int main(void) {
    char s[11] = "01234";
    char t[] = "5678901234";
    
    // oops, appends 10 characters onto s
    // instead of ensuring that s has no
    // more than 10 characters
    strncat(s, t, 10);
    printf("s : %s\n", s);
    printf("t : %s\n", t);
}