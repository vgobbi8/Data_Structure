#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int *allocMemory(int length);
void readVector(int *vect, int  length);
int findMaxValue(int *vect, int  length);
int findMinValue(int *vect, int  length);
float avgVector(int *vect, int  length);
void freeMemory(int *vect);

int main(void){
	int length, *vect, max, min;
	float avg;
	
	system("cls");
	printf("Type vector length: \n");
	scanf("%d",&length);
	
	vect = allocMemory(length);
	
	readVector(vect,length);
	
	printf("Max value:  %d\n",findMaxValue(vect,length));
	printf("Min value:  %d\n",findMinValue(vect,length));
	printf("Agv value:  %f\n",avgVector(vect,length));

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

int findMaxValue(int *vect,int length){
	int higest = *(vect); //gets the first value of the vector
	for (int i = 0;i < length; i++){
		if(higest < *(vect + i)) higest = *(vect + i);	
	}
	return higest;	
}

int findMinValue(int *vect,int length){
	int lower = *(vect); //gets the first value of the vector
	for (int i = 0;i < length; i++){
		if(lower > *(vect + i)) lower = *(vect + i);	
	}
	return lower;
}

float avgVector(int *vect, int length){
	float sum;
	for (int i = 0; i < length; i++ ){
		sum  += *(vect+i);
	}
	return sum / length;
}

