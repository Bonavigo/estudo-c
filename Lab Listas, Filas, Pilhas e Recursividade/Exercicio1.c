#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Definição do nó da lista duplamente encadeada
typedef struct Node {
    char nome[100];
    struct Node* next;
    struct Node* prev;
} Node;

// Definição do vetor de listas encadeadas
typedef struct {
    Node* list[ALPHABET_SIZE];  // Vetor de 26 listas para cada letra do alfabeto
} Index;

// Função para inicializar a estrutura
void initIndex(Index* index) {
    int i;
	for (i = 0; i < ALPHABET_SIZE; i++) {
        index->list[i] = NULL;
    }
}

// Função para calcular o índice da primeira letra, ignorando maiúsculas/minúsculas
// Retorna um índice de 0 a 25 baseado na letra inicial do nome
int indice(char* nome) {
    return toupper(nome[0]) - 'A';
}

// Função para adicionar um nome na estrutura em ordem alfabética, sem considerar maiúsculas/minúsculas
void addName(Index* index, char* nome) {
    int idx = indice(nome);
    Node* newNode = (Node*)malloc(sizeof(Node)); // Cria um novo nó
    strcpy(newNode->nome, nome);
    newNode->next = NULL;
    newNode->prev = NULL;

    Node* head = index->list[idx];
    
    if (head == NULL) { // Caso a lista esteja vazia
        index->list[idx] = newNode;
    } else {
        Node* temp = head;
        
        // Encontra a posição correta na ordem alfabética, ignorando maiúsculas/minúsculas
        while (temp != NULL && strcasecmp(temp->nome, nome) < 0) {
            temp = temp->next;
        }

        // Inserção no início da lista
        if (temp == head) {
            newNode->next = head;
            head->prev = newNode;
            index->list[idx] = newNode;
        } else if (temp == NULL) { // Inserção no final da lista
            Node* tail = head;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = newNode;
            newNode->prev = tail;
        } else { // Inserção no meio da lista
            newNode->next = temp;
            newNode->prev = temp->prev;
            if (temp->prev != NULL) {
                temp->prev->next = newNode;
            }
            temp->prev = newNode;
        }
    }
}

// Função para imprimir a estrutura de dados
void printIndex(Index* index) {
    printf("\nLista:\n");
    int i;
	for (i = 0; i < ALPHABET_SIZE; i++) {
        if (index->list[i] != NULL) {
            printf("%c\n", 'A' + i);
            Node* temp = index->list[i];
            while (temp != NULL) {
                printf("  %s\n", temp->nome);
                temp = temp->next;
            }
        }
    }
}

// Função para pesquisar se um nome existe e identificar sua posição
void searchName(Index* index, char* nome) {
    int idx = indice(nome);
    Node* temp = index->list[idx];
    
    // Busca sem considerar maiúsculas/minúsculas
    while (temp != NULL) {
        if (strcasecmp(temp->nome, nome) == 0) {
            printf("Nome '%s' encontrado na lista de %c.\n", nome, 'A' + idx);
            return;
        }
        temp = temp->next;
    }
    printf("Nome '%s' nao encontrado.\n", nome);
}

// Função para deletar um nome
void deleteName(Index* index, char* nome) {
    int idx = indice(nome);
    Node* temp = index->list[idx];

    // Busca e exclusão sem considerar maiúsculas/minúsculas
    while (temp != NULL) {
        if (strcasecmp(temp->nome, nome) == 0) {
            // Reajuste dos ponteiros ao excluir o nó
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                index->list[idx] = temp->next; // Caso seja o primeiro nó
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
            printf("Nome '%s' foi deletado.\n", nome);
            return;
        }
        temp = temp->next;
    }
    printf("Nome '%s' nao encontrado para exclusao.\n", nome);
}

int main() {
    Index index;
    initIndex(&index);

    // Adicionando nomes fixos à estrutura
    addName(&index, "Aline");
    addName(&index, "Bia");
    addName(&index, "Carla");
    addName(&index, "Debora");
    addName(&index, "Zaza");
    addName(&index, "Italo");        
    addName(&index, "Amanda");
    addName(&index, "Beatriz");
    addName(&index, "Carlos");
    addName(&index, "Zoraide");
    addName(&index, "Elias");
    addName(&index, "Igor");
    addName(&index, "Ana");
    addName(&index, "Cesar");
    addName(&index, "Odoacro");
    addName(&index, "Hermenegildo"); 
    addName(&index, "Zuleika");
    addName(&index, "Ananda");
    addName(&index, "Cosmos");
    addName(&index, "Ivan");
    addName(&index, "Xuxa");
    addName(&index, "Yago");
    addName(&index, "Carlos");
    addName(&index, "Marta");
    addName(&index, "Yara");
    addName(&index, "Daniel");

    // Imprime a estrutura
    printIndex(&index);

    // Interatividade para procurar um nome
    printf("\nDigite um nome para procurar: ");
    char nomeBusca[100];
    scanf(" %[^\n]s", nomeBusca);
    searchName(&index, nomeBusca);

    // Menu para deletar um nome ou sair do programa
    while (1) {
        printf("\nOpcoes:\n1. Deletar um nome\n2. Sair\nEscolha uma opcao: ");
        int opcao;
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite o nome a ser deletado: ");
            char nomeDelete[100];
            scanf(" %[^\n]s", nomeDelete);
            deleteName(&index, nomeDelete);
            printIndex(&index);
        } else if (opcao == 2) {
            printf("Saindo do programa.\n");
            break;
        } else {
            printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}

