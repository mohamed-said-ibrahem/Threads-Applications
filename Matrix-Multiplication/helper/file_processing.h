#ifndef HELPER_FILE_PROCESSING_H_
#define HELPER_FILE_PROCESSING_H_
#include <stdio.h>
#include <stdlib.h>

void read_input(char* inputFile);
void write_output(char* outputFile,int rows,int cols);
void read_matrix(FILE *file);

#endif /* HELPER_FILE_PROCESSING_H_ */
