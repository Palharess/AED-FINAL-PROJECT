#ifndef __MENU_HPP__
#define __MENU_HPP__

#include "voos.hpp"
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



void mostra_menu();
void checa_dados(L_LIST todos_passageiros, Voo * voos);
Pessoa cadastra_pessoa(L_LIST todos_passageiros);
Pessoa acha_pessoa(L_LIST todos_passageiros);
void compra_passagem(Pessoa atual, Voo * voos);
Voo * cria_todos_voos();
void mostra_voos(Voo * voos);
Voo identifica_voo_cidade(Voo * voos, char * cidade);
void end(Voo * voos, L_LIST todos_passageiros);

#endif