#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"methodFile.h"
#include"methodDistance.h"

typedef struct aresta Aresta;
char* Aloca_Nome(char *name);
Aresta* Calculate_Distance(char **vector, int amountLine, int amountToken, int size);
int comparar_Distancia(const void *x, const void *y);
void Free_Arestas(Aresta *arestas, int size);




struct aresta{
    char* ID1;
    char* ID2;
    float distance;
};

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
    
    /*Montar vetor com as distância*/
    int size_arestas =0;
    for(int i=0; i<amountLine; i++) size_arestas += i;
    Aresta* arestas = Calculate_Distance(vector, amountLine, amountToken, size_arestas);
    
    
    

    printf("tam: %d\n",size_arestas);


    
    //for(int j=0; j < size_arestas; j++){
    //    printf("[%d]: %s %s %f\n",j,arestas[j].ID1, arestas[j].ID2, arestas[j].distance);
    //}

    /*ordenar o Vetor com as distâncias*/
    qsort(arestas,(size_t)size_arestas,sizeof(struct aresta), comparar_Distancia);

    for(int i=0; i<size_arestas; i++){
        printf("%f\n",arestas[i].distance);
        //printf("%s %s %f\n",arestas[i].ID1, arestas[i].ID2, arestas[i].distance);
    }


    Free_Vector(vector, amountLine, amountToken);
    Free_Arestas(arestas, size_arestas);
    fclose(arq);

return 0;

}





int comparar_Distancia(const void *x, const void *y){
    if(((Aresta*)x)->distance > ((Aresta*)y)->distance){
        return 1;
    }
    if(((Aresta*)x)->distance < ((Aresta*)y)->distance){
        return -1;
    }
    return 0;
}





char* Aloca_Nome(char *name){
    char* Name = malloc((sizeof(char) * strlen(name)) +1);
    strcpy(Name, name);
    return Name;
}



Aresta* Calculate_Distance(char **vector, int amountLine, int amountToken, int size){
    /*Declarando vetor de arestas*/
    Aresta* arestas = malloc(size * sizeof(Aresta));

    long double soma =0.0;  //recebe as distancia 
    int  count  =0;         //marca a posição do vetor de aresta

    /*Achando Dois POntos Para Calcular Distancia*/
    /*for percorendo o  vetor de pontos, pulando de ID para ID*/
    for(int i=0; i<(amountLine*amountToken); i= i+amountToken){
        /*for percorrendo vetor de pontos, pulando de ID para ID, começa um ponto após o for anterior*/                 
        for(int j=i+amountToken; j<(amountLine*amountToken); j= j+amountToken){ 
            /*Copia Identificadores dos dois pontos para vetor arestas*/
            arestas[count].ID1 = Aloca_Nome(vector[i]);                         
            arestas[count].ID2 = Aloca_Nome(vector[j]);
            
            /*Fazendo Calculo parcial da distancia dos pontos -> soma = (x2-x1)² + (y2-y1)²  */
            /*for percore vetor de pontos, apontando somante para as posições das coordenadas*/
            for(int c=1; c< amountToken; c++){
                soma = soma + (long double)pow((atof(vector[j+c]) - atof(vector[i+c])), 2);
            }
            
            /*Resultado do Calculo parcial da distancia dos pontos -> soma = reaiz{(x2-x1)² + (y2-y1)²}  */
            arestas[count].distance = (float)sqrt(soma);

            /*Incrementando contador e zerando a soma*/
            soma =0;
            count++;
        }
    }
    return arestas;
}
void Free_Arestas(Aresta *arestas, int size){
    for(int i=0; i<size; i++){
        free(arestas[i].ID1);
        free(arestas[i].ID2);
    }
    free(arestas);
    return;
}