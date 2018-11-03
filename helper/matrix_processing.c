#include "file_processing.h"
#include "../threads/element_row_threaded.h"
#include <stdio.h>
#include <stdlib.h>

void read_matrix(FILE *file){
	    size_t max_bytes = 1000;
	    char *line = (char *)malloc(max_bytes);
	    getline(&line, &max_bytes, file);
	    char *p = line;
	    int rows = strtol(p, &p, 0);
	    p += 1;
	    int cols = strtol(p, &p, 0);
	     int first_matrix[rows][cols];
	    int i = 0;

	    for(int a = 0;a<rows;a++){
	    	getline(&line, &max_bytes, file);
	    	char *t = line;
	    	for (int j = 0; j < cols; ++j){
		    first_matrix[i][j] = strtol(t, &t, 0);
		    t += 1;
	    	}
	    	i++;
	    }
	    printf("First Matrix: \n");
	    for (int i = 0; i < rows; i++){
	    	for(int j = 0;j< cols; j++){
	    		printf(" %d ",first_matrix[i][j]);
	    	}
	    	printf("\n");
	    }

	   	    getline(&line, &max_bytes, file);
	   	    char *p_2 = line;
	   	    int rows_2 = strtol(p_2, &p_2, 0);
	   	    p_2 += 1;
	   	    int cols_2 = strtol(p_2, &p_2, 0);

	   	     int second_matrix[rows_2][cols_2];
	   	    int k = 0;

		    for(int b = 0;b<rows_2;b++){
	   	    	getline(&line, &max_bytes, file);
	   	    	char *t_2 = line;
	   	    	for (int j = 0; j < cols_2; ++j){
	   		    second_matrix[k][j] = strtol(t_2, &t_2, 0);
	   		    t_2 += 1;
	   	    	}
	   	    	k++;
	   	    }
	   	    printf("Second Matrix: \n");

	   	    for (int i = 0; i < rows_2; i++){
	   	    	for(int j = 0;j< cols_2; j++){
	   	    		printf(" %d ",second_matrix[i][j]);
	   	    	}
	   	    	printf("\n");
	   	    }

	   	    struct timeval start, stop;
	   	    gettimeofday(&start, NULL); // start stopwatch
		   	row_threads(first_matrix,second_matrix,rows,cols,cols_2);
	   	    gettimeofday(&stop, NULL); // stop
	   	    printf("Time taken in seconds =  %lu\n", stop.tv_sec - start.tv_sec);
	   	    printf("Time taken in microseconds = %lu\n\n", stop.tv_usec - start.tv_usec);

	   	    gettimeofday(&start, NULL); // start stopwatch
		   	element_threads(first_matrix,second_matrix,rows,cols,cols_2);
	   	    gettimeofday(&stop, NULL); // stop
	   	    printf("Time taken in seconds =  %lu\n", stop.tv_sec - start.tv_sec);
	   	    printf("Time taken in microseconds = %lu\n\n", stop.tv_usec - start.tv_usec);

//
//	   	   row_threads(first_matrix,second_matrix,rows,cols,cols_2);
//	   	   element_threads(first_matrix,second_matrix,rows,cols,cols_2);

		  free(line);
}


void read_input(char* inputFile){
	 FILE* file = fopen(inputFile, "r");
	 if (file == NULL) {
	        printf("ERROR WITH INPUT FILE");
	        exit(1);
	}
	read_matrix(file);
	fclose(file);
}






