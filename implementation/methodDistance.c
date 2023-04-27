#include"methodDistance.h"
#include"UF.h"

struct aresta{
    char* ID1;
    char* ID2;
    float distance;
};



void monta_arvore(int size, int amountArestas, Aresta* arestas){
    char *ID = NULL;
    /*vetor com as alturas das arvores*/
    int sz[size];
    /*vetor indicador de arvore, iniciar cada no sendo unico pai*/
    int id = UF_init(sz,size);


    int size = 0;
    for(int i = 1;i <= amountArestas;i++){
        
        if(UF_find(arestas,i) != UF_find(arestas, i) ){ // se estiverem em componentes distintas
            UF_union(awrestas,sz,arestas->ID1,arestas->ID2);
            
            //mst[++size] = arestas[i];
        }
        
    }
    
}




char* retorna_ID1(Aresta *arestas,int index){
    return arestas[index].ID1;
}
char* retorna_ID2(Aresta *arestas,int index){
    return arestas[index].ID1;
}
float retorna_distance(Aresta *arestas,int index){
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
    /*Ordena o Vetor Arestas*/
    qsort(arestas,(size_t)size,sizeof(Aresta), comparar_Distancia);
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


void Display_Vector_Arestas(Aresta *arestas, int size){
    for(int i=0; i<size; i++){
        printf("%f\n",arestas[i].distance);
        //printf("%s %s %f\n",arestas[i].ID1, arestas[i].ID2, arestas[i].distance);
    }
}