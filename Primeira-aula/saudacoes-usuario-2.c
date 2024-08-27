#include<stdio.h>
void main(){
	char nome[81];
	printf("Nome: ");
	gets(nome);
	printf("Saudacoes, %s", nome);
}