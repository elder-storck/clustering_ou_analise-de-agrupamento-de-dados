#include "UF.h"
#include "methodDistance.h"

struct node{
    /* data */
    int     id;
    int     sz;
};

void UF_display(Node *nodes, int size){
    for(int i=0; i<size; i++){
        printf("Pai: %d, Peso:%d\n",nodes[i].id, nodes[i].sz);
    }
    return;
}

/*inicia Cada objeto começa na sua propria componente*/
Node* UF_init(int amountPontos){
    /*estrutura arvore*/
    Node *nodes = malloc(amountPontos * sizeof(Node));
    
    //int *arv = malloc(sizeof(int)*size);
    for (int i=0; i<amountPontos; i++){
        //printf("%s\n",vector[i*amountToken]);
        //nodes[i].name = malloc((strlen(vector[i * amountToken]) *sizeof(char)) +1);
        //strcpy(nodes[i].name, vector[i * amountToken]);
        nodes[i].id = i;
        nodes[i].sz = 1;
    }
    return nodes;
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


void UF_free(Node *node){
    free(node);
    return;    
}





