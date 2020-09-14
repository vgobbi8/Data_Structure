#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

char * converte(char ch){
	char *palavra;
	palavra = (char *) calloc(2,sizeof(char *));
	palavra[0] = ch;
	palavra[1] = '\0';
	return palavra;
}
int main(){
	setlocale(LC_ALL,"portuguese");
	char c;
	char * palavra;
	printf("Insira o caractere: ");
	scanf("%c",&c);
	palavra = converte(c);
	printf("Convertido: %s",palavra);	
}


