#include<stdio.h>
#indclude<math.h>



int subtract2sc_issafe(int x, int y){

    //Grabs the size of int
    int size = sizeof(int)
    //Computes the difference of x and y
    int diff = x - y;

    //Converts the size into bits so we can calculate the upper/lowerbound
    int bits = size / 8;

    //Computes the upper and lower bound
    int lower_bound = - pow(2, (bits -1));
    int upper_bound = pow(2, (bits - 1))

    //Checks for overflow (if the difference is bigger or lower than +-2^(w-1)) where w is the number of bits
    if(diff <= lower_bound || dif >= upper_bound){
        return 0
    }
    else{
        return 1
    }


}

int main (int argc, char* argv[]){

//Tests Overflow
printf(subtract2sc_issafe())

//Tests Underflow
printf(subtract2sc_issafe())
}

