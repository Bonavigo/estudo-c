#include<stdio.h>
#include<stdlib.h>

void trocaRef(int *x, int *y){
	int aux = *x;
	*x = *y;
	*y = aux;
	
	printf("\n Dentro da funcao x = %d e y = %d", *x, *y);
}

void troca(int x, int y){
	int aux = x;
	x = y;
	y = aux;
	printf("\n Dentro da funcao x = %d e y = %d", x, y);
}


void main(){
	int x=10, y=25;
	
	printf("\n PASSAGEM POR VALOR");
	printf("\n Antes da funcao x = %d e y = %d", x, y);	
	troca(x,y);
	printf("\n Depois da funcao x = %d e y = %d", x, y);

	
	printf("\n\n\n\n PASSAGEM POR REFERENCIA");
	printf("\n Antes da funcao x = %d e y = %d", x, y);	
	trocaRef(&x,&y);
	printf("\n Depois da funcao x = %d e y = %d", x, y);
}