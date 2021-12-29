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



// char** readFileLines(char* path) {

//     char line[MAX_LINE_LENGTH] = {0};
//     unsigned int line_count = 0;
    
    
//     /* Open file */
//     FILE *file = fopen(path, "r");
    
//     if (!file)
//     {
//         perror(path);
//     }
    
//     while (fgets(line, MAX_LINE_LENGTH, file))
//     {
//         printf("line[%06d]: %s", ++line_count, line);
        
//         if (line[strlen(line) - 1] != '\n')
//             printf("\n");
//     }
    
//     if (fclose(file))
//     {
//         perror(path);
//     }
// }

