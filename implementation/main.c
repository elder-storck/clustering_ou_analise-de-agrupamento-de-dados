#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int QuantLinha(FILE *arq);
int QuantColuna(FILE *arq);
void inputArquivo(char *inputArq);

int main(int argc, char *argv[]){
    char* inputArq = argv[1];   //arquivo entrada
    int k = atoi(argv[2]);      //tamanho de K
    char* outputArq = argv[3];  //arquivo saída
    

    inputArquivo(inputArq);
    
    if(argc != 4) printf("Entrada Inválida!!\n");

//    if(argv[0])
return 0;
}
void inputArquivo(char *inputArq){
    FILE *arq;
    char *token;
    int amountLine=0, amountToken =0;
    
    /*Abre o arquivo e testa*/
    arq = fopen(inputArq, "r");
    if(arq == NULL){
        printf("\n FUDEOOO -Arquivo FUdidu\n");
        return;
    }
    amountLine  = QuantLinha(arq);
    amountToken = QuantColuna(arq);
    printf("%d %d\n",amountLine, amountToken);
    
    char tag[amountLine][100];
    float vetor[amountLine][amountToken];

    //getline(linha, ,)
    rewind(arq);

    char *line = NULL;
    size_t len =0;
    //getline(&line, &len,arq);
    //printf("%s \n",line);

    int countAuxLine =0;
    int countAuxcoluna =0;
    const char s[2] = ",";

    while((getline(&line, &len, arq)) != -1){
        printf("%s",line);
        token = strtok(line,s);
        /*for(int i=0; i<(amountLine-1); i++){
            token = strtok(line,",");
            printf("%s  ",token);
        }*/

        //token = fscanf()
        //token = strtok(line,"\n");
        printf("%s  ",token);

        countAuxLine++;
        //printf("\n%s\n",token);    
    }

/*
    char *
    token = strtok(arq,",");
    while(!feof(arq)){
        line = fgets(line,1000,arq);
        token = strtok()
    }




    for(int i=0; i<amountLine; i++){
        //fgets(line, 1000, arq);
        //printf("%s\n",line);
        for(int j=0; j<(amountToken-1); j++){
            //printf("%d ",j);
            fscanf(arq, "%s[^,]",token);
            printf("%s\n",token);
        }

    }



*/

//    le_Linha(arq);
        //printf("%d\n",countLinha);

    //fseek(arq, 0, SEEK_SET);

    //float vetor[countLinha][countColunas];

    fclose(arq);
}
int QuantColuna(FILE *arq){
    char linha[1000];
    char *token;
    /*Lê a Primeira Linha*/
    fgets(linha, 1000,arq);
    
    /*Contando quantidade de tokens em uma linha*/
    int countColunas = 0;
    token = strtok(linha,",");
    while(token){
        countColunas++;
        token = strtok(NULL,",");
    }
    rewind(arq);
    //fseek(arq, 0, SEEK_SET);
    return countColunas;
}

int QuantLinha(FILE *arq){
    /*Contando quantidade de Linhas*/
    int countLinha = 0;
    char c;
    for (c = getc(arq); c != EOF; c = getc(arq)){
        if (c == '\n')  countLinha++;
    }
    //fseek(arq, 0, SEEK_SET);
    rewind(arq);
    return countLinha;
}
