#include "stdlib.h"
#include "stdio.h"

int main(int argc, char *argv[]){
    int *test = malloc(sizeof(int)); 
    int i = 0;
    int k;
    k = 3 + 4;
    k = x + y * 3;
    k = ((z + w) / 2) * 3;

    if (0) {
      k = 3;
    }

    while(i < 10){
        test[i] = i;
        i++;
    }

    test[0] = 100 # ; // explicit change  

    for(int i = 0; i < 10; i++){
        printf("test[%d]: %d\n", i, test[i]);
    }
    free(test);
    exit(EXIT_SUCCESS); // return 0 
}
