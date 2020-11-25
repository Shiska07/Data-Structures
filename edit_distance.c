#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "edit_distance.h"

void table_print(int R, int C, int dist[][C],char * first_string, char * second_string) {
	int i,j,k;
	printf("    |    |");
	for(i = 0; i < C-1; i++){
		printf("%4c|",second_string[i]);
	}
	printf("\n");
	for(k = 0; k <= C; k++){
			printf("-----");
	}
	printf("\n");
	for(i = 0; i < R; i++){
		if(i == 0){
			printf("    |");
		}
		else {
			printf("%4c|",first_string[i-1]);
		}
		for(j = 0; j < C; j++){
			printf("%4d|",dist[i][j]);
		}
		printf("\n");
		for(k = 0; k <= C; k++){
			printf("-----");
		}
		printf("\n");
	}
}

int calculate_distance(int R, int C, int i, int j, int dist[][C],char * first_string, char * second_string){
	int top;
	int left;
	int diag;
	int min;
	char let_r = first_string[i-1];    //letter from row
	char let_c = second_string[j-1];   //letter from column
	top = 1 + dist[i-1][j];
	min = top;
	left = 1 + dist[i][j-1];
	if(left < min)
		min = left;
	if(let_r == let_c){
		diag = 0 + dist[i-1][j-1];
	}
	else{
		diag = 1 + dist[i-1][j-1];
	}
	if(diag < min)
		min = diag;
	return min;
}

int edit_distance(char * first_string, char * second_string, int print_table){    
	int R = strlen(first_string) + 1;  
	int C = strlen(second_string) + 1;
	int dist[R][C];                     
	int i,j;
	dist[0][0] = 0;
	for (i = 0; i < R; i++) {            //outerloop w/ i corresponds to the rows
		for( j = 0; j < C; j++) {        //innerloop corresponds to the letter
			if (i == 0 && j == 0){
				dist[i][j] = 0;
			}
			else if (i == 0){
				dist[i][j] = 1 + dist[i][j-1];    //filling up first row with consequtive numbers
			}
			else if (j == 0){
				dist[i][j] = 1 + dist[i-1][j];     //filling up first column with consequtive numbers
			}
			else {
				dist[i][j] = calculate_distance(R,C,i,j,dist,first_string,second_string);
			}
		}
	}
	if(print_table)
		table_print(R,C,dist,first_string,second_string);
	
	return dist[R-1][C-1];  
}	  
	
void free_array(char** array, int n){
	int i;
	for(i = 0; i < n; i++){
		free(array[i]);
	}
}
	
void spellcheck(char * dictname, char * testname){	

	FILE* myFile1 = NULL;
	FILE* myFile2 = NULL;
	
	myFile1 = fopen(dictname,"r");
	myFile2 = fopen(testname, "r");
	
	char buffer1[100];
	char buffer2[100];
	
	int no_of_words1 = 0;
	int no_of_words2 = 0;
	
	int word_length = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	
	int distance = -1;
	int min_distance = INT_MAX;
	
	if((myFile1 == NULL) || (myFile2 == NULL)){
		printf("The file could not be opened.\n");
		exit(0);
	}
	
	//storing number of words in each file
	fgets(buffer1, sizeof(buffer1), myFile1);
	no_of_words1 = atoi(buffer1);
	fgets(buffer2, sizeof(buffer2), myFile2);
	no_of_words2 = atoi(buffer2);
	
	char* dictionary_array[no_of_words1];  
	char* testFile_array[no_of_words2];
	int* mindist_nos = calloc(no_of_words1, sizeof(int));     //this array will hold indices of dictionary array which have minimum distance with given word
	
	
	//copying words in dictionary file to an array
	while(!feof(myFile1)){ 
		fscanf(myFile1,"%s",buffer1);
		word_length = strlen(buffer1);
		dictionary_array[i] = malloc((sizeof(char))*(word_length+1));
		strcpy(dictionary_array[i],buffer1);
		i++;
	}
	
	//copying words in test file to an array
	while(!feof(myFile2)){ 
		fscanf(myFile2,"%s",buffer2);
		word_length = strlen(buffer2);
		testFile_array[j] = malloc((sizeof(char))*(word_length+1));
		strcpy(testFile_array[j],buffer2);
		j++;
	}
	
	//comparing each file in testfile with each file in dictionary to find similar words
	for(i = 0; i < no_of_words2; i++){
		printf("------- Current test word: %s\n", testFile_array[i]);
		for(j = 0; j < no_of_words1; j++){
			distance = edit_distance(testFile_array[i],dictionary_array[j],0);
			mindist_nos[j] = distance;          //stores distance for all words in dictionary_array with the current word in testFile_array
			if(distance < min_distance){
				min_distance = distance;
			}
		}
		printf("Minimum distance: %d \n", min_distance);
		printf("Words that give minimum distance:\n");
		for(k = 0; k < no_of_words1; k++){
			if(mindist_nos[k] == min_distance){
				printf("%s\n", dictionary_array[k]);
			}
		}
		min_distance = INT_MAX;
		printf("\n");
	}
	
	free_array(dictionary_array,no_of_words1);
	free_array(testFile_array,no_of_words2);
	free(mindist_nos);
	fclose(myFile1);
	fclose(myFile2);
}

