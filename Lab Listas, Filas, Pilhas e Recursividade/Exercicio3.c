#include <stdio.h>
#include <stdbool.h>

#define MAX 10 // Tamanho máximo do vetor compartilhado

typedef struct {
    int vetor[MAX];
    int topoA;
    int topoB;
} Pilhas;

// Função para inicializar as pilhas A e B
void criaPilha(Pilhas* pilhas) {
    pilhas->topoA = -1; // Inicializa topo da pilha A
    pilhas->topoB = MAX; // Inicializa topo da pilha B
}

// Função para empilhar um objeto na pilha A
void empilhaA(Pilhas* pilhas, int obj) {
    if (pilhas->topoA + 1 == pilhas->topoB) {
        printf("A pilha A esta cheia!\n");
        return;
    }
    pilhas->topoA++;
    pilhas->vetor[pilhas->topoA] = obj;
    printf("Empilhado na pilha A: %d\n", obj);
}

// Função para empilhar um objeto na pilha B
void empilhaB(Pilhas* pilhas, int obj) {
    if (pilhas->topoB - 1 == pilhas->topoA) {
        printf("A pilha B esta cheia!\n");
        return;
    }
    pilhas->topoB--;
    pilhas->vetor[pilhas->topoB] = obj;
    printf("Empilhado na pilha B: %d\n", obj);
}

// Função para verificar se a pilha A está vazia
bool vaziaA(Pilhas* pilhas) {
    return pilhas->topoA == -1;
}

// Função para verificar se a pilha B está vazia
bool vaziaB(Pilhas* pilhas) {
    return pilhas->topoB == MAX;
}

// Função para desempilhar um objeto da pilha A
int desempilhaA(Pilhas* pilhas) {
    if (vaziaA(pilhas)) {
        printf("A pilha A esta vazia!\n");
        return -1;
    }
    int obj = pilhas->vetor[pilhas->topoA];
    pilhas->topoA--;
    printf("Desempilhado da pilha A: %d\n", obj);
    return obj;
}

// Função para desempilhar um objeto da pilha B
int desempilhaB(Pilhas* pilhas) {
    if (vaziaB(pilhas)) {
        printf("A pilha B esta vazia!\n");
        return -1;
    }
    int obj = pilhas->vetor[pilhas->topoB];
    pilhas->topoB++;
    printf("Desempilhado da pilha B: %d\n", obj);
    return obj;
}

// Função para verificar se a pilha A está cheia
bool cheiaA(Pilhas* pilhas) {
    return pilhas->topoA + 1 == pilhas->topoB;
}

// Função para verificar se a pilha B está cheia
bool cheiaB(Pilhas* pilhas) {
    return pilhas->topoB - 1 == pilhas->topoA;
}

// Função para retornar o topo da pilha A sem desempilhar
int topoA(Pilhas* pilhas) {
    if (vaziaA(pilhas)) {
        printf("A pilha A esta vazia!\n");
        return -1;
    }
    return pilhas->vetor[pilhas->topoA];
}

// Função para retornar o topo da pilha B sem desempilhar
int topoB(Pilhas* pilhas) {
    if (vaziaB(pilhas)) {
        printf("A pilha B esta vazia!\n");
        return -1;
    }
    return pilhas->vetor[pilhas->topoB];
}

// Função para mostrar todos os elementos da pilha A
void mostrarPilhaA(Pilhas* pilhas) {
	int i;
    if (vaziaA(pilhas)) {
        printf("A pilha A esta vazia!\n");
        return;
    }
    printf("Pilha A: ");
    
	for (i = 0; i <= pilhas->topoA; i++) {
	    printf("%d ", pilhas->vetor[i]);
    }
    printf("\n");
}

// Função para mostrar todos os elementos da pilha B
void mostrarPilhaB(Pilhas* pilhas) {
	int i;
    if (vaziaB(pilhas)) {
        printf("A pilha B esta vazia!\n");
        return;
    }
    printf("Pilha B: ");
    for (i = pilhas->topoB; i < MAX; i++) {
        printf("%d ", pilhas->vetor[i]);
    }
    printf("\n");
}

// Função para retornar o tamanho da pilha A
int tamanhoA(Pilhas* pilhas) {
    return pilhas->topoA + 1;
}

// Função para retornar o tamanho da pilha B
int tamanhoB(Pilhas* pilhas) {
    return MAX - pilhas->topoB;
}

int main() {
    Pilhas pilhas;
    criaPilha(&pilhas);

    // Empilhando elementos nas duas pilhas
    empilhaA(&pilhas, 10);
    empilhaA(&pilhas, 20);
    empilhaB(&pilhas, 30);
    empilhaB(&pilhas, 40);
    empilhaA(&pilhas, 50);

    // Mostrando as pilhas
    mostrarPilhaA(&pilhas);
    mostrarPilhaB(&pilhas);

    // Desempilhando da pilha A
    desempilhaA(&pilhas);

    // Desempilhando da pilha B
    desempilhaB(&pilhas);

    // Mostrando as pilhas após desempilhar
    mostrarPilhaA(&pilhas);
    mostrarPilhaB(&pilhas);

    // Verificando os tamanhos das pilhas
    printf("Tamanho da pilha A: %d\n", tamanhoA(&pilhas));
    printf("Tamanho da pilha B: %d\n", tamanhoB(&pilhas));

    return 0;
}

