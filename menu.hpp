#ifndef __MENU_HPP__
#define __MENU_HPP__

#include "voos.hpp"


void mostra_menu();
Pessoa cadastra_pessoa(L_LIST todos_passageiros);
Pessoa acha_pessoa(L_LIST todos_passageiros);
void compra_passagem(Pessoa atual, Voo * voos);
Voo * cria_todos_voos();
void mostra_voos(Voo * voos);
Voo identifica_voo_cidade(Voo * voos, char * cidade);

#endif