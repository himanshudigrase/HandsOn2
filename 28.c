//Name: Himanshu Shankar Digrase
//ID: MT2022155

//Question: Write a program to change the exiting message queue permission(use msqid ds structure)

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<unistd.h>

void main(){
    key_t key;
    int queueIdentifier;
    struct msqid_ds messageQueueInfo;
    int msgcntlStatus;

    key = ftok(".",1);

    if(key == -1)perror("Error while computing key");

    queueIdentifier  = msgget(key,IPC_CREAT | 0700);

    if(queueIdentifier == -1)perror("Error while getting message queue");

    printf("Press enter to change permission");
    getchar();

    messageQueueInfo.msg_perm.mode = 0777;

    msgcntlStatus = msgctl(queueIdentifier,IPC_SET,&messageQueueInfo);

    if(msgcntlStatus == -1)perror("Error while changing permission");

    
}