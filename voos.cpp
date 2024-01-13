// O voo seria a estrutura geral, que relaciona os passageiros com o avião

#include <stdio.h>
#include <stdlib.h>
#include "voos.hpp"






struct voo{
    Aviao plane;
    int lugares[20][4];
    int qtd;
    L_LIST lista;
};

Voo cria_voo(Aviao plane){
    Voo nova = NULL;
    nova = (Voo) calloc(1, sizeof(struct voo));
    nova->plane = plane;
    nova->lista = cria_lista();
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 4; j++){
            nova->lugares[i]
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
    
}   

void mostra_passegeiro(Voo voo){
    for(int i = 0; i < 20; i++){
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


int verifica_assento(Voo voo, int linha, int coluna){
    if(voo->qtd == 0) return 1;
    else{
        
    }
}
