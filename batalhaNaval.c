#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define OCUPADO 3
#define LIVRE 0

int main() {
    int tabuleiro[TAM][TAM];
    
    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = LIVRE;
        }
    }

    int podeInserir = 1;

    // --- Navio 1: Horizontal ---
    int l1 = 1, c1 = 2; // coordenadas iniciais
    if (c1 + NAVIO <= TAM) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[l1][c1 + i] != LIVRE) podeInserir = 0;
        }
        if (podeInserir) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[l1][c1 + i] = OCUPADO;
            }
        } else {
            printf("Erro: Sobreposição ou limite no navio horizontal 1.\n");
        }
    } else {
        printf("Erro: Navio horizontal 1 fora dos limites.\n");
    }

    podeInserir = 1;

    // --- Navio 2: Vertical ---
    int l2 = 5, c2 = 4;
    if (l2 + NAVIO <= TAM) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[l2 + i][c2] != LIVRE) podeInserir = 0;
        }
        if (podeInserir) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[l2 + i][c2] = OCUPADO;
            }
        } else {
            printf("Erro: Sobreposição ou limite no navio vertical 2.\n");
        }
    } else {
        printf("Erro: Navio vertical 2 fora dos limites.\n");
    }

    podeInserir = 1;

    // --- Navio 3: Diagonal ↘ (linha++, coluna++) ---
    int l3 = 0, c3 = 0;
    if (l3 + NAVIO <= TAM && c3 + NAVIO <= TAM) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[l3 + i][c3 + i] != LIVRE) podeInserir = 0;
        }
        if (podeInserir) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[l3 + i][c3 + i] = OCUPADO;
            }
        } else {
            printf("Erro: Sobreposição ou limite no navio diagonal ↘ 3.\n");
        }
    } else {
        printf("Erro: Navio diagonal ↘ 3 fora dos limites.\n");
    }

    podeInserir = 1;

    // --- Navio 4: Diagonal ↙ (linha++, coluna--) ---
    int l4 = 0, c4 = 9;
    if (l4 + NAVIO <= TAM && c4 - NAVIO + 1 >= 0) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[l4 + i][c4 - i] != LIVRE) podeInserir = 0;
        }
        if (podeInserir) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[l4 + i][c4 - i] = OCUPADO;
            }
        } else {
            printf("Erro: Sobreposição ou limite no navio diagonal ↙ 4.\n");
        }
    } else {
        printf("Erro: Navio diagonal ↙ 4 fora dos limites.\n");
    }

    // --- Exibir o tabuleiro ---
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
