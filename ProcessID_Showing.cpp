#define GNU _GNU_SOURCE
#include <iostream>
#include <unistd.h>  // For getpid() and getppid()
using namespace std;
int main() {
    
    int child_status;
    int child_pid;
    int parentPID;
    int process_no;

    // Get process ID
    parentPID = getpid();

    child_status = fork();
    if (child_status==0){
        child_pid=getpid();
        process_no=sched_getcpu(); // get processor no
        cout << "Parent PID: " << parentPID << ", Child PID: " << child_pid << ", Processor: " << process_no << endl;

    }
    else{
        cout << "Parent PID : " << parentPID << endl; // first print this because child not created at first 

    }
    

    return 0;
}
