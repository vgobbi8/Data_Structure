#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int funcao(int valor){
	return valor % 10;
}


int main(){
	setlocale(LC_ALL,"portuguese");
	int val;
	printf("Insira um valor: ");
	scanf("%d",&val);
	
	printf("O resto da divis�o por 10 �: %d",funcao(val));	
}


