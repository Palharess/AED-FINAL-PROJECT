#include <stdio.h>
#include <stdlib.h>
#include "aviao.hpp"
#include "pessoa.hpp"
#include <string.h>


struct aviao{
    char modelo[20];
    char data_ida[15];
    char destino[30];
    char aeroporto[20];
};


Aviao cria_aviao(char * modelo, char * data_ida, char * destino, char * aeroporto){
    Aviao nova = NULL;
    nova = (Aviao) calloc(1, sizeof(struct aviao));
    strcpy(nova->modelo, modelo);
    strcpy(nova->data_ida, data_ida);
    strcpy(nova->destino, destino);
    strcpy(nova->aeroporto, aeroporto);
    return nova;
}

char * pega_cidade(Aviao plane){
    return plane->destino;
}
char * pega_data_ida(Aviao plane){
    return plane->data_ida;
}
char * pega_modelo(Aviao plane){
    return plane->modelo;
}
char * pega_aeroporto(Aviao plane){
    return plane->aeroporto;
}
