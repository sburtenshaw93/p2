#include <iostream>
#include <sys/wait.h> // Allow interactions with child processes
#include <unistd.h> // Portable Operationg System Interface API --> POSIX
#include <cstring> // to use all string and namespace function

int main(int argc, char* argv[]) {
    pid_t pid = fork();

    if (pid < 0) {
        std::cout << "Fork failed" << std::endl;
        return 1;
    }

    if (pid > 0) {
        std::cout << "PARENT started, now wating for process ID#" << pid << std::endl;

        // Waiting for child to finish running
        int status;
        waitpid(pid, &status, 0);

        std::cout << "PARENT resumed. CHILD exit code of " << WEXITSTATUS(status) << ". Now terminating parent" << std::endl;
    } else {
        // Child is processing here
        std::cout << "CHILD started." << std::endl;

        // The child didn't get into the chopper with the terminator 2 and died ❌
        if (argc == 1){
            std::cout << "No arguments was provided. Terminating child." << std::endl;
            return 0;

        // Taking in arguments and not finding the fart the child left behind to (sniff)    
        } else if (argc == 2) {
            std::cout << "One argument provided. Calling execlp(), never returned (sniff)" << std::endl;
            execlp(argv[1], argv[1], (char*)NULL);
            std::cerr << "execlp failed!" << std::endl;
            return 1;
        } else {
            std::cout << "More than argument was provided. Calling execvp(), never to return (sniff)" << std::endl;
            execvp(argv[1], &argv[1]);
            std::cerr << "execvp failed!" << std::endl;
            return 1;
        }
    }    

    return 0;
}