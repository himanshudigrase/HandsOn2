//Name: Himanshu Shankar Digrase
//ID: MT2022155

// Question : Write a program to receive messages from the message queue with `IPC_NOWAIT` as a flag

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<unistd.h>

int main(){
    key_t key;
    int queueIdentifier;
    int messageStatus;
     
     struct msgbuf{
        long mtype;
        int someNumber;
     }data;

    key = ftok(".",1);

    if(key == -1)perror("Key error");

    queueIdentifier = msgget(key,IPC_CREAT|0700);

    if(queueIdentifier == -1)perror("Error with queueIdentifier");

    data.mtype = 1;
    data.someNumber = 1;
    messageStatus = msgrcv(queueIdentifier,&data,sizeof(data),data.mtype,IPC_NOWAIT);

    if(messageStatus == -1)perror("Error while receiving data");

    printf("Recieved num: %d\n",data.someNumber);

    return 0;
}