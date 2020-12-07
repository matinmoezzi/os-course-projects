//Matin-Moezi 9512058

#include <pthread.h>
#include <semaphore.h>

#include "dinning_philosophers_m.h"

static enum {THINKING, HUNGRY, EATING} state[5];
static pthread_cond_t self[5];
static pthread_mutex_t mutex;

void Init(){
	pthread_mutex_init(&mutex,NULL);
	for(int i = 0; i < 5;i++){
		state[i] = THINKING;
		pthread_cond_init(&self[i],NULL);
	}
}
void Test(int i){
	if((state[(i + 4) % 5] != EATING) && (state[i] == HUNGRY) && (state[(i + 1) % 5] != EATING)){
		state[i] = EATING;
		pthread_cond_signal(&self[i]);
	}
}
void Pickup(int i){
	pthread_mutex_lock(&mutex);
	state[i] = HUNGRY;
	Test(i);
		if(state[i]!=EATING)
//	while(state[i] == HUNGRY)
		pthread_cond_wait(&self[i],&mutex);
	pthread_mutex_unlock(&mutex);
}
void Putdown(int i){
	pthread_mutex_lock(&mutex);
	state[i]=THINKING;
	Test((i + 4) % 5);
	Test((i + 1) % 5);
	pthread_mutex_unlock(&mutex);
}
