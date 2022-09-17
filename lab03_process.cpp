#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main(){
	pid_t pid1, pid2, cpid;
	int i, j, a, status;
	a=0;
	
	cout<<"\n Parent process pid="<<getpid()<<"\n";
	pid1 = fork();
	
	if(pid1 <0){
		cout<<"First Fork Failed\n";
		exit(-1);
	}//end if
	
	else if(pid1 ==0){
		cout<<"\n Child1 process pid= "<<getpid()<<"\n";
		for(i=0; i<10; i++){
			a++;
			cout<<"Child1: a = "<<a<<"\n";
			sleep(5);
		}//end for
	}//end else if
	
	else{//parent
		pid2 = fork();
		if(pid2<0){
			cout<<"Second Fork Failed\n";
			exit(-1);
		}//end for
		
		else if(pid2 ==0){
			cout<<"\n Child2 process pid= "<<getpid()<<"\n";
			for (j=0; j<10; j++){
				a++;
				cout<<"Child2: a = "<<a<<"\n";
				sleep(5);
			}//end for
		}//end else if
	
		else{//parent
			cpid = wait(&status);
			cout<<"\n **Parent is Closing**\n";
			exit(0);
		}
	}//end else parent
	
}//end main
	 
	

