#include<stdio.h>
#include <stdlib.h>
int **allocMat(int rows,int columns);
int findMinimax(int **mat,int rows, int columns);
void readMat(int **mat,int rows, int columns);
void freeMat(int **mat,int rows);

int main(){
	int rows = 0;
	int columns = 0;
	printf("Type number of rows: \n");
	scanf("%d",&rows);
	printf("Type number of columns: \n");
	scanf("%d",&columns);
	int **mat = allocMat(rows,columns);
	readMat(mat,rows,columns);
	printf("MINIMAX: %d ",findMinimax(mat,rows,columns));
	freeMat(mat,rows);	
}


int **allocMat(int rows, int columns){
	int **newMat; 
	newMat = (int **)calloc(rows,sizeof(int *)); //creates a new multidimensional array, based in rows 
	for(int i = 0; i<rows; i++){ //then, iterate each row...
		newMat[i] = (int *) calloc(columns, sizeof(int)); // and create n columns for that row
		if(!newMat[i]){ //if it can't allocate memory
			for(int j = (i- 1); j >=0; j--){ //it must free all the memory that was allocated before
				free(newMat[i]);	
			}
			free(newMat);
		}
	}
	return newMat;
}
void readMat(int **mat, int rows, int columns){
	for(int i = 0; i< rows; i++){
		for(int j = 0; j < columns; j++){
			printf("Type a value for the {%d} {%d} position: \n",(i+1),(j+1));
			scanf("%d",&mat[i][j]);
		}
	}
}
void freeMat(int **mat, int rows){
	for(int i = 0; i >rows; i++){ 
		free(mat[i]);	
	}
	free(mat);
}


int findLineWithMaxValue(int **mat,int rows, int columns){
	int max = mat[0][0];
	int rowMax = 0;
	for (int i = 0; i< rows; i++){
		for(int  j =0; j < columns; j++){
			if(max < mat[i][j]) {
				max = mat[i][j];
				rowMax = i;
			}	
		}
	}
	return rowMax;
}


int findMinimax(int **mat, int rows, int columns){
	int rowMax = findLineWithMaxValue(mat,rows,columns);
	int minimax = *(*mat);
	for (int i = 0; i< columns; i++){
		if(minimax > mat[rowMax][i]){
			minimax = mat[rowMax][i];
		}
	}
	return minimax;
}


