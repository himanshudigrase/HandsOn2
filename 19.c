//Name: Himanshu Shankar Digrase
//ID: MT2022155

// Question: Create a FIFO file by `mkfifo` library function and `mknod` system call

#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>

int main(){
    char *mkfifoN = "./myfifo";
    char *mknodN = "./mymknod";
    int mkfifo_status,mknod_status;


    mkfifo_status = mkfifo(mkfifoN,S_IRWXU);
    if(mkfifo_status == -1)perror("Error while creating FIFO file");
    else printf("Successfull created FIFO by mknod");


    mknod_status = mknod(mknodN,__S_IFIFO |S_IRWXU,0);

    if(mknod_status == -1)perror("Error while creating mknod");
    else printf("Successfully created FIFO by mknod");

}