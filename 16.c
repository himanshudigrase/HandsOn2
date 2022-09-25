//Name: Himanshu Shankar Digrase
//ID: MT2022155

// Question : Write a program to send and receive data from parent to child vice versa. Use two way communication.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
    int fd1[2];
    int fd2[2];
    char fixed_str[] = "Fixed one from parent";
    char fixed_str2[] = "Fixed from child";
    char input_str[100];

    pid_t p;
    if(pipe(fd1) == -1){
        printf("Error in pipe1");
        return 1;
    }
    if(pipe(fd2) == -1){
        printf("Error in pipe2");
        return 1;
    }
     p = fork();

     if(p<0){
        printf("Error in fork");
        return 1;
     }

     // parent
     else if(p>0){
        char concat_str[100];

        write(fd1[1],fixed_str,strlen(fixed_str)+1);
        //close(fd1[1]);

        wait(NULL);

        read(fd2[0],concat_str,100);
        printf("From child :%s \n",concat_str);

        //close(fd2[0]);
     }
     else{
        char concat_str[100];
        read(fd1[0],concat_str,100);
        printf("From parent: %s \n",concat_str);
        //close(fd1[0]);

        write(fd2[1],fixed_str2,strlen(fixed_str2)+1);
        //close(fd2[1]);

        exit(0);

     }
}