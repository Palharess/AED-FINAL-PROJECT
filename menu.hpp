#ifndef __MENU_HPP__
#define __MENU_HPP__

#include "voos.hpp"


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