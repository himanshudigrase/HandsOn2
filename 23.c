//Name: Himanshu Shankar Digrase
//ID: MT2022155

// Question : Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<errno.h>

void main(){

	int fifoStatus;
	long maxFiles;  //max no of files which can be opened thru sysconf system call
	long sizeOfPipe;
	
	char *fifoName = "23-fifo";
	fifoStatus = mkfifo(fifoName,S_IRWXU);
	
	if(fifoStatus==-1) perror("Error while creating FIFO");
	else{
		maxFiles = sysconf(_SC_OPEN_MAX);
		
		if(maxFiles == -1)perror("Error in sysconf");
		else printf("Max files that can be opened : %ld\n",maxFiles);
	
		sizeOfPipe = pathconf(fifoName,_PC_PIPE_BUF);
		
		if(sizeOfPipe == -1)perror("Error in pathconf");
		else printf("Max size of Pipe: %ld\n",sizeOfPipe);
	}
}