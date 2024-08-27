#include<stdio.h>
#include<stdlib.h>

void main(){
	int x=10, y=25;
	int *px, *py;
	
	px = &x;
	py = &y;
	
	printf("\n x = %d \t px = %p \t *px = %d", x, px, *px);
}
