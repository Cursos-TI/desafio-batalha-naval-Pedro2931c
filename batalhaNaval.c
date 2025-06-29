#include <stdio.h>
#include <stdlib.h>

#define TAM_NOVATO 5
#define TAM_AVENTUREIRO 10
#define TAM_HABILIDADE 5
#define NAVIO 3

void imprimirMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void inicializarMatriz(int linhas, int colunas, int matriz[linhas][colunas], int valor) {
    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            matriz[i][j] = valor;
}

int main() {
    // Nível Novato
    int tabuleiroNovato[TAM_NOVATO][TAM_NOVATO];
    inicializarMatriz(TAM_NOVATO, TAM_NOVATO, tabuleiroNovato, 0);

    for (int j = 0; j < 3; j++) {
        tabuleiroNovato[1][j] = NAVIO;
        printf("Navio Horizontal - Coordenada: (%d, %d)\n", 1, j);
    }

    for (int i = 2; i < 5; i++) {
        tabuleiroNovato[i][3] = NAVIO;
        printf("Navio Vertical - Coordenada: (%d, %d)\n", i, 3);
    }

    printf("\nTabuleiro Novato (5x5):\n");
    imprimirMatriz(TAM_NOVATO, TAM_NOVATO, tabuleiroNovato);


    // Nível Aventureiro
    int tabuleiroAventureiro[TAM_AVENTUREIRO][TAM_AVENTUREIRO];
    inicializarMatriz(TAM_AVENTUREIRO, TAM_AVENTUREIRO, tabuleiroAventureiro, 0);

    for (int j = 1; j <= 3; j++) {
        tabuleiroAventureiro[0][j] = NAVIO;
    }

    for (int i = 5; i <= 7; i++) {
        tabuleiroAventureiro[i][6] = NAVIO;
    }

    for (int i = 2; i < 5; i++) {
        tabuleiroAventureiro[i][i] = NAVIO;
    }

    for (int i = 7, j = 2; i <= 9 && j <= 4; i++, j++) {
        tabuleiroAventureiro[i][TAM_AVENTUREIRO - j - 1] = NAVIO;
    }

    printf("\nTabuleiro Aventureiro (10x10):\n");
    imprimirMatriz(TAM_AVENTUREIRO, TAM_AVENTUREIRO, tabuleiroAventureiro);


    // Nível Mestre
    int cone[TAM_HABILIDADE][TAM_HABILIDADE], cruz[TAM_HABILIDADE][TAM_HABILIDADE], octaedro[TAM_HABILIDADE][TAM_HABILIDADE];
    inicializarMatriz(TAM_HABILIDADE, TAM_HABILIDADE, cone, 0);
    inicializarMatriz(TAM_HABILIDADE, TAM_HABILIDADE, cruz, 0);
    inicializarMatriz(TAM_HABILIDADE, TAM_HABILIDADE, octaedro, 0);

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i + j >= 2 && j - i <= 2 && i - j <= 2 && i <= 2) {
                cone[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }

    printf("\nHabilidade: Cone\n");
    imprimirMatriz(TAM_HABILIDADE, TAM_HABILIDADE, cone);

    printf("\nHabilidade: Cruz\n");
    imprimirMatriz(TAM_HABILIDADE, TAM_HABILIDADE, cruz);

    printf("\nHabilidade: Octaedro\n");
    imprimirMatriz(TAM_HABILIDADE, TAM_HABILIDADE, octaedro);

    return 0;
}
