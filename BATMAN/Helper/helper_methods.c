#include "helper_methods.h"
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

pthread_mutex_t mutex;

pthread_cond_t northQueue;
pthread_cond_t eastQueue;
pthread_cond_t southQueue;
pthread_cond_t westQueue;

pthread_cond_t northFirst;
pthread_cond_t eastFirst;
pthread_cond_t southFirst;
pthread_cond_t westFirst;

int northCounter;
int eastCounter;
int southCounter;
int westCounter;
int total;

void init_monitor()
{
	northCounter = 0;
	eastCounter = 0;
	southCounter= 0;
	westCounter = 0;
	total = 0;

	pthread_mutex_init(&mutex, NULL);

	pthread_cond_init(&northQueue, NULL);
	pthread_cond_init(&eastQueue, NULL);
	pthread_cond_init(&southQueue, NULL);
	pthread_cond_init(&westQueue, NULL);
	pthread_cond_init(&northFirst, NULL);
	pthread_cond_init(&eastFirst, NULL);
	pthread_cond_init(&southFirst, NULL);
	pthread_cond_init(&westFirst, NULL);

};

void arrive(BAT b){
	pthread_mutex_lock(&mutex);
	if(b.direcrion == 'n'){

		northCounter++;
		pthread_cond_wait(&northQueue, &mutex);

	}else if(b.direcrion == 'e'){

		eastCounter++;
		pthread_cond_wait(&eastQueue, &mutex);

	}else if(b.direcrion == 's'){

		southCounter++;
		pthread_cond_wait(&southQueue, &mutex);

	}else if(b.direcrion == 'w'){

		westCounter++;
		pthread_cond_wait(&westQueue, &mutex);

	}
	total++;
	printf("BAT %d from %c arrives at crossing\n", b.id, b.direcrion);

	pthread_mutex_unlock(&mutex);
};
void cross(BAT b){
	pthread_mutex_lock(&mutex);
	if(b.right == 'n'){
		if(northCounter>0){
			 pthread_cond_wait(&northFirst, &mutex);
		}
	}else if(b.right == 'e'){
		if(eastCounter>0){
			 pthread_cond_wait(&eastFirst, &mutex);
		}
	}else if(b.right == 's'){
		if(southCounter>0){
			 pthread_cond_wait(&southFirst, &mutex);
		}
	}else if(b.right == 'w'){
		if(westCounter>0){
			 pthread_cond_wait(&westFirst, &mutex);
		}
	}

	if(b.direcrion == 'n'){

			northCounter--;
			pthread_cond_signal(&northQueue);

		}else if(b.direcrion == 'e'){

			eastCounter--;
			pthread_cond_signal(&eastQueue);

		}else if(b.direcrion == 's'){

			southCounter--;
			pthread_cond_signal(&southQueue);

		}else if(b.direcrion == 'w'){

			westCounter--;
			pthread_cond_signal(&westQueue);

		}

	total--;

	printf("BAT %d from %c crossing\n", b.id, b.direcrion);

	sleep(1);

	pthread_mutex_unlock(&mutex);
};
void leave(BAT b){

	pthread_mutex_lock(&mutex);

	if(b.right == 'n'){

		pthread_cond_signal(&northFirst);  //should it be &northFirst or to be northQueue

	}else if(b.right == 'e'){

		pthread_cond_signal(&eastFirst);

	}else if(b.right == 's'){

		pthread_cond_signal(&southFirst);

	}else if(b.right == 'w'){

		pthread_cond_signal(&westFirst);

	}

	printf("BAT %d from %c leaving crossing\n", b.id, b.direcrion);
	pthread_mutex_unlock(&mutex);
};

void destroy(BAT b){
    pthread_mutex_destroy(&mutex);

    pthread_cond_destroy(&northQueue);
    pthread_cond_destroy(&eastQueue);
    pthread_cond_destroy(&westQueue);
    pthread_cond_destroy(&southQueue);
    pthread_cond_destroy(&northFirst);
    pthread_cond_destroy(&eastFirst);
    pthread_cond_destroy(&westFirst);
    pthread_cond_destroy(&southFirst);
};

void check(BAT b){
	if(total == 4){
		if(b.direcrion == 'n'){

			pthread_cond_signal(&northFirst);
			printf("DEADLOCK: BAT jam detected, signalling North to go");

		}else if(b.direcrion == 'e'){

			pthread_cond_signal(&eastFirst);
			printf("DEADLOCK: BAT jam detected, signalling East to go");


		}else if(b.direcrion == 's'){

			pthread_cond_signal(&southFirst);
			printf("DEADLOCK: BAT jam detected, signalling South to go");

		}else if(b.direcrion == 'w'){

			printf("DEADLOCK: BAT jam detected, signalling West to go");
			pthread_cond_signal(&westFirst);

		}
	}
};




