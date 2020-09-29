#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <ctype.h>

struct Node{
	int num;
	struct Node *next;
}; 
typedef struct Node list;


void start(list * my_list);
list * alloc_node();
list * insert(list * my_list);
void free_list(list * my_list);
int get_list_length(list * my_list);

int main(void)
{	
	system("cls");
	int list_length = 0;
    
    list *my_list = (list *) malloc(sizeof(list));
	if(!my_list){
		printf("Out of memory!\n");
		exit(1);
	}
    else
    {
    	start(my_list);	
    	
    	insert(my_list);
     	insert(my_list);    	
		insert(my_list);
		insert(my_list);
	 	insert(my_list);
	
		list_length = get_list_length(my_list);

		printf("Length: %d",list_length);

    	free_list(my_list);
	}
}

void start(list *my_list)
{
	my_list->next = NULL;
	my_list->num = 0;
}

list * alloc_node(){
	list * new_item = (list *) malloc(sizeof(list));
	if(!new_item){
		printf("\nOut of memory!\n");
		exit(1);
	}else{
		printf("\nNew item: ");
		scanf("%d",&new_item->num);
		return new_item;
	}
}

list * insert(list * my_list){
	list * item = alloc_node();
	list * old = my_list->next;
	my_list->next = item;
	item->next = old;
}
void free_list(list * my_list){
	if(my_list != NULL){ //Recebe a lista  como parâmetro
		list * next,*current; //Cria duas variáveis do tipo lista
		current = my_list->next; //a variável auxiliar que representa o item atual recebe o próximo da lista
		while(current != NULL){ 
			next = current->next; //armazena o próximo item na variável auxiliar que represnta o próximo item
			free(current); //libera  o atual
			current = next; // torna o atual igual ao proximo
		}
	}
}

int get_list_length(list * my_list){
	int counter = 0;
	list * current;
	current = my_list;
	if(my_list == NULL){
		return 0;
	} else{
		while(current->next != NULL){
			counter++;
			current = current->next;
		}
	}
	return counter;
}

