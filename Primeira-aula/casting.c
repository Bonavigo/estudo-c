#include<stdio.h>

void main(){
	int x, y, z;
	double w;
	printf("\n Digite um valor para x: ");
	scanf("%d", &x);
	
	printf("\n Digite um valor para y: ");
	scanf("%d", &y);
	
	w = (x+y)/3;
	z = (int)((x+y)/2); //casting
	
	printf("\n z = %d e w = %lf", z, w);
}