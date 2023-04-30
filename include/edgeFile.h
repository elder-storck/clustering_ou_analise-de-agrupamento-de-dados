#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"Point.h"

typedef struct edge Edge;


/* 
 * Função que retorna atributo ID1 da struct Aresta
 * Pré-condição: ponteiro para lista de structs Arestas válida
 * Pós-condição: nenhuma
 * Input: ponteiro para lista de structs Aresta, posição da struct
 * Output: atributo ID1 da struct
 */
int Edge_returnID1(Edge *list_edge, int index);

/* 
 * Função que retorna atributo ID2 da struct Aresta
 * Pré-condição: ponteiro para lista de structs Arestas válida
 * Pós-condição: nenhuma
 * Input: ponteiro para lista de structs Aresta, posição da struct
 * Output: atributo ID2 da struct
 */
int Edge_returnID2(Edge *arestas, int index);

/* 
 * Função que retorna atributo distancia da struct Aresta
 * Pré-condição: ponteiro para lista de structs Arestas válida
 * Pós-condição: nenhuma
 * Input: ponteiro para lista de structs Aresta, posição da struct
 * Output: atributo distancia da struct
 */
float Edge_returnDistance(Edge *list_edge, int index);

/* 
 * Função que cria e calcula lista de structs Aresta
 * Pré-condição: ponteiro para lista de structs Pontos
 * Pós-condição: lista de structs aresta criada e preenchida
 * Input: ponteiro para lista de structs Ponto, quant. pontos, quant. coordenadas, quant. arestas
 * Output: ponteiro para lista de structs Arestas
 */
Edge* Edge_initAndCaculate(Point *list_points, int amountPoints, int amountCoordinates, int amountEdge);

/* 
 * Função que exibe lista de structs Aresta 
 * Pré-condição: lista de structs Aresta válida
 * Pós-condição: nenhuma
 * Input: lista de structs Aresta preenchida, quantidade de arestas
 * Output: nenhum
 */
void Edge_displayList(Edge *list_edge, int size);

/* 
 * Função que libera lista de structs Aresta 
 * Pré-condição: lista de structs Aresta válida
 * Pós-condição: lista de structs Aresta liberada da memória
 * Input: lista de structs Aresta 
 * Output: nenhum
 */
void Edge_free(Edge *list_edge);