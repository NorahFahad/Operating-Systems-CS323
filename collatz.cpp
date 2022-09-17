#include <iostream>
#include <stdlib.h> //exit()
#include <unistd.h> //fork()
#include <sys/types.h> //pid_t
#include <sys/wait.h> //wait()
using namespace std; //to replace std::cout with cout && cin

int main(){

	pid_t pid;
	int status, n; //n is the entered by the user
	
		cout<<"Enter a number for the Collatz Conjecture: "; 
  		cin>>n;
  		while(n<=0){//while loop if the user entered 0 or negative number
			cout<<"ERROR!! please enter a positive number to run the Collatz Conjecture: ";
			cin>>n;
		} //end while loop 
		
	pid = fork(); //Fork the Child

	if(pid<0){ //fork error occurred
		cout<<"Fork failed\n";
		exit(-1);
	}//end if 
	
	else if(pid == 0){ //child process
		cout<<"CHILD ID: "<<getpid()<<"\n"<<endl; //print child process id
		
		// CALCULATE THE COLLATZ CONJECTURE SECTION //
		cout<<"The number is: "<<n<<endl; // print the number that user entered
		cout<<"The Collatz Conjecture is {"<<n<<",";
		while (n!=1){
			if(n%2 == 0){ //if the number is even
				n = n / 2; 
			} //end if
			else if(n%2 == 1){ //if the number is odd
				n = (3 * n) + 1;
			} //end else if
			cout<<n<<","; //print the sequnce for collatz
		}//end while loop
	cout<<"}\nCHILD PROCESS END-_-"<<endl;
	} //end else if child process

	else{ //parent process
		cout<<"PARENT ID: "<<getpid()<<endl; //print parent process id
		pid = wait(&status); //Parent waits for child to end
		cout<<"\nPARENT IS CLOSING-_-"<<endl;
		exit(0);
	}//end else
}//end main

