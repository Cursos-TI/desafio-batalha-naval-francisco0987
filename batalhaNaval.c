#include <stdio.h>
#define TAM 10
#define NAVIO 3
#define OCUPADO 3
#define LIVRE 0
#define HABILIDADE 5

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = LIVRE;
        }
    }

    // --- Posiciona navios (como antes) ---

    // Navio horizontal
    int l1 = 1, c1 = 1;
    for (int i = 0; i < NAVIO; i++) {
        if (c1 + i < TAM) {
            tabuleiro[l1][c1 + i] = OCUPADO;
        }
    }

    // Navio vertical
    int l2 = 4, c2 = 7;
    for (int i = 0; i < NAVIO; i++) {
        if (l2 + i < TAM) {
            tabuleiro[l2 + i][c2] = OCUPADO;
        }
    }

    // Navio diagonal ↘
    int l3 = 0, c3 = 0;
    for (int i = 0; i < NAVIO; i++) {
        if (l3 + i < TAM && c3 + i < TAM) {
            tabuleiro[l3 + i][c3 + i] = OCUPADO;
        }
    }

    // Navio diagonal ↙
    int l4 = 0, c4 = 9;
    for (int i = 0; i < NAVIO; i++) {
        if (l4 + i < TAM && c4 - i >= 0) {
            tabuleiro[l4 + i][c4 - i] = OCUPADO;
        }
    }

    // --- Habilidade: CONE (matriz 5x5) ---
    int cone[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1; // dentro do cone
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // Aplica cone no tabuleiro (origem no centro da matriz do cone)
    int origemLinhaCone = 5, origemColunaCone = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int li = origemLinhaCone + i - 2;
            int co = origemColunaCone + j - 2;
            if (li >= 0 && li < TAM && co >= 0 && co < TAM && cone[i][j] == 1 && tabuleiro[li][co] == LIVRE) {
                tabuleiro[li][co] = HABILIDADE;
            }
        }
    }

    // --- Habilidade: CRUZ (matriz 5x5) ---
    int cruz[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1; // linhas central e coluna central
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Aplica cruz no tabuleiro
    int origemLinhaCruz = 2, origemColunaCruz = 5;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int li = origemLinhaCruz + i - 2;
            int co = origemColunaCruz + j - 2;
            if (li >= 0 && li < TAM && co >= 0 && co < TAM && cruz[i][j] == 1 && tabuleiro[li][co] == LIVRE) {
                tabuleiro[li][co] = HABILIDADE;
            }
        }
    }

    // --- Habilidade: OCTAEDRO (losango) ---
    int octaedro[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedro[i][j] = 1; // forma de losango
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // Aplica octaedro no tabuleiro
    int origemLinhaOct = 7, origemColunaOct = 5;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int li = origemLinhaOct + i - 2;
            int co = origemColunaOct + j - 2;
            if (li >= 0 && li < TAM && co >= 0 && co < TAM && octaedro[i][j] == 1 && tabuleiro[li][co] == LIVRE) {
                tabuleiro[li][co] = HABILIDADE;
            }
        }
    }

    // --- Exibe o tabuleiro ---
    printf("\nTabuleiro final:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == LIVRE)
                printf("0 ");
            else if (tabuleiro[i][j] == OCUPADO)
                printf("3 ");
            else if (tabuleiro[i][j] == HABILIDADE)
                printf("5 ");
        }
        printf("\n");
    }

    return 0;
}
