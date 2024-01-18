#ifndef __AVIAO_HPP__
#define __AVIAO_HPP__

typedef struct aviao * Aviao;

Aviao cria_aviao(char * modelo, char * data_ida, char * destino, char * aeroporto);
char * pega_cidade(Aviao plane);
char * pega_data_ida(Aviao plane);
char * pega_modelo(Aviao plane);
char * pega_aeroporto(Aviao plane);

#endif