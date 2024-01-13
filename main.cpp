#include <stdio.h>
#include "voos.hpp"


int main(){
    
    Pessoa pessoa = cria_pessoa("17230891", "Bruno Massahiro Watanabe", "07/08/2004", "1263712", "Helicóptero de Combate", 0);

    escolher_assento(pessoa, 1 , 2);
    Aviao plane = cria_aviao("AirBus A320", "11/09/2001","0/0/0","Twin Towers");
    Voo voo = cria_voo(plane);
    
    adiciona_passageiro(pessoa,voo);
    mostra_assento(voo);



    return 0;
}