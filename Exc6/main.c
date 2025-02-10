#include <stdio.h>
#include <string.h>

#define MAX 21

int getLength(char *string) {
    int counter = 0;
    while(string[counter] != '\0' && string[counter] != '\n') {
        counter++;
    }
    printf("counter: %d\n", counter);
    return counter;
}

void stringCopy(char *destination, char *source) {
    int stringLength = getLength(source);
    printf("String length in method: %d\n", stringLength);

    for (int i = 0; i <= stringLength; i++) {
        if(i == stringLength) {
            destination[i] = '\0';
            break;
        }
        destination[i] = source[i];   
    }
}

int main(int argc, char *argv[]) {
    char string[MAX];
    char destination[MAX];
    char destination2[MAX];

    printf("Provide as input: ");
    fgets(string, sizeof(string), stdin);
    printf("String is: %s\n", string);

    strcpy(destination, string);
    printf("Destination1 is: %s\n", destination);

    stringCopy(destination2, string);
    printf("Destination 2: %s\n", destination2);
}