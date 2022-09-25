//Name: Himanshu Shankar Digrase
//ID: MT2022155


#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<unistd.h>


//
void main(){
    key_t queueKey;  // IPC key
    int queueIdentifier; //IPC identifier
    int messageStatus;  //status os msgsnd call

    struct msgbuf{
        long mtype;
        int someNumber;
    }data;

    queueKey = ftok(".",1);

    if(queueKey == -1)perror("Error while computing key");

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);

    if(queueIdentifier == -1)perror("Error while creating message queue");

    data.mtype = 1;
    data.someNumber = 100;

    messageStatus = msgsnd(queueIdentifier,&data,sizeof(data),0);

    if(messageStatus == -1)perror("Error while sending message via message queue");

    printf("Message sent! Use ipcs-q");

}