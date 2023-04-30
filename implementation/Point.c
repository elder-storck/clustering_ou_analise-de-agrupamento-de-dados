#include"Point.h"

struct ponto{
    char  *name;
    int      id;
    float *coordenadas;
};

char* Point_returna_name(Ponto *points, int index){
    return points[index].name;
}
int Point_retorna_ID(Ponto *points, int index){
    return points[index].id;
}
float Point_retorna_coordenada(Ponto *points, int index, int indexCoord){
    return points[index].coordenadas[indexCoord];
}



FILE* Point_open_file(char *nameFile){
    /*Abrir o arquivo*/
    FILE *file;
    file = fopen(nameFile, "r");

    /*Testar Arquivo*/
    if(file == NULL){
        printf("\n ERRo 001: Função Open_File: Erro Ao abrir arquivo\n");
        exit(0);
    }
    return file; 
}



int Point_amount_token(FILE *file){
    char linha[500];
    char *token;
    
    /*Lê a Primeira Linha*/
    fgets(linha, 500,file);
    
    /*Contando quantidade de tokens em uma linha*/
    int countColunas = 0;
    token = strtok(linha,",");
    while(token){
        countColunas++;
        token = strtok(NULL,",");
    }

    /*rebobina o ponteiro para o inicio do arquivo*/
    rewind(file);

    return countColunas;
}



int Point_amount_line(FILE *file){
    int countLinha = 0;
    char c;

    /*enquanto não é fim do arquivo -> incrementa contador*/
    for (c = getc(file); c != EOF; c = getc(file)){ 
        if (c == '\n')  countLinha++;
    }
    
    /*rebobina o ponteiro para o inicio do arquivo*/
    rewind(file);
    return countLinha;
}


Ponto* Point_le_file(FILE *file, int amountPontos, int amountCoordenas){

    Ponto* pontos = malloc(amountPontos * sizeof(Ponto));


    char *token;                            //recebe dados entre linhas
    char *line = malloc(1000*sizeof(char)); //recebe todos os dados de uma linha
    size_t len =1000;                       
    int countLine =0;
    int countCoord =0;



    while((getline(&line, &len, file)) != -1){
  
        /* Primeira pesquisa por vírgula. */
        token = strtok(line, ",");

        /*ALocando espaço referente a identificador do ponto*/
        pontos[countLine].name = malloc((sizeof(char) * strlen(token)) +1); 
        strcpy(pontos[countLine].name,token);

        /*Alocando espaço para coordenadas do ponto*/
        pontos[countLine].coordenadas = malloc(amountCoordenas * sizeof(float));
        
        pontos[countLine].id = countLine;

        countCoord =0;
 
        /*Pesquisando por mais virgula*/
        do{
            token = strtok('\0', ","); //Demais pesquisas por vírgula.
            if(token){                 //Se token diferente de NULL
                /*ALocando valores referentes a coordenadas*/
                pontos[countLine].coordenadas[countCoord++] = atof(token);
                //vector[countAux] = malloc((sizeof(char) * strlen(token)) +1);
                //strcpy(vector[countAux],token);
            } 
        } while(token); //enquanto token != NULL

    countLine++;
    }
    free(line);
return pontos;
}


void Point_display(Ponto *pontos, int amountPontos, int amountCoordenas){
    for(int i=0; i<amountPontos; i++){        
        printf("\nname: %s, Id:%d ", pontos[i].name, pontos[i].id);
        for(int j=0; j<amountCoordenas; j++){
            printf(",%.2f ", pontos[i].coordenadas[j]);
        }
    }
    printf("\n");
    return;
}


void Point_free(Ponto *pontos, int amountPontos, int amountCoordenas){
    
    for(int i=0; i<amountPontos; i++){
        free(pontos[i].coordenadas);
        free(pontos[i].name);
    }
    free(pontos);        
    return;
}


