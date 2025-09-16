#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen("formatted.txt", "w");
    fprintf(f, "char         : %c\n", 'a');
    fprintf(f, "int          : %d\n", -100);
    fprintf(f, "unsigned int : %u\n", 1999);
    fprintf(f, "long         : %ld\n", LONG_MAX);
    fprintf(f, "double       : %f\n", 1.0);
    fprintf(f, "string       : %s\n", "hello");
    fprintf(f, "mix of values: %c%d %s\n", 'c', 99, "wheee!");
    fclose(f);
}