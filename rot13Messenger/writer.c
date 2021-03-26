#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h>  
#include "rot13.h"
#include <string.h>

#define MAXMEM 1024

int main() 
{ 
    // ftok to generate unique key 
    key_t key = ftok("shmfile",65); 

    // shmget returns an identifier in shmid 
    int shmid = shmget(key,MAXMEM,0666|IPC_CREAT); 
    

  
    // shmat to attach to shared memory 
    char* str = (char*) shmat(shmid,(void*)0,0); 
    char* input = (char*)malloc(MAXMEM * sizeof(char));

    printf("Enter the word you wish to ROT13 encode: \n"); 
    scanf("%s", input);
    char* output = encodeRot13String(input);
    //stpcpy(str, output);
    sprintf(str, "%s", output);
    printf("Data written in memory: %s\n",str); 
      
    //detach from shared memory  
    shmdt(str); 
    return 0; 
} 