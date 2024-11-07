#include <stdio.h>

int main() {
  int n, i, j;

  printf("Digite o numero de vertices (n): ");
  scanf("%d", &n);

  // Matriz de adjacência
  int matriz[n][n];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) {
        matriz[i][j] = 0;
      } else {
        matriz[i][j] = 1;
      }
    }
  }

  // Imprimindo a matriz de adjacência
  printf("\nMatriz de Adjacencia:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  // Lista de adjacências
  printf("\nLista de Adjacencias:\n");
  for (i = 0; i < n; i++) {
    printf("%d: ", i);
    for (j = 0; j < n; j++) {
      if (matriz[i][j] == 1) {
        printf("%d ", j);
      }
    }
    printf("\n");
  }

  return 0;
}
