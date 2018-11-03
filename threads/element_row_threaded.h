#ifndef THREADS_ELEMENT_ROW_THREADED_H_
#define THREADS_ELEMENT_ROW_THREADED_H_

void row_threads(int *firstArray,int *secondArray,int first,int second,int third);

void *compute_matrix_row(void *row);


void element_threads(int *firstArray,int *secondArray,int first,int second,int third);

void *compute_matrix_element(void *element);

void write_output_for_second_method(char* outputFile,int rows,int cols);



#endif /* THREADS_ELEMENT_ROW_THREADED_H_ */
