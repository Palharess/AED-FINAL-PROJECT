#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAMANHO_LINHA 1000
#define MAX_PALAVRAS 50

int main() {
    FILE *arquivo;
    char linha[MAX_TAMANHO_LINHA];
    char *palavras[MAX_PALAVRAS];
    int numPalavras;

    arquivo = fopen("arquivo.txt", "r");

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Substituir o caractere de nova linha por um caractere nulo
        linha[strcspn(linha, "\n")] = '\0';

        // Inicializar variáveis
        numPalavras = 0;

        // Obter a primeira palavra
        char *token = strtok(linha, " ");

        // Processar as palavras restantes
        while (token != NULL && numPalavras < MAX_PALAVRAS) {
            palavras[numPalavras] = strdup(token);  // alocar memória e copiar a palavra
            numPalavras++;

            token = strtok(NULL, " ");
        }

        // Imprimir as palavras (ou você pode fazer o que quiser com elas)
        printf("Palavras na linha: ");
        printf("%d ", atoi(&palavras[7][0]));
        printf("\n");

    }

    fclose(arquivo);


    return 0;
}
