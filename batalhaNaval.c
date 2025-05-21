#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

int main() {
    // Declara o tabuleiro e inicializa todas as posições com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Define as coordenadas iniciais dos navios (pode alterar conforme necessário)
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 4;

    int linhaNavioVertical = 5;
    int colunaNavioVertical = 6;

    int podeInserir = 1;

    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaNavioHorizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
        podeInserir = 0;
    }

    // Verifica se o navio vertical cabe no tabuleiro
    if (linhaNavioVertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
        podeInserir = 0;
    }

    // Verifica se há sobreposição para o navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO && podeInserir; i++) {
        if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] != AGUA) {
            printf("Erro: Sobreposição detectada no navio horizontal.\n");
            podeInserir = 0;
        }
    }

    // Verifica se há sobreposição para o navio vertical
    for (int i = 0; i < TAMANHO_NAVIO && podeInserir; i++) {
        if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] != AGUA) {
            printf("Erro: Sobreposição detectada no navio vertical.\n");
            podeInserir = 0;
        }
    }

    // Se for possível, posiciona os navios
    if (podeInserir) {
        // Posiciona o navio horizontal
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = NAVIO;
        }

        // Posiciona o navio vertical
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = NAVIO;
        }

        // Exibe o tabuleiro no console
        printf("Tabuleiro:\n");
        for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
            for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
