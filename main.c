#include "main.h"

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

char* GetWordMirror(char *initialWord) {
    int initialWordLen = strlen(initialWord);
    char *mirroredWord = malloc(initialWordLen + 1);
    for (int i = initialWordLen; i >= 0; i--)
    {
        mirroredWord[initialWordLen-i] = initialWord[i-1];
    }
    
    return mirroredWord;
}

char* WordPuissance(char *initialWord, int puissance) {
    if (puissance == 0) {return "";}
    char *finalWord = malloc(strlen(initialWord)*puissance + 1);
    strcpy(finalWord, initialWord);

    for (int i = 0; i < puissance-1; i++)
    {
        strcat(finalWord, initialWord);
    }

    return finalWord;
}

bool IsStringProducingFinishedWord(char *string) {
    if (strstr(string, "+") == NULL & strstr(string, "*") == NULL) {return true;}
    else {return false;}
}

bool IsWordInAlphabet(char* word, char* alphabet) {
    char* currentChar = word;
    while(*currentChar) 
    {
        if (!strchr(alphabet, *currentChar)) {return false;}
        currentChar++;
    }
    return true;
}

char* loadAutomate(char* path){
    //ouvre le fichier
    FILE* import_file = fopen(path,"r"); //read only
    //si fichier null, doit revenir au mainmenu
    if(import_file == NULL){
            printf("Erreur, le fichier recherché n'existe pas\n");
            mainMenu();
    }

    //Devrait initialiser une variable/ struct représentant l'automate du txt
    //TODO

    printf("Lecture...\n\n");
    //buffer contenant la ligne à l'instant t, en changeant à l'instant t+1

    char c;
    do{
        c= fgetc(import_file);
        if(feof(import_file)){
            fclose(import_file);
            exit(-1);
        }
        printf("%c",c);
    }while(1);
    
    fclose(import_file);
    
    scanf("Appuyez sur entrée pour terminer...");
    //devrait retourner la struct AEF + path
    return "";
}

char* mainMenu(){
    

    //choix de l'action à réaliser
    int* act = malloc(sizeof(int) *2);

    printf("Choisissez l'action à réaliser:\n- 0: Quitter le programme\n- 1: Importer un automate\n");
    scanf("%d",act);
    if(act[0] == 0){
        printf("Le programme va fermer");
        exit(-1);
    }else if(act[0] == 1){
        //256 caractères max : limite de windows
        char filename[256];

        printf("Donnez le répertoire+nom du fichier que vous souhaitez traiter\n");
        scanf("%s",filename);

        //debug
        printf("%s\n",filename);
        
        //Sinon on applique la fonction de lecture caractère par caractère du fichier.
        loadAutomate(filename);
    }else{

        printf("L'action choisie n'est pas reconnue. Le programme va fermer.\n");
    }
}