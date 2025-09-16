#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: index_of str char\n");
        exit(1);
    }
    char *str = argv[1];
    char c = argv[2][0];   // first character of the string argv[2]

    char *first = strchr(str, c);
    char *last = strrchr(str, c);
    if (first) {
        printf("first index : %lu\n", first - str);
        printf("last index  : %lu\n", last - str);
    }
}