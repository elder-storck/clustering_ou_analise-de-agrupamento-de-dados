#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct ponto Ponto;

char* Point_returna_name(Ponto *points, int index);
int Point_retorna_ID(Ponto *points, int index);
float Point_retorna_coordenada(Ponto *points, int index, int indexCoord);

FILE* Point_open_file(char *nameFile);
int Point_amount_token(FILE *file);
int Point_amount_line(FILE *file);
Ponto* Point_le_file(FILE *file, int amountPontos, int amountCoordenas);
void Point_display(Ponto *pontos, int amountPontos, int amountCoordenas);
void Point_free(Ponto *pontos, int amountPontos, int amountCoordenas);