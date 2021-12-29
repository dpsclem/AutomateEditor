#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define true 1
#define false 0

#define MAX_LINE_LENGTH 80

char** readFileLines(char* path);
char* ConcatWords(char *firstWord, char *secondWord);
bool IsWordEmpty(char *wordToCheck);


int main() {
    return 0;
}

char* ConcatWords(char *firstWord, char *secondWord){
    char *result = malloc(strlen(firstWord) + strlen(secondWord) + 1);

    strcpy(result, firstWord);
    strcat(result, secondWord);

    return result;
}

bool IsWordEmpty(char *wordToCheck) {
    if (strlen(wordToCheck) == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
