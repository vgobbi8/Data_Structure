#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
typedef struct node{
	float info;
	node * next;
};

struct list {
	int length;
	struct node* begin, end;
};

list * criar();
void remover(list * my_list,float * info);
void insere_inicio();
void insere_fim();
void liberar_memoria(list * my_list);

int main(){
	setlocale(LC_ALL,"portuguese");
	int opc;
	list * minha_lista;
	do{
		switch(opc){
			case 1:
				insert_begin();
			case 2:
				insert_end();
			case 3:
				remove_item();
			case 4:
				buscar_elemento();
			case 5:
				listar();
			case 6:
				liberar_memoria();			
		}
	} while (opc != 7);
}


int menu(){
	int opc;
	system("cls");
	printf("Escolha uma opção\n");
	printf("1 - Inserir no início\n");
	printf("2 - Inserir no fim\n");	
	printf("3 - Remover um elemento\n");
	printf("4 - Buscar um elemento\n");
	printf("5 - Listar\n");
	printf("6 - Liberar memória");
	printf("7 - Sair");
	scanf("%d",&opc);
	return opc;
}



list * criar(){
	list * new_list = (list) malloc(sizeof (list));
	new_list->length = 0;
	new_list->begin = NULL;
	new_list->end = NULL;
	return new_list;
}

void liberar_memoria(list * my_list){
	if(my_list != NULL){
		 free(my_list);
	}
}

void insere_inicio(list * my_list,float info){
	node * new_item;
	node * prev, curr;
		
}










