#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>

void main(){
    int fifoStat;
    char data[] = "Data to be sent";
    int fd,writeBytes;
    char *fifoFile = "./myFifo-20a";

    fifoStat = mkfifo(fifoFile,S_IRWXU);

    if(fifoStat == -1)perror("Error while creating fifo using mkfifo");
    fd = open(fifoFile,O_WRONLY);

    writeBytes = write(fd,&data,sizeof(data));

    close(fd);
}