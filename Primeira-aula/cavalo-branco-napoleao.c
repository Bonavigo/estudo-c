#include <stdio.h>
#include <string.h>

void main(){
	static char resposta_certa[]="branco";
	char resposta_usuario[40];
	
	puts("Qual a cor do cavalo branco de Napoleao?");
	gets(resposta_usuario);
	while(strcmp(resposta_usuario, resposta_certa)!=0){
		puts("Resposta errada! Tente novamente");
		gets(resposta_usuario);
	}
	puts("Parabens!!! Acertou!");
}