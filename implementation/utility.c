#include"../include/utility.h"


FILE* utility_openFile(char *nameFile, char *action){
    //Abrir o arquivo/
    FILE *file;
    file = fopen(nameFile, action);

    //Testar Arquivo/
    if(file == NULL){
        printf("\n ERRo 001: Função Open_File: Erro Ao abrir arquivo\n");
        exit(0);
    }
    return file; 
}


char* utility_alocName(char *name){
    //aloca o nome e copia o nome para o ponteiro
    char* nameReturn = malloc((strlen(name) *sizeof(char)) +1);
    strcpy(nameReturn, name);
    return nameReturn;
}


int utility_amountToken(FILE *file){
    char linha[500];
    char *token;
    
    /*Lê a Primeira Linha*/
    fgets(linha, 500,file);
    
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


int utility_amountLine(FILE *file){
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

