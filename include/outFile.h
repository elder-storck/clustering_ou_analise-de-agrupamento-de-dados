#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"UF.h"
#include"Point.h"
#include<string.h>

/* 
 * Função que imprime os dados no arquivo 
 * Pré-condição: lista de structs ponto válida e lista de structs tree válida
 * Pós-condição: arquivo criado e com os dados impressos
 * Input: lista de structs ponto, lista de structs tree, nome arquivo, quantidade de pontos, quantidade de grupos
 * Output: nenhum
 */
void outFile_write(Point *list_points, Tree *list_tree, char *nameFile, int amountPontos, int k);
