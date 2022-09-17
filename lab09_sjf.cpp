#include <iostream>
#include "pthread.h"

using namespace std;
//void *start_finish(void *);
float n,tempb,tempa,tempp,tw,average,gap,arrive[3],burst[3],process[3],start[ 3],finish[3],waiting[3],response[3],turnaround[3];
 
//start finish function//
void* start_finish(void *){
	start[0]=arrive[0]; 
	finish[0]=arrive[0]+burst[0];
	for(int i=1;i<3;i++){
		gap=0;
		if(arrive[i]>finish[i-1]){ 
			gap=arrive[i]-finish[i-1];
			start[i]=finish[i-1]+gap;
		}//end if
	else
		start[i]=finish[i-1];
		finish[i]=start[i]+burst[i];
	}//end for
	return(NULL);
}//end start_finish()

int main(){

	pthread_t tidA, tidB;
	
	int i,j;
	for(i=0;i<3;i++){//Get values from User
		n=i+1;
		process[i]=n;
		cout<<"What is P"<<n<<" arrival time: ";
		cin>>arrive[i];
		cout<<"What is P"<<n<<" burst time: ";
		cin>>burst[i];
	}//end for
	
//Sort process based on arrival time//
	for(i=0;i<2;i++)
		for(j=i+1;j<3;j++){ 
			if(arrive[j]<arrive[i]){
				tempa=arrive[i];
				arrive[i]=arrive[j];
				arrive[j]=tempa;
				
				tempb=burst[i];
				burst[i]=burst[j];
				burst[j]=tempb;
				
				tempp=process[i];
				process[i]=process[j];
				process[j]=tempp;
			}//end if
		}//end for

//calculate start and finish time//
pthread_create(&tidA, NULL, start_finish, NULL);
pthread_join(tidA, NULL);
//start_finish();

//resort//
	for(i=0;i<2;i++) 
		for(j=i+1;j<3;j++){
			if(arrive[j]<=start[i] && burst[j]<burst[i]){
				tempa=arrive[i]; 
				arrive[i]=arrive[j];
				arrive[j]=tempa;
				
				tempb=burst[i];
				burst[i]=burst[j];
				burst[j]=tempb;
				
				tempp=process[i];
				process[i]=process[j];
				process[j]=tempp;
			}//end if
		}//end for
		
//calculate start and finish time//
pthread_create(&tidB, NULL, start_finish, NULL);
pthread_join(tidB, NULL);
//start_finish();

//calculate responce, waiting, turnaround times for each process//
	tw=0;
	for(i=0;i<3;i++){
		response[i]=start[i]-arrive[i];
		waiting[i]=start[i]-arrive[i];
		turnaround[i]=finish[i]-arrive[i];
		tw+=waiting[i];
	}//end for
	
//calculate average waiting time//
	average=tw/3;

//display result//
for(i=0;i<3;i++){
	cout<<"Process number("<<process[i]<<")\n"<<"Arrive at= "<<arrive[i]<<"\n"<<"Waiting Time= "<<waiting[i]<<"\n"<<"Response Time= "<<response[i]<<"\n"<<"Turnaround Time= "<<turnaround[i]<<"\n";
}//end for

	cout<<"Total waiting time="<<tw;
	cout<<"\nAverage waiting time= "<<average;
	cout<<"\n\n\t\t\t--------*******SJF ********---------\n";
	return(0);
}//end main

