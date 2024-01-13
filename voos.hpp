#ifndef __VOOS_HPP__
#define __VOOS_HPP__
#include "pessoa.hpp"
#include "aviao.hpp"
#include "linked.hpp"
typedef struct voo * Voo;


Voo cria_voo(Aviao plane);
void mostra_assento(Voo voo);
void adiciona_passageiro(Pessoa passageiro, Voo voo);
void mostra_passegeiro(Voo voo);
int verifica_assento(Voo voo, int linha, int coluna);



#endif