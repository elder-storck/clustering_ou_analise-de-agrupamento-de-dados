#include"methodFile.h"

typedef struct firstNode firstNode_t;

struct firstNode{
    int index;
    char *name;
};


char* alocName(char *name){
    char* nameReturn = malloc((strlen(name) *sizeof(char)) +1);
    strcpy(nameReturn, name);
    return nameReturn;
}



int comparar_name_first(const void *x, const void *y){
    char *name1 = ((firstNode_t*)x)->name;
    char *name2 = ((firstNode_t*)y)->name;

    for(int i=0; name1[i] != '\0' || name2[i] != '\0'; i++){
        if(name1[i] > name2[i]) return  1;
        if(name1[i] < name2[i]) return -1;
    }
}

void ordenaPorName(firstNode_t *list, int amountNodes, int indexInit){
    qsort(&list[indexInit],(size_t)amountNodes,sizeof(firstNode_t), comparar_name);
}


void outFile_free(firstNode_t *list, int size){
    for(int i=0; i<size; i++){
        free(list[i].name);
    }
    free(list);
}

void escreveFile(Ponto *pontos, Node *nodes, char *nameFile, int amountPontos, int k){
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
        UF_ordenaPorName(nodes, amountPontos/k, ((amountPontos/k)*i));
    }

    Node **listnodes   = malloc(k * sizeof(Node*));
    //int apontadorList[k];
    firstNode_t *listFirstNode = malloc(k*sizeof(firstNode_t));


    for(int i=0; i<k; i++){
        
        listnodes[i]     = UF_initCopy(nodes, ((amountPontos/k)*i), amountPontos/k);
        listFirstNode[i].index = i;
        listFirstNode[i].name = alocName(UF_returnName(listnodes[i],0));

    }
    ordenaPorName(listFirstNode, k, 0);


    int ordenadas = -1, menor =0;


    for(int i=0; i<k; i++){
        int index = listFirstNode[i].index;
        //printf("%d\n",index);

        fputs(UF_returnName(listnodes[index], 0), file);
        for(int j=1; j<amountPontos/k; j++){
            fputc(',',file);
            fputs(UF_returnName(listnodes[index], j), file);
        }
        if(i != (amountPontos-1))   fputs("\n",file);
    }
    
 
    outFile_free(listFirstNode,k);
    for(int i=0; i<k; i++){
        UF_free(listnodes[i],amountPontos/k);
    }
    free(listnodes);
    fclose(file);
}