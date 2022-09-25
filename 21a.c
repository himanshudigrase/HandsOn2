//Name: Himanshu Shankar Digrase
//ID: MT2022155


// Question : Write two programs so that both can communicate by FIFO - Use two way communications.

#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<string.h>

int main(){
    int fd;
    char *myfifo = "./myfifo-21";
    int fifoStat;
    fifoStat = mkfifo(myfifo,S_IRWXU);
    if(fifoStat == -1)perror("Error while creating FIFO");

    char arr1[20],arr2[20];

    while(1){
        fd = open(myfifo,O_WRONLY);

        fgets(arr2,20,stdin);

        write(fd,arr2,strlen(arr2)+1);
        close(fd);


        fd = open(myfifo,O_RDONLY);

        read(fd,arr1,sizeof(arr1));

        printf("User2: %s\n",arr1);
        close(fd);
    }
 return 0;
}