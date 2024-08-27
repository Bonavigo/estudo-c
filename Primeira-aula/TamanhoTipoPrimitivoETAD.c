#include<stdio.h>
#include<stdlib.h>

struct Ponto{
	int x, y;
};

void main(){
	
	int *p;	//declara um ponteiro para um inteiro
	
	//malloc é o comando para alocação dinâmica de memória
	p = (int *) malloc(5*sizeof(int)); //similar a declaração int p[5];
	
	for(int i=0; i<5; i++){
		printf("\n Digite o valor da posicao %d: ", i);
		scanf("%d", &p[i]);
	}
	
	for(int i=0; i<5; i++){
		printf("\n p[%d] = %d ", i, p[i]);
	}
	
	printf("\n Tamanho de um char	= %lld", sizeof(char));
	printf("\n Tamanho de um int	= %ld", sizeof(int));
	printf("\n Tamanho de um float	= %ld", sizeof(float));
	printf("\n Tamanho de um double	= %ld", sizeof(double));
	printf("\n Tamanho de um Ponto	= %ld", sizeof(struct Ponto));
}