#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int *allocMemory(int length);
void readVector(int *vect, int  length);
void orderVector(int *vect, int  length);
void printVector(int *vect, int  length);
void freeMemory(int *vect);

int main(void){
	int length, *vect, max, min;
	int avg;
	
	system("cls");
	printf("Type vector length: \n");
	scanf("%d",&length);
	
	vect = allocMemory(length);
	
	readVector(vect,length);
	
	printVector(vect,length);

	orderVector(vect,length);

	printVector(vect,length);
		
	freeMemory(vect);
}

int *allocMemory(int length){
	int * newVector;
	newVector = (int *) calloc(length, sizeof(int));
	if(!newVector){
		printf("Out  of memory!");
		exit(1);
	}
	return newVector;
}
void freeMemory(int *vect){
	free(vect);
}

void readVector(int *vect,int length){
	for(int i = 0; i< length; i++){
		system("cls");
		printf("Type a value for the %d position: ",(i+1));		
		scanf("%d",&*(vect +i));
	}
}

void orderVector(int *vect, int length){
	int val;
	for (int i = 0; i < length; i++ ){
		for(int j = 0;j<length; j++){
			if(*(vect+i) < *(vect+j)){
				val = *(vect+i);
				*(vect+i) = *(vect+j);
				*(vect+j) = val;
			}	
		} 		
	}
}

void printVector(int *vect, int length){
	for (int i = 0; i < length; i++ ){
		printf("%d\n",*(vect+i));
	}
}
