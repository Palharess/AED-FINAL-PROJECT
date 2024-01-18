#include <stdio.h>
#include <stdlib.h>
#include "linked.hpp"
#include "voos.hpp"


struct l_node{
    L_NODE next;
    Pessoa individuo;
};

struct l_list{
    L_NODE head;
    int qtd;
};

L_LIST cria_lista(){
    L_LIST lista = NULL;
    lista = (L_LIST) malloc(sizeof(struct l_list));
    lista->head = NULL;
    lista->qtd =0;
    return lista;
};

L_NODE cria_node(Pessoa individuo){
    L_NODE new_node = NULL;
    new_node = (L_NODE) malloc(sizeof(struct l_node));
    new_node ->next = NULL;
    new_node->individuo = individuo;
    return new_node;
}
void insere_node(L_NODE head, L_NODE inserir){
    if(head->next == NULL){
        head->next = inserir;
        inserir->next = NULL;
        return;
    }
    insere_node(head->next, inserir);
}

void insere_lista(L_LIST lista, Pessoa individuo){
    L_NODE new_node = cria_node(individuo);
    if(lista->head == NULL){
        lista->head = new_node;
        lista->qtd++;
        lista->head->next = NULL;
        return;
    }
    insere_node(lista->head, new_node);
    lista->qtd++;
}

void mostra_node(L_NODE node){
    if(node == NULL) return;
    printf("%s ", pega_nome(node->individuo));
    mostra_node(node->next);
}

void mostra_lista(L_LIST lista){
    printf("[");
    if(lista->head != NULL) mostra_node(lista->head);
    printf("]\n");
}

void free_node(L_NODE node){
    free(node);
}
bool free_lista(L_LIST lista){
    while(lista->qtd > 0){
        free_node(lista->head);
        lista->head = lista->head->next;
        lista->qtd--;
    }
    lista->head = NULL;
    return true;
}

//passa um linha e uma coluna e verifica se o o individuo passado bate com os parametros passados

int verifica_disponibilidade(L_LIST lista, int linha, int coluna){
    if(pega_linha(lista->head->individuo) == linha && pega_coluna(lista->head->individuo) == coluna){
        return 1;
    }
    else{
        return 0;
    }
}

char * pega_nome_na_lista(L_NODE node, int qtd, int indice){
    if(indice == qtd){
        return pega_nome(node->individuo);
    }
    indice += 1;
    pega_nome_na_lista(node->next, qtd, indice);
}

L_NODE pega_head(L_LIST lista){
    return lista->head;
}

Pessoa pega_pessoa(L_NODE node){
    return node->individuo;
}

int quantidade_passageiros(L_LIST lista){
    return lista->qtd;
}

Pessoa retorna_by_id(L_NODE lista, int id, int indice){
    if(indice == id){
        return pega_pessoa(lista);
    }
    indice += 1;
    pega_nome_na_lista(lista->next, id, indice);
}

L_NODE pega_next(L_NODE node){
    return node->next;
}