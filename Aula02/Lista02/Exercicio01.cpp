#include<stdio.h>
#include<stdlib.h>

void funcao(int a,int b,int c, int * maior, int * menor);

int main(){
	int a,b,c;
	int maior,menor;
	
	printf("Informe a: ");
	scanf("%d",&a);

	printf("Informe b: ");
	scanf("%d",&b);
	
	printf("Informe c: ");
	scanf("%d",&c);

	funcao(a,b,c,&maior,&menor);
	
	printf("Maior: %d \n",maior);
	printf("Menor: %d \n",menor);
}

void funcao(int a,int b,int c, int * maior, int * menor){
	if((a > b) && (a > c)){
		*maior = a;
		if(b < c) *menor = b; else *menor = c;	
	} else if(b > c){
		*maior = b;
		if(a < c) *menor = a; else *menor = c;
	} else {
		*maior = c;
		if(a < b) *menor = a;  else *menor = b;
	}
}
