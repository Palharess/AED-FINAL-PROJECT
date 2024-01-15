#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.hpp"

void cadastra_pessoa(){
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
    printf("%s \n%s \n%s\n %s\n %s\n", nome,cpf,nascimento,rg,sexo);
    // Pessoa pessoa = cria_pessoa()
}

void mostra_menu(){
    int escolha;
    printf("RESERVE SUAS PASSAGENS\n");
    printf("Ja possui cadastro? (Escreva 1 para sim ou 2 para nao)\n");
    scanf("%d%*c", &escolha);
    if(escolha == 2){
        cadastra_pessoa();
    }
    printf("DIGITE N-N PARA ESCOLHER O QUE FAZER\n");
    printf("1) COMPRE SUA PASSAGEM\n");

    scanf("%d", &escolha);
    if(escolha == 1){

    }
}