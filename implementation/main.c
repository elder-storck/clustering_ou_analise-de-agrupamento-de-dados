#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"methodFile.h"

float* Calculate_Distance(char **vector, int amountLine, int amountToken);

int main(int argc, char *argv[]){
    char* inputFile = argv[1];   //arquivo entrada
    int k = atoi(argv[2]);      //tamanho de K
    char* outputFile = argv[3];  //arquivo saída
    
    /*Abre o arquivo e testa*/
    FILE *arq = Open_File(inputFile);

    /*Conta quantidade de linhas e colunas em um Arquivo*/
    int amountLine  = Amount_Line(arq);
    int amountToken = Amount_Token(arq);
    printf("%d %d\n",amountLine, amountToken);
    rewind(arq);

    

    /*Motar vetor com os pontos e suas coordenadas*/
    char** vector = Mount_Vector(arq, amountLine, amountToken);
    
    /*Calcular distância*/
    float* distance = Calculate_Distance(vector,amountLine,amountToken);
    for(int i=0; i<51; i++){
        printf("%.3f\n",distance[i]);
    }
    
    Free_Vector(vector, amountLine, amountToken);
    free(distance);
    fclose(arq);

return 0;

}

float* Calculate_Distance(char **vector, int amountLine, int amountToken){
    float* distance =  malloc(((amountLine+1)*(amountLine/2)) * sizeof(float));    //**************diminuir tamanho 
    long double soma =0.0;
    int count=0;

    for(int i=0; i<(amountLine*amountToken); i= i+amountToken){     //Pula de Ponto em Ponto 
        //printf("i: %s\n",vector[i]);
        for(int j=i+amountToken; j<(amountLine*amountToken); j= j+amountToken){ //Pula de ponto em ponto, começa um ponto após o ponto que o i aponta
            for(int c=1; c< amountToken; c++){                                  //anda através das coordenadas do vetor
                soma = soma + (long double)pow((atof(vector[j+c]) - atof(vector[i+c])), 2);     //Claculo parcial distancia (x2-x1)² + (y2-y1)²
            }
            distance[count] = sqrt(soma);       //caculo da distancia
            soma =0;
            count++;
            //printf("%d\n",count);
        }
    }
    return distance;
}
