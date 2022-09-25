#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<unistd.h>

void main(){
    key_t queueKey;
    int queueIdentifier;
    struct msqid_ds messageQueueInfo;
    int msgctlStatus;

    queueKey = ftok(".",1);

    if(queueKey == -1)perror("Error while computing key");

    queueIdentifier = msgget(queueKey,IPC_CREAT | 0700);

    if(queueIdentifier == -1)perror("Error while creating msg queue");

    printf("Key: %d\n",queueKey);
    printf("Message Queue Identifier: %d\n",queueIdentifier);

    msgctlStatus = msgctl(queueIdentifier,IPC_STAT,&messageQueueInfo);

    if(msgctlStatus == -1)perror("Error while getting Message queue info");

    printf("Access Permission : %od \n",messageQueueInfo.msg_perm.mode);
    printf("UID: %d\n",messageQueueInfo.msg_perm.uid);
    printf("GID: %d\n",messageQueueInfo.msg_perm.gid);
    printf("Time of last message sent: %ld\n",messageQueueInfo.msg_stime);
    printf("Time of last message received: %ld\n",messageQueueInfo.msg_rtime);
    printf("Size of Queue: %ld\n",messageQueueInfo.__msg_cbytes);
    printf("Number of messgaes in queue: %ld\n",messageQueueInfo.msg_qnum);
    printf("Maximum number of Bytes allowed in queue: %ld\n",messageQueueInfo.msg_qbytes);
    printf("PID of last msg sent: %d\n",messageQueueInfo.msg_lspid);
    printf("PID of last received msg: %d\n",messageQueueInfo.msg_lrpid);

}