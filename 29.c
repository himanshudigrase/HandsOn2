//Name: Himanshu Shankar Digrase
//ID: MT2022155

//Question: Write a program to remove message queue

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<unistd.h>

int main(){
    key_t key;
    int queueIdentifier;
    int messageStatus;

    key = ftok(".",1);

    if(key == -1)perror("Key error");

    queueIdentifier = msgget(key,IPC_CREAT|0700);

    if(queueIdentifier == -1)perror("Error with queueIdentifier");

    printf("Key: %d\n",key);
    printf("Message queue Identifier: %d\n\n",queueIdentifier);
    messageStatus = msgctl(queueIdentifier,IPC_RMID,NULL);

    if(messageStatus == -1)perror("Error while removing queue");

    return 0;
}