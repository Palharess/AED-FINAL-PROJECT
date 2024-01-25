#ifndef __LINKED_HPP__
#define __LINKED_HPP__
#include "pessoa.hpp"
typedef struct l_node * L_NODE;

typedef struct l_list * L_LIST;

L_LIST cria_lista();
L_NODE cria_node(Pessoa individuo);
void insere_node(L_NODE head, L_NODE inserir);
void insere_lista(L_LIST lista, Pessoa individuo);
void mostra_node(L_NODE node);
void mostra_lista(L_LIST lista);
void remove_lista_por_nome(L_LIST lista, char * nome);
void free_node(L_NODE node);
bool free_lista(L_LIST lista);
int verifica_disponibilidade(L_LIST lista, int linha, int coluna);
char * pega_nome_na_lista(L_NODE lista, int qtd, int indice);
L_NODE pega_head(L_LIST lista);
Pessoa pega_pessoa(L_NODE node);
int quantidade_passageiros(L_LIST lista);
Pessoa retorna_by_id(L_NODE lista, int id, int indice);
L_NODE pega_next(L_NODE node);

#endif