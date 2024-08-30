#include <stdio.h>
#include "pilha.h"

int main (void) {
	int n;
	Pilha P = pilha(32);
	printf("Decimal? ");
	scanf("%d", &n);
	do {
		empilha(n%2, P);
		n /= 2;
	} while(n != 0);
	printf("Binario: ");
	while(!vaziap(P))
		printf("%d", desempilha(P));
	destroip(&n);
	return 0;
}