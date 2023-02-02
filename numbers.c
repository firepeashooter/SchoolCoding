#include<stdio.h>
#include<math.h>



int subtract2sc_issafe(int x, int y){

    //Check Negative by sign bit and make sure that we also check that x and y are different signs

    //Grabs the size of int
    int size = sizeof(int);
    //Computes the difference of x and y
    int diff = x - y;
	
    //Converts the size into bits so we can calculate the upper/lowerbound
    int bits = size * 8;

    //Overflows if the result has the same sign as y
    if( (diff > 0 && y > 0) || (diff < 0 && y < 0)){
        return 0;
    }
    else{
        return 1;
    }


}

int main (int argc, char* argv[]){

//Tests Overflow
//printf(subtract2sc_issafe());

//Tests Underflow
printf("%i\n", subtract2sc_issafe(-2147483648, 1));
}

