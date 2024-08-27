#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char salute[81] = "Saudacoes, ";
	char frase[81] = ". Como vai? ";
	char nome[20];
	puts("Digite o seu nome: ");
	gets(nome);
	
	strcat(salute, nome);
	
	puts(salute);
	puts(nome);
	
	strcat(frase, salute);
	puts(frase);
	
	return 0;
}