/*
1) Considere a existência de duas filas A e B onde os elementos estão ordenados da seguinte forma: 
  o maior deles está no começo da fila e o menor no final. 
  Escreva um programa que crie uma fila com os elementos das duas filas A e B também ordenados.
*/

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
       No* ini;
       No* fim;
};
typedef struct fila Fila;

//---------------------


No* ins_fim (No* fim, float v);
No* ret_ini (No* ini);
void insere (Fila* f, float v);
float retira (Fila* f);
int vazia (Fila* f);
void libera (Fila* f);
void ordena(Fila* fa, Fila* fb, Fila* fc, float valorRecursivo, char filaOrigem);
//--------------------


Fila* cria (void)
{
      Fila* f = (Fila*) malloc(sizeof(Fila));
      f->ini = f->fim = NULL;
      return f;
}

/* função auxiliar: insere no fim */
No* ins_fim (No* fim, float v)
{
    No* p = (No*) malloc(sizeof(No));
    p->info = v;
    p->prox = NULL;
    if (fim != NULL) /* verifica se lista não estava vazia */
    fim->prox = p;
    return p;
}

/* função auxiliar: retira do início */
No* ret_ini (No* ini)
{
    No* p = ini->prox;
    free(ini);
    return p;
}



void insere (Fila* f, float v)
{
     f->fim = ins_fim(f->fim,v);
     if (f->ini==NULL) /* fila antes vazia? */
        f->ini = f->fim;
}

float retira (Fila* f)
{
      float v;
      if (vazia(f)) 
      {
         printf("Fila vazia.\n");
         exit(1); /* aborta programa */
       }
       v = f->ini->info;
       f->ini = ret_ini(f->ini);
       if (f->ini == NULL) /* fila ficou vazia? */
       f->fim = NULL;
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


/* imprime: versão com lista */
void imprime (Fila* f)
{
     No* q;
     for (q=f->ini; q!=NULL; q=q->prox)
         printf("%f\n",q->info);
}

void ordena(Fila* fa, Fila* fb, Fila* fc, float valorRecursivo, char filaOrigem)
{
	float valor, valor1;
	
	//verifica se as filas estao vazias
	if (vazia(fa))
	{
		//adiciona toda a fila b em c caso ela tambem nao seja vazia
		while(!vazia(fb))
		{
			valor = retira(fb);
			insere(fc, valor);	
		}
	}
	else
	{
		if (vazia(fb))
		{
			//adiciona toda a fila a em c caso ela tambem nao seja vazia
			while(!vazia(fa))
			{
				valor = retira(fa);
				insere(fc, valor);	
			}
		}
		else
		{
			if (filaOrigem == 'a')
			{
				valor  = valorRecursivo;
				valor1 = retira(fb);
			}
			else
				if (filaOrigem == 'b')
				{
					valor = retira(fa);
					valor1 = valorRecursivo;
				}
				else
				{
					valor  = retira(fa);
					valor1 = retira(fb);
				}
			
			if (valor > valor1)
			{
				insere(fc, valor);	
				ordena(fa,fb,fc, valor1, 'b');
			}
			else
			{
				insere(fc, valor1);
				ordena(fa,fb,fc, valor, 'a');
			}
			
		} 
	}
}

/* Módulo para ilustrar utilização da fila */
int main (void)
{
    Fila* fila_A = cria();
    Fila* fila_B = cria();
    Fila* fila_C = cria();
    
    //Insere na fila A 5 elementos ordenados
    insere(fila_A,60);
    insere(fila_A,55);
    insere(fila_A,21.2);
    insere(fila_A,3);
    insere(fila_A,-1);
    
    //Insere na fila B 3 elementos ordenados
    insere(fila_B,70);
    insere(fila_B,50);
    insere(fila_B,30);
    
    //Ordena as filas gerando uma nova fila;
    ordena(fila_A, fila_B, fila_C, 0, 'c');
    
    //Imprime a fila resultante
    imprime(fila_C);
    
    //libera as filas
    libera(fila_A);
    libera(fila_B);
    libera(fila_C);
    
    system("pause");
    return 0;
}
