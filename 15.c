//Name: Himanshu Shankar Digrase
//ID: MT2022155
// Question : Write a simple program to send some data from parent to the child process.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
    int fd[2];

    char str[100];
    pid_t p;

    if(pipe(fd) == -1) {
        printf("Error while pipe");
        return 1;
    }

    scanf("%s",str);

    p = fork();

    if(p<0){
        printf("Fork failed");
        return 1;
    }

    // parent process
    else if(p>0){
        write(fd[1],str,strlen(str)+1);
        close(fd[1]);
    }

    else{
        char str2[100];
        read(fd[0],str2,100);
        printf("String from parent is: %s",str);
        close(fd[0]);
        exit(0);
    }
}