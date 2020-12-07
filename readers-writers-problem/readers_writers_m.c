//Matin-Moezi 9512058

#include <pthread.h>
#include <semaphore.h>

#include "readers_writers_m.h"

static int data,readerCount;

static sem_t CounterLock,WriterLock;

void Init(int n){
	readerCount = 0;
	data = n;
	sem_init(&WriterLock,0,1);
	sem_init(&CounterLock,0,1);
}

int Read(){
	int value;
	sem_wait(&CounterLock);
	readerCount++;
	if(readerCount == 1)
		sem_wait(&WriterLock);
	sem_post(&CounterLock);
	value = data;
	sem_wait(&CounterLock);
	readerCount--;
	if(readerCount == 0)
		sem_post(&WriterLock);
	sem_post(&CounterLock);
	return value;
}

void Write(int n){
	sem_wait(&WriterLock);
	data = n;
	sem_post(&WriterLock);
}
