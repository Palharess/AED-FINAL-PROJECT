#include <stdio.h>
#include <stdlib.h>
#include "aviao.hpp"
#include "pessoa.hpp"
#include <string.h>


struct aviao{
    char modelo[20];
    char ida[15];
    char volta[15];
    char aeroporto[20];
};


Aviao cria_aviao(char * modelo, char * ida, char * volta, char * aeroporto){
    Aviao nova = NULL;
    nova = (Aviao) calloc(1, sizeof(struct aviao));
    strcpy(nova->modelo, modelo);
    strcpy(nova->ida, ida);
    strcpy(nova->volta, volta);
    strcpy(nova->aeroporto, aeroporto);
    return nova;
}