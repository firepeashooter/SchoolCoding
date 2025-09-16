#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str[80];
    strcpy(str, ":::field1::field2:field3:::field4");
    size_t len = strlen(str);
    char *t = strtok(str, ":");
    while (t) {
        puts(t);
        t = strtok(NULL, ":");
    }

    puts("what did strtok do to str?");
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c) {
            printf("%c\n", c);
        }
        else {
            printf("null\n");
        }
    }
}