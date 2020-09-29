#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <ctype.h>
   
//==============================================================================   
struct node {
	char character;
	struct node* next;
};

typedef struct node list;
//==============================================================================
list* start (void);
list* insert (list* l, char ch);
void print_list (list* l);
void free_list (list* l);
void replace (list* l, char original, char new_item);

//==============================================================================
int main()
{
	
	system("cls");
    
    list *char_list;
	list *tmp;
	 

	char_list = start();
		
	
	printf("\nWait! Values are being inserted . . .\n");
	char_list = insert(char_list, 'A');
	char_list = insert(char_list, 'B');
	char_list = insert(char_list, 'C');
	char_list = insert(char_list, 'D');
	char_list = insert(char_list, 'E');
	char_list = insert(char_list, 'B');
	
	
	printf("Original word: \n");

	print_list(char_list);
		
	printf("\nReplacing B with W . . . \n");
	
    replace (char_list, 'B', 'W');	
	
	printf("\nResult: \n");
	print_list(char_list);

	free_list(char_list);
        
}

//==============================================================================
void print_list (list* l)
{
	list* p;	
	for (p = l; p != NULL; p = p->next)
		printf("char = %c\n", p->character);
}
//==============================================================================
list* insert (list* l, char ch)
{
	list* new_item = (list*) malloc(sizeof(list));
	new_item->character = ch;
	new_item->next = l;
	return new_item;
}
//==============================================================================
list* start (void)
{
	return NULL;
}
//============================================================================== 
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
//==============================================================================
void replace (list* l, char original, char new_char)
{
          
	list* p;
	for (p=l; p!=NULL; p=p->next)
	{
		if (p->character == original)
		{
			p->character = new_char;
        }
    } 
}
//==============================================================================



