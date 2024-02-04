#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.hpp"
#include <windows.h>
#include <iostream>

#define MAX_TAMANHO_LINHA 1000
#define MAX_PALAVRAS 50
using namespace std;

void checa_dados(L_LIST todos_passageiros, Voo * voos){
    //nome,cpf,rg,n,s,v,l,c
    FILE *arquivo;
    char linha[MAX_TAMANHO_LINHA];
    char *palavras[MAX_PALAVRAS];
    int numPalavras;

    arquivo = fopen("arquivo.txt", "r");

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        Pessoa add;
        Voo achou;
        linha[strcspn(linha, "\n")] = '\0';
        numPalavras = 0;
        char *token = strtok(linha, ",");

        while (token != NULL && numPalavras < MAX_PALAVRAS) {
            palavras[numPalavras] = strdup(token);  
            numPalavras++;
            token = strtok(NULL, ",");
        }

        add = cria_pessoa(palavras[1], palavras[0], palavras[3], palavras[2], palavras[4]);
        escolher_voo(add, palavras[5]);
        
        escolher_assento(add,atoi(&palavras[6][0]), atoi(&palavras[7][0]));
       
        insere_lista(todos_passageiros, add);


        achou = identifica_voo_cidade(voos, pega_voo(add));
        
        adiciona_passageiro(add, achou);


    }

    fclose(arquivo);


}

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
    cout << CIANO << "Nome: " << LIMPA;
    scanf("%[^\n]%*c", nome);
    cout << CIANO << "Cpf: " << LIMPA;
    scanf("%s%*c", cpf);
    cout << CIANO << "Data de Nascimento: " << LIMPA;
    scanf("%s%*c", nascimento);
    cout << CIANO << "Rg: " << LIMPA;
    scanf("%s%*c", rg);
    cout << CIANO << "Sexo: " << LIMPA;
    scanf("%s%*c", sexo);
    Pessoa pessoa = cria_pessoa(cpf,nome,nascimento,rg,sexo);
    insere_lista(todos_passageiros, pessoa);
    system("cls");
    cout << AZUL << "Voce foi cadastrado!\n" << LIMPA;
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

Voo identifica_voo_cidade(Voo * voos, char * cidade){
    for(int i = 0; i < 3; i++){
        if(strcmp(pega_cidade(pega_aviao(voos[i])), cidade) == 0){
            return voos[i];
        }
    }
}



void mostra_voos(Voo * voos){
    printf("Voos disponiveis:\n");
    for(int i = 0; i < 3;i++){
        printf("%d-%s\n",i + 1,pega_cidade(pega_aviao(voos[i])));
        printf("Data da ida: %s\n",pega_data_ida(pega_aviao(voos[i])));
        printf("Aeroporto: %s\n",pega_aeroporto(pega_aviao(voos[i])));
        printf("Modelo do Aviao: %s\n",pega_modelo(pega_aviao(voos[i])));
        printf("Lugares Restantes: %d\n", pega_restantes(voos[i]));
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
    escolhido = identifica_voo_cidade(voos, destino);
    system("cls");
    printf("O voo escolhido foi: %s\n", pega_cidade(pega_aviao(escolhido)));
    printf("Assentos:\n");
    mostra_assento(escolhido);
    printf("Escolha um assento (ex: g4): ");
    scanf("%c%d%*c", &fileira, &coluna);
    coluna--;
    fila = (fileira - 'a');
    while(1){
        if(verifica_assento(escolhido, fila,coluna) == 0){
            break;
        }
        printf("Esse assento esta ocupado, escolha outro: ");
        scanf("%c%d%*c", &fileira, &coluna);
        coluna--;
        fila = (fileira - 'a');
    }
    escolher_assento(atual, fila, coluna);
    escolher_voo(atual, pega_cidade(pega_aviao(escolhido)));
    adiciona_passageiro(atual, escolhido);
    system("cls");
    printf("Passagem comprada!\n");
    //aq 
    FILE *pont_arq;
    pont_arq = fopen("arquivo.txt", "a");
    fprintf(pont_arq, "%s,%s,%s,%s,%s,%s,%d,%d\n", pega_nome(atual), pega_cpf(atual), pega_rg(atual), pega_nascimento(atual)
    , pega_sexo(atual), pega_voo(atual),  pega_linha(atual), pega_coluna(atual));
    fclose(pont_arq);

    Sleep(500);
}

void end(Voo * voos, L_LIST todos_passageiros){
    for(int i = 0; i < 3; i++){
        free(pega_aviao(voos[i]));
        free_lista(pega_lista(voos[i]));
        free(voos[i]);
    }
    free(voos);
    free_lista(todos_passageiros);
}

void mostra_menu(){

    int vez = 0;
    L_LIST todos_passageiros = cria_lista();
    Voo * voos = cria_todos_voos();
    checa_dados(todos_passageiros, voos);
    Pessoa atual;
    Voo achou_voo;
    int escolha;
    while(1){
        cout << VERMELHO << "BEM VINDO!"  << "\n\n";
        cout << CIANO << "1)" << LIMPA <<" Reservar Passagens\n";
        cout << CIANO << "2)" << LIMPA <<" Ver Passageiros\n";
        scanf("%d%*c", &escolha);
        if(escolha == 1){
            system("cls");
            cout << VERMELHO << "RESERVE SUAS PASSAGENS!"  << "\n\n";
            // Ja possui cadastro? (Escreva 1 para sim ou 2 para nao
            cout << CIANO << "Ja possui cadastro?"  << LIMPA << " (Escreva" <<VERMELHO<<" 1 "<< LIMPA<< "para sim ou "<< VERMELHO<<"2 "<< LIMPA<<"para nao)"<<"\n";
            scanf("%d%*c", &escolha);
            system("cls");
            if(escolha == 2){
                atual = cadastra_pessoa(todos_passageiros);
            }
            else if (escolha == 1){
                atual = acha_pessoa(todos_passageiros);
            }
            else{
                end(voos,todos_passageiros);
            }
            while(1){
                cout << VERMELHO << "BEM VINDO "  << AZUL << pega_nome(atual) <<VERMELHO<<"!"<<LIMPA<<"\n";
                cout << LIMPA << "DIGITE" << VERMELHO <<" 1-5" <<LIMPA << " PARA ESCOLHER O QUE FAZER " << "\n";
                cout << CIANO << "1) " << LIMPA <<"COMPRE SUA PASSAGEM\n";
                cout << CIANO << "2) " << LIMPA <<"VISUALIZE SUA VIAGEM\n";
                cout << CIANO << "3) " << LIMPA <<"ALTERE SEU ASSENTO\n";
                cout << CIANO << "4) " << LIMPA <<"CANCELE SUA VIAGEM\n";
                cout << CIANO << "5) " << LIMPA <<"LOGOUT\n";
                scanf("%d%*c", &escolha);
                if(escolha == 1 && pega_linha(atual) != -1 && pega_coluna(atual) != -1){
                    system("cls");
                    cout << AZUL << "Voce ja possui uma passagem" <<"\n\n";
                }
                else if(escolha == 1){
                    compra_passagem(atual,voos);
                }
                else if(escolha == 2){
                    system("cls");
                    if(pega_linha(atual) != -1 && pega_coluna(atual) != -1){
                        char esse = 'a' + pega_linha(atual);
                        achou_voo = acha_voo_nome(voos, pega_voo(atual));
                        cout << CIANO << "Destino: " << LIMPA << pega_cidade(pega_aviao(achou_voo)) <<"\n";
                        cout << CIANO << "Data da ida: " << LIMPA << pega_data_ida(pega_aviao(achou_voo)) <<"\n";
                        cout << CIANO << "Aeroporto: " << LIMPA << pega_aeroporto(pega_aviao(achou_voo)) <<"\n";
                        cout << CIANO << "Modelo do Aviao: " << LIMPA << pega_modelo(pega_aviao(achou_voo)) <<"\n";
                        cout << CIANO << "Poltrona: " << LIMPA << esse << pega_coluna(atual) + 1 <<"\n";
                        getchar();
                        system("cls");
                    }
                    else{
                        system("cls");
                        printf("Voce nao possui uma passagem\n");
                    }
                }
                else if(escolha == 3){
                    system("cls");
                    if(pega_linha(atual) != -1 && pega_coluna(atual) != -1){
                        altere_assento(atual,acha_voo_nome(voos, pega_voo(atual)));
                    }
                    else{
                        system("cls");
                        printf("Voce nao possui uma passagem\n");                
                    }
                }
                else if(escolha == 4){
                    system("cls");
                    if(pega_linha(atual) != -1 && pega_coluna(atual) != -1){
                        cancela_passagem(atual, acha_voo_nome(voos, pega_voo(atual)), todos_passageiros);
                    }
                    else{
                        system("cls");
                        printf("Voce nao possui uma passagem\n");
                    }
                }  
                else if(escolha == 5){
                    system("cls");
                    break;
                }
            }
        }
        
        else{
            if(quantidade_passageiros(todos_passageiros) > 0){
                system("cls");
                char teste;
                Voo v;
                L_LIST passageiros;
                Pessoa pessoa;
                for(int i = 0; i < 3; i++){
                    v = voos[i];
                    passageiros = pega_lista(voos[i]);
                    if(quantidade_passageiros(pega_lista(v)) == 0){
                        cout << "O VOO PARA " << VERMELHO <<pega_cidade(pega_aviao(v)) << LIMPA << " NAO POSSUI PASSAGEIROS" << "\n\n";
                    }
                    else{
                        cout << VERMELHO << pega_cidade(pega_aviao(v)) << ":" "\n\n";
                        int achou;
                        for(int j = 0; j < quantidade_passageiros(pega_lista(v)); j++){
                            L_NODE node = pega_head(passageiros);
                            achou = j;
                            while(achou > 0){
                                node = pega_next(node);
                                achou--;
                            }

                            pessoa = pega_pessoa(node);
                            cout << CIANO << "\nPassageiro: " << LIMPA << j + 1<<"\n\n";
                            cout << CIANO << "Nome: " << LIMPA << pega_nome(pessoa) << "\n";
                            cout << CIANO << "Cpf: " << LIMPA << pega_cpf(pessoa) <<"\n";
                            cout << CIANO << "Nascimento: " << LIMPA << pega_nascimento(pessoa) <<"\n";
                            cout << CIANO << "Rg: " << LIMPA << pega_rg(pessoa) <<"\n";
                            cout << CIANO << "Sexo: " << LIMPA << pega_sexo(pessoa) <<"\n";
                            
                        }
                    }
                    getchar();
                    system("cls");
                    
                }
                
                
            }
            else{
                system("cls");
                cout << AZUL << "SEM PASSAGEIROS NO MOMENTO" << LIMPA <<"\n";

            }
        }
        vez++;
    }
    
}