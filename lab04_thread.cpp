#include <iostream>
#include "pthread.h"
#include <unistd.h>
#include <stdlib.h>
using namespace std;
#define NLOOP 10
int counter = 0;
void * doit(void *);
void * doit1(void *);
int main(){

	pthread_t tidA, tidB;
	pthread_create(&tidA, NULL, doit, NULL);
	pthread_create(&tidB, NULL, doit1, NULL);
	
	pthread_join(tidA, NULL);
	pthread_join(tidB, NULL);
	exit(0);
}//end main

void * doit(void *vprt){
	int i, val;
	for(i=0; i<NLOOP; i++){
		val = counter;
		cout<<"Thread = "<<pthread_self();
		cout<<"   Counter = "<<dec<<counter<<endl;
		sleep(1);
		counter=val+1;
	}//end for
	return(NULL);
}//end doit
	
void * doit1(void *vprt){
	int i, val;
	for(i=0; i<NLOOP; i++){
		val = counter;
		cout<<"Thread = "<<pthread_self();
		cout<<"   Counter = "<<dec<<counter<<endl;
		sleep(1);
		counter = val+5;
	}
	
	return(NULL);
	}

