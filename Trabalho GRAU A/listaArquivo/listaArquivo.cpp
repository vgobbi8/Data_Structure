//programa que gerencia uma lista em memoria
//lista sem cabeï¿½alho
//permite gravaï¿½ï¿½o e leitura da lista em arquivo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>
#define max 50
typedef char TEXTO[max];

typedef struct DADOS
{
  int codigo;
  TEXTO nome;
} DADOS;

typedef struct NODO
{
  int codigo;
  TEXTO nome;
  NODO *proximo;
} NODO;

typedef struct lista
{
  int tamanho;
  NODO *inicio;
  NODO *fim;
} lista;

typedef struct lista LISTA;

enum chave_ordenacao
{
  codigo = 0,
  nome = 1
};

FILE *criaArquivo();
FILE *abreArquivo();
void fecha(FILE *arq);
void grava(FILE *arq, LISTA *L);
void ler(FILE *arq, LISTA *L, chave_ordenacao chave);
LISTA *cria();
int vazia(LISTA *l);
void insere(LISTA *l, DADOS v, chave_ordenacao chave);
int remove(LISTA *l, DADOS *v);
void mostralista(LISTA *L);
int tamanho(LISTA *L);
DADOS lerElemento();
char menu();

int procuraCodigo(int pmCodigo, LISTA * l);
void reordenarLista(LISTA *l, chave_ordenacao chave);
void inserePorCodigo(NODO *novo, NODO *anterior, NODO *corrente, LISTA *l);
void inserePorNome(NODO *novo, NODO *anterior, NODO *corrente, LISTA *l);

main()
{
	setlocale(LC_ALL,"portuguese");
  chave_ordenacao chave_atual;
  chave_atual = codigo;
  LISTA *inicio;
  FILE *arquivo;
  DADOS informa;
  char conf;
  char op = 'Z';
  inicio = NULL;
  while (op != 'F')
  {
    op = menu();
    switch (op)
    {
    case 'I':
      printf("\nI - inicializa lista\n");
      inicio = cria(); //aloca o inï¿½cio da lista
      system("pause");
      break;
    case 'N':
      printf("\nN - novo elemento\n");
      if (inicio == NULL)
      {
        printf("\nLista nao inicializada\n");
        system("pause");
      }
      else
      {
        informa = lerElemento();
        if(!procuraCodigo(informa.codigo,inicio)){
        	insere(inicio, informa, chave_atual);
		} else {
	   		printf("\nEste código já está em uso!\n");
        	system("pause");		
		}
      }
      break;
    case 'M':
      printf("\nM - mostra lista\n");
      if (inicio == NULL)
        printf("\n Lista Vazia \n ");
      else
        mostralista(inicio);
      system("pause");
      break;
    case 'G':
      printf("\nG - grava arquivo\n");
      //gravando dados da lista no arquivo
      if (inicio == NULL)
      {
        printf("\nLista nao inicializada\n");
        system("pause");
      }
      else
      {
        printf("\n Gravando dados no arquivo\n");
        arquivo = criaArquivo();
        grava(arquivo, inicio);
        fecha(arquivo);
        printf("\n Dados gravados....\n");
        system("pause");
      }
      break;
    case 'L':
      printf("\nL - ler arquivo\n");
      //lendo dados do arquivo para lista nova
      printf("\n Lendo dados do arquivo\n");
      arquivo = abreArquivo();
      if (inicio != NULL)
      {
        printf("\nExistem dados na lista em memoria");
        printf("\nDeseja substituir pelo arquivo(S/N)?");
        do
        {
          conf = toupper(getche());
        } while ((conf != 'S') && (conf != 'N'));
      }
      else
        conf = 'S';
      if (conf == 'S')
      {
        inicio = cria();
        ler(arquivo, inicio, chave_atual);
        mostralista(inicio);
        printf("\n Dados lidos....\n");
      }
      else
        printf("\n Arquivo nao lido....\n");
      fecha(arquivo);
      system("pause");
      break;
    case 'T':
      printf("\nT - tamanho\n");
      if (inicio == NULL)
      {
        printf("\nLista nao inicializada\n");
        system("pause");
      }
      else
      {
        printf("Lista tem %d elementos \n", tamanho(inicio));
        system("pause");
      }
      break;
    case 'A':
      int esc;

      if (inicio == NULL){
        printf("\nLista não inicializada!\n");
	  } 
	  else{
	  	printf("\nEscolha a chave: ");
      	printf("\n0 - CÃ³digo: ");
      	printf("\n1 - Nome: ");
      	scanf("%d", &esc);
	  	if ((chave_ordenacao)esc == chave_atual)
      	{
      	  printf("\nChave não alterada pois é a mesma que a anterior!\n");
      	}
      	else
      	{
      	  chave_atual = (chave_ordenacao)esc;
      	  reordenarLista(inicio, chave_atual);
      	  printf("\nLista reordenada:\n");
      	  mostralista(inicio);
      	}
  	  }
      system("pause");
      break;
    case 'F':
      free(inicio);
      printf("\nfinalizando sistema\n");
      break;

    default:
      printf("\n opcao invalida \n");
      system("pause");
    }
  }
  printf("\n");
  system("pause");
}

char menu()
{
  system("cls");
  printf("\nI - inicializa lista");
  printf("\nN - novo elemento");
  printf("\nM - mostra lista");
  printf("\nG - grava arquivo");
  printf("\nL - ler arquivo");
  printf("\nT - tamanho lista");
  printf("\nA - Alterar chave de ordenacao");
  printf("\nF - fim");
  printf("\nDigite opcao: ");
  fflush(stdin);
  return (toupper(getche()));
}

FILE *abreArquivo()
{
  FILE *arq;
  arq = fopen("dados.bin", "rb");
  if (arq == NULL)
    printf("\nArquivo nao existe!\n");
  else
    printf("\nArquivo aberto com sucesso\n");
  return (arq);
}

FILE *criaArquivo()
{
  FILE *arq;
  arq = fopen("dados.bin", "wb");
  if (arq == NULL)
    printf("\nErro ao criar arquivo!\n");
  return (arq);
}

void fecha(FILE *arq)
{
  fclose(arq);
}

void grava(FILE *arq, LISTA *L)
{
  NODO *p;
  DADOS registro;
  p = L->inicio;
  while (p != NULL)
  {
    registro.codigo = p->codigo;
    strcpy(registro.nome, p->nome);
    fwrite(&registro, sizeof(DADOS), 1, arq);
    printf("\ngravando: %d - %s", registro.codigo, registro.nome);
    p = p->proximo;
  }
}

void ler(FILE *arq, LISTA *L, chave_ordenacao chave)
{
  DADOS registro;
  rewind(arq); //garante que o cursor de leitura estï¿½ no inicio do arquivo
  while (!feof(arq))
  {
    if (fread(&registro, sizeof(DADOS), 1, arq) == 1)
      insere(L, registro, chave);
  }
}

LISTA *cria()
{
  LISTA *p;
  p = (LISTA *)malloc(sizeof(LISTA));
  p->fim = NULL;
  p->inicio = NULL;
  p->tamanho = 0;
  return (p);
}

int vazia(LISTA *l)
{
  if (l->inicio == NULL)
    return (1);
  else
    return (0);
}

void insere(LISTA *l, DADOS v, chave_ordenacao chave)
{
  NODO *novo;
  NODO *anterior;
  NODO *corrente;
  novo = (NODO *)malloc(sizeof(NODO));
  novo->codigo = v.codigo;
  strcpy(novo->nome, v.nome);
  novo->proximo = NULL; //Inicializa apontando para nulo
  if (vazia(l))
  { //Se a lista for vazia
    //O novo item Ã© inicio e fim da lista
    l->inicio = novo;
    l->fim = novo;
  }
  else
  {
    if (chave == codigo)
    {
      inserePorCodigo(novo, anterior, corrente, l);
    }
    else
    {
      inserePorNome(novo, anterior, corrente, l);
    }
  }
  l->tamanho = l->tamanho + 1;
}
int remove(LISTA *l, DADOS *v)
{
  int codigo = v->codigo;
  NODO *anterior;
  NODO *corrente;
  if (vazia(l))
  {
    return (0);
  }
  else
  {
    corrente = l->inicio;
    if (codigo == corrente->codigo)
    {
      strcpy(v->nome, corrente->nome);
      l->inicio = corrente->proximo;
      free(corrente);
      l->tamanho = l->tamanho - 1;
      return (1);
    }
    else
    {
      while ((corrente != NULL) &&
             (codigo != corrente->codigo) &&
             (codigo > corrente->codigo))
      {
        anterior = corrente;
        corrente = anterior->proximo;
      }
      if ((corrente == NULL) || (codigo > corrente->codigo))
      {
        return (0);
      }
      else
      {
        strcpy(v->nome, corrente->nome);
        anterior->proximo = corrente->proximo;
        if (l->fim == corrente)
        {
          l->fim = anterior;
        }
        l->tamanho = l->tamanho - 1;
        free(corrente);
        return (1);
      }
    }
  }
}

void mostralista(LISTA *L)
{
  NODO *p;
  int conta = 0;
  p = L->inicio; 
  while (p != NULL)
  {
    conta++;
    printf("Dados [%d]\n", conta);
    printf("Codigo %d \n", p->codigo);
    printf("Nome %s \n", p->nome);
    p = p->proximo; 
  }
}

DADOS lerElemento()
{
  DADOS info;
  	printf("\nDigite o codigo: ");
  	scanf("%d", &info.codigo);
  
  printf("\nDigite o nome: ");
  fflush(stdin);
  gets(info.nome);
  return (info);
}

int tamanho(LISTA *L)
{
  int t = 0;
  NODO *p = L->inicio;
  while (p != NULL)
  {
    t++;
    p = p->proximo;
  }
  return (t);
}
void reordenarLista(LISTA *l, chave_ordenacao chave)
{
  NODO *corrente;
  corrente = l->inicio;
  while (corrente != NULL)
  {
    NODO *outro = corrente->proximo;
    while (outro != NULL)
    {
 
      if (((chave == codigo) && (corrente->codigo > outro->codigo)) || ((chave == nome) && (strcmp(corrente->nome, outro->nome) > 0)))
      {
      	TEXTO nome;
		strcpy(nome,outro->nome);
      	int cod = outro->codigo;
		outro->codigo = corrente->codigo;
      	strcpy(outro->nome,corrente->nome);      	
		strcpy(corrente->nome, nome);
      	corrente->codigo = cod;
      }   	
      outro = outro->proximo;
    }
    corrente = corrente->proximo;
  }
}

void inserePorCodigo(NODO *novo, NODO *anterior, NODO *corrente, LISTA *l)
{
  corrente = l->inicio;
  if (novo->codigo < corrente->codigo)
  {
    novo->proximo = l->inicio;
    l->inicio = novo;
  }
  else
  {
    while ((corrente != NULL) && (novo->codigo >= corrente->codigo))
    {
      anterior = corrente;
      corrente = anterior->proximo;
    }
    anterior->proximo = novo;
    novo->proximo = corrente;
    if (corrente == NULL)
      l->fim = novo;
  }
}
void inserePorNome(NODO *novo, NODO *anterior, NODO *corrente, LISTA *l)
{
  corrente = l->inicio;
  if (strcmp(novo->nome, corrente->nome) < 0) //se for menor que zero, o novo nome deve ir antes
  {
    novo->proximo = l->inicio;
    l->inicio = novo;
  }
  else
  {
    while ((corrente != NULL) && strcmp(novo->nome, corrente->nome) >= 0)
    {
      anterior = corrente;
      corrente = anterior->proximo;
    }
    anterior->proximo = novo;
    novo->proximo = corrente;
    if (corrente == NULL)
      l->fim = novo;
  }
}
int procuraCodigo(int pmCodigo, LISTA * l){
	NODO * corrente = l->inicio;
	while(corrente != NULL){
		if(corrente->codigo == pmCodigo) return 1;
		corrente = corrente->proximo;
	}
	return 0;
}

