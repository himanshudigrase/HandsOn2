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
    int fd1;
    char *myfifo = "./myfifo-21";
    int fifoStat;
    
    fifoStat = mkfifo(myfifo,S_IRWXU);
    
    if(fifoStat == -1)perror("Error while creating FIFO");

    char str1[20],str2[20];

    while(1){
        fd1 = open(myfifo,O_RDONLY);

        read(fd1,str1,20);
        printf("User1: %s\n",str1);
        close(fd1);


        fd1 = open(myfifo,O_WRONLY);
        fgets(str2,20,stdin);
        write(fd1,str2,sizeof(str2));

        
        close(fd1);
    }
 return 0;
}