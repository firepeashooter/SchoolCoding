#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char *filename = "tmp2.txt";
    FILE *f = fopen(filename, "r");
    if (!f) {
        fprintf(stderr, "Could not open tmp.txt for reading");
        exit(1);
    }
    char buf[100];
    while (fgets(buf, 100, f)) {
        printf("%s", buf);
    }
    fclose(f);
}