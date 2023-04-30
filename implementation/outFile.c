#include"../include/outFile.h"

typedef struct firstNode firstNode_t;

struct firstNode{
    int index;
    char *name;
};


int toCompareName(const void *x, const void *y){
    char *name1 = ((firstNode_t*)x)->name;
    char *name2 = ((firstNode_t*)y)->name;

    for(int i=0; name1[i] != '\0' || name2[i] != '\0'; i++){
        if(name1[i] > name2[i]) return  1;
        if(name1[i] < name2[i]) return -1;
    }
}

void ordenaPorName(firstNode_t *list, int amountNodes, int indexInit){
    qsort(&list[indexInit],(size_t)amountNodes,sizeof(firstNode_t), toCompareName);
}


void outFile_free(firstNode_t *list, int size){
    for(int i=0; i<size; i++){
        free(list[i].name);
    }
    free(list);
}


void outFile_write(Point *list_points, Tree *list_tree, char *nameFile, int amountPontos, int k){
    //Abrir o arquivo/
    FILE *file;
    file = fopen(nameFile, "w");

    //Testar Arquivo//
    if(file == NULL){
        printf("\n ERRo 001: Função Open_File: Erro Ao abrir arquivo\n");
        exit(0);
    }

    //Ordena por nome sem separar os grupos de pais em comum
    for(int i=0; i<k; i++){
        UF_ordenaPorName(list_tree, amountPontos/k, ((amountPontos/k)*i));
    }

    Tree **list_list_tree   = malloc(k * sizeof(Tree*));        //lista de grupos de árvore
    firstNode_t *listFirstNode = malloc(k*sizeof(firstNode_t)); //lista com o primeiro nó de cada grupo


    for(int i=0; i<k; i++){
        //separando arvore em grupos de árvores
        list_list_tree[i]      = UF_initCopy(list_tree, ((amountPontos/k)*i), amountPontos/k);
        //criando lista com o primeiro nó de cada grupo de árvores
        listFirstNode[i].index = i;
        listFirstNode[i].name = utility_alocName(UF_returnName(list_list_tree[i],0));
    }

    ordenaPorName(listFirstNode, k, 0); //ordenando lista com o primeiro nó de cada grupo

    for(int i=0; i<k; i++){ //percorrendo grupos
        int index = listFirstNode[i].index;                   //id apartir da lista de primeiro nó ordenado 
        fputs(UF_returnName(list_list_tree[index], 0), file); //escrevendo primeiro nome do grupo
        
        for(int j=1; j<amountPontos/k; j++){                  //escrevendo os outros nomes do grupo
            fputc(',',file);
            fputs(UF_returnName(list_list_tree[index], j), file);
        }
        if(i != (amountPontos-1))   fputs("\n",file);
    }
    
    //liberando listas
    outFile_free(listFirstNode,k);
    for(int i=0; i<k; i++){
        UF_free(list_list_tree[i],amountPontos/k);
    }
    free(list_list_tree);

    fclose(file);
}