//Name: Himanshu Shankar Digrase
//ID: MT2022155

// Question : Write a program to execute `ls -l | wc`. Use `dup2`


#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

void main(){
     int a[2];// a[0] for reading a[1] for wrting
     int b[2];
     pipe(a); // using pipe for ipc
     pipe(b);
     if(!fork()){
        close(1);
        // making stdout same as a[1]
        dup2(a[1],b[1]);

        close(a[0]);// closing reading part
        close(b[0]);
        execl("/usr/bin/ls","ls -l","-l",NULL);
     }
     else{

        close(0);//closing normal stdin

        //making stdin same as a[0]
        dup2(a[0],b[0]);

        close(a[1]);//closing writing part
        close(b[1]);
        execl("/usr/bin/wc","wc",NULL);
     }
}
