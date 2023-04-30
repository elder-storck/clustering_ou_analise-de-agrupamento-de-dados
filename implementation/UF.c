#include "UF.h"
#include "methodDistance.h"

struct node{
    /* data */
    int     id;
    char *name;
    int     sz;
};


char* UF_returnName(Node *nodes,int index){
    return nodes[index].name;
}


int UF_returnID(Node *nodes,int index){
    return nodes[index].id;
}


void UF_display(Node *nodes, int size){
    for(int i=0; i<size; i++){
        printf("\n[%d]Pai: %d, Peso:%d, name:%s",i,nodes[i].id, nodes[i].sz, nodes[i].name);
    }
    return;
}

/*inicia Cada objeto começa na sua propria componente*/
Node* UF_init(int amountPontos, Ponto *pontos){
    /*estrutura arvore*/
    Node *nodes = malloc(amountPontos * sizeof(Node));
    
    //int *arv = malloc(sizeof(int)*size);
    for (int i=0; i<amountPontos; i++){
        //printf("%s\n",vector[i*amountToken]);
        nodes[i].name = malloc((strlen(Point_returna_name(pontos,i)) *sizeof(char)) +1);
        strcpy(nodes[i].name, Point_returna_name(pontos,i));
        nodes[i].id = i;
        nodes[i].sz = 1;
    }
    return nodes;
}

Node* UF_initCopy(Node *nodes, int indexInit, int size){
    /*estrutura arvore*/
    Node *node = malloc(size * sizeof(Node));
    

    //int *arv = malloc(sizeof(int)*size);
    for (int i=0; i<size; i++){
        //printf("%s\n",vector[i*amountToken]);
        node[i].name = malloc((strlen(nodes[indexInit+i].name) *sizeof(char)) +1);
        strcpy(node[i].name, nodes[indexInit+i].name);
        node[i].id = i;
        node[i].sz = 1;
    }
    return node;
}

/*Faz união de duas árvores, pendura a árv. menor sob a maior*/
void UF_union(Node *node, int p, int q) {
    int i = UF_find(node, p); 
    int j = UF_find(node, q); // Profundidade de ? acessos.
    if (i == j) return;
    
    if (node[i].sz < node[j].sz){
        node[i].id = j;
        node[j].sz += node[i].sz;
    }else{
        node[j].id = i;
        node[i].sz += node[j].sz;
        }
    return;
}

/*Buscar o pai até a raiz*/
int UF_find(Node *node, int i) {
    while (i != node[i].id) {
        node[i].id = node[node[i].id].id; // Uma unica linha de codigo adicional.
        i = node[i].id;                   // Cada passo agora requer 5 acessos.
    }
    return i;
}

bool UF_connected(Node *node, int p, int q){
    return UF_find(node, p) == UF_find(node, q);
}





int comparar_Pai(const void *x, const void *y){
    if(((Node*)x)->id > ((Node*)y)->id){
        return 1;
    }
    if(((Node*)x)->id < ((Node*)y)->id){
        return -1;
    }
    return 0;
}

void UF_ordenaPorPai(Node *nodes, int amountNodes){
    qsort(nodes,(size_t)amountNodes,sizeof(Node), comparar_Pai);
}

int comparar_name(const void *x, const void *y){
    char *name1 = ((Node*)x)->name;
    char *name2 = ((Node*)y)->name;

    for(int i=0; name1[i] != '\0' || name2[i] != '\0'; i++){
        if(name1[i] > name2[i]) return  1;
        if(name1[i] < name2[i]) return -1;
    }
}

void UF_ordenaPorName(Node *nodes, int amountNodes, int index){
    qsort(&nodes[index],(size_t)amountNodes,sizeof(Node), comparar_name);
}


//void UF_ordenaPorName(Node *nodes, int amountNodes, int index){
//    qsort(&nodes[index],(size_t)amountNodes,sizeof(Node), comparar_name);
//}


void UF_free(Node *nodes, int amountNodes){
    for (int i=0; i<amountNodes; i++){
        free(nodes[i].name);
    }
    free(nodes);
    return;
}

