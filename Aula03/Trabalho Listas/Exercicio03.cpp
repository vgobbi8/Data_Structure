#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <ctype.h>


struct node{
  int data;
  struct node* next;
};
typedef struct node list;

//==============================================================================
list* start()
{
   return NULL;
}
//==============================================================================
list* insert(list* l, int data)
{
   list* new_node= (list*)malloc(sizeof(list));
   new_node->data = data;
   new_node->next = l;
   return new_node;
}
//==============================================================================
list* insert(list* l, list* node)
{
   node->next = l;
   return node;
}
//==============================================================================
void print_list(list* l)
{
   list* p;
   for(p=l;p !=NULL;p=p->next){
     printf("data = %d\n",p->data);
   }
}
//==============================================================================
void free_list(list* l)
{
   list* p = l;
   while (p != NULL){
     list* t = p-> next;
     free(p);
     p = t;
   }
}
//==============================================================================
list * invert(list* base_ls) {
	
  list* new_ls = NULL; //creates a new list
  
  while (base_ls) { 
    list* next = base_ls->next;
    base_ls->next = new_ls;
    new_ls = base_ls;
    base_ls = next;
  }
  return new_ls;
}

//==============================================================================
int main()
{

	system("cls");
        
    list* l; 
    l = start();
    l = insert(l, 1); 
    l = insert(l, 2); 
    l = insert(l, 3); 
    l = insert(l, 4); 
    printf("\nOriginal: \n");
    print_list(l);
    printf("\n\nInverse: \n"); 
    l = invert(l);
    print_list(l);   
    
    free_list(l);
}

