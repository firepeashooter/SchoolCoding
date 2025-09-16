#include <stdio.h>
#include <string.h>

// Probably need -std=c99 to compile
// gcc -std=c99 -o readkeybd readkeybd.c

int main(void) {
	puts("Enter some text and press Enter");
	char str[10];
	char unused[10];
	gets(str);
	puts("You wrote:");
	puts(str);
	puts(unused);
}
