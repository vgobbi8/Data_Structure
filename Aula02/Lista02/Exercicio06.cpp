#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 

main(void)
{
	char *a, *b;
	a = "abacade";
	b = "uva";
	
	//Compara endereços de memória
	if (a < b)
   		printf ("%s vem antes de %s no dicionário", a, b);
	else
   		printf ("%s vem depois de %s no dicionário", a, b);
}

