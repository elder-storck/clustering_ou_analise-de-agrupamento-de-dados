#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"Point.h"
#include"UF.h"

typedef struct aresta Aresta;

int MD_returnID1(Aresta *arestas, int index);
int MD_returnID2(Aresta *arestas, int index);
float MD_returnDistance(Aresta *arestas, int index);


char* Aloca_Nome(char *name);
Aresta* Distance_calculate_arestas(Ponto *pontos, int amountPontos, int amountCoordenadas, int amountArestas);
int comparar_Distancia(const void *x, const void *y);
void Distance_free_arestas(Aresta *arestas, int size);
void Display_Vector_Arestas(Aresta *arestas, int size);

void monta_arvore(int amountPontos, Aresta* arestas);