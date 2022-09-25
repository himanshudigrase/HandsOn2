//Name: Himanshu Shankar Digrase
//ID: MT2022155


// Question : Write a program to execute `ls -l | wc`. Use `dup`

#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

void main(){
     int a[2];// a[0] for reading a[1] for wrting

     pipe(a); // using pipe for ipc

     if(!fork()){
        close(1);
        // making stdout same as a[1]
        dup(a[1]);

        close(a[0]);// closing reading part

        execl("/usr/bin/ls","ls -l","-l",NULL);
     }
     else{

        close(0);//closing normal stdin

        //making stdin same as a[0]
        dup(a[0]);

        close(a[1]);//closing writing part

        execl("/usr/bin/wc","wc",NULL);
     }
}
