// O voo seria a estrutura geral, que relaciona os passageiros com o avião

#include <stdio.h>
#include <stdlib.h>
#include "voos.hpp"
#include <string.h>

#define MAX_TAMANHO_LINHA 1000
#define MAX_PALAVRAS 50

struct voo{
    Aviao plane;
    int lugares[10][4];
    int qtd;
    int restantes;
    L_LIST lista;
};

Voo cria_voo(Aviao plane){
    Voo nova = NULL;
    nova = (Voo) calloc(1, sizeof(struct voo));
    nova->plane = plane;
    nova->lista = cria_lista();
    nova->restantes = 40;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 4; j++){
            nova->lugares[i][j] = 0;
        }
    }
    return nova;
    
}

void adiciona_passageiro(Pessoa passageiro, Voo voo){
    int linha = pega_linha(passageiro);
    int coluna = pega_coluna(passageiro);
    voo->lugares[linha][coluna] = 1;
    insere_lista(voo->lista, passageiro);
    voo->qtd++;
    voo->restantes--;
    
}   

void mostra_passegeiro(Voo voo){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 4; j++){
            if(voo->lugares[i][j] == 1){
                for(int k = 0; k < voo->qtd; k++){
                    if(verifica_disponibilidade(voo->lista, i,j)){
                        
                        printf("%s", pega_nome_na_lista(pega_head(voo->lista), k, 0));
                    }
                }
            }            
        }
    }
}

// 1 = ocupado
int verifica_assento(Voo voo, int linha, int coluna){
    if(voo->qtd == 0) return 0;
    else{
        if(voo->lugares[linha][coluna] == 1){
            return 1;
        }
    }
}
void mostra_assento(Voo voo){
    char fileira = 'a';
    printf("  1 2 3 4\n");
    for(int i = 0; i < 10; i++){
        printf("%c ", fileira + i);
        for(int j = 0; j < 4; j++){
            printf("%d ", voo->lugares[i][j]);
        }
        printf("\n");
    }
}

Aviao pega_aviao(Voo voo){
    return voo->plane;
}

int pega_restantes(Voo voo){
    return voo->restantes;
}

Voo acha_voo_nome(Voo * voos, char * nome){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < voos[i]->qtd; j++){
            if(strcmp(pega_cidade(pega_aviao(voos[i])), nome) == 0){
                return voos[i];
            }
        }
    }
}

//retira a pessoa do assento antigo e coloca no novo
void troca_assento(Pessoa atual, Voo voo, int antigo_l, int antigo_c){
    int linha = pega_linha(atual);
    int coluna = pega_coluna(atual);
    voo->lugares[linha][coluna] = 1;
    voo->lugares[antigo_l][antigo_c] = 0;
}


void altere_assento(Pessoa atual, Voo voo){
    system("cls");
    int coluna;
    char fileira;
    char resposta;
    int fila;
    printf("Seu assento atual: %c%d\n",'a' + pega_linha(atual),pega_coluna(atual) + 1);
    mostra_assento(voo);

    while(1){
        printf("Escolha um assento (ex: g4): ");
        scanf("%c%d%*c", &fileira, &coluna);
        coluna--;
        fila = (fileira - 'a');
        while(1){
            if(verifica_assento(voo, fila,coluna) == 0){
                break;
            }
            printf("Esse assento esta ocupado, escolha outro: ");
            scanf("%c%d%*c", &fileira, &coluna);
            coluna--;
            fila = (fileira - 'a');
        }
        printf("Deseja trocar o assento %c%d por %c%d? (S/N) ", 'a' + pega_linha(atual),pega_coluna(atual) + 1, fileira,coluna + 1);
        scanf("%c%*c", &resposta);
        if(resposta == 'S'){
            int antigo_c, antigo_l;
            antigo_l = pega_linha(atual);
            antigo_c = pega_coluna(atual);
            escolher_assento(atual, fila, coluna);
            troca_assento(atual, voo, antigo_l, antigo_c);
            system("cls");
            printf("ASSENTO TROCADO!\n");
            break;
        }

    }
}
void cancela_passagem(Pessoa atual, Voo voo, L_LIST todos_passageiros){
    char resposta;
    int linha = pega_linha(atual), coluna = pega_coluna(atual);
    printf("Destino:%s\n",pega_cidade(pega_aviao(voo)));
    printf("Data da ida: %s\n",pega_data_ida(pega_aviao(voo)));
    printf("Aeroporto: %s\n",pega_aeroporto(pega_aviao(voo)));
    printf("Modelo do Aviao: %s\n",pega_modelo(pega_aviao(voo)));
    printf("Poltrona: %c%d\n",'a' + pega_linha(atual),pega_coluna(atual) + 1);
    printf("\n");
    printf("Deseja cancelar sua passagem? (S/N) ");
    scanf("%c%*c", &resposta);
    if(resposta == 'S'){
        voo->lugares[linha][coluna] = 0;
        voo->restantes++;
        remove_lista_por_nome(voo->lista, pega_nome(atual));
        escolher_assento(atual, -1,-1);
        FILE *arquivo;
        FILE *temp;
        char l[MAX_TAMANHO_LINHA];
        char *palavras[MAX_PALAVRAS];
        int numPalavras;

        arquivo = fopen("arquivo.txt", "r");
        temp = fopen("temp.txt", "w");

        while (fgets(l, sizeof(l), arquivo) != NULL) {
            l[strcspn(l, "\n")] = '\0';
            numPalavras = 0;
            char *token = strtok(l, ",");

            while (token != NULL && numPalavras < MAX_PALAVRAS) {
                palavras[numPalavras] = strdup(token);  
                numPalavras++;
                token = strtok(NULL, ",");
            }
            //nome,cpf,rg,n,s,v,l,c
            if(strcmp(pega_nome(atual), palavras[0]) != 0){
                int l = atoi(palavras[6]),c = atoi(palavras[7]);
                fprintf(temp, "%s,%s,%s,%s,%s,%s,%d,%d\n", palavras[0], palavras[1], palavras[2], palavras[3]
                    , palavras[4], palavras[5],  l, c);
            }

        }
        mostra_lista(voo->lista);
        mostra_lista(todos_passageiros);
        fclose(arquivo);
        fclose(temp);
        remove("arquivo.txt");
        rename("temp.txt", "arquivo.txt");
    }
}

L_LIST pega_lista(Voo voo){
    return voo->lista;
}