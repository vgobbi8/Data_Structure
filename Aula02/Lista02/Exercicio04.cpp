#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void converte(int min, int * h, int * m){
	*h = min / 60;
	*m = min % 60;
	
}

int main(){
	setlocale(LC_ALL,"portuguese");
	int min, h, m;
	printf("Insira os minutos: ");
	scanf("%d",&min);

	converte(min,&h,&m);
	printf("Horas: %d \nMinutos: %d",h,m);	
}


