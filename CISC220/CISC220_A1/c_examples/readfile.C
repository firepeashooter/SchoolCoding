#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char *filename = "tmp.txt";
    FILE *f = fopen(filename, "r");
    if (!f) {
        fprintf(stderr, "Could not open tmp.txt for reading");
        exit(1);
    }
    int c;
    while ((c = fgetc(f)) != EOF) {
        putchar(c);
    }
    fclose(f);
}