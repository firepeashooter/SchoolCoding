#include <stdio.h>   
#include <stdlib.h>  
#include "a5.h"


void testQ1(){

	char string[] = "findthefirstelementindex";

	int index = strind(string, 'e');

	printf("First index is: %d\n", index);


}

void testQ2(){
	char string[] = "maxoccuringstringjjjjjjjjj";

	char result = strmaxfreq(string);

	printf("Max Occuring Character: %c\n", result);
}


void testQ3(){

	char str[] = "hello";
	char *rep = strrepeat(str, 4);
	puts(rep);

}


void testQ4(){

	char *str = malloc(27);     // IMPORTANT: MUST BE DYNAMICALLY ALLOCATED, CANNOT BE
                                // INITIALIZED FROM A STRING LITERAL

    for (char c = 'A'; c <= 'Z'; c++) {
        str[c - 'A'] = c;
    }
    str[26] = '\0';

    strselfcat(&str);           // str now points at a reallocated array
    puts(str);

}

void testQ5(){

	char str[] = "hello";
	strrmlast(str, 'l');
	puts(str);

}

void main(int argc, char const *argv[])
{
	// testQ1();
	// testQ2();
	// testQ3();
   	// testQ4(); 
	// testQ5();
}



