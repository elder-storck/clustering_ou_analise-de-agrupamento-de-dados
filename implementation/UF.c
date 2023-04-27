#include "UF.h"


/*inicia Cada objeto começa na sua propria componente*/
int* UF_init(int *sz, int size){
    /*estrutura arvore*/
    int *arv = malloc(sizeof(int)*size);
    for (int i=0; i<size; i++){
        sz[i]  = 1;
        arv[i] = i;  
    }
    return arv;
}

/*Faz união de duas árvores, pendura a árv. menor sob a maior*/
void UF_union(int *id, int *sz, int p, int q) {
    int i = UF_find(id, p); 
    int j = UF_find(id, q); // Profundidade de ? acessos.
    if (i == j) return;
        if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
    else { id[j] = i; sz[i] += sz[j]; }
}

/*Buscar o pai até a raiz*/
int UF_find(int *id, int i) {
    while (i != id[i]) {
        id[i] = id[id[i]]; // Uma unica linha de codigo adicional.
        i = id[i]; // Cada passo agora requer 5 acessos.
    }
    return i;
}

bool UF_connected(int *id, int p, int q){
    return UF_find(id, p) == UF_find(id, q);
}


void UF_free(int *id){
    free(id);
    return;    
}





