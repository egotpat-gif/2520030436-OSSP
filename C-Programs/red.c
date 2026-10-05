#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child Process: Redirect standard output to write end of pipe
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);

        printf("Hello from child process via pipe!\n");
        return 0;
    } else {
        // Parent Process: Redirect standard input to read end of pipe
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);

        wait(NULL); // Synchronize process execution

        char buffer[100];
        if (fgets(buffer, sizeof(buffer), stdin)) {
            printf("Parent received: %s", buffer);
        }
    }

    return 0;
}
