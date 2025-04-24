//Inter Process Communication
//#include<bits/stdc++.h>
#include<unistd.h>
#include<stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sched.h>
int main(){
    pid_t pid;
    int processor_no;


    //create child
    pid=fork();
    if(pid<0){
        perror("Fork");
        exit(EXIT_FAILURE);
        
    }
    else if(pid == 0) {
        //child process
        pid=getpid();
        processor_no=sched_getcpu();
        printf("Child PID: %d, Processor No: %d \n",pid,processor_no);
    }

    else{
        //Parent Process
        //wait for the terminitation of Child Process in order to avoid making them orphan process
        pid=getpid();
        processor_no=sched_getcpu();
        printf("Parent PID: %d, Processor No: %d \n",pid,processor_no);
        int status;
        wait(&status);
    }


    exit(EXIT_SUCCESS);
}