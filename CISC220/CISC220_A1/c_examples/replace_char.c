#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: replace_char file targetchar replacementchar\n");
        exit(1);
    }
    FILE *f = fopen(argv[1], "r+");
    char target = argv[2][0];
    char replace = argv[3][0];
    char c;
    while ((c = fgetc(f)) != EOF) {
        if (c == target) {
            fseek(f, -1, SEEK_CUR);
            fputc(replace, f);
        }
    }
    fclose(f);
}