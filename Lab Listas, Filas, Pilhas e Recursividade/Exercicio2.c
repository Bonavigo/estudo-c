#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct {
    int itens[MAX];
    int frente;
    int final;
    int tamanho;
} Fila;

// Função para criar uma fila vazia
void criaFila(Fila *fila) {
    fila->frente = -1;
    fila->final = -1;
    fila->tamanho = 0;
}

// Função para verificar se a fila está vazia
bool vazia(Fila *fila) {
    return fila->tamanho == 0;
}

// Função para verificar se a fila está cheia
bool cheia(Fila *fila) {
    return fila->tamanho == MAX;
}

// Função para enfileirar um elemento no final da fila
void enfileira(Fila *fila, int obj) {
    if (cheia(fila)) {
        printf("A fila está cheia! Nao e possível enfileirar %d.\n", obj);
        return;
    }

    if (fila->frente == -1) fila->frente = 0;

    fila->final = (fila->final + 1) % MAX;
    fila->itens[fila->final] = obj;
    fila->tamanho++;
    printf("Enfileirado: %d\n", obj);
}

// Função para desenfileirar um elemento da frente da fila
int desenfileira(Fila *fila) {
    if (vazia(fila)) {
        printf("A fila esta vazia! Nao e possível desenfileirar.\n");
        return -1;
    }

    int obj = fila->itens[fila->frente];
    fila->frente = (fila->frente + 1) % MAX;
    fila->tamanho--;

    if (vazia(fila)) {
        // Reseta os ponteiros se a fila está vazia
        fila->frente = -1;
        fila->final = -1;
    }

    printf("Desenfileirado: %d\n", obj);
    return obj;
}

// Função para retornar o primeiro elemento da fila sem removê-lo
int cabeca(Fila *fila) {
    if (vazia(fila)) {
        printf("A fila esta vazia! Nao ha cabeca.\n");
        return -1;
    }
    return fila->itens[fila->frente];
}

// Função para retornar o último elemento da fila sem removê-lo
int cauda(Fila *fila) {
    if (vazia(fila)) {
        printf("A fila esta vazia! Nao ha cauda.\n");
        return -1;
    }
    return fila->itens[fila->final];
}

// Função para mostrar todos os elementos da fila
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

// Função para pesquisar se um elemento está na fila
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

// Função para retornar o tamanho da fila
int tamanho(Fila *fila) {
    return fila->tamanho;
}

int main() {
    Fila fila;
    criaFila(&fila);

    // Testando a implementação
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
        printf("4. Pesquisar número na fila\n");
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

