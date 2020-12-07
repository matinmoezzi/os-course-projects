//Matin-Moezi 9512058

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "dinning_philosophers_m.h"

int rnd(){
	srand(time(0));
	return rand() % 5;
}

void eating(int i){
	printf("Philosopher %d is eating...\n",i);
	sleep(rnd());
}
void thinking(int i){
	printf("Philosopher %d is thinking...\n",i);
	sleep(rnd());
}
void pickup(int i){
	printf("Philosopher %d waiting...\n",i);
	Pickup(i);
}
void putdown(int i){
	printf("Philosopher %d is full.\n",i);
	Putdown(i);
}
void *load(void *arg){
	int i = *(int *)arg;
	thinking(i);
	pickup(i);
	eating(i);
	putdown(i);
}
int main(){
	Init();
	pthread_t phils[5];
	int arg[] = {1,2,3,4,5};
	for(int i = 0; i < 5; i++){
		pthread_create(&phils[i],NULL,load,&arg[i]);
	}	
	for(int i = 0; i < 5;i++){
		pthread_join(phils[i],NULL);
	}
	return 0;
}
