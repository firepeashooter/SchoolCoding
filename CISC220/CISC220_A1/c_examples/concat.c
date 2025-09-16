#include <stdio.h>
#include <string.h>

int main(void) {
    char s[11] = "01234";
    char t[] = "56789";
    
    // concatenate s and t
    // size of s must be big enough
    // to hold the final string plust
    // the null terminator
    strcat(s, t);
    printf("s : %s\n", s);
}