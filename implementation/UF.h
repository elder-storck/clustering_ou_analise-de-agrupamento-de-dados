#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include"Point.h"

typedef struct node Node;


char* UF_returnName(Node *nodes,int index);

int UF_returnID(Node *nodes,int index);

void UF_display(Node *nodes, int size);


// Inicializa estrutura com N objetos numerados de 0 a N-1.
Node* UF_init(int amountPontos, Ponto *pontos);

Node* UF_initCopy(Node *nodes, int indexInit, int size);

// Adiciona uma conexao entre p e q.
void UF_union(Node *node, int p, int q);

// Retorna o identificador do componente de p (entre 0 a N-1).
int UF_find(Node *node, int i);

// Os objetos p e q estao no mesmo componente?
bool UF_connected(Node *node, int p, int q);



void UF_ordenaPorPai(Node *nodes, int amountNodes);

int comparar_name(const void *x, const void *y);


void UF_ordenaPorName(Node *nodes, int amountNodes, int index);

void UF_free(Node *nodes, int amountNodes);

