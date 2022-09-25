#include<sys/types.h> // for ftok and msgget
#include<sys/ipc.h> // same
#include<sys/msg.h> // for msgget
#include<stdio.h> // for perror and printf
#include<unistd.h> 

void main(){
    key_t queuekey;  //IPC msg queue key
    int queueIdentifier; // msg queue identifier

    queuekey = ftok(".",1); // pathname and proj id

    if(queuekey == -1)perror("Error while computing key");

    //get a system msg queue identifier
    queueIdentifier = msgget(queuekey,IPC_CREAT | IPC_EXCL |0700); 
    
    if(queueIdentifier == -1) perror("Error while creating msg");

    printf("Key: %d\n",queuekey);
    printf("Message Queue Identifier: %d\n",queueIdentifier);
}