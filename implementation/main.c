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


    Point_free(pontos, amountLine, amountToken-1);
    Distance_free_arestas(arestas, size_arestas);
    free(node);
    fclose(arq);

return 0;

}
void escreveFile(Ponto *pontos, Node *nodes, char *nameFile, int amountPontos, int k){
    /*Abrir o arquivo*/
    FILE *file;
    file = fopen(nameFile, "w");

    /*Testar Arquivo*/
    if(file == NULL){
        printf("\n ERRo 001: Função Open_File: Erro Ao abrir arquivo\n");
        exit(0);
    }

    


    fclose(file);
}

