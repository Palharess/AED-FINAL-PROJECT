#include <stdio.h>
#include <stdlib.h>
#include "pessoa.hpp"
#include <string.h>


struct pessoa{
    char cpf[12];
    char nome[30];
    char nascimento[12];
    char rg[10];
    char sexo[30];
    int linha, coluna;
    int tem;
};



Pessoa cria_pessoa(char * cpf, char * nome, char * nascimento, char * rg, char * sexo, int tem){
    Pessoa nova = NULL;
    nova = (Pessoa) calloc(1, sizeof(struct pessoa));
    strcpy(nova->cpf, cpf);
    strcpy(nova->nome, nome);
    strcpy(nova->nascimento, nascimento);
    strcpy(nova->rg, rg);
    strcpy(nova->sexo, sexo);
    nova->tem = tem;
    return nova;
}

int pega_linha(Pessoa pessoa){
    return pessoa->linha;
}
int pega_coluna(Pessoa pessoa){
    return pessoa->coluna;
}
char * pega_nome(Pessoa pessoa){
    return pessoa->nome;
}

void escolher_assento(Pessoa pessoa, int linha, int coluna){
    pessoa->coluna = coluna;
    pessoa->linha = linha;
}




