#include<stdio.h>
#include<stdlib.h>

void funcao(int *a,int *b,int *c);

int main(){
	int a,b,c;
	
	printf("Informe a: ");
	scanf("%d",&a);

	printf("Informe b: ");
	scanf("%d",&b);
	
	printf("Informe c: ");
	scanf("%d",&c);

	funcao(&a,&b,&c);
	
	printf("Maior: %d \n",a);
	printf("Meio: %d \n",b);
	printf("Menor: %d \n",c);
}

void funcao(int *a,int *b,int *c){
	if((*a < *b) || (*a < *c)){
		int aux = *a;
		if(*b > *c){
			*a = *b;
			*b = aux;
		} else {
			*a = *c;
			*c = aux;
			aux = *b;
			*b = *c;
			*c = aux;			
		}		
	} else if(*b < *c){
			int aux;
			aux = *b;
			*b = *c;
			*c = aux;			
	}
}
