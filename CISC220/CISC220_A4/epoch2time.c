#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // test for number of command line arguments and sign of first
    // command line argument here...



    // the following attempts to interpret argv[1] as an unsigned int
    unsigned int n = strtoul(argv[1], NULL, 10);
    
    // useful constants
    const unsigned int SEC_PER_MIN = 60;
    const unsigned int SEC_PER_HOUR = 60 * SEC_PER_MIN;
    const unsigned int HOUR_PER_DAY = 24;

    // compute clocktime corresponding to timestamp n here...

    
}