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


    return 0;
}