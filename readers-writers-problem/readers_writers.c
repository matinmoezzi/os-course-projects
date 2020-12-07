//Matin-Moezi 9512058

#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

#include "readers_writers_m.h"

#define MAX_THREADS 4

typedef struct {
	int tid,data;
}arg_t;

int generate_arg(){
//	srand(time(0));
	return rand() % 100 + 1;
}

void *read(void *arg){
	arg_t this = *(arg_t *)arg;
	printf("Reader %d is reading...\n",this.tid);
	int value = Read();
	printf("Reader %d read %d.\n",this.tid,value);
}

void *write(void *arg){
	arg_t this = *(arg_t *)arg;
	printf("Writer %d is writing %d ...\n",this.tid,this.data);
	Write(this.data);
	printf("Writer %d wrote %d.\n",this.tid,this.data);
}

int main(){
	Init(0);
	pthread_t reader_threads[MAX_THREADS];
	pthread_t writer_threads[MAX_THREADS];
	arg_t reader_arg[MAX_THREADS],writer_arg[MAX_THREADS];
	for(int i = 0; i < MAX_THREADS; i++){
		reader_arg[i].tid = i + 1;
		writer_arg[i].tid = i + 1;
		writer_arg[i].data =  generate_arg();
		pthread_create(&reader_threads[i],NULL,read,&reader_arg[i]);
		pthread_create(&writer_threads[i],NULL,write,&writer_arg[i]);
	}
	for(int i = 0; i < MAX_THREADS;i++){
		pthread_join(reader_threads[i],NULL);
		pthread_join(writer_threads[i],NULL);
	}
	return 0;
}
