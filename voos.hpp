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
Aviao pega_aviao(Voo voo);
int pega_restantes(Voo voo);
Voo acha_voo_nome(Voo * voos, char * nome);
void altere_assento(Pessoa atual, Voo voo);

void troca_assento(Pessoa atual, Voo voo, int antigo_l, int antigo_c);
void cancela_passagem(Pessoa atual, Voo voo);
L_LIST pega_lista(Voo voo);

#endif