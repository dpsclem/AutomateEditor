#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 80

char** readFileLines(char* path);
char* ConcatWords(char *firstWord, char *secondWord);


int main() {
    return 0;
}

char* ConcatWords(char *firstWord, char *secondWord){
    char *result = malloc(strlen(firstWord) + strlen(secondWord) + 1);

    strcpy(result, firstWord);
    strcat(result, secondWord);

    return result;
}
