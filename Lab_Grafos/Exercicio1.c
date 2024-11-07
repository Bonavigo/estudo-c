#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100  // N�mero m�ximo de v�rtices

// Fun��o para verificar se todos os valores na linha s�o 0 ou 1
int verificarValoresValidos(char linha[]) {
    int i;
    for (i = 0; linha[i] != '\0'; i++) {
        if (linha[i] != ' ' && linha[i] != '0' && linha[i] != '1') {
            return 0;  // Retorna 0 se encontrar um caractere diferente de 0, 1 ou espa�o
        }
    }
    return 1;  // Retorna 1 se todos os caracteres s�o v�lidos
}

// Fun��o para ler a matriz de adjac�ncias do grafo
void lerMatrizAdjacencias(int matriz[MAX_VERTICES][MAX_VERTICES], int *numVertices) {
    int i = 0, j;
    char linha[256];  // Buffer para ler a linha

    printf("Digite a matriz de adjacencias (linha por linha). Digite 'FIM' em maiusculo e pressione Enter para terminar:\n");
    
    while (i < MAX_VERTICES) {
        // L� uma linha completa
        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            break;  // Sai se houver erro na leitura
        }

        // Remove o caractere de nova linha do final, se presente
        linha[strcspn(linha, "\n")] = '\0';

        // Verifica se a entrada � "FIM"
        if (strcmp(linha, "FIM") == 0) {
            break;  // Sai do loop se "FIM" for inserido
        }

        // Verifica se os valores da linha s�o v�lidos (somente 0 e 1)
        if (!verificarValoresValidos(linha)) {
            printf("Entrada invalida! Por favor, insira apenas os numeros 0 e 1.\n");
            continue;  // Pede para o usu�rio inserir novamente
        }

        // L� os valores da linha
        j = 0;
        char *token = strtok(linha, " ");
        while (token != NULL && j < MAX_VERTICES) {
            matriz[i][j] = atoi(token);  // Converte o token para inteiro
            token = strtok(NULL, " ");     // Passa para o pr�ximo token
            j++;
        }

        // Incrementa o n�mero de linhas lidas se j > 0
        if (j > 0) {
            i++;  
        }
    }

    *numVertices = i;  // Define o n�mero de v�rtices com base na quantidade de linhas lidas
}

// Fun��o para imprimir a matriz de adjac�ncias
void imprimirMatrizAdjacencias(int matriz[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int i, j;

    printf("Matriz de adjacencias:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Fun��o para listar todas as arestas do grafo
void listarArestas(int matriz[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("\nArestas do grafo:\n");
    int i;
    int j;
    // Percorre a matriz e imprime as arestas
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            if (matriz[i][j] == 1) {
                printf("(%d, %d)\n", i, j);  // Imprime a aresta (i, j)
            }
        }
    }
}

// Fun��o para imprimir a lista de adjac�ncias
void imprimirListaAdjacencias(int matriz[MAX_VERTICES][MAX_VERTICES], int numVertices) {
 	int i;
 	int j;
    printf("\nLista de adjacencias:\n");
	for (i = 0; i < numVertices; i++) {
        printf("V�rtice %d: ", i);
        for (j = 0; j < numVertices; j++) {
            if (matriz[i][j] == 1) {
                printf("%d ", j);  // Imprime o vizinho do v�rtice
            }
        }
        printf("\n");
    }
}

// Fun��o para verificar o tipo de grafo (d�grafo, n�o direcionado ou misto)
void verificarTipoGrafo(int matriz[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int i;
    int j;
    int digrafo = 1;  // Supondo que � um d�grafo inicialmente
    int grafoNaoDirecionado = 1;  // Supondo que � um grafo n�o direcionado inicialmente

    // Percorre a matriz de adjac�ncias para verificar a simetria das arestas
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            // Verifica se existe uma aresta de i para j, mas n�o existe de j para i (n�o � n�o direcionado)
            if (matriz[i][j] == 1 && matriz[j][i] == 0) {
                grafoNaoDirecionado = 0;  // N�o � um grafo n�o direcionado
            }
            // Verifica se existe uma aresta bidirecional (n�o � d�grafo)
            if (matriz[i][j] == 1 && matriz[j][i] == 1) {
                digrafo = 0;  // N�o � um d�grafo
            }
        }
    }

    // Agora, baseando-se nas verifica��es acima, determina o tipo de grafo
    if (digrafo) {
        printf("O grafo e um digrafo porque as arestas tem uma direcao\n");
        printf("Ou seja, elas tem um sentido de um v�rtice para outro.\n");
    } else if (grafoNaoDirecionado) {
        printf("O grafo e um grafo nao direcionado. As arestas nao tem direcao.\n");
        printf("Ou seja, elas conectam os vertices de forma simetrica.\n");
    } else {
        printf("O grafo e um grafo misto porque ele tem arestas direcionadas e nao direcionadas.\n");
    }
}

// Fun��o para calcular o grau de cada v�rtice
void calcularGrau(int matriz[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int grauEntrada[MAX_VERTICES] = {0};  // Grau de entrada para cada v�rtice
    int grauSaida[MAX_VERTICES] = {0};   // Grau de sa�da para cada v�rtice

    // Calcula os graus de entrada e sa�da
    int i;
    int j;
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            if (matriz[i][j] == 1) {
                grauSaida[i]++;  // Aresta de i para j
                grauEntrada[j]++; // Aresta de i para j
            }
        }
    }

    // Exibe os graus de cada v�rtice
    printf("\nGrau de cada vertice:\n");
    for (i = 0; i < numVertices; i++) {
        printf("Vertice %d: Grau de Entrada = %d, Grau de Saida = %d\n", i, grauEntrada[i], grauSaida[i]);
    }
}

// Fun��o auxiliar para detectar ciclos na DFS
int dfsCiclo(int v, int matriz[MAX_VERTICES][MAX_VERTICES], int visitado[MAX_VERTICES], int recursao[MAX_VERTICES], int numVertices) {
    int i;
    visitado[v] = 1;  // Marca o v�rtice como visitado
    recursao[v] = 1;  // Marca o v�rtice na pilha de recurs�o

    // Percorre todos os vizinhos
    for (i = 0; i < numVertices; i++) {
        if (matriz[v][i] == 1) {
            // Se o vizinho ainda est� na pilha de recurs�o, h� um ciclo
            if (recursao[i] == 1) {
                return 1;  // Ciclo encontrado
            }
            // Se o vizinho ainda n�o foi visitado, chama DFS recursivamente
            if (!visitado[i] && dfsCiclo(i, matriz, visitado, recursao, numVertices)) {
                return 1;  // Ciclo encontrado
            }
        }
    }

    recursao[v] = 0;  // Retira o v�rtice da pilha de recurs�o
    return 0;  // Nenhum ciclo encontrado
}

// Fun��o para verificar se o grafo � c�clico
void verificarCiclicidade(int matriz[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int visitado[MAX_VERTICES] = {0};  // Vetor de v�rtices visitados
    int recursao[MAX_VERTICES] = {0};  // Pilha de recurs�o

    int i;
    for (i = 0; i < numVertices; i++) {
        if (!visitado[i]) {
            if (dfsCiclo(i, matriz, visitado, recursao, numVertices)) {
                printf("O grafo possui um ciclo.\n");
                return;  // Ciclo encontrado
            }
        }
    }
    printf("O grafo nao possui ciclos.\n");  // Nenhum ciclo encontrado
}

int main() {
    int matriz[MAX_VERTICES][MAX_VERTICES] = {0};  // Matriz de adjac�ncias
    int numVertices;

    lerMatrizAdjacencias(matriz, &numVertices);  // L� a matriz de adjac�ncias

    imprimirMatrizAdjacencias(matriz, numVertices);  // Imprime a matriz de adjac�ncias
    listarArestas(matriz, numVertices);  // Lista as arestas
    imprimirListaAdjacencias(matriz, numVertices);  // Imprime a lista de adjac�ncias
    verificarTipoGrafo(matriz, numVertices);  // Verifica o tipo de grafo
    calcularGrau(matriz, numVertices);  // Calcula os graus dos v�rtices
    verificarCiclicidade(matriz, numVertices);  // Verifica se o grafo � c�clico

    return 0;
}

