#include <iostream>
using namespace std; 
int main(){ 
float n,tempb,tempa,tempp,tw,average,gap,arrive[3],burst[3],process[3],start[3],finish[3],waiting[3],response[3], turnaround[3];
int i,j; 

////////////// Get values from User///////////
for(i=0;i<3;i++){
	n=i+1;
	process[i]=n;
	cout<<"What is p"<<n<<" arrival time? "; 
	cin>>arrive[i]; 
	cout<<"What is p"<<n<<" burst time? "; 
	cin>>burst[i];
}//end for

//////////Sort process based on arrival time//////////////
for(i=0;i<2;i++)
	for( j=i+1;j<3;j++){
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

///////////////calculate start and finish time ////////////////
start[0]=arrive[0];
finish[0]=arrive[0]+burst[0];
for(i=1;i<3;i++){ 
	gap=0; 
	if(arrive[i]>finish[i-1]){
		gap=arrive[i]-finish[i-1]; 
		start[i]=finish[i-1]+gap; 
	}//end if
	else
	start[i]=finish[i-1]; 
	finish[i]=start[i]+burst[i]; 
}//end for

///calculate response, waiting, turnaround times for each process///
tw=0; 
for(i=0;i<3;i++){ 
	response[i]=start[i]-arrive[i];
	waiting[i]=start[i]-arrive[i];
	turnaround[i]=finish[i]-arrive[i];
	tw+=waiting[i];
}//end for

average=tw/3;

/////////////////Display results////////////////////
for(i=0;i<3;i++){
	cout<<"Process number("<<process[i]<<")\n"<<"Arrive at= "<<arrive[i]<<"\n"<<"Waiting Time= "<<waiting[i]<<"\n"<<"Response Time= "<<response[i]<<"\n"<<"Turnaround Time= "<<turnaround[i]<<"\n";
}//end for

cout<<"Total waiting time= "<<tw;
cout<<"\n Average waiting time= "<<average; 
cout<<"\n\n\t\t\t--------*******FCFS ********---------\n"; 
return(0);
}//end main 
