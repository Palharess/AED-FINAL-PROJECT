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
    char voo[30];
};



Pessoa cria_pessoa(char * cpf, char * nome, char * nascimento, char * rg, char * sexo){
    Pessoa nova = NULL;
    nova = (Pessoa) calloc(1, sizeof(struct pessoa));
    strcpy(nova->cpf, cpf);
    strcpy(nova->nome, nome);
    strcpy(nova->nascimento, nascimento);
    strcpy(nova->rg, rg);
    strcpy(nova->sexo, sexo);
    nova->linha = -1;
    nova->coluna = -1;
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


void escolher_voo(Pessoa pessoa, char * voo){
    strcpy(pessoa->voo, voo);
}

char * pega_voo(Pessoa pessoa){
    return pessoa->voo;
}

char * pega_cpf(Pessoa pessoa){
    return pessoa->cpf;
}
char * pega_sexo(Pessoa pessoa){
    return pessoa->sexo;
}
char * pega_nascimento(Pessoa pessoa){
    return pessoa->nascimento;
}
char * pega_rg(Pessoa pessoa){
    return pessoa->rg;
}