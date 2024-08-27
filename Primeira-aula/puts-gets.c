#include <stdio.h>

int main(){
	char nome[81];
	puts("Nome: ");
	gets(nome);
	puts("Saudacoes");
	puts(nome);
	puts("puts() sempre pula linha");
	puts(&nome[1]);
}