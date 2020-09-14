#include<stdio.h>
#include <stdlib.h>
float **allocMat(int rows,int columns);
void readMat(float **mat,int rows, int columns,char *name);
void freeMat(float **mat,int rows);
void sumMat(float **result,float ** mat_1, float **mat_2, int rows, int columns);
void showMat(float **mat,int rows, int columns, char *name);
int main(){
	int rows = 0;
	int columns = 0;
	float **mat_1;
	float **mat_2;
	float **result;
	printf("Type number of rows: \n");
	scanf("%d",&rows);
	printf("Type number of columns: \n");
	scanf("%d",&columns);

	mat_1 = allocMat(rows,columns);
	
	mat_2 = allocMat(rows,columns);
	
	result = allocMat(rows,columns);
	
	readMat(mat_1,rows,columns,"Matrix 1");
	readMat(mat_2,rows,columns,"Matrix 2");


	sumMat(result, mat_1,mat_2,rows,columns);
	
	showMat(result,rows,columns,"Result");
	freeMat(mat_1,rows);
	freeMat(mat_2,rows);
	freeMat(result,rows);	
}


float **allocMat(int rows, int columns){
	float **newMat; 
	newMat = (float **)calloc(rows,sizeof(float *)); //creates a new multidimensional array, based in rows 
	for(int i = 0; i<rows; i++){ //then, iterate each row...
		newMat[i] = (float *) calloc(columns, sizeof(float)); // and create n columns for that row
		if(!newMat[i]){ //if it can't allocate memory
			for(int j = (i- 1); j >=0; j--){ //it must free all the memory that was allocated before
				free(newMat[i]);	
			}
			free(newMat);
		}
	}
	return newMat;
}
void readMat(float **mat, int rows, int columns, char *name){
	printf("\n Matrix: %s \n",name);
	for(int i = 0; i< rows; i++){
		for(int j = 0; j < columns; j++){
			printf("Type a value for the {%d} {%d} position: \n",(i+1),(j+1));
			scanf("%f",&mat[i][j]);
		}
	}
}
void freeMat(float **mat, int rows){
	for(int i = 0; i >rows; i++){ 
		free(mat[i]);	
	}
	free(mat);
}


void sumMat(float **result,float **mat_1, float **mat_2, int rows, int columns){
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<columns; j++)
		{
			result[i][j] = mat_1[i][j] + mat_2[i][j];
		}
	}	
}

void showMat (float **mat, int rows, int columns, char *name)
{
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<columns; j++)
			printf("%.2f ", mat[i][j]); 
		printf("\n");
	}
}


