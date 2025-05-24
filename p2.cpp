#include <iostream>
#include <sys/wait.h> // Allow interactions with child processes
#include <unistd.h> // Portable Operationg System Interface API --> POSIX
#include <cstring> // to use all string and namespace function

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        std::cout << "Fork failed" << std::endl;
        return 1;
    }

    if (pid > 0) {
        std::cout << "PARENT started, now wating for process ID#" << pid << std::endl;
    }

    if (pid == 0) {
        std::cout << "CHILD started." << std::endl;
    }


    return 0;
}