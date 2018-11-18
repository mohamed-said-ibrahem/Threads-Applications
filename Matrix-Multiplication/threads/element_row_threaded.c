#include "element_row_threaded.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


int firstArr[1000][1000], secondArr[1000][1000],outputArr[1000][1000],outputArrElements[1000][1000];
int m,n;


void *compute_matrix_row(void *row) {
    int i = (int) row;
    for (int k = 0; k < n; k++)
    	for (int j = 0; j < m; j++)
        	outputArr[i][k] += firstArr[i][j] * secondArr[j][k];
}


void write_output(char* outputFile,int rows,int cols){

	FILE *file = fopen(outputFile, "w");
    if (file == NULL) {

        printf("ERROR WITH OUTPUT FILE");
        exit(1);
    }
    for(int i=0;i<rows;i++) {
		for(int j=0;j<cols;j++) {
			fprintf(file,"%d ",outputArr[i][j]);
		}
		fprintf(file,"\n");
    }

	fclose(file);
}

void write_output_for_second_method(char* outputFile,int rows,int cols){

	FILE *file = fopen(outputFile, "w");
    if (file == NULL) {

        printf("ERROR WITH OUTPUT FILE");
        exit(1);
    }
    for(int i=0;i<rows;i++) {
		for(int j=0;j<cols;j++) {
			fprintf(file,"%d ",outputArrElements[i][j]);
		}
		fprintf(file,"\n");
    }

	fclose(file);
}
void row_threads(int *firstArray,int *secondArray,int first,int second,int third) {

	int l=0;
	for(int i =0;i<first;i++){
		for(int j=0;j<second;j++){
			firstArr[i][j] = *(firstArray+l);
			l++;
		}
	}
	 l=0;
	for(int i =0;i<second;i++){
		for(int j=0;j<third;j++){
			secondArr[i][j] = *(secondArray+l);
			l++;
		}
	}

    m = second;
    n = third;
    pthread_t threads[first];

    pthread_t row_thread[first];
    for (int i = 0; i < first; i++)
        if (pthread_create(&row_thread[i], NULL, compute_matrix_row, (void *) (intptr_t) i)) {
            printf("CANT CREATE THREAD!\n");
            exit(1);
        }
    for (int i = 0; i < first; i++)
        pthread_join(row_thread[i], NULL);

    printf("Result Matrix Method 1 (Row): \n");
    for(int o=0;o<first;o++) {
		for(int p=0;p<third;p++) {
			printf(" %d\t",outputArr[o][p]);
		}
		printf("\n");
    }
    write_output("output.txt",first,third);

}




void element_threads(int *firstArray,int *secondArray,int first,int second,int third) {

	int l=0;
	for(int i =0;i<first;i++){
		for(int j=0;j<second;j++){
			firstArr[i][j] = *(firstArray+l);
			l++;
		}
	}
	 l=0;
	for(int i =0;i<second;i++){
		for(int j=0;j<third;j++){
			secondArr[i][j] = *(secondArray+l);
			l++;
		}
	}

    m = second;
    n = third;

    pthread_t threads[first][third];
    for (int i = 0; i < first; i++){
        for (int j = 0; j < third; j++){
        	int parameters = i*1000+j;
            if (pthread_create(&threads[i][j], NULL, compute_matrix_element, (void *)parameters)) {
                printf("COULD NOT CREATE AN ELEMENT THREAD!\n");
                exit(1);
            }
        }
    }

    for (int i = 0; i < first; i++)
        for (int j = 0; j < third; j++)
            pthread_join(threads[i][j], NULL);

    printf("Result Matrix Method(2)(element): \n");
    for(int o=0;o<first;o++) {
		for(int p=0;p<third;p++) {
			printf(" %d\t",outputArrElements[o][p]);
		}
		printf("\n");
    }
    write_output_for_second_method("output.txt",first,third);
}

void *compute_matrix_element(void *parameters) {
	int t= (int)parameters;
	int i=t/1000,j=t%1000;
	for(int k=0;k < m ; k++){
		outputArrElements[i][j]+=firstArr[i][k]*secondArr[k][j];
	}

}




