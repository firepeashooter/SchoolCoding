#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen("tell.txt", "r");
    char c;
    long pos = ftell(f);
    while ((c = fgetc(f)) != EOF) {
        printf("%c : position = %ld\n", c, pos);
        pos = ftell(f);
    }
    fclose(f);
}