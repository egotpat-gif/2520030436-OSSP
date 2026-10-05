#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        sleep(3);
        return 0;
    }

    printf("[1] PID=%d Status=Running\n", pid);
    waitpid(pid, NULL, 0);
    printf("[1] PID=%d Status=Completed\n", pid);
    return 0;
}
