#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<string.h>
#include<sys/time.h>

int main(){
    int fd,writeBytes,fifoStat;
    char *fifoName = "./myfifo-22-1";
    fifoStat = mkfifo(fifoName,S_IRWXU);
    if(fifoStat == -1)perror("Error while creating FIFO");

    fd = open(fifoName,O_NONBLOCK|O_WRONLY);;

    if(fd == -1)perror("Error while opening FIFO file");

    writeBytes = write(fd,"Hello",5);

    if(writeBytes == -1)perror("Error while writing");

    close(fd);
}