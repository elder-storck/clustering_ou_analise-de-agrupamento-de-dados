#include"methodFile.h"



FILE* Open_File(char *nameFile){
    /*Abrir o arquivo*/
    FILE *file;
    file = fopen(nameFile, "r");

    /*Testar Arquivo*/
    if(file == NULL){
        printf("\n ERRo 001: Função Open_File: Erro Ao abrir arquivo\n");
        exit(0);
    }
    return file; 
}



int Amount_Token(FILE *file){
    char linha[10000];
    char *token;
    
    /*Lê a Primeira Linha*/
    fgets(linha, 1000,file);
    
    /*Contando quantidade de tokens em uma linha*/
    int countColunas = 0;
    token = strtok(linha,",");
    while(token){
        countColunas++;
        token = strtok(NULL,",");
    }

    /*rebobina o ponteiro para o inicio do arquivo*/
    rewind(file);

    return countColunas;
}



int Amount_Line(FILE *file){
    int countLinha = 0;
    char c;

    /*enquanto não é fim do arquivo -> incrementa contador*/
    for (c = getc(file); c != EOF; c = getc(file)){ 
        if (c == '\n')  countLinha++;
    }
    
    /*rebobina o ponteiro para o inicio do arquivo*/
    rewind(file);
    return countLinha;
}




void Display_Vector(char **vector, int amountLine, int amountToken){
    for(int i=0; i<(amountLine*amountToken); i++){        
        if((i%amountToken) == 0){
            printf("ID   : %s\n",vector[i]);    //identificador de um ponto
        }else{
            printf("Coord: %s\n",vector[i]);    //coordenadas do ponto
        }
    }
    return;
}
void Free_Vector(char **vector, int amountLine, int amountToken){
    for(int i=0; i<(amountLine*amountToken); i++) free(vector[i]);
    free(vector);        
    return;
}


char** Mount_Vector(FILE *file, int amountLine, int amountToken){

    /*Declaração do vetor*/
    char** vector = (char**) malloc(sizeof(char*) * amountLine * amountToken);

    char *token;        //recebe dados entre linhas
    char *line = NULL;  //recebe todos os dados de uma linha
    size_t len =0;      //auxiliar

    int countAux =0;


    while((getline(&line, &len, file)) != -1){
  
        /* Primeira pesquisa por vírgula. */
        token = strtok(line, ",");

        /*ALocando espaço referente a identificador do ponto*/
        vector[countAux] = malloc((sizeof(char) * strlen(token)) +1);
        strcpy(vector[countAux],token);
 
        /*Pesquisando por mais virgula*/
        do{
            token = strtok('\0', ","); //Demais pesquisas por vírgula.
            if(token){                 //Se token diferente de NULL
                countAux++;
                /*ALocando valores referentes a coordenadas*/
                vector[countAux] = malloc((sizeof(char) * strlen(token)) +1);
                strcpy(vector[countAux],token);
            } 
        } while(token); //enquanto token != NULL

    countAux++;
    }
return vector;
}








