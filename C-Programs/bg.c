#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        sleep(5);
        printf("Background job completed.\n");
        return 0;
    }

    printf("Background job started. PID=%d\n", pid);
    printf("Parent returns to prompt immediately.\n");
    waitpid(pid, NULL, 0);
    return 0;
}
