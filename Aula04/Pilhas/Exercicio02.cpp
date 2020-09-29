#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nodo{
  char info;
  struct nodo* prox;
}no;

typedef struct pilha{
  nodo *base,*topo;
  int qtd;
}pilha;

void push(pilha *stack, char info);
char top(pilha *stack);
void pop(pilha *stack);
int tamanho(pilha *stack);
pilha *cria();
void mostra(pilha *stack);
main(){
 pilha *s;
 char letra;
 char palavra[10],nova[10];
 int i,t;
 do{
 	 system("cls");
	 printf("\nPILHA COM ENCADEAMENTO \n"); 
	 printf("Digite uma palavra(fim - termina):");
	 fflush(stdin);
	 gets(palavra);
	 s=cria();
	 printf("\nEmpilhando elementos: \n");
	 printf("Tamanho da palavra: %d\n",strlen(palavra));
	 //Varre a palavra inteira 
	 for(i=0;i<strlen(palavra);i++){
	 	letra=palavra[i];
	    printf("Letra: %c\n",letra);
	    push(s,letra); //Empilha a letra
	 }
	 printf("\nDesempilhando elementos: \n"); 
	 strcpy(nova,"");
	 t=tamanho(s);//tamanho da pilha
	 printf("Itens na pilha: %d",t);
	 for(i=0;i<t;i++)
	   strcat(nova," ");
	 for(i=0;i<t;i++){
	 	letra=top(s);
	    printf("\nTOPO: %c",letra);
	    nova[i]=letra;
	    pop(s);
	 } 
	 printf("\n Nova palavra: %s",nova);
	 printf("\n\nCOMPARAR\n");
	 if (strcmp(palavra,nova)==0)
	    printf("Palavra Palindromo");
	 else
	    printf("Palavra NAO Palindromo");
	 printf("\n\n");
	 system("pause");
    }while(strcmp(strlwr(palavra),"fim")!=0);
}
//Implementa??o das fun??es
void push(pilha *stack, char info){
 nodo *p;
 p=(nodo *)malloc(sizeof(nodo));
 p->info=info;
 p->prox=NULL;
 if(stack->base==NULL){
   stack->base=p;
   stack->topo=p;
   stack->qtd=1;
 }else {
   p->prox=stack->topo;
   stack->topo=p;
   stack->qtd +=1;
 }
}

char top(pilha *stack){
   return(stack->topo->info); 
}

void pop(pilha *stack){
 nodo *p;
 p=stack->topo;
 if (p != NULL){
	 stack->topo=p->prox;
	 if (stack->topo == NULL)
	     stack->base = NULL;
	 free(p);  
	 stack->qtd -=1;   
 }
 else
   printf("\nPilha Vazia!\n");
}

pilha *cria(){
 pilha *stack;
 stack=(pilha*)malloc(sizeof(pilha));
 stack->base=NULL;
 stack->topo=NULL;
 stack->qtd=0;
 return(stack);
}

void mostra(pilha *stack){
  nodo *p;
  p=stack->topo;
  printf("\n TOPO -> ");
  while(p!=NULL){
    printf("%c -> ",p->info);
    p=p->prox;
  }  
}
int tamanho(pilha *stack){
	return(stack->qtd);
}

