#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <ctype.h>

   
struct node {
	int data;
	struct node* next;
};

typedef struct node list;

list* start (void);
list* insert (list* l, int value);
void print_list (list* l);
void free_list (list* l);
list* last_value (list* l, int value);


int main()
{
	
	system("cls");
    
    list *values;
	list *tmp;
	 
	values = start();
		
	values = insert(values, 1);
	values = insert(values, 2);
	values = insert(values, 3);
	values = insert(values, 4);
	values = insert(values, 5);
	values = insert(values, 2);
	
	//Imprime toda a lista
    printf ("\n\nLista original....\n");
	print_list(values);
	tmp = last_value(values,2);
	
    printf ("\n\nFound Element....\n");
	print_list(tmp);
	
	free_list(values);
    
}

void print_list (list* l)
{
	list* p;	
	for (p = l; p != NULL; p = p->next)
		printf("data = %d\n", p->data);
}

list* insert (list* l, int value)
{
	list* new_item = (list*) malloc(sizeof(list));
	new_item->data = value;
	new_item->next = l;
	return new_item;
}

list* start (void)
{
	return NULL;
}
 
void free_list (list* l)
{
	list* p = l;
	while (p != NULL) 
	{
		list* t = p->next;
		free(p); 
		p = t; 	
	}
}

list* last_value (list* l, int value)
{
          
	list* p;
	list* posElem = NULL;
	
	for (p=l; p!=NULL; p=p->next)
	{
		if (p->data == value)
		{
			posElem = p;   
        }
    } 
    
    return posElem;
}




