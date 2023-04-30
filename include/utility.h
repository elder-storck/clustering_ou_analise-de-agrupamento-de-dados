#include<stdio.h>
#include<stdlib.h>

/* 
 * Função que retorna ponteiro para arquivo aberto 
 * Pré-condição: nehum
 * Pós-condição: arquivo aberto
 * Input: nome do arquivo, letra da ação correspondente
 * Output: ponteiro para o arquivo
 */
FILE* utility_openFile(char *nameFile, char *action);

/* 
 * Função que aloca e copia o nome para um ponteiro 
 * Pré-condição: ponteiro name diferente de NULL
 * Pós-condição: ponteiro alocado e com valor
 * Input:        nome a ser copiado
 * Output:       ponteiro para nome copiado
 */
char* utility_alocName(char *name);

/* 
 * Função conta quantidade de token na linha de um arquivo 
 * Pré-condição: ponteiro para arquivo válido
 * Pós-condição: ponteiro para leitura do arquivo rebobinado para o início
 * Input:        ponteiro para arquivo
 * Output:       quantidade de tokens na linha de um arquivo
 */
int utility_amountToken(FILE *file);

/* 
 * Função conta quantidade de linhas de um arquivo 
 * Pré-condição: ponteiro para arquivo válido
 * Pós-condição: ponteiro para leitura do arquivo rebobinado para o início
 * Input:        ponteiro para arquivo
 * Output:       quantidade de linhas de um arquivo
 */
int utility_amountLine(FILE *file);

