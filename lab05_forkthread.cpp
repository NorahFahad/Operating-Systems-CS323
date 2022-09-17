#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "pthread.h"
using namespace std;
int counter = 0;
void * doit(void *);
int main(){
	pthread_t tid;
	pid_t pid, cpid;
	int status;
	
	pthread_create(&tid, NULL, doit, NULL);
	sleep(2);
	pid = fork();
		
	if(pid<0){
		cout<<"FORK FAILED\n";
		exit(-1);
	}
	
	else if(pid == 0){
		//cout<<"child pid="<<getpid()<<"\n";
		//	for(int i=0; i<10; i++){
				sleep(2);
				cout<<"Child counter = "<< counter << endl;
		//		counter++;
			}
	//}
	
	else{
		cpid = wait(&status);
		pthread_join(tid, NULL);
		exit(0);
	}
	
}//end main
	
void * doit(void *vptr){

	sleep(1);
	cout<< "Thread First Counter = "<< ++counter << endl;
	sleep(5);
	cout<< "Thread Second Counter = "<< ++counter << endl;
	return(NULL);
}
	
