#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h>  
#include "rot13.h"
  
int main() 
{ 
    // ftok to generate unique key 
    key_t key = ftok("shmfile",65); 
  
    // shmget returns an identifier in shmid 
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
  
    // shmat to attach to shared memory 
    char* str = (char*) shmat(shmid,(void*)0,0); 
    char* answer = encodeRot13String(str);
    printf("Data read from memory: %s\n",answer); 
      
    //detach from shared memory  
    shmdt(str); 
    
    // destroy the shared memory 
    shmctl(shmid,IPC_RMID,NULL); 
     
    return 0; 
} 