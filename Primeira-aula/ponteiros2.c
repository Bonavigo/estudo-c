#include<stdio.h>
#include<stdlib.h>

int main(){
	int *p, *p1, x=10;
	float y=20.5;
	
	p=&x;
	printf("\n Conteudo apontado por p: %d", *p);
	
	p1 = p;
	printf("\n Conteudo apontado por p1: %d", *p1);
	
	p = &y;
	printf("\n Conteudo apontado por p: %ld \n", *p);
	printf("\n Conteudo apontado por p: %f \n", *p);
	printf("\n Conteudo apontado por p: %f \n", *((float*)p));	
	return 0;
}