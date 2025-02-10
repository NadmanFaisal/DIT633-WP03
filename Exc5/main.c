#include <stdlib.h> // library for srand and rand
#include <stdio.h> // library for printf
#include <time.h> // library for time

/*

Improvements:-

Question:-

Aks Ionel why it is displaying 8 bits for the sizeof

*/

#define MAX 3 // MAX is 3 to hold 3 elements in the array

int main(int argc, char* argv[]){

    int *array = malloc(MAX * sizeof(int)); // allocate 3 elements in heap
    int numberInTheArray = 0; // num in array
    int multipliedByTwo = 0; // num in array * 2
    int *ptr = array; // pointer copy to the array

    srand(time(NULL)); // initialize rand to generate new number

    for(int i = 0; i < MAX; i++){ // for each element in the array
        array[i] = rand() % 99 + 1; // assing rand val
    }

    printf("The value of the address of the array (pointer) is: %p\n", array); // print address of pointer
    printf("First integer in the array is (array[0]): %d\n", array[0]); // print first integer of the array
    printf("The last integer in the array is: %d\n", array[MAX - 1]); // print last integer in the array
    printf("The size of an integer (number of bytes) is: %ld\n", sizeof(int)); // print size of int in bytes
    printf("The size of the whole array in bytes is: %ld\n\n", sizeof(array));  // print whole array in bytes
    // ask about sizeof(int) * MAX

    for(int i = 0; i < MAX; i++){ // for each num in array
        printf("The value of the current index is: %d\n", *ptr); // print out the value in the current index
        numberInTheArray = *ptr; // store the value in variable
        multipliedByTwo = numberInTheArray * 2; // multiply it and store in variable
        printf("The value of the current index multiplied by two is: %d\n\n", multipliedByTwo); // print value multiplied by two
        ptr++; // move to next ptr
    }

    free(array); // free the allocated memory.

}