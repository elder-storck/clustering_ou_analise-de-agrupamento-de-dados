#include"../include/edgeFile.h"

struct edge{
    int   ID1;
    int   ID2;
    float distance;
};

int Edge_returnID1(Edge *list_edge, int index){
    return list_edge[index].ID1;
}

int Edge_returnID2(Edge *list_edge, int index){
    return list_edge[index].ID2;
}

float Edge_returnDistance(Edge *list_edge, int index){
    return list_edge[index].distance;
}


int compararDistance(const void *x, const void *y){
    if(((Edge*)x)->distance > ((Edge*)y)->distance){
        return 1;
    }
    if(((Edge*)x)->distance < ((Edge*)y)->distance){
        return -1;
    }
    return 0;
} 


Edge* Edge_initAndCaculate(Point *list_points, int amountPoints, int amountCoordinates, int amountEdge){
    
    Edge* list_edge = malloc(amountEdge * sizeof(Edge));    //Declarando lista de struct arestas

    long double soma =0.0;  //soma armazena a diferença de coordenadas dos pontos 
    int  count  =0;         //marca a posição da lista de aresta
    

    for(int i=0; i<amountPoints; i++){  //percorre a lista de pontos  

        for(int j=i+1; j<amountPoints; j++){    //percorre a lista de pontos, começando um após o anterior
    
            list_edge[count].ID1 = i; //Copia Identificador do ponto para o vetor arestas                         
            list_edge[count].ID2 = j; //Copia Identificador do ponto para o vetor arestas
  
            for(int c=0; c< amountCoordinates; c++){    //percorrendo o vetor das coordenadas
                //Fazendo Calculo parcial da distancia dos pontos -> soma = (x2-x1)² + (y2-y1)²
                soma = soma + (long double)pow((Point_returnCoordinate(list_points,j,c) - Point_returnCoordinate(list_points,i,c)), 2);
            }

            // distância =  raiz{(x2-x1)² + (y2-y1)²} ou raiz{soma}
            list_edge[count].distance = (float)sqrt(soma);  //tirando a raiz quadrada da diferença das coordenadas

            soma =0;    //zerando a soma
            count++;    //incrementando o contador
        }
    }
    qsort(list_edge,(size_t)amountEdge,sizeof(Edge), compararDistance);   //ordena o vetor distancia por menor distancia
    return list_edge;
}


void Edge_displayList(Edge *list_edge, int size){
    for(int i=0; i<size; i++){
        printf("%d %d %f\n",list_edge[i].ID1, list_edge[i].ID2, list_edge[i].distance);
    }
}


void Edge_free(Edge *list_edge){
    free(list_edge);
    return;
}