#include <iostream>  
#include <stdlib.h> 
#include <unistd.h>
#include "pthread.h"
using namespace std;
#define NLOOP 10

pthread_mutex_t Count_mutex = PTHREAD_MUTEX_INITIALIZER;

int counter = 0;
void * doit(void *);
int main(){

	pthread_t tidA, tidB, tidC;
	pthread_create(&tidA, NULL, doit, NULL);
	pthread_create(&tidB, NULL, doit, NULL);
	pthread_create(&tidC, NULL, doit, NULL);
	
	pthread_join(tidA, NULL);
	pthread_join(tidB, NULL);
	pthread_join(tidC, NULL);

	pthread_mutex_destroy(&Count_mutex);
	exit(0);
}//end main

void * doit(void *vprt){
	int i, val;
	for(i=0; i<NLOOP; i++){
	//pthread_mutex_lock(&Count_mutex);
		val = counter;
		cout<<pthread_self()<<"  "<<dec<<val+1<<endl;
		sleep(1);
	//pthread_mutex_lock(&Count_mutex);
		counter = val+1;
	//pthread_mutex_unlock(&Count_mutex);
	}
	return (NULL);
} //end doit function

