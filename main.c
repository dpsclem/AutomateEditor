#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 80

char** readFileLines(char* path);



int main() {
   readFileLines("Langage.txt");
   return 0;
}


char** readFileLines(char* path) {

    char line[MAX_LINE_LENGTH] = {0};
    unsigned int line_count = 0;
    
    
    /* Open file */
    FILE *file = fopen(path, "r");
    
    if (!file)
    {
        perror(path);
    }
    
    while (fgets(line, MAX_LINE_LENGTH, file))
    {
        printf("line[%06d]: %s", ++line_count, line);
        
        if (line[strlen(line) - 1] != '\n')
            printf("\n");
    }
    
    if (fclose(file))
    {
        perror(path);
    }
}