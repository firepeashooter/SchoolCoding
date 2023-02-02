#include<stdio.h>
#include<math.h>



int subtract2sc_issafe(int x, int y){
    int diff = x-y;

    //Overflows if x and ys sign are different and if the result has the same sign as y
    if( (x > 0 && y < 0) || (x < 0 && y > 0)){
    
    //Overflows if the result has the same sign as y
        if( (diff > 0 && y > 0) || (diff < 0 && y < 0)){
            return 0;
        }
        else{
            return 1;
        }
    }

    //Twos compliment subtraction never overflows when the signs are the same  therefore we always return 1
    return 1;
}

int main (int argc, char* argv[]){

//Tests Overflow
printf("%i\n", subtract2sc_issafe(2147483647, -5));

//Tests Underflow
printf("%i\n", subtract2sc_issafe(-2147483648, 5));

//Tests Not Overflow if signs are different
printf("%i\n", subtract2sc_issafe(-10, 4));

//Tests Not overflow if the signs are the same
printf("%i\n", subtract2sc_issafe(10, 4));
}

