#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // test for number of command line arguments and sign of first
    // command line argument here...
    if (argc != 2){

        fprintf(stderr, "Usage: epoch2time number-of-seconds\n");
        exit(1);
    }

    if (argv[1][0] == '-'){
        fprintf(stderr, "epoch2time: negative number of seconds\n");
        exit(2);
    } 



    // the following attempts to interpret argv[1] as an unsigned int
    unsigned int n = strtoul(argv[1], NULL, 10);
    
    // useful constants
    const unsigned int SEC_PER_MIN = 60;
    const unsigned int SEC_PER_HOUR = 60 * SEC_PER_MIN;
    const unsigned int HOUR_PER_DAY = 24;

    //Computer hour, minute and second times

    int hours = (n / SEC_PER_HOUR) % HOUR_PER_DAY;
    int remainder1 = n % SEC_PER_HOUR;
    int minutes = remainder1 / SEC_PER_MIN;
    int seconds = remainder1 % SEC_PER_MIN;

    //print the command line argument follow by the formatted time
    printf("%u = %02u:%02u:%02u\n", n, hours, minutes, seconds);

    
}