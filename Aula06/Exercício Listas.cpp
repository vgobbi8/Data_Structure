#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <ctype.h>


typedef struct Pessoa{
	int codigo;
	char nome[50];
	int dia;
	int mes;
}Pessoa; 

typedef struct nodo {
	Pessoa pessoa;
	nodo * proximo;
	nodo * anterior;	
};

typedef struct LISTA{
	int tamanho;
	nodo * inicio;
	nodo * fim;
};

int tam;

void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
void insereFim(node *LISTA);
void insereInicio(node *LISTA);
void exibe(node *LISTA);
void libera(node *LISTA);
void insere (node *LISTA);
node *retira(node *LISTA);
node* buscaElemento(node *LISTA, int opt);

//==============================================================================
int main(void)
{	
	system("cls");
    node * ls;
    node * ls_aux;
    ls = (LISTA *) malloc(sizeof(LISTA));

	if(!ls){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
    ls_aux = (LISTA *) malloc(sizeof(LISTA));
	if(!ls_aux){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
    else
    {
    	inicia(ls);
    	inicia(ls_aux);
    	int opc;
    	
    	do{
    		opc=menu();
			switch (opc){
				case 1:
					
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
				case 7:
					break;
				default:
					break;		
			}			
    	}while(opc);
    
    
    	free(LISTA); //libera memoria (criar fun??o)
    
        printf ("\n\n\n\nPressione qualquer tecla para finalizar o programa.....");    
        getch(); //Aguarda comando para sair do programa
	}
}
//==============================================================================
int menu(){
	int opc;
	system("cls");
	printf("Selecione uma op��o\n");
	printf("1- Inserir Elemento na lista\n");
	printf("2 - Mostrar a lista\n");	
	printf("3 - Remover elemento da lista\n");
	printf("4 - Mostrar Tamanho\n");
	printf("5 - Copiar\n");
	printf("6 - Transfere\n");
	printf("7 - Divide\n");
	printf("0 - Finalizar\n");
	scanf("%d",&opc);	
	return opc;
}

void inicia(LISTA *l)
{
	l->inicio = NULL;
	l->fim = NULL;
	tam=0;
}

//==============================================================================
void escolheOperacao(node *LISTA, int op)
{
	node *tmp;
	int opt;
	
	switch(op){
		case 0:
			libera(LISTA); //libera memoria e sai do programa
			break;
			
		case 1:
            insereInicio(LISTA); //adiciona elemento no inicio da lista
            getch(); //Aguarda comando...
			break;
		
		case 2:
			insereFim(LISTA); //adiciona elemento no final da lista
            getch(); //Aguarda comando...			
			break;
		
		case 3:
			retira(LISTA);
			break;		
			
		case 4:
			
            printf("\nQual elemento voce deseja encontrar: ");
	        scanf("%d", &opt);
            tmp = buscaElemento(LISTA,opt);
        	if (tmp != NULL)
        		printf("O valor foi encontrado: %d\n", tmp->num);
        	else
        		printf("Valor nao encontrado na lista....\n");    
            getch(); //Aguarda comando para sair do programa 
			break;
			
		case 5:
			exibe(LISTA);
			break;
		
		case 6:
			libera(LISTA); //libera memoria
			printf("Memoria liberada....\n");
			getch(); //Aguarda comando para sair do programa 
			break;
		
		default:
			printf("Comando invalido....\n\n");
			getch(); //Aguarda comando para sair do programa 
	}
}
//==============================================================================
int vazia(node *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}
//==============================================================================
node *aloca()
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
		printf("Novo elemento: "); scanf("%d", &novo->num);
		return novo;
	}
}
//==============================================================================

void insereFim(node *LISTA)
{
	node *novo=aloca();
	novo->prox = NULL;
	
	if(vazia(LISTA))
		LISTA->prox=novo;
	else{
		node *tmp = LISTA->prox;
		
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		
		tmp->prox = novo;
	}
	tam++;
}
//==============================================================================
void insereInicio(node *LISTA)
{
	node *novo=aloca();	
	node *oldHead = LISTA->prox;
	
	LISTA->prox = novo;
	novo->prox = oldHead;
	
	tam++;
}
//==============================================================================
void exibe(node *LISTA)
{
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
        getch(); //Aguarda comando...
		return ;
	}
	
	node *tmp;
	tmp = LISTA->prox;
	printf("Lista:");
	while( tmp != NULL){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n        ");
	int count;
	for(count=0 ; count < tam ; count++)
		printf("  ^  ");
	printf("\nOrdem:");
	for(count=0 ; count < tam ; count++)
		printf("%5d", count+1);
	
		
	printf("\n\n");
    getch(); //Aguarda comando para sair do programa
}
//==============================================================================
void libera(node *LISTA)
{
	if(!vazia(LISTA)){
		node *proxNode,
			  *atual;
		
		atual = LISTA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}
//==============================================================================
void insere(node *LISTA)
{
	int pos,
		count;
	printf("Em que posicao, [de 1 ate %d] voce deseja inserir: ", tam);
	scanf("%d", &pos);
	
	if(pos>0 && pos <= tam)
    {
		if(pos==1)
			insereInicio(LISTA);
		else{
			node *atual = LISTA->prox,
				 *anterior=LISTA; 
			node *novo=aloca();
				 
			for(count=1 ; count < pos ; count++){
					anterior=atual;
					atual=atual->prox;
			}
			anterior->prox=novo;
			novo->prox = atual;
			tam++;
		}
			
	}
    else
	{
		printf("Elemento invalido\n\n");
    }    
        
   getch(); //Aguarda comando para sair do programa     		
}
//==============================================================================
node *retira(node *LISTA)
{
	int opt,
		count;
	printf("Qual elemento voce deseja retirar: ");
	scanf("%d", &opt);
	
    node* ant = NULL; /* ponteiro para elemento anterior */
    node* p = LISTA; /* ponteiro para percorrer a lista*/
	
       while (p != NULL && p->num != opt) 
       {
             ant = p;
             p = p->prox;
       }    
    
    /* verifica se achou elemento */
    if (p == NULL)
    {
     printf("Elemento invalido\n\n");
     return LISTA; /* n?o achou: retorna lista original */    
    }
    
    if (ant == NULL) 
    {
              /* retira elemento do inicio */
              LISTA = p->prox;
              tam--;
    }
    else 
    {
              /* retira elemento do meio da lista */
              ant->prox = p->prox;
              tam--;
    }
    free(p); 
    printf("Elemento removido\n\n"); 
    getch(); //Aguarda comando para sair do programa       
       	
}

//==============================================================================
node* buscaElemento(node *LISTA, int opt)
{
    
    //int opt;
    
	//printf("Qual elemento voce deseja encontrar: ");
	//scanf("%d", &opt);
		
	node* p;
	for (p=LISTA; p!=NULL; p=p->prox)
	{
		if (p->num == opt)
			return p;
    }
	return NULL; //nao encontrou   
    
      
       	
}
//==============================================================================

Pessoa coletaDadosPessoa(){
	Pessoa nova;
	system("cls");
	printf("Informe o codigo da pessoa");
	scanf("%d",&nova.codigo);
	printf("Informe o Nome da pessoa");
	scanf("%d",&nova.nome);
	printf("Informe o dia de aniversario da pessoa");
	scanf("%d",&nova.dia);
	printf("Informe o mes de aniversario da pessoa");
	scanf("%d",&nova.mes);
	return nova;
}


