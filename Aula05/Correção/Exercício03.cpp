#include <stdlib.h>
#include <stdio.h>

struct no 
{
       float info;
       struct no* prox;
};
typedef struct no No;

struct fila 
{
       float soma;
       float media;
       float maior;
       float menor;
       int totalElementos;
	   No* ini;
       No* fim;
};
typedef struct fila Fila;

//---------------------


No* ins_fim (Fila* f, No* fim, float v);
No* ret_ini (No* ini);
void insere (Fila* f, float v);
float retira (Fila* f);
int vazia (Fila* f);
void libera (Fila* f);
void atualizarFila(Fila* f);
//--------------------


Fila* cria (void)
{
      Fila* f = (Fila*) malloc(sizeof(Fila));
      f->ini = f->fim = NULL;
      f->maior = 0;
      f->media = 0;
      f->menor = 0;
      f->soma = 0;
      f->totalElementos = 0;
      return f;
}

No* ins_fim (Fila* f, No* fim, float v)
{
    No* p = (No*) malloc(sizeof(No));
    p->info = v;
    p->prox = NULL;
    if (fim != NULL) 
    {
    	fim->prox = p;
 	}

    if (f->totalElementos == 0)
    {
    	f->	maior = v;
    	f->media = v;
    	f->menor = v;
    	f->soma = v;
	}
	f->totalElementos++;
	f->	soma = f->soma + v;
	atualizarFila(f);
	
    return p;
}

void atualizarFila(Fila* f){
	No* q;
	
    for (q=f->ini; q!=NULL; q=q->prox)
    {
    	if (f->maior < q->info )
			f->	maior = q->info;
	
		if (f->menor > q->info)
			f->	menor = q->info;
	}
	
	f->media = f->soma / f->totalElementos; 
}


No* ret_ini (No* ini)
{
    No* p = ini->prox;
    free(ini);
    return p;
}



void insere (Fila* f, float v)
{
     f->fim = ins_fim(f, f->fim,v);
     if (f->ini==NULL) 
        f->ini = f->fim;
}

float retira (Fila* f)
{
      float v;
      if (vazia(f)) 
      {
         printf("Fila vazia.\n");
         exit(1); 
       }
       v = f->ini->info;
       f->ini = ret_ini(f->ini);
       if (f->ini == NULL) 
       		f->fim = NULL;
       	
		f->totalElementos--;
		f->	soma = f->soma - v;
		atualizarFila(f);   	
       		
       return v;
}


int vazia (Fila* f)
{
    return (f->ini==NULL);
}

void libera (Fila* f)
{
     No* q = f->ini;
     while (q!=NULL) 
     {
           No* t = q->prox;
           free(q);
           q = t;
     }
     free(f);
}



void imprime (Fila* f)
{
     No* q;
     for (q=f->ini; q!=NULL; q=q->prox)
         printf("%f\n",q->info);
}



int main (void)
{
    Fila* fila_teste = cria();
    

    insere(fila_teste,60);
    insere(fila_teste,55);
    insere(fila_teste,21.2);
    insere(fila_teste,3);
    insere(fila_teste,-1);
    insere(fila_teste,70);
    insere(fila_teste,50);
    insere(fila_teste,30);
    
    

    printf("O maior valor eh %.2f\n", fila_teste->maior );
    printf("O menor valor eh %.2f\n", fila_teste->menor  );
    printf("A soma dos valores eh %.2f\n", fila_teste->soma   );
    printf("A quantidade de elementos eh %d\n", fila_teste->totalElementos    );
    printf("A media eh %.2f\n", fila_teste->media     );
    

    libera(fila_teste);
    
    system("pause");
    return 0;
}
