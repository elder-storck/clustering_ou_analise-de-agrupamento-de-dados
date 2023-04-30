#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include"Point.h"
#include"edgeFile.h"

typedef struct tree Tree;


/* 
 * Função que retorna atributo nome da struct árvore 
 * Pré-condição: ponteiro para lista de structs árvore
 * Pós-condição: nenhuma
 * Input: ponteiro para lista de structs árvore, posição da struct
 * Output: atributo name da struct
 */
char* UF_returnName(Tree *nodes,int index);

/* 
 * Função que retorna atributo id da struct árvore 
 * Pré-condição: ponteiro para lista de structs árvore
 * Pós-condição: nenhuma
 * Input: ponteiro para lista de structs árvore, posição da struct
 * Output: atributo id da struct
 */
int UF_returnID(Tree *nodes,int index);

/* 
 * Função que exibe lista de structs árvore
 * Pré-condição: lista de structs árvore válida
 * Pós-condição: nenhuma
 * Input: lista de structs árvore preenchida, tamanho da árvore
 * Output: nenhum
 */
void UF_display(Tree *nodes, int size);

/* 
 * Função que inicia e preenche com valores dos pontos a lista de structs tree, 
 * Pré-condição: lista de structs point válida
 * Pós-condição: lista de struct tree iniciada e preenchida
 * Input: lista de structs point preenchida, quant. pontos
 * Output: lista de struct tree
 */
Tree* UF_init(Point *pontos, int amountPontos);

/* 
 * Função que inicia e copia uma lista de structs tree 
 * Pré-condição: lista de structs tree válida
 * Pós-condição: lista de struct tree iniciada e preenchida
 * Input: lista de structs tree preenchida, identificador da posição inicial, tamanho
 * Output: lista de struct tree
 */
Tree* UF_initCopy(Tree *treeAux, int indexInit, int size);


/* 
 * Função que Faz união de duas árvores, pendura a árv. menor sob a maior 
 * Pré-condição: lista de structs tree válida
 * Pós-condição: dois nó unidos
 * Input: lista de structs tree preenchida, nó A, nó B
 * Output: nenhum
 */
void UF_union(Tree *node, int p, int q);

/* 
 * Função que Busca o pai até a raiz 
 * Pré-condição: lista de structs tree válida
 * Pós-condição: nenhum
 * Input: lista de structs tree preenchida, indentificador
 * Output: identificador do componente de 'i' (entre 0 a N-1).
 */
int UF_find(Tree *node, int i);

/* 
 * Função que verifica se os objetos p e q estao no mesmo componente 
 * Pré-condição: lista de structs tree válida
 * Pós-condição: nenhum
 * Input: lista de structs tree preenchida, indentificador p,  indentificador q 
 * Output: true or false
 */
bool UF_connected(Tree *node, int p, int q);

/* 
 * Função que ordena lista de structs tree com o qsort 
 * Pré-condição: lista de structs tree válida
 * Pós-condição: lista de structs tree ordenada por ordem lexicografica
 * Input: lista de structs tree preenchida, tamanho da lista,  indentificador primeiro elemento 
 * Output: nenhum
 */
void UF_ordenaPorName(Tree *list_tree, int amountNodes, int index);

/* 
 * Função que libera lista de structs tree 
 * Pré-condição: lista de structs tree válida
 * Pós-condição: lista de structs tree liberada da memória
 * Input: lista de structs tree preenchida, tamanho da lista
 * Output: nenhum
 */
void UF_free(Tree *nodes, int amountNodes);

/* 
 * Função que cria lista de structs Tree e executa algoritimo de Kruskal
 * Pré-condição: ponteiro para lista de structs arestas e pontos, válidos
 * Pós-condição: lista de structs tree criada e preenchida
 * Input: ponteiro para lista de structs arestas e pontos, quant. grupos, quant. pontos, quant. arestas
 * Output: ponteiro para lista de structs Tree
 */
Tree* monta_arvore(Edge* list_edge, Point *list_points, int k, int amountPoints, int amountEdge);