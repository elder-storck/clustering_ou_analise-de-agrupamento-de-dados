#include"methodDistance.h"

struct aresta{
    int ID1;
    int ID2;
    float distance;
};

int Distance_returnID1(Aresta *arestas, int index){
    return arestas[index].ID1;
}

int MD_returnID2(Aresta *arestas, int index){
    return arestas[index].ID2;
}
float MD_returnDistance(Aresta *arestas, int index){
    return arestas[index].distance;
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




/*
char* Aloca_Nome(char *name){
    char* Name = malloc((sizeof(char) * strlen(name)) +1);
    strcpy(Name, name);
    return Name;
}
*/


Aresta* Distance_calculate_arestas(Ponto *pontos, int amountPontos, int amountCoordenadas, int amountArestas){
    /*Declarando vetor de arestas*/
    
    Aresta* arestas = malloc(amountArestas * sizeof(Aresta));

    long double soma =0.0;  //recebe as distancia 
    int  count  =0;         //marca a posição do vetor de aresta

    /*Achando Dois POntos Para Calcular Distancia*/
    /*for percorendo o  vetor de pontos, pulando de ID para ID*/
    for(int i=0; i<amountPontos; i++){
        //printf("%d\n", i);
        /*for percorrendo vetor de pontos, pulando de ID para ID, começa um ponto após o for anterior*/                 
        for(int j=i+1; j<amountPontos; j++){
            /*Copia Identificadores dos dois pontos para vetor arestas*/
            //printf("%d %d", poin)
            arestas[count].ID1 = i; //Point_retorna_ID(pontos, i);                         
            arestas[count].ID2 = j; //Point_retorna_ID(pontos, j);

            /*Fazendo Calculo parcial da distancia dos pontos -> soma = (x2-x1)² + (y2-y1)²  */
            /*for percore vetor de pontos, apontando somante para as posições das coordenadas*/
            for(int c=0; c< amountCoordenadas; c++){
                soma = soma + (long double)pow((Point_retorna_coordenada(pontos,j,c) - Point_retorna_coordenada(pontos,i,c)), 2);
            }

            /*Resultado do Calculo parcial da distancia dos pontos -> soma = reaiz{(x2-x1)² + (y2-y1)²}  */
            arestas[count].distance = (float)sqrt(soma);

            /*Incrementando contador e zerando a soma*/
            soma =0;
            count++;
        }
    }
    /*Ordena o Vetor Arestas*/
    qsort(arestas,(size_t)amountArestas,sizeof(Aresta), comparar_Distancia);
    return arestas;
}



void Distance_free_arestas(Aresta *arestas, int size){
    free(arestas);
    return;
}


void Display_Vector_Arestas(Aresta *arestas, int size){
    for(int i=0; i<size; i++){
        //printf("%f\n",arestas[i].distance);
        printf("%d %d %f\n",arestas[i].ID1, arestas[i].ID2, arestas[i].distance);
    }
}

Node* monta_arvore(Aresta* arestas, Ponto *pontos, int k, int amountPontos, int amountArestas){
    /*Iniciando vetor arvore*/
    Node *node = UF_init(amountPontos, pontos);
    
    /*variável auxiliar para contar quantidade de arestas unidas*/
    int count =0;
    /*passando no vetor arestas*/
    for(int i = 0;(i <= amountArestas) && count < ((amountPontos) -(k)) ;i++){
        /*verificando se duas arestas estão conexas*/
        if( UF_find(node, arestas[i].ID1) != UF_find(node, arestas[i].ID2)){
            /*unindo duas arestas*/
            UF_union(node, arestas[i].ID1, arestas[i].ID2);
            count++;
        }
    }

    UF_ordenaPorPai(node,amountPontos);
    //for(int i=0;i<amountPontos; i++){
        //if(i == UF_returnID(node,i))  printf("[%d]Pai: %d\n",i,UF_returnID(node,i));
        //if(UF_returnID(node, i) == 19){
        //    printf("%s\n",Point_returna_name(pontos, i));
        //}
    //}
    //UF_display(node, amountPontos);
    return node;
}
