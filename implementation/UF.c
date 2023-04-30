#include "../include/UF.h"


struct tree{
    /* data */
    int     id;
    char *name;
    int     sz;
};


char* UF_returnName(Tree *tree,int index){
    return tree[index].name;
}

int UF_returnID(Tree *tree,int index){
    return tree[index].id;
}

void UF_display(Tree *tree, int size){
    for(int i=0; i<size; i++){
        printf("\n[%d]Pai: %d, Peso:%d, name:%s",i,tree[i].id, tree[i].sz, tree[i].name);
    }
    return;
}


Tree* UF_init(Point *pontos, int amountPontos){

    Tree *list_tree = malloc(amountPontos * sizeof(Tree)); //alocando árvore
    
    for (int i=0; i<amountPontos; i++){
        list_tree[i].name = utility_alocName(Point_returnName(pontos,i)); //aloca e copia nome do ponto para árv
        list_tree[i].id = i;       //preenchendo id 
        list_tree[i].sz = 1;       //preenchendo tamanho
    }
    return list_tree;
}


Tree* UF_initCopy(Tree *treeAux, int indexInit, int size){
    
    Tree *list_tree = malloc(size * sizeof(Tree)); //alocando árvore

    for (int i=0; i<size; i++){
        list_tree[i].name = utility_alocName(treeAux[indexInit+i].name); //aloca e copia o nome
        list_tree[i].id = i;       //preenchendo id
        list_tree[i].sz = 1;       //preenchendo tamanho
    }
    return list_tree;
}


void UF_union(Tree *node, int p, int q) {
    int i = UF_find(node, p);   //procura o pai de p
    int j = UF_find(node, q);   //procura o pai de q
    if (i == j) return;         //verificando se é igual
    
    if (node[i].sz < node[j].sz){   //verificando qual é a maior árvore
        node[i].id = j;             //unindo árvore
        node[j].sz += node[i].sz;
    }else{
        node[j].id = i;
        node[i].sz += node[j].sz;
        }
    return;
}


int UF_find(Tree *node, int i) {
    while (i != node[i].id) {
        node[i].id = node[node[i].id].id; 
        i = node[i].id;                   
    }
    return i;
}


bool UF_connected(Tree *node, int p, int q){
    return UF_find(node, p) == UF_find(node, q);
}


int toComparePai(const void *x, const void *y){
    if(((Tree*)x)->id > ((Tree*)y)->id){
        return 1;
    }
    if(((Tree*)x)->id < ((Tree*)y)->id){
        return -1;
    }
    return 0;
}

int UF_toCompareName(const void *x, const void *y){
    char *name1 = ((Tree*)x)->name;
    char *name2 = ((Tree*)y)->name;

    for(int i=0; name1[i] != '\0' || name2[i] != '\0'; i++){
        if(name1[i] > name2[i]) return  1;
        if(name1[i] < name2[i]) return -1;
    }
}

void UF_ordenaPorName(Tree *list_tree, int amountNodes, int index){
    qsort(&list_tree[index],(size_t)amountNodes,sizeof(Tree), UF_toCompareName);
}

void UF_free(Tree *list_tree, int size){
    for (int i=0; i<size; i++){
        free(list_tree[i].name);
    }
    free(list_tree);
    return;
}


Tree* monta_arvore(Edge* list_edge, Point *list_points, int k, int amountPoints, int amountEdge){
    
    Tree *list_tree = UF_init(list_points, amountPoints);    //declarando árvore
    
    int count =0; //variável auxiliar para contar quantidade de arestas unidas

    for(int i = 0;(i <= amountEdge) && count < (amountPoints -k) ;i++){      //passando vetor arestas
        if( UF_find(list_tree, Edge_returnID1(list_edge, i)) != UF_find(list_tree,Edge_returnID2(list_edge, i))){ //verificando se arestas estão unidas
            UF_union(list_tree, Edge_returnID1(list_edge, i), Edge_returnID2(list_edge, i));                  //unindo duas arestas/
            count++;                                                             //incrementando contador
        }
    }
    qsort(list_tree,(size_t)amountPoints,sizeof(Tree), toComparePai); //ordenando num mesmo vetor os 'k' grupos de arvores
    return list_tree;
}