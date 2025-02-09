#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50

void printArray(int *index, int *array) {
    printf("The numbers are: ");
    for(*index = 0; *index < MAX; ++*index) {
        printf("%d ", array[*index]);
    }
    printf("\n");
}

void multiplyArray(int *index, int *array) {
    for(*index = 0; *index < MAX; ++*index) {
        array[*index] = array[*index] * 2;
    }
}

int main(int argc, char *argv[]) {
    int array[MAX];
    int i;
    int *pI = &i;
    int randomNumber;

    srand(time(NULL)); 

    for(*pI = 0; *pI < MAX; ++*pI) {
        randomNumber = rand() % 101;
        array[*pI] = randomNumber;
    }
        

    printf("The value of the address of the array (pointer) is: %p\n", array);
    printf("First integer in the array is (array[0]): %d\n", array[0]);
    printf("The last integer in the array is: %d\n", array[MAX - 1]);
    printf("The size of an integer (number of bytes) is: %zu\n", sizeof(int));
    printf("The size of the whole array in bytes is: %zu\n", sizeof(array));

    printArray(pI, array);
    multiplyArray(pI, array);
    printArray(pI, array);
}