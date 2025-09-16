#include <stdio.h>
#include <string.h>

int main(void) {
	puts("Enter some text and press Enter");
	char str[10];
	char unused[10];
	char *res = fgets(str, 10, stdin);
	
	puts("You wrote:");
	int n = 0;
	while (res) {
		printf("%s", str);
		if (str[strlen(str) - 1] == '\n') {
			res = NULL;
		}
		else {
			res = fgets(str, 10, stdin);
		}
	}
	puts(unused);
}
