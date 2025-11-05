#include <stdio.h>
#include "strtoi.h"

int main(int argc, char *argv[]) {
    // assumes one command-line argument
    char *s = argv[1];
    int val = strtoi(s);
    printf("%d\n", val);
    return 0;
}