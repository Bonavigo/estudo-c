#include <stdio.h>

#define MAX_VERTICES 100  // Definindo um n�mero m�ximo de v�rtices

void imprimir_arestas(int matriz[MAX_VERTICES][MAX_VERTICES], int n) {
	int i;
	int j;
    printf("Arestas e seus pesos:\n");
    
    // Percorrer a matriz de adjac�ncias
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {  // Apenas i < j para evitar duplica��o de arestas
            if (matriz[i][j] != 0) {  // Se houver uma aresta entre i e j
                printf("(%d, %d) -> Peso: %d\n", i + 1, j + 1, matriz[i][j]);
            }
        }
    }
}

int main() {
	int i;
    int n;
    int j;
    
    // Leitura da quantidade de v�rtices
    printf("Digite o numero de vertices: ");
    scanf("%d", &n);
    
    int matriz[MAX_VERTICES][MAX_VERTICES];
    
    // Leitura da matriz de adjac�ncias (onde o peso � 0 para v�rtices desconectados)
    printf("\nDigite a matriz de adjac�ncias: (Lembrese que precisa ser uma matriz Quadratica\n");
    printf("aonde a quantidadede de V e A sao iguais)\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    
    // Chama a fun��o para imprimir as arestas
    imprimir_arestas(matriz, n);
    
    return 0;
}

