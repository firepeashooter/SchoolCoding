#include <stdbool.h>
#include "strtoi.h"

int chartoi(char c) {
    int i = c - '0';
    if (i < 0 || i > 9) {
        return -1;
    }
    return i;
}

int strtoi(const char s[]) {

    int index = 0;
    int result = 0;
    int isNegative = 0;

    //checks if the string starts with -, + or a digit
    if (s[0] == '-' || s[0] == '+' || chartoi(s[0]) != -1){

        //we have to start after the sign if there is one
        if(s[0] == '-' || s[0] == '+'){
            index ++;
        }

        //Check if the sign is negative so we can negate the number at the end
        if (s[0] == '-'){
            isNegative = 1;
        }


        while(s[index] != '\0'){
    
            //converted char to integer       
            int charInt = chartoi(s[index]);
            
            //if chartoi returns -1 then end the while and return 0
            if (charInt == -1){

                if (isNegative){
                    return result * -1;
                }
                return result;
            }
    
            //builds the number from all the char conversions
            result = result * 10 + charInt;
    
            index++;
        }

        if (isNegative){
            return result * -1;
        }

        return result;


    }

    return 0;

    
}
