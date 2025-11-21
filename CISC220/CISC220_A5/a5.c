#include <stdio.h>   
#include <stdlib.h>  
#include <string.h>
#include "a5.h"





int strind(const char *s, char c){


//Loop through the string s 
for (int i = 0; s[i] != '\0'; i++){

    if(s[i] == c){
        return i;
    }
}

return -1;

};



char strmaxfreq(const char *s){


    //Empty string case
    if(s[0] == '\0'){
        return '\0';
    }

    //Basically our dictionary of all possible chars
    int freq[256] = {0};

    //loop throught the string to add frequencies to the table
    for (int i = 0; s[i] != '\0'; i++){
        freq[s[i]]++;
    }

    //initializing starting values
    int max_count = 0;
    int max_char = '\0';

    //loop throught the string to find the highest value
    for (int i = 0; s[i] != '\0'; i++){

        if (freq[s[i]] > max_count){
            max_count = freq[s[i]];
            max_char = s[i];
        }
    }

    return max_char;

};

char *strrepeat(const char *s, size_t n){

    //make a string that can hold the biggest string we need
    size_t len = strlen(s);
    int capacity = (len * n) + 1;

    char* dest = calloc(capacity, sizeof(char));
    char* p = dest;

    for (int i = 0; i < (len * n); i++){
        *p = s[i % len];
        p++;
    }

    return dest;

};

void strselfcat(char **s){

    size_t n = strlen(*s);

    char* s_new = realloc(*s, 2 * n + 1);
    if (!s_new){
        fprintf(stderr, "Your not smart enough to understand this error");
        return;
    }

    memcpy(s_new + n, s_new, n);

    //add null terminator to the new string
    s_new[2 * n] = '\n';

    *s = s_new;

};

void strrmlast(char *s, char c){

    //find the index of the last occurence
    char* index = strrchr(s, c);

    if (index == NULL){
        return;
    };

    memmove(index, index+1, strlen(index));

};


;
