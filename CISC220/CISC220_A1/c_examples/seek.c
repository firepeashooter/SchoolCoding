#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen("tell.txt", "r");
    char buf[4];
    while (1) {
        puts("Enter a position to seek to: ");
        fgets(buf, 4, stdin);
        int pos = atoi(buf);
        if (pos < 0) {
            break;
        }
        if (pos >= 0 && pos < 24) {
            fseek(f, pos, SEEK_SET);
            char c = fgetc(f);
            printf("found : %c at position : %d\n", c, pos);
        }
    } 
    fclose(f);
}