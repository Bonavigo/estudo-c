#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int n, i, j;

    fp = fopen("Entrada.txt", "r");

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fscanf(fp, "%d", &n);  // Lê o número de vértices do grafo

    // Aloca a matriz corretamente como um ponteiro duplo (int**)
    int **matriz = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    // Inicializa a matriz com zeros
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz[i][j] = 0;
        }
    }

    // Lê a matriz triangular inferior
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            fscanf(fp, "%d", &matriz[i][j]);
        }
    }
    fclose(fp);

    // Completa a matriz (torna-a simétrica)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j > i) {  // Preenche a parte superior da matriz
                matriz[i][j] = matriz[j][i];
            }
        }
    }

    // Imprime a matriz completa
    printf("Matriz Completa:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Libera a memória
    for (i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

