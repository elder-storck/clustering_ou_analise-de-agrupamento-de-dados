#include"../include/Point.h"


struct point{
    char  *name;        //identificador name do ponto
    int      id;        //identificador numerico (usado somente dentro do programa)
    float *coordinates; //coordenadas do ponto
};

char* Point_returnName(Point *list_points, int index){
    return list_points[index].name;
}

int Point_returnID(Point *list_points, int index){
    return list_points[index].id;
}

float Point_returnCoordinate(Point *list_points, int index, int indexCoord){
    return list_points[index].coordinates[indexCoord];
}


Point* Point_readFile(FILE *file, int amountPoints, int amountCoordinates){
    //lista de structs ponto
    Point* list_points = malloc(amountPoints * sizeof(Point));

    char *line = malloc(1000*sizeof(char)); //recebe todos os dados de uma linha
    char *token;        //recebe dados entre linhas
    size_t len =1000;   //somente usado na função getline
    int countLine =0;   //contador de linhas                    
    int countCoord =0;  //contador de coordenadas

    while((getline(&line, &len, file)) != -1){  
        // Primeira pesquisa por vírgula / lendo nome do ponto
        token = strtok(line, ",");

        //ALocando espaço referente nome do ponto/
        list_points[countLine].name = utility_alocName(token);
        //Alocando espaço para coordenadas do ponto/
        list_points[countLine].coordinates = malloc(amountCoordinates * sizeof(float));
        //atribuindo valor ao ID do ponto
        list_points[countLine].id = countLine;

        countCoord =0;
        //Pesquisando por mais virgula / lendo coordenadas do ponto
        do{
            //Demais pesquisas por vírgula.
            token = strtok('\0', ","); 
            //Se token diferente de NULL
            if(token){                 
                /*ALocando valores referentes a coordenadas*/
                list_points[countLine].coordinates[countCoord++] = atof(token);
            } 
        } while(token);//enquanto token diferente de NULL
    countLine++;
    }

    free(line);
    return list_points;
}


void Point_display(Point *list_points, int amountPoints, int amountCoordinates){
    //andando pela lista de pontos
    for(int i=0; i<amountPoints; i++){        
        printf("\nname: %s, Id:%d ", list_points[i].name, list_points[i].id);
        
        //andando pela lista de coordenadas
        for(int j=0; j<amountCoordinates; j++){
            printf(",%.2f ", list_points[i].coordinates[j]);
        }
    }

    printf("\n");
    return;
}


void Point_free(Point *list_points, int amountPoints){
    
    for(int i=0; i<amountPoints; i++){
        free(list_points[i].coordinates);   //liberando vetor coordenadas
        free(list_points[i].name);          //liberando nome
    }

    free(list_points);        
    return;
}


