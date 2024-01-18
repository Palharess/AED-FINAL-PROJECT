// O voo seria a estrutura geral, que relaciona os passageiros com o avião

#include <stdio.h>
#include <stdlib.h>
#include "voos.hpp"
#include <string.h>


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
    Pessoa teste;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < voos[i]->qtd; j++){
            teste = retorna_by_id(pega_head(voos[i]->lista), j, 0);
            if(strcmp(pega_nome(teste), nome) == 0){
                return voos[i];
            }
        }
    }
}

void altere_assento(Pessoa atual, Voo voo){
    mostra_assento(voo);
}