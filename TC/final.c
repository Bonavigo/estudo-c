#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 50
#define MAX_NOME 60
#define MAX_SIGLA 10

typedef struct {
    char nome[MAX_NOME];
    int idade;
} Pessoa;

typedef struct {
    Pessoa pes;
    int codigo;
    char depto[MAX_SIGLA];
} Professor;

typedef struct {
    Pessoa pes;
    int matricula;
    int ano;
    char depto[MAX_SIGLA];
} Aluno;

typedef struct {
    int codigo;
    int autor;
    int orientador;
    char titulo[MAX_NOME];
    int qtdeVotos;
} TC;

typedef struct {
    char cpf[15];
    bool votou;
    int codigoTC;
} Eleitor;

Professor docentes[MAX];
int qtdeDocentes;
Aluno formandos[MAX];
int qtdeFormandos;
TC listaTCs[MAX];
int qtdeTCs;
Eleitor comissao[MAX];
int qtdeEleitores;

// Função para carregar professores
void carregarProfessores() {
    FILE *file = fopen("professor.txt", "r");
    if (!file) {
        printf("Arquivo professor.txt não encontrado.\n");
        exit(1);
    }
    fscanf(file, "%d", &qtdeDocentes);
    for (int i = 0; i < qtdeDocentes; i++) {
        fscanf(file, "%d %s %d %[^\n]", &docentes[i].codigo, docentes[i].depto, &docentes[i].pes.idade, docentes[i].pes.nome);
    }
    fclose(file);
}

// Função para carregar alunos
void carregarAlunos() {
    FILE *file = fopen("aluno.txt", "r");
    if (!file) {
        printf("Arquivo aluno.txt não encontrado.\n");
        exit(1);
    }
    fscanf(file, "%d", &qtdeFormandos);
    for (int i = 0; i < qtdeFormandos; i++) {
        fscanf(file, "%d %d %s %d %[^\n]", &formandos[i].matricula, &formandos[i].ano, formandos[i].depto, &formandos[i].pes.idade, formandos[i].pes.nome);
    }
    fclose(file);
}

// Função para carregar TCs
void carregarTCs(char *depto) {
    char filename[20];
    sprintf(filename, "TC_%s.txt", depto);
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Arquivo %s não encontrado.\n", filename);
        exit(1);
    }
    fscanf(file, "%d", &qtdeTCs);
    for (int i = 0; i < qtdeTCs; i++) {
        fscanf(file, "%d %d %d %[^\n]", &listaTCs[i].codigo, &listaTCs[i].autor, &listaTCs[i].orientador, listaTCs[i].titulo);
        listaTCs[i].qtdeVotos = 0;
    }
    fclose(file);
}

// Função para carregar eleitores
void carregarEleitores() {
    FILE *file = fopen("comissao.txt", "r");
    if (!file) {
        printf("Arquivo comissao.txt não encontrado.\n");
        exit(1);
    }
    fscanf(file, "%d", &qtdeEleitores);
    for (int i = 0; i < qtdeEleitores; i++) {
        fscanf(file, "%s", comissao[i].cpf);
        comissao[i].votou = false;
    }
    fclose(file);
}

// Função de validação de CPF (simplificada)
bool validarCPF(const char *cpf) {
    // Algoritmo completo de validação de CPF seria implementado aqui
    return true;
}

// Função para registrar voto
void registrarVoto(char *cpfEleitor, int codigoTC) {
    for (int i = 0; i < qtdeEleitores; i++) {
        if (strcmp(comissao[i].cpf, cpfEleitor) == 0) {
            if (comissao[i].votou) {
                printf("Eleitor já votou.\n");
            } else {
                comissao[i].votou = true;
                comissao[i].codigoTC = codigoTC;
                // Incrementar votos no TC correspondente.
                for (int j = 0; j < qtdeTCs; j++) {
                    if (listaTCs[j].codigo == codigoTC) {
                        listaTCs[j].qtdeVotos++;
                        printf("Voto registrado para o TC: %d\n", codigoTC);
                        break;
                    }
                }
            }
            return;
        }
    }
    printf("CPF não encontrado ou inválido.\n");
}

// Função para gerar arquivo parcial
void suspenderVotacao() {
    FILE *file = fopen("parcial.txt", "w");
    fprintf(file, "%d\n", qtdeEleitores);
    for (int i = 0; i < qtdeEleitores; i++) {
        if (comissao[i].votou) {
            fprintf(file, "%s %d\n", comissao[i].cpf, comissao[i].codigoTC);
        }
    }
    fclose(file);
    printf("Votação suspensa e salva em parcial.txt\n");
}

// Função para concluir votação e gerar resultado detalhado
void concluirVotacao() {
    FILE *file = fopen("resultado.txt", "w");

    int maxVotos = 0;
    // Encontrar a quantidade máxima de votos recebida por um TC
    for (int i = 0; i < qtdeTCs; i++) {
        if (listaTCs[i].qtdeVotos > maxVotos) {
            maxVotos = listaTCs[i].qtdeVotos;
        }
    }

    fprintf(file, "TC(s) vencedor(es):\n");
    for (int i = 0; i < qtdeTCs; i++) {
        if (listaTCs[i].qtdeVotos == maxVotos) {
            // Buscar informações do autor e orientador
            Aluno *autor = NULL;
            Professor *orientador = NULL;

            // Encontrar o autor com base no código
            for (int j = 0; j < qtdeFormandos; j++) {
                if (formandos[j].matricula == listaTCs[i].autor) {
                    autor = &formandos[j];
                    break;
                }
            }

            // Encontrar o orientador com base no código
            for (int j = 0; j < qtdeDocentes; j++) {
                if (docentes[j].codigo == listaTCs[i].orientador) {
                    orientador = &docentes[j];
                    break;
                }
            }

            fprintf(file, "Codigo: %d\nTitulo: %s\n", listaTCs[i].codigo, listaTCs[i].titulo);
            if (autor) {
                fprintf(file, "Aluno: %s\nDepto aluno: %s\n", autor->pes.nome, autor->depto);
            }
            if (orientador) {
                fprintf(file, "Orientador: %s\nDepto orientador: %s\n", orientador->pes.nome, orientador->depto);
            }
            fprintf(file, "Votos: %d\n\n", listaTCs[i].qtdeVotos);
        }
    }

    fprintf(file, "Eleitores que votaram\n");
    for (int i = 0; i < qtdeEleitores; i++) {
        if (comissao[i].votou) {
            fprintf(file, "%s %d\n", comissao[i].cpf, comissao[i].codigoTC);
        }
    }

    fprintf(file, "\nEleitores que não votaram\n");
    for (int i = 0; i < qtdeEleitores; i++) {
        if (!comissao[i].votou) {
            fprintf(file, "%s\n", comissao[i].cpf);
        }
    }

    fclose(file);
    printf("Votacao concluida e resultado salvo em resultado.txt\n");
}


// Menu de votação
void menuVotacao() {
    char opcao;
    char cpfEleitor[15];
    int codigoTC;
    do {
        printf("Menu de Votacao:\n");
        printf("a) Entrar com voto\n");
        printf("b) Suspender votacao\n");
        printf("c) Concluir votacao\n");
        scanf(" %c", &opcao);
        switch (opcao) {
            case 'a':
            case 'A':
                printf("Digite o CPF do eleitor: ");
                scanf("%s", cpfEleitor);
                if (!validarCPF(cpfEleitor)) {
                    printf("CPF invalido.\n");
                    break;
                }
                printf("Digite o codigo do TC: ");
                scanf("%d", &codigoTC);
                registrarVoto(cpfEleitor, codigoTC);
                break;
            case 'b':
            case 'B':
                suspenderVotacao();
                return;
            case 'c':
            case 'C':
                concluirVotacao();
                return;
            default:
                printf("Opção invalida!\n");
        }
    } while (opcao != 'c' && opcao != 'C');
}

// Função principal
int main() {
    carregarProfessores();
    carregarAlunos();
    carregarTCs("BCC");  // Carregar TCs de cada departamento necessário
    carregarTCs("BSI");
    carregarTCs("ADS");
    carregarTCs("GTI");
    carregarEleitores();

    char opcaoMenu1;
    printf("MENU1:\n");
    printf("a) Iniciar nova votacao\n");
    printf("b) Continuar votacao gravada\n");
    scanf(" %c", &opcaoMenu1);
    
    if (opcaoMenu1 == 'a' || opcaoMenu1 == 'A') {
        menuVotacao();
    } else if (opcaoMenu1 == 'b' || opcaoMenu1 == 'B') {
        FILE *file = fopen("parcial.txt", "r");
        if (file) {
            int qtdeVotantes;
            fscanf(file, "%d", &qtdeVotantes);
            for (int i = 0; i < qtdeVotantes; i++) {
                fscanf(file, "%s %d", comissao[i].cpf, &comissao[i].codigoTC);
                comissao[i].votou = true;
                for (int j = 0; j < qtdeTCs; j++) {
                    if (listaTCs[j].codigo == comissao[i].codigoTC) {
                        listaTCs[j].qtdeVotos++;
                    }
                }
            }
            fclose(file);
            menuVotacao();
        } else {
            printf("Arquivo parcial.txt nao encontrado.\n");
        }
    } else {
        printf("Opção invalida!\n");
    }
    
    return 0;
}