#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"methodFile.h"
#include"methodDistance.h"
#include"UF.h"




int main(int argc, char *argv[]){
    /*Arquivo Entrada*/
    char* inputFile = argv[1];
    /*Quantidade de Grupos*/
    int k = atoi(argv[2]);
    /*Arquivo saída*/
    char* outputFile = argv[3];
    
    /*Abre o arquivo e testa*/
    FILE *arq = Open_File(inputFile);

    /*Conta quantidade de linhas do Arquivo*/
    int amountLine  = Amount_Line(arq);
    /*Conta quantidade de colunas do Arquivo*/
    int amountToken = Amount_Token(arq);
    rewind(arq);
    //printf("%d %d\n",amountLine, amountToken);
    
    /*Vetor com os pontos e suas coordenadas*/
    char** vector = Mount_Vector(arq, amountLine, amountToken);
    
    /*Quantidade de Arestas*/
    int size_arestas =0;
    for(int i=0; i<amountLine; i++) size_arestas += i;
    
    /*Vetor arestas (ID1, ID2, tamanho aresta)*/
    Aresta* arestas = Calculate_Distance(vector, amountLine, amountToken, size_arestas);
    



    Free_Vector(vector, amountLine, amountToken);
    Free_Arestas(arestas, size_arestas);
    fclose(arq);

return 0;

}

