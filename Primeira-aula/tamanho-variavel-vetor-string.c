#include<stdio.h>

int main(){
	char palavra1[] = {'A','M','O','R','\0'};
	char palavra2[] = "AMOR";
	
	printf("\nTamanho da variavel palavra1: %d", sizeof(palavra1));
	printf("\nTamanho da variavel palavra2: %d", sizeof(palavra2));
	return 0;
}