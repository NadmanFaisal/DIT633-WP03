#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 10
#define MIN_RANGE 1
#define MAX_RANGE 99

int main(int argc, char* argv[]){

    int array[MAX] = {0};
    srand(time(0));
    
    
    for(int i = 0; i < MAX ; i++){

        int randNum = (rand() % MAX_RANGE) + MIN_RANGE;
        array[i] = randNum;
        printf("%d", array[i]);
        printf(" ");
    }



    printf("\nThe value of the address of the array (pointer) is: %p\n", &array);
    printf("First integer in the array is (array[0]): %d\n", *array);
    printf("The last integer in the array is: %d\n", array[MAX-1]);
    printf("The size of an integer (number of bytes) is: %lu\n", sizeof(array)/sizeof(array[0]));
    printf("The size of the whole array in bytes is: %ld\n", sizeof(array));

}