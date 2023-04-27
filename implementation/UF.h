#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

// Inicializa estrutura com N objetos numerados de 0 a N-1.
int* UF_init(int *sz, int size);

// Adiciona uma conexao entre p e q.
void UF_union(int *id, int *sz, int p, int q);

// Retorna o identificador do componente de p (entre 0 a N-1).
int UF_find(int *id, int i);

// Os objetos p e q estao no mesmo componente?
bool UF_connected(int *id, int p, int q);

void UF_free(int *id);