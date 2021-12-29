#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define true 1
#define false 0


char** readFileLines(char* path);
char* ConcatWords(char *firstWord, char *secondWord);
bool IsWordEmpty(char *wordToCheck);
char *GetWordMirror(char *initialWord);
char *WordPuissance(char *initialWord, int puissance);