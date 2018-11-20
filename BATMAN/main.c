#include "Helper/helper_methods.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <string.h>

void* start(void* b) {
	BAT *newBat = (BAT *) b;
	check(newBat);
	run(newBat);
	return NULL;
}

BAT *init_bat(int id, char direction, char right) {
    BAT *mybatt = malloc(sizeof(BAT));
    mybatt->id = id;
    mybatt->direcrion = direction;
    mybatt->right = right;
    return mybatt;
}

int main() {
	char string[256];
	scanf("%s", string);
	int length = strlen(string);
//	printf("%d\n",length);
    pthread_t threads[length];
    BAT bats[length];

	for(int i = 0 ;i<length;i++){
		        bats[i].id =i;
		        bats[i].direcrion =string[i];
		        if(string[i]=='n'){
			        bats[i].right ='e';
		        }else if(string[i]=='e'){
			        bats[i].right ='s';
		        }else if(string[i]=='s'){
			        bats[i].right ='w';
		        }else if(string[i]=='w'){
			        bats[i].right ='n';
		        }
	}
	for (int i = 0; i < length; i++){
		int a = bats[i].id;
		char b = bats[i].direcrion;
		char c = bats[i].right;
		pthread_create(&threads[i], NULL, start,(void *) init_bat(a, b, c));
	}
	for (int i = 0; i < length; i++)
	pthread_join(threads[i], NULL);



}
