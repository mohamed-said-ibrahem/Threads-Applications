#include "file_processing.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


int unsorted_array[100];
int total_length;

#define MAX 100

#define THREAD_MAX 4


int a[MAX];
int part = 0;

void merge(int low, int mid, int high)
{
	int left[mid - low + 1];
	int right[high - mid];


	int n1 = mid - low + 1, n2 = high - mid, i, j;

	for (i = 0; i < n1; i++)
		left[i] = a[i + low];

	for (i = 0; i < n2; i++)
		right[i] = a[i + mid + 1];

	int k = low;
	i = j = 0;

	while (i < n1 && j < n2) {
		if (left[i] <= right[j])
			a[k++] = left[i++];
		else
			a[k++] = right[j++];
	}

	while (i < n1) {
		a[k++] = left[i++];
	}

	while (j < n2) {
		a[k++] = right[j++];
	}
}

void merge_sort2(int low, int high)
{
	int mid = low + (high - low) / 2;
	if (low < high) {

		merge_sort2(low, mid);

		merge_sort2(mid + 1, high);

		merge(low, mid, high);
	}
}

void* merge_sort(void* arg)
{
	int thread_part = part++;

	int low = thread_part * (total_length / 4);
	int high = (thread_part + 1) * (total_length / 4) - 1;

	int mid = low + (high - low) / 2;
	if (low < high) {
		merge_sort2(low, mid);
		merge_sort2(mid + 1, high);
		merge(low, mid, high);
	}
}

void read_unsorted_array(FILE *input){
		 FILE* file = fopen(input,"r");
		 if (file == NULL) {
				printf("ERROR WITH INPUT FILE");
				exit(1);
		}
	    size_t max_bytes = 1000;
	    char *line = (char *)malloc(max_bytes);
	    getline(&line, &max_bytes, file);
	    char *p = line;
	    int length = strtol(p, &p, 0);
	    total_length = length;
	    printf("%d\n",length);

	    getline(&line, &max_bytes, file);
    	char *t = line;
	    for(int a = 0;a<length;a++){
	    	unsorted_array[a]=strtol(t, &t, 0);
	    	t+=1;
	    }

		for (int i = 0; i < total_length; i++)
	    		a[i] = unsorted_array[i];

	    	clock_t t1, t2;

	    	t1 = clock();
	    	pthread_t threads[total_length];

	    	for (int i = 0; i < total_length; i++)
	    		pthread_create(&threads[i], NULL, merge_sort,(void*)NULL);

	    	for (int i = 0; i < total_length; i++)
	    		pthread_join(threads[i], NULL);

	    	merge(0, (length / 2 - 1) / 2, length / 2 - 1);
	    	merge(length / 2, length/2 + (length-1-length/2)/2, length - 1);
	    	merge(0, (length - 1)/2, length - 1);

	    	t2 = clock();

	    	printf("Sorted array: ");
	    	for (int i = 0; i < total_length; i++)
	    		printf("%d ",a[i]);

	    	printf("\n");


}




