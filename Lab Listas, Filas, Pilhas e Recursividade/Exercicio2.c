#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct {
    int itens[MAX];
    int frente;
    int final;
    int tamanho;
} Fila;

// Fun��o para criar uma fila vazia
void criaFila(Fila *fila) {
    fila->frente = -1;
    fila->final = -1;
    fila->tamanho = 0;
}

// Fun��o para verificar se a fila est� vazia
bool vazia(Fila *fila) {
    return fila->tamanho == 0;
}

// Fun��o para verificar se a fila est� cheia
bool cheia(Fila *fila) {
    return fila->tamanho == MAX;
}

// Fun��o para enfileirar um elemento no final da fila
void enfileira(Fila *fila, int obj) {
    if (cheia(fila)) {
        printf("A fila est� cheia! Nao e poss�vel enfileirar %d.\n", obj);
        return;
    }

    if (fila->frente == -1) fila->frente = 0;

    fila->final = (fila->final + 1) % MAX;
    fila->itens[fila->final] = obj;
    fila->tamanho++;
    printf("Enfileirado: %d\n", obj);
}

// Fun��o para desenfileirar um elemento da frente da fila
int desenfileira(Fila *fila) {
    if (vazia(fila)) {
        printf("A fila esta vazia! Nao e poss�vel desenfileirar.\n");
        return -1;
    }

    int obj = fila->itens[fila->frente];
    fila->frente = (fila->frente + 1) % MAX;
    fila->tamanho--;

    if (vazia(fila)) {
        // Reseta os ponteiros se a fila est� vazia
        fila->frente = -1;
        fila->final = -1;
    }

    printf("Desenfileirado: %d\n", obj);
    return obj;
}

// Fun��o para retornar o primeiro elemento da fila sem remov�-lo
int cabeca(Fila *fila) {
    if (vazia(fila)) {
        printf("A fila esta vazia! Nao ha cabeca.\n");
        return -1;
    }
    return fila->itens[fila->frente];
}

// Fun��o para retornar o �ltimo elemento da fila sem remov�-lo
int cauda(Fila *fila) {
    if (vazia(fila)) {
        printf("A fila esta vazia! Nao ha cauda.\n");
        return -1;
    }
    return fila->itens[fila->final];
}

// Fun��o para mostrar todos os elementos da fila
void mostrarFila(Fila *fila) {
    if (vazia(fila)) {
        printf("A fila esta vazia!\n");
        return;
    }
    printf("Fila: ");
    int i;
	for (i = 0; i < fila->tamanho; i++) {
        int idx = (fila->frente + i) % MAX;
        printf("%d ", fila->itens[idx]);
    }
    printf("\n");
}

// Fun��o para pesquisar se um elemento est� na fila
bool pesquisa(Fila *fila, int obj) {
    int i;
	if (vazia(fila)) {
        return false;
    }
    for (i = 0; i < fila->tamanho; i++) {
        int idx = (fila->frente + i) % MAX;
        if (fila->itens[idx] == obj) {
            return true;
        }
    }
    return false;
}

// Fun��o para retornar o tamanho da fila
int tamanho(Fila *fila) {
    return fila->tamanho;
}

int main() {
    Fila fila;
    criaFila(&fila);

    // Testando a implementa��o
    enfileira(&fila, 10);
    enfileira(&fila, 20);
    enfileira(&fila, 30);
    enfileira(&fila, 40);
    enfileira(&fila, 50);

    while (1) {
        int opcao;
        printf("\nEscolha uma opcao:\n");
        printf("1. Mostrar fila\n");
        printf("2. Enfileirar\n");
        printf("3. Desenfileirar\n");
        printf("4. Pesquisar n�mero na fila\n");
        printf("5. Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        printf("\n");
        printf("\n");

        if (opcao == 1) {
            mostrarFila(&fila);
        } else if (opcao == 2) {
            int num;
            printf("Digite o numero a ser enfileirado: ");
            scanf("%d", &num);
            enfileira(&fila, num);
        } else if (opcao == 3) {
            desenfileira(&fila);
        } else if (opcao == 4) {
            int num;
            printf("Digite o numero para pesquisar na fila: ");
            scanf("%d", &num);
            if (pesquisa(&fila, num)) {
                printf("Numero %d encontrado na fila.\n", num);
            } else {
                printf("Numero %d nao encontrado na fila.\n", num);
            }
        } else if (opcao == 5) {
            printf("Saindo do programa.\n");
            break;
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    }

    return 0;
}

