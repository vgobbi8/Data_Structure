#include <stdlib.h>
#include <stdio.h>
#define MAX 50
struct pilha 
{ int n;
  float vet[MAX];
};

typedef struct pilha Pilha;

// prototipa??o -------------------

Pilha * cria (void);
Pilha * push (Pilha* p, float v);
Pilha * pop (Pilha* p);
float top (Pilha* p);
void imprime (Pilha* p);
int vazia (Pilha* p);
void libera (Pilha* p);
void TransfereIgual(Pilha * origem, Pilha * destino);
void Transfere(Pilha * origem, Pilha * destino);
main ()
{ 
     Pilha * pil;
     Pilha * pil_sec;
     int op;
     float val;
     pil=cria();     

     do{
      system("cls");
      printf("Menu - PILHA COM VETOR\n");
      printf("1- Adiciona elemento\n");
      printf("2- Mostra pilha\n");
      printf("3- Desempilha\n");
      printf("4 - Transfere\n");
      printf("5 - Transfere Igual\n");
      printf("0- Finaliza\n");
      printf("Digite:");
      scanf("%d",&op);
      switch (op){
      	case 1:
      		printf("Empilhar!\n"); 
            printf("\n digite elemento para inserir na pilha: ");
            scanf("%f", &val);     
            pil=push(pil,val); 			       		
      		break;
      	case 2:
      		printf("Mostrar!\n");  
			    imprime(pil);     		
      		break;
      	case 3:
      		printf("Desempilhar!\n");
			    printf("Topo: %f\n",top(pil));
          pil=pop(pil);
          imprime(pil);			        		
      		break;
        case 4:
        system("cls");
          printf("Transfere\n");
               pil_sec = cria();
          Transfere(pil,pil_sec);
          printf("Pilha original: \n");
          imprime(pil);
          printf("Pilha Secundária: \n");
          imprime(pil_sec);
          libera(pil_sec);
          break;
        case 5:
          printf("Transfere Igual\n");
               pil_sec = cria();
          TransfereIgual(pil,pil_sec);
          printf("Pilha original: \n");
          imprime(pil);
          printf("Pilha Secundária: \n");
          imprime(pil_sec);
          libera(pil_sec);
          break;
      	case 0:
      		printf("Terminar programa!\n"); 
            libera(pil);	
            libera(pil_sec);		       		
      		break;
      	default:
      		printf("Escolha incorreta!\n");
	  } 
	 printf("\n\n");
     system("pause"); 	  
	}while(op!=0);   
}
//Implementa??o
Pilha* cria (void)
{
  Pilha* p = (Pilha*) malloc(sizeof(Pilha));
  p->n = 0; /* inicializa com zero elementos */
  return p;
}
//-----------------------------
Pilha* push (Pilha* p, float v)
{
  if (p->n == MAX) 
  { /* capacidade esgotada */
    printf("Capacidade da pilha estourou.\n");
  }
  else {
/* insere elemento na pr?xima posi??o livre */
  p->vet[p->n] = v;
  p->n++;
  return p;
  }
}
//-----------------------------
float top (Pilha* p)
{
  if (vazia(p)) 
  {
     printf("Pilha vazia.\n");
     return(0);
  }
/* consulta elemento do topo */
  float x = p->vet[p->n-1];
  return(x);
}
//-----------------------------
Pilha* pop (Pilha* p)
{
  if (vazia(p)) 
  {
     printf("Pilha vazia.\n");
  }
  else {
/* retira elemento do topo */
  p->vet[p->n-1]=0.0;
  p->n--;
  return p;
  }
}
//-----------------------------
int vazia (Pilha* p)
{
  return (p->n == 0);
}

void imprime (Pilha* p)
{
  int i;
  printf("TOPO >>\n");
  for (i=p->n-1; i>=0; i--)
      printf("%6.2f\n",p->vet[i]);
  printf("<< BASE ");
}

void libera (Pilha* p)
{
   free(p);
}

void Transfere(Pilha * origem, Pilha * destino){
  for(int i = (origem->n-1); i>=0; i--){
    push(destino,origem->vet[i]);
  }
}
void TransfereIgual(Pilha * origem, Pilha * destino){
  for(int i  = 0; i<origem->n;i++){
    push(destino,origem->vet[i]);
  }
}
