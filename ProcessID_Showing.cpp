#include <iostream>
#include <unistd.h>  // For getpid() and getppid()

int main() {
    // Get process ID
    pid_t pid = getpid();
    
    // Get parent process ID
    pid_t ppid = getppid();

    // Print process IDs
    std::cout << "Process ID (PID): " << pid << std::endl;
    std::cout << "Parent Process ID (PPID): " << ppid << std::endl;

    return 0;
}
