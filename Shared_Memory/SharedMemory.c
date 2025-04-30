#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include<sys/wait.h>
int global_var=10;

int main(){
    int local_var;
    int *local_addr,*global_addr;
    pid_t pid;
    int status;

    local_var=20;
    local_addr=&local_var;
    global_addr=&global_var;
    

    //Create a child
    pid=fork();
    if(pid==-1){
        perror("fork: ");
        exit(EXIT_FAILURE);
    }
    else if(pid==0){
        //Child Process
        printf("Child -> Local Veriable: %d , Global variable: %d\n", local_var,global_var);
        printf("Child -> Local Veriable Address: %p , Global variable Addrsss: %p\n", local_addr,global_addr);
        local_var=100;
        global_var=200;
        printf("Child -> Local Veriable: %d , Global variable: %d\n", local_var,global_var);
        printf("Child -> Local Veriable Address: %p , Global variable Addrsss: %p\n", local_addr,global_addr);
    }
    else{
        //parent process
        printf("Parent -> Local Veriable: %d , Global variable: %d\n", local_var,global_var);
        printf("Parent -> Local Veriable Address: %p , Global variable Addrsss: %p\n", local_addr,global_addr);
        wait(&status);
        //Parent's task after child terminatiion
        for(int i=0 ; i<10 ; i++){
            printf("Parent -> Local Veriable: %d , Global variable: %d\n", local_var,global_var);
            printf("Parent -> Local Veriable Address: %p , Global variable Addrsss: %p\n", local_addr,global_addr);
        }
    }

    printf("Successfully terminating.. \n");


    exit(EXIT_SUCCESS);
}