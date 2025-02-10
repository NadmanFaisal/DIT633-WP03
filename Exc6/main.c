#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char string[21];
    char destination[21];
    printf("Provide as input: ");
    fgets(string, sizeof(string), stdin);
    printf("String is: %s\n", string);

    strcpy(destination, string);
    printf("Destination is: %s\n", destination);
}