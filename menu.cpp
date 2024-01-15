#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.hpp"



void cadastra_pessoa(L_LIST todos_passageiros){
    char cpf[12];
    char nome[30];
    char nascimento[12];
    char rg[10];
    char sexo[30];

    printf("Insira seus dados para continuar\n");
    printf("Nome: ");
    scanf("%[^\n]%*c", nome);
    printf("Cpf: ");
    scanf("%s%*c", cpf);
    printf("Data de Nascimento (Ex: 01/04/2005): ");
    scanf("%s%*c", nascimento);
    printf("Rg: ");
    scanf("%s%*c", rg);
    printf("Sexo: ");
    scanf("%s%*c", sexo);
    Pessoa pessoa = cria_pessoa(cpf,nome,nascimento,rg,sexo);
    insere_lista(todos_passageiros, pessoa);
    printf("Voce foi cadastrado!\n");
    // printf("%s\n", pega_nome(pessoa));
    // printf("%s\n", pega_nome(pega_pessoa(pega_head(todos_passageiros))));
}

void mostra_menu(){
    L_LIST todos_passageiros = cria_lista();
    Pessoa atual;
    int escolha;
    printf("RESERVE SUAS PASSAGENS\n");
    printf("Ja possui cadastro? (Escreva 1 para sim ou 2 para nao)\n");
    scanf("%d%*c", &escolha);
    if(escolha == 2){
        cadastra_pessoa(todos_passageiros);
        
    }
    printf("DIGITE N-N PARA ESCOLHER O QUE FAZER\n");
    printf("1) COMPRE SUA PASSAGEM\n");

    scanf("%d", &escolha);
    if(escolha == 1){

    }
}