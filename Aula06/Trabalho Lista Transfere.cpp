#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<locale.h>
#define max 50


typedef struct Pessoa{
 int codigo;
 char nome[50]; 
 int dia;
 int mes;
}Pessoa;

typedef struct nodo {
   Pessoa pessoa; 
   nodo* proximo;
   nodo* anterior;
}nodo;

typedef struct LISTA{
 int tamanho;
 nodo* inicio;
 nodo* fim;
}LISTA;


LISTA* cria ();
int vazia (LISTA* l);
int tamanho(LISTA* l);
void libera(LISTA* l);
void mostra(LISTA* l);
void insere(LISTA* l, Pessoa v);
int remove(LISTA* l, Pessoa* v);
void copia(LISTA* b1, LISTA* b2);
void transfere(LISTA* b1, LISTA* b2);
void divide(LISTA* b1, LISTA* b2);
void inverte(LISTA* b1, LISTA* b2);
int menu();
int main(){
	setlocale(LC_ALL,"portuguese");
	
  LISTA *principal, *secundaria;
  Pessoa p;
  int opc;
  int achou;
  principal=cria();
  do{
  	opc = menu();
	switch (opc)	{ 
	 case 1:    	
			  	printf("Digite um codigo:");
			    scanf("%d",&p.codigo);
			  	printf("Digite o dia do nascimento:");    
			    scanf("%d",&p.dia);
			  	printf("Digite o mes do nascimento:");    
			    scanf("%d",&p.mes);    
			  	printf("Digite um nome:"); 
				fflush(stdin);
			    gets(p.nome);  	
			  	insere(principal,p);
			  break;
	 case 2:  printf("ELEMENTOS DA LISTA:\n");  
	          mostra(principal);
	          break;
     case 3: 
			  	printf("Digite um codigo:");
			    scanf("%d",&p.codigo);
				achou = remove(principal,&p);
				if (achou == 0)
				   printf("ELEMENTO NAO EXISTE\n\n");
				else {
	  	             printf("Dados: %d\n",p.codigo);
	  	             printf("Nome: %s\n",p.nome);
	  	             printf("Nascimento: %d/%d\n",p.dia,p.mes);					
				}
              break;
     case 4:
     	      printf("TAMANHO DA LISTA: %d ELEMENTOS\n",tamanho(principal));
     	      break;
     case 5:
     	      printf("COPIAR LISTA\n");
     	      secundaria=cria();
     	      copia(principal,secundaria);
     	      printf("\nLISTA ORIGINAL\n");
			  mostra(principal);      	      
     	      printf("\nNOVA LISTA\n");
			  mostra(secundaria);   	      
     	      break;    
     case 6:
     	      printf("TRANSFERIR LISTA\n");
     	      secundaria=cria();   
     	      transfere(principal,secundaria);
     	      printf("\nLISTA ORIGINAL\n");
			  mostra(principal);      	      
     	      printf("\nNOVA LISTA\n");
			  mostra(secundaria); 			     	      
     	      break; 
     case 7:
     	      printf("DIVIDIR LISTA\n");
     		  secundaria=cria();
     	      divide(principal,secundaria);
     	      printf("\nLISTA ORIGINAL\n");
			  mostra(principal);      	      
     	      printf("\nNOVA LISTA\n");
			  mostra(secundaria); 			        	      
     	      break;  			    			    	      
     case 8:
     	      printf("INVERTE LISTA\n");
     	      secundaria=cria();
     	      inverte(principal,secundaria);
     	      printf("\nLISTA ORIGINAL\n");
			  mostra(principal);      	      
     	      printf("\nNOVA LISTA\n");
			  mostra(secundaria); 			        	      
     	      break; 
     case 0:
     	      break;
     default:
     	      printf("ESCOLHA INCORRETA\n\n");
  }
  system("pause");
  
 }while(opc!=0);
}

int menu(){
	int opc;
	system("cls");
	printf("Selecione uma opção\n");
	printf("1- Inserir Elemento na lista principal\n");
	printf("2 - Mostrar a lista principal\n");	
	printf("3 - Remover elemento da lista da lista principal\n");
	printf("4 - Mostrar Tamanho da lista principal\n");
	printf("5 - Copiar lista principal para secundÃ¡ria\n");
	printf("6 - Transfere da lista principal para secundÃ¡ria\n");
	printf("7 - Divide lista principal\n");
	printf("0 - Finalizar\n");
	scanf("%d",&opc);	
	return opc;
}

LISTA* cria (){
 LISTA* N = (LISTA*) malloc(sizeof(LISTA)); 
 N->tamanho = 0;
 N->inicio=NULL;
 N->fim=NULL;
 return(N);
}

int vazia (LISTA* l){
    if (l->inicio == NULL)
      return(1);
    else
      return(0);
}
int tamanho (LISTA* l){ 
    if (l != NULL)
      return(l->tamanho);
    else
      return(0);
}
void libera (LISTA* l){ 
    if (l != NULL)
      free(l);
}
void mostra (LISTA* l){ 
  nodo* p;
    if (l != NULL){
      p=l->inicio;
	  while(p!=NULL){
	  	printf("Dados: %d\n",p->pessoa.codigo);
	  	printf("Nome: %s\n",p->pessoa.nome);
	  	printf("Nascimento: %d/%d\n",p->pessoa.dia,p->pessoa.mes);		  	  	
	  	p=p->proximo;//navegar nos ponteiros
	  }	
	}
}
//insere em ordem crescente de cï¿½digo
void insere (LISTA * l, Pessoa p){
 nodo* novo;
 nodo* anterior;
 nodo* corrente;
 novo=(nodo*)malloc(sizeof(nodo)); 
 //novo->pessoa = (Pessoa) malloc(sizeof(Pessoa));
 novo->pessoa.codigo = p.codigo;
 strcpy(novo->pessoa.nome,p.nome);
 novo->pessoa.dia = p.dia;
 novo->pessoa.mes = p.mes; 
 novo->proximo=NULL;
 	  	printf("Dados: %d\n",novo->pessoa.codigo);
	  	printf("Nome: %s\n",novo->pessoa.nome);
	  	printf("Nascimento: %d/%d\n",novo->pessoa.dia,novo->pessoa.mes);
 if (vazia(l)){
   l->inicio = novo;
   l->fim = novo;  }
 else { corrente = l->inicio;
   if (novo->pessoa.codigo < corrente->pessoa.codigo){
    novo->proximo = l->inicio;
     l->inicio = novo;    }
   else {
while((corrente !=NULL)&&(novo->pessoa.codigo>=corrente->pessoa.codigo)){
     anterior = corrente; 
     corrente = anterior->proximo;    }
anterior->proximo = novo;
novo->proximo = corrente;
if (corrente == NULL)
         l->fim = novo;    }   }
  l->tamanho = l->tamanho + 1; 
}

void insereDec (LISTA * l, Pessoa v){
 nodo* novo;
 nodo* anterior;
 nodo* corrente;
 novo=(nodo*)malloc(sizeof(nodo)); 
 //novo->pessoa = (Pessoa *) malloc(sizeof(Pessoa));
 novo->pessoa.codigo = v.codigo;
 strcpy(novo->pessoa.nome,v.nome);
 novo->pessoa.dia = v.dia;
 novo->pessoa.mes = v.mes; 
 novo->proximo=NULL;
 if (vazia(l)){
   l->inicio = novo;
   l->fim = novo;  }
 else { corrente = l->inicio;
   if (novo->pessoa.codigo > corrente->pessoa.codigo){
     novo->proximo = l->inicio;
     l->inicio = novo;    }
   else {
while((corrente !=NULL)&&(novo->pessoa.codigo<corrente->pessoa.codigo)){
     anterior = corrente; 
     corrente = anterior->proximo;    }
anterior->proximo = novo;
novo->proximo = corrente;
if (corrente == NULL)
         l->fim = novo;    }   }
  l->tamanho = l->tamanho + 1; 
}

int remove (LISTA * l, Pessoa* v){
 int codigo = v->codigo;
 nodo* anterior;
 nodo* corrente;
 if (vazia(l))  { 
     return(0);
  }
 else 
  {
   corrente = l->inicio;
if (codigo == corrente->pessoa.codigo){
    strcpy(v->nome,corrente->pessoa.nome);
     v->dia=corrente->pessoa.dia;
     v->mes=corrente->pessoa.mes;
     l->inicio = corrente->proximo;
     free(corrente);
     l->tamanho = l->tamanho -1;
     return(1);
   }
   else{
     while((corrente != NULL) && 
           (codigo != corrente->pessoa.codigo)&&
           (codigo > corrente->pessoa.codigo)) {
       anterior = corrente;
       corrente = anterior->proximo;
     }
     if (corrente == NULL){
        return(0);
      }
     else {
       strcpy(v->nome,corrente->pessoa.nome);
       v->mes=corrente->pessoa.mes;
       v->dia=corrente->pessoa.dia;       
       anterior->proximo = corrente->proximo;
       if (l->fim == corrente) {
          l->fim = anterior;   }
       l->tamanho = l->tamanho - 1;
       free(corrente);
       return(1);
      }   
	}   
}  

}
void inverte(LISTA* b1, LISTA* b2){
  nodo *p;
  Pessoa info;
    if (b1 != NULL){
      p=b1->inicio;
	  while(p!=NULL){
	  	info.codigo= p->pessoa.codigo;
	  	strcpy(info.nome,p->pessoa.nome);
	  	info.dia= p->pessoa.dia;
	  	info.mes= p->pessoa.mes;
		insereDec(b2,info);  		  	  	
	  	p=p->proximo;
	  }	
	}	
}
//essa funï¿½ï¿½o deve receber um ponteiro para lista b1 e
//copiar todos os elementos de b1 para a lista b2
//ao final da funï¿½ï¿½o as duas listas terï¿½o os mesmos elementos (na mesma ordem)	
void copia(LISTA* b1, LISTA* b2){
  nodo *p;
  Pessoa info;
    if (b1 != NULL){
      p=b1->inicio;
	  while(p!=NULL){
	  	info.codigo= p->pessoa.codigo;
	  	strcpy(info.nome,p->pessoa.nome);
	  	info.dia= p->pessoa.dia;
	  	info.mes= p->pessoa.mes;
		insere(b2,info);  		  	  	
	  	p=p->proximo;
	  }	
	}	
}
void transfere(LISTA* b1, LISTA* b2){
//essa funï¿½ï¿½o deve receber um ponteiro para lista b1 e
//transferir todos os elementos de b1 para a lista b2
//ao final da funï¿½ï¿½o a lista b1 estarï¿½ vazia
//e a lista b2 terï¿½ os elementos que estavam em b1	
  if (b1 != NULL){
   b2->inicio=b1->inicio;
   b2->fim=b1->fim;
   b2->tamanho=b1->tamanho;
   b1->tamanho=0;
   b1->inicio=NULL;
   b1->fim=NULL;	
  }	
}

void divide(LISTA* b1, LISTA* b2){
//essa funï¿½ï¿½o deve receber um ponteiro para lista b1 e
//determinar o "meio" da lista
//os elementos do inï¿½cio atï¿½ o meio ficarï¿½o em b1
//jï¿½ os elementos depois do meio, serï¿½o transferidos para b2
nodo *p;
int metade, conta;
 if (b1 != NULL){
    p = b1->inicio;
    metade = b1->tamanho / 2;
    for(conta=1;conta < metade;conta++){
  	  p=p->proximo;	
    }
    b2->inicio=p->proximo;
    b2->fim=b1->fim;
    b2->tamanho= b1->tamanho - metade;
    p->proximo = NULL;
    b1->fim=p;
    b1->tamanho=metade;
  }
}
