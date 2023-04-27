#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct aresta Aresta;

char* retorna_ID1(Aresta *arestas,int index);
char* retorna_ID2(Aresta *arestas,int index);
float retorna_distance(Aresta *arestas,int index);

char* Aloca_Nome(char *name);
Aresta* Calculate_Distance(char **vector, int amountLine, int amountToken, int size);
int comparar_Distancia(const void *x, const void *y);
void Free_Arestas(Aresta *arestas, int size);
void Display_Vector_Arestas(Aresta *arestas, int size);