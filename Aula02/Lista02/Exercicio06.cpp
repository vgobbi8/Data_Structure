#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 

main(void)
{
	char *a, *b;
	a = "abacade";
	b = "uva";
	
	//Compara endere�os de mem�ria
	if (a < b)
   		printf ("%s vem antes de %s no dicion�rio", a, b);
	else
   		printf ("%s vem depois de %s no dicion�rio", a, b);
}

