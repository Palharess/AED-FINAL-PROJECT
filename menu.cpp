#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.hpp"
#include <windows.h>


Pessoa acha_pessoa(L_LIST todos_passageiros){
    char nome[35];
    int qtd_lista = quantidade_passageiros(todos_passageiros);
    printf("Digite seu nome para acharmos seu cadastro: ");
    scanf("%[^\n]%*c", nome);
    L_NODE atual = pega_head(todos_passageiros);
    for(int i = 0; i < quantidade_passageiros(todos_passageiros); i++){
        if(strcmp(pega_nome(pega_pessoa(atual)), nome) == 0){
            system("cls");
            return pega_pessoa(atual);
        }
        atual = pega_next(atual);
    }
            
}

Pessoa cadastra_pessoa(L_LIST todos_passageiros){
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
    system("cls");
    printf("Voce foi cadastrado!\n");
    // printf("%s\n", pega_nome(pessoa));
    // printf("%s\n", pega_nome(pega_pessoa(pega_head(todos_passageiros))));
    return pessoa;
}

Voo * cria_todos_voos(){
    Voo rj,sp,bra;
    Voo *voos = (Voo*) malloc(sizeof(3*sizeof(Voo)));
    rj = cria_voo(cria_aviao("Bong", "16/01/2024", "Rio de Janeiro", "Congonhas"));
    sp = cria_voo(cria_aviao("Bong", "18/01/2024", "Sao Paulo", "Congonhas"));
    bra = cria_voo(cria_aviao("Bong", "25/01/2024", "Brasilia", "Congonhas"));
    voos[0] = rj;
    voos[1] = sp;
    voos[2] = bra;
    return voos;
}

Voo identifica_voo(Voo * voos, char * cidade){
    for(int i = 0; i < 3; i++){
        if(strcmp(pega_cidade(pega_aviao(voos[i])), cidade) == 0){
            return voos[i];
        }
    }
}


void mostra_voos(Voo * voos){
    printf("Voos disponíveis:\n");
    for(int i = 0; i < 3;i++){
        printf("%d-%s\n",i + 1,pega_cidade(pega_aviao(voos[i])));
        printf("Data da ida: %s\n",pega_data_ida(pega_aviao(voos[i])));
        printf("Aeroporto: %s\n",pega_aeroporto(pega_aviao(voos[i])));
        printf("Modelo do Aviao: %s\n",pega_modelo(pega_aviao(voos[i])));
        printf("\n");
    }
}

void compra_passagem(Pessoa atual, Voo * voos){
    char destino[30];
    int coluna;
    char fileira;
    int fila;
    Voo escolhido;
    system("cls");
    mostra_voos(voos);
    printf("Digite a cidade destino do voo escolhido: ");
    scanf("%[^\n]%*c", destino);
    escolhido = identifica_voo(voos, destino);
    system("cls");
    printf("O voo escolhido foi: %s\n", pega_cidade(pega_aviao(escolhido)));
    printf("Os assentos disponiveis sao:\n");
    mostra_assento(escolhido);
    printf("Escolha um assento (ex: g4): ");
    scanf("%c%d", &fileira, &coluna);
    coluna--;
    fila = (fileira - 'a');
    while(1){
        if(verifica_assento(escolhido, fila,coluna) == 0){
            break;
        }
        printf("Esse assento está ocupado, escolha outro: ");
        scanf("%c%d", &fileira, &coluna);
        fila = (fileira - 'a');
    }
    
    
    Sleep(100000);
}

void mostra_menu(){
    L_LIST todos_passageiros = cria_lista();
    Voo * voos = cria_todos_voos();
    Pessoa atual;
    int escolha;
    while(1){
        printf("RESERVE SUAS PASSAGENS\n");
        printf("Ja possui cadastro? (Escreva 1 para sim ou 2 para nao)\n");
        scanf("%d%*c", &escolha);
        system("cls");
        if(escolha == 2){
            atual = cadastra_pessoa(todos_passageiros);
        }
        else{
            atual = acha_pessoa(todos_passageiros);
        }

        printf("BEM VINDO %s!\n", pega_nome(atual));
        printf("DIGITE N-N PARA ESCOLHER O QUE FAZER\n");
        printf("1) COMPRE SUA PASSAGEM\n");
        scanf("%d%*c", &escolha);
        if(escolha == 1){
            compra_passagem(atual,voos);
        }
    }

}