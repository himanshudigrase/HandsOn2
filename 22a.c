//Name: Himanshu Shankar Digrase
//ID: MT2022155

// Question : Write a program to wait for data to be written into FIFO within 10 seconds, use `select` system call with FIFO.

#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<string.h>
#include<sys/time.h>

int main(){
    int fd,readBytes,fifoStat;
    char *fifoName = "./myfifo-22-1";
    fifoStat = mkfifo(fifoName,S_IRWXU);
    if(fifoStat == -1)perror("Error while creating FIFO");

    char data[100];
    fd_set readFDSet; //represents fd set for select function
    struct timeval timer;
    int selectStatus;

    fd = open(fifoName,O_NONBLOCK | O_RDONLY);

    if(fd == -1)perror("Error while opening FIFO file");

    FD_ZERO(&readFDSet); //initializes fdset to havezero bits i:e removes all fds from set
    FD_SET(fd,&readFDSet);//sets the bit for fd in the fdset i:e adds the fd to set

    timer.tv_sec = 10;//represents # of whole seconds of elapsed time
    timer.tv_usec = 0;//rest of elapsed time

    selectStatus = select(fd+1,&readFDSet,NULL,NULL,&timer);

    if(selectStatus == -1)perror("Error while calling select");
    else if(selectStatus){
        readBytes = read(fd,&data,100);
        printf("Data received: %s\n",data);
    }
    else printf("No data passed for 10 secs");

    close(fd);
    
}