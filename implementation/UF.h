#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct node Node;

int UF_returnID(Node *nodes,int index);

void UF_display(Node *nodes, int size);


// Inicializa estrutura com N objetos numerados de 0 a N-1.
Node* UF_init(int amountPontos);

// Adiciona uma conexao entre p e q.
void UF_union(Node *node, int p, int q);

// Retorna o identificador do componente de p (entre 0 a N-1).
int UF_find(Node *node, int i);

// Os objetos p e q estao no mesmo componente?
bool UF_connected(Node *node, int p, int q);

void UF_free(Node *node);