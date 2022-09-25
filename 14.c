#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
    // we are using two pipes
    // first to send input string from parent
    // second to send concatenated string from child

    int fd1[2];
    int fd2[2];

    char fixed_str[] = "fixed string";
    char input_str[100];
    pid_t p;

    if(pipe(fd1) == -1){
        printf("Pipe failed 1");
        return 1;
    }
    if(pipe(fd2) == -1){
        printf("Pipe failed 2");
        return 1;
    }

    scanf("%s",input_str);

    p = fork();

    if(p<0){
        printf("Fork failed");
        return 1;
    }
    // parent process
    else if(p>0){
        char concat_str[100];

        close(fd1[0]); //Closing reading end of first pipe
        // write ip string and closing writing end of first pipe
        write(fd1[1],input_str,strlen(input_str)+1);
        close(fd1[1]);

        //waiting for child to send a string
        wait(NULL);

        close(fd2[1]);//closind wrting end of 2nd pipe

        read(fd2[0],concat_str,100);
        printf("COncatenated string %s\n",concat_str);
        close(fd2[0]);
    }

    else{
        close(fd1[1]);


        char concat_str[100];
        read(fd1[0],concat_str,100);

        int k = strlen(concat_str);
        int i;

        for(i = 0;i<strlen(fixed_str);i++)
            concat_str[k++] = fixed_str[i];

        concat_str[k] = '\0';

        close(fd1[0]);
        close(fd2[0]);

        //write concatenated string and close writing end
        write(fd2[1], concat_str, strlen(concat_str)+1);
        close(fd2[1]);  

        exit(0);  
    }
}