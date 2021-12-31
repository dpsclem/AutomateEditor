
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define true 1
#define false 0


char** readFileLines(char* path);
char* ConcatWords(char* firstWord, char* secondWord);
bool IsWordEmpty(char* wordToCheck);
char* GetWordMirror(char* initialWord);
char* WordPuissance(char* initialWord, int puissance);
bool IsStringProducingFinishedWord(char* string);
bool IsWordInAlphabet(char* word, char* alphabet);
void mainMenu();
void CreationMenu();
char* loadAutomate(char* path);


struct Lien{
    int etatActuel;
    int etatLien;
    char lettreTransition;
};
typedef struct Lien Lien;

struct AEF{
    char *alphabet;
    char *etats;
    char *etat_initial;
    char *etat_final;
    Lien* transitions;
};
typedef struct AEF AEF;

