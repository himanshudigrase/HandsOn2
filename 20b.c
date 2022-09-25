#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>

void main(){
    int fd,readBytes;
    char *fifoFile = "./myFifo-20a";
    char data[100];

    fd = open(fifoFile,O_RDONLY);

    if(fd == -1)perror("Error while opening FIFO file");
    else{
        readBytes = read(fd,data,100);

        printf("Read data bytes: %d\n",readBytes);
        printf("Data is : %s \n",data);
    }

}