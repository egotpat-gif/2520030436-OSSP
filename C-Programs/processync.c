#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        sleep(2);
        printf("Child finished.\n");
        return 0;
    }

    printf("Parent waiting using waitpid()...\n");
    waitpid(pid, NULL, 0);
    printf("Child has terminated.\n");
    return 0;
}
