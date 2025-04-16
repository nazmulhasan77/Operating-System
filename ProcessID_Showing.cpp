#include <iostream>
#include <unistd.h>  // For getpid() and getppid()
using namespace std;
int main() {
    // Get process ID
    int child_status;
    int child_pid;
    int parentPID;
    
    parentPID = getpid();

    child_status = fork();
    if (child_status==0){
        child_pid=getpid();

        cout << "Parent PID: " << parentPID << ", Child PID: " << child_pid << endl;

    }
    else{
        cout << "Parent PID : " << parentPID << endl; // first print this because child not created at first 

    }
    

    return 0;
}
