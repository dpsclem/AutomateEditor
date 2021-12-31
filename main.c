#include "main.h"
#define LINEMAX = 2

int main() {
    mainMenu();
    /*
    int statesQuantity = 2;
    Lien lien1;
    lien1.etatActuel = "e1";
    lien1.etatLien = "e3";
    lien1.lettreTransition = "b";

    Lien lien2;
    lien2.etatActuel = "e1";
    lien2.etatLien = "e3";
    lien2.lettreTransition = "b";

    Lien* matrice = calloc(statesQuantity,sizeof(Lien));
    matrice[0] = lien1;
    matrice[1] = lien2;
    for (int i = 0; i < 2; i++) {
        printf("%s %s %s\n", matrice[i].etatActuel, matrice[i].etatLien,  matrice[i].lettreTransition);
    }
    */
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
    if ((strstr(string, "+") == NULL) & (strstr(string, "*") == NULL)) {return true;}
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
            printf("Reading error, file doesn't exist. Returning to main menu.\n");
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
    
    scanf("Tap ENTER to end.");
    //devrait retourner la struct AEF + path
    return "";
}

void mainMenu(){
    //choix de l'action à réaliser
    int* act = malloc(sizeof(int) *2);

    printf("Choose the action:\n- 0: End program\n- 1: Import automaton\n- 2: Create automaton\n");
    scanf("%d",act);
    
    if(act[0] == 0){
        printf("Program will close itself.");
        exit(-1);
    }else if(act[0] == 1){
        //256 caractères max : limite de windows
        char filename[256];

        printf("Input the path + extension to the file you wan't to import.\n");
        scanf("%s",filename);

        //debug
        printf("%s\n",filename);
        
        //Sinon on applique la fonction de lecture caractère par caractère du fichier.
        loadAutomate(filename);
    }else if(act[0] == 2){
        //On lance le menu de création
        CreationMenu();

    }else{

        printf("Chosen action was not recognized. Please specify a correct action.\n");
        mainMenu();
    }
}

//Fonction pour créer l'AEF de toutes pièces
//Est un choix dans le mainMenu
void CreationMenu(){
    printf("-Automaton creation menu-\n");

    //Initialisation d'une instance de struct
    AEF aef;

    //Choix du nombre d'états de l'AEF
    int statesQuantity;
    printf("How many states do you wan't ? (Integer only)\n");
    
    //On va récupérer le int nombre d'états
    scanf("%d",&statesQuantity);
    //vérification que bien un int et pas autre chose.
   

    /*
    char *p, buf[2];
    do{
        if(!fgets(buf, sizeof buf, stdin))
        break;

        //On enlève \n
        buf[strcspn(buf,"\n")] = 0;
        statesQuantity = strtol(buf, &p,10);
    }while (p != buf + strlen(buf));
    */

    //On peut display les états créés
    printf("%d states were created\n",statesQuantity);
    


    //Choix du nombre de lettres de l'alphabet
    int lettersQuantity;
    printf("\nHow many letters in your alphabet ? (Integer only)\n");
    scanf("%d",&lettersQuantity);
    printf("%d letters were created.\n",lettersQuantity);

    //Le nom des états est normalisé et s'écrit "e"+"numéro"
    //Ajoute directement dans la ligne etats de l'AEF les états générés
    /*
    char* states = malloc(statesQuantity*sizeof(char)+1);
    for(int i =0; i < statesQuantity; i++){
        states[i] = ("e%d",&i);
        //printf(states[i]);
    }
    aef.etats = states;
    */

    //Ajoute les lettres à l'alphabet;
    char* alphabet = malloc(lettersQuantity*sizeof(char)+1);
    for(int i = 0; i < lettersQuantity; i++){
        printf("Input the symbol for letter %d. (Only 1 character)\n",i);
        scanf("%s",&alphabet[i]);
        //alphabet[i] = i + 61;
    }
    //Et peuple l'alphabet de l'AEF
    aef.alphabet = alphabet;

    //Ajout état initial
    printf("What state is the initial state ?\n");
    scanf("%s", aef.etat_initial);

    printf("Do you want to add a final state ? (y/n)\n");
    char answer;
    scanf("%s",&answer);
    while(answer != 'y' || answer != 'n'){
        printf("Do you want to add a final state ? (y/n)\n");
    }
    
    if(answer == 'y'){
        //On a dit qu'on souhaitait des états finaux
        //demander le nombre d'états finaux
        int finalStatesQuantity;
        printf("How many final states do you want ?\n");
        scanf("%d",&finalStatesQuantity);

        //Ajout état(s) final(finaux)
        char* finalStates = malloc(finalStatesQuantity*sizeof(char)+1);
        //On print les différents états:
        printf("States :\n");
        for(int i = 0; i < statesQuantity; i++){
            printf("%d\n",aef.etats[i]);
        }
        
        /*
        for(int i = 0; i < finalStatesQuantity; i++){
            printf("Write the number of the state you want to be final.");
            int state;
            scanf("%d",&state);
            //On vérifie que l'état n'existe pas dans final state
            for(int j = 0; j < strlen(finalStates); j++){
                if(finalStates[j]==state){
                    printf("State is already designated as final");
                }else{
                    finalStates[i] = state;
                }
            }
        }
        */

        int i = 0;
        while(i < finalStatesQuantity){
            printf("Write the number of the state you want to be final.");
            int state;
            scanf("%d",&state);
            //On vérifie que l'état n'existe pas dans final state
            for(unsigned j = 0; j < strlen(finalStates); j++){
                if(finalStates[j]==state){
                    printf("State is already designated as final");
                    break;
                }else{
                    finalStates[i] = state;
                    i+=1;
                }
            }
        }
    } 
    
    
    

    //On display tout afin de permettre à l'utilisateur de vérifier si il ne s'est pas trompé.

    //On va maintenant passer à la création des liaisons
    
    /*
    Lien currentLink;
    char nextRep = "o";
    int i =0;
    do
    {
        i +=1;
        printf("Etat : e%d\n", i);
        currentLink.etatActuel = i;
        scanf("Avec quel etat souhaitez vous créer une liaison : %d", currentLink.etatLien);
        scanf("Lettre de transition : %s", currentLink.lettreTransition);
        aef.transitions = malloc(sizeof(currentLink));
        scanf("Continuer ? o/n : %s", nextRep);

    }
    while (nextRep ="o");
    */

}



