#include <stdio.h>

void printchars(const char s[]) {
    // complete this function here...
    int index = 0;

    while (s[index] != '\0'){

        printf("%d %c\n", index, s[index]);
        index++;
    }

    
}

int main(int argc, char *argv[]) {
    // assumes one command-line argument
    char *s = argv[1];
    printchars(s);
    return 0;
}