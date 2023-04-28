#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"UF.h"
#include"Point.h"
#include<string.h>


FILE* Open_File(char *nameFile);
int Amount_Line(FILE *file);
int Amount_Token(FILE *file);
void Display_Vector(char **vector, int amountLine, int amountToken);
void Free_Vector(char **vector, int amountLine, int amountToken);
char** Mount_Vector(FILE *file, int amountLine, int amountToken);
