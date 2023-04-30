#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"../include/outFile.h"
#include"../include/edgeFile.h"
#include"../include/UF.h"
#include"../include/Point.h"
#include"../include/utility.h"



int main(int argc, char *argv[]){

    char* inputFile = argv[1];  //nome do arquivo Entrada
    int k = atoi(argv[2]);      //Quantidade de Grupos
    char* outputFile = argv[3]; //nome do arquivo de sáida
    
    FILE *arq = utility_openFile(inputFile,"r");    //Abre o arquivo e testa

    int amountPontos = utility_amountLine(arq);         //Conta quantidade de linhas do Arquivo
    int amountCoords = (utility_amountToken(arq)) -1;   //Conta quantidade de colunas do Arquivo
    rewind(arq);                                    //rebobina o ponteiro de leitura do arquivo
    
    Point *list_points = Point_readFile(arq, amountPontos, amountCoords); //le arquivo e preenche lista de pontos
    fclose(arq);
    
    int size_arestas =0;                                //quantidade de arestas da árvore
    for(int i=0; i<amountPontos; i++) size_arestas += i;//contando quantidade de arestas da árvore

    //calcula distância e monta lista de struct arestas
    Edge *list_edge = Edge_initAndCaculate(list_points, amountPontos,amountCoords, size_arestas);
    
    // executa algoritimo de kruskal e monta lista de struct tree
    Tree *list_tree = monta_arvore(list_edge,list_points, k, amountPontos, size_arestas);
    Edge_free(list_edge);

    //imprime os dados no arquivo
    outFile_write(list_points,list_tree,outputFile,amountPontos, k);

    //liberando estruturas
    Point_free(list_points, amountPontos);
    UF_free(list_tree, amountPontos);
    return 0;

}



