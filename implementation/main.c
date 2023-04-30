#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"methodFile.h"
#include"methodDistance.h"
#include"UF.h"
#include"Point.h"



int main(int argc, char *argv[]){
    
    
    
    
    /*Arquivo Entrada*/
    char* inputFile = argv[1];
    /*Quantidade de Grupos*/
    int k = atoi(argv[2]);
    if(k <= 0){
        printf("\n\nERRO 00: Número de grupos inválido\n\n");
        exit(1);
    } 
    /*Arquivo saída*/
    char* outputFile = argv[3];
    



    /*Abre o arquivo e testa*/
    FILE *arq = Point_open_file(inputFile);

    /*Conta quantidade de linhas do Arquivo*/
    int amountLine  = Point_amount_line(arq);
    /*Conta quantidade de colunas do Arquivo*/
    int amountToken = Point_amount_token(arq);
    rewind(arq);
    
    /*Vetor com pontos*/
    Ponto *pontos = Point_le_file(arq, amountLine, amountToken-1);
    //Point_display(pontos, amountLine, amountToken-1);
    /*Montar vetor com as distância*/
    int size_arestas =0;    ///***********calcular ********//
    for(int i=0; i<amountLine; i++) size_arestas += i;  
    Aresta *arestas = Distance_calculate_arestas(pontos, amountLine,amountToken-1, size_arestas);
    //Display_Vector_Arestas(arestas, 10);


    Node* node = monta_arvore(arestas,pontos, k, amountLine, size_arestas);
    //UF_display(node, amountLine);

    escreveFile(pontos,node,outputFile,amountLine, k);

    //UF_free() liberar names
    Point_free(pontos, amountLine, amountToken-1);
    Distance_free_arestas(arestas, size_arestas);
    
    UF_free(node, amountLine);
    fclose(arq);

return 0;

}



