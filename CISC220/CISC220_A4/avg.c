#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    if (argc == 1){
        printf("0\n");
        return 0; 
    }
    double total = 0;

    for (int i = 1; i < argc; i++){
        
    
        char *cur = argv[i];
        double val = atof(cur);

        total = total + val;

    }

    double result = total / (argc - 1);

    printf("The average is: %f\n", result);

    
}
