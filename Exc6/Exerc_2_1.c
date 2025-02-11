#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 20

void copyString(char* destString, char* srcString){
    char *p_to_Str = srcString;
    int lenOfStr = strlen(srcString); 

    for(int i = 0; i < lenOfStr; i++){
        *destString = *p_to_Str;
        destString++;
        p_to_Str++;
    }

}

int main(int argc, char* argv[]){

    printf("%s","Input your string: ");
    char string[MAX];
    fgets(string, MAX, stdin);
    fflush(stdin);

    char anotherString[MAX];
    strcpy(anotherString, string);

    char anotherString2[MAX]; 
    copyString(anotherString2, string);

    printf("Here is copied string from library: %s", anotherString);
    printf("Here is copied string from a local function: %s", anotherString2);

    


}