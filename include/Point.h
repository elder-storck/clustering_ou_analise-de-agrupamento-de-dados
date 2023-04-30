#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"utility.h"

//struct para armazenar os valores referentes ao ponto
typedef struct point Point;

/* 
 * Função que retorna atributo nome da struct 
 * Pré-condição: ponteiro para lista de structs válida
 * Pós-condição: nenhuma
 * Input: ponteiro para lista de structs Ponto, posição da struct
 * Output: atributo name da struct
 */
char* Point_returnName(Point *list_points, int index);

/* 
 * Função que retorna atributo ID da struct 
 * Pré-condição: ponteiro para lista de structs válida
 * Pós-condição: nenhuma
 * Input: ponteiro para lista de structs Ponto, posição da struct
 * Output: atributo ID da struct
 */
int Point_returnID(Point *list_points, int index);

/* 
 * Função que retorna atributo coordenada da struct 
 * Pré-condição: ponteiro para lista de structs válida
 * Pós-condição: nenhuma
 * Input: ponteiro para lista de structs Ponto, e posição da struct
 * Output: atributo coordenada da struct
 */
float Point_returnCoordinate(Point *list_points, int index, int indexCoord);

/* 
 * Função que lê arquivo e retorna lista de structs ponto preenchida 
 * Pré-condição: ponteiro para arquivo válido
 * Pós-condição: lista de structs criada e preenchida
 * Input: ponteiro para arquivo, quantidade de pontos, quantidade de coordenadas
 * Output: lista de structs ponto preenchida
 */
Point* Point_readFile(FILE *file, int amountPoints, int amountCoordinates);

/* 
 * Função que exibe lista de structs ponto 
 * Pré-condição: lista de structs ponto válida
 * Pós-condição: nenhuma
 * Input: lista de structs ponto preenchida, quantidade de pontos, quantidade de coordenadas
 * Output: nenhum
 */
void Point_display(Point *pontos, int amountPontos, int amountCoordenas);

/* 
 * Função que libera lista de structs ponto 
 * Pré-condição: lista de structs ponto válida
 * Pós-condição: lista de structs ponto liberada da memória
 * Input: lista de structs ponto preenchida, quantidade de pontos
 * Output: nenhum
 */
void Point_free(Point *list_points, int amountPoints);