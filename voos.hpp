#ifndef __VOOS_HPP__
#define __VOOS_HPP__
#include "pessoa.hpp"
#include "aviao.hpp"
#include "linked.hpp"
typedef struct voo * Voo;

#define LIMPA "\033[0m"
#define LIMPA_FUNDO "\033[49m"

#define BRANCO "\033[1;30m"
#define VERMELHO "\033[1;31m"
#define VERDE "\033[1;32m"
#define AMARELO "\033[1;33m"
#define AZUL "\033[1;34m"
#define MGENTA "\033[1;35m"
#define CIANO "\033[1;36m"
#define CINZA "\033[1;37m"
#define FUNDO_BRANCO "\033[1;40m"
#define FUNDO_VERMELHO "\033[1;41m"
#define FUNDO_VERDE "\033[1;42m"
#define FUNDO_AMARELO "\033[1;43m"
#define FUNDO_AZUL "\033[1;44m"
#define FUNDO_MAGENTA "\033[1;45m"
#define FUNDO_CIANO "\033[1;46m"
#define FUNDO_CINZA "\033[1;47m"




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
void cancela_passagem(Pessoa atual, Voo voo, L_LIST todos_passageiros);
L_LIST pega_lista(Voo voo);

#endif