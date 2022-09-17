#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdint>
#include "pthread.h"
using std::cout;
using std::dec; 
using std::endl; 

pthread_mutex_t Chopstick_mutex [5]= 
{PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER, 
PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER};

void *doit(void *);
int main(){
   pthread_t Lawyer[5];
   int i;
   cout<<dec; 
   
   for(i=0;i<5;i++)
      pthread_create(&Lawyer[i], NULL, doit, (void *)(intptr_t)i);
   
   for(i=0;i<5;i++)
      pthread_join(Lawyer[i], NULL);
   
   for(i=0;i<5;i++)
      pthread_mutex_destroy(&Chopstick_mutex[i]);
  
   exit(0);
}

void * doit(void *vptr){

   //Get the Left Chopstick
   pthread_mutex_lock(&Chopstick_mutex[(intptr_t)vptr]);
   pthread_mutex_lock(&Chopstick_mutex[((intptr_t) vptr+1)%5]);
   cout<<"Lawyer " << (intptr_t)vptr << " got chopstick number ";
   cout <<(intptr_t) vptr << endl;
   
  sleep(1);
  
  //Get the Right Chopstick
   //pthread_mutex_lock(&Chopstick_mutex[((intptr_t) vptr+1)%5]);
   cout<<"Lawyer " << (intptr_t)vptr << " got chopstick number ";
   cout << ((intptr_t)vptr+1)%5 << endl;
   
  //Eating
   cout<<"Lawyer " << (intptr_t) vptr << " is eating with chopsticks ";
   cout << (intptr_t) vptr << " & "<< (((intptr_t)vptr+1)%5) << endl;
   
   sleep(2);
   
   //Unlock both left and right Chopsticks
   pthread_mutex_unlock(&Chopstick_mutex[(intptr_t)vptr]);
   pthread_mutex_unlock(&Chopstick_mutex[((intptr_t)vptr+1)%5]);
   
   return(NULL);
}

