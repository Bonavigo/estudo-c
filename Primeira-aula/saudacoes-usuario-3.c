#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char nome[81];
	int i;
	puts("Nome: ");
	gets(nome);
	
	for(i=0; i<strlen(nome)+4; i++){
		printf("End=%5c caractere = %c = %3i \n", &nome[i], nome[i],nome[i]);
	}
}
