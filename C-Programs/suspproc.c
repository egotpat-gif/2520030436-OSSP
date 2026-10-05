#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("\nSIGTSTP received. Process will stop.\n");
    signal(SIGTSTP, SIG_DFL);
    raise(SIGTSTP);
}

int main() {
    signal(SIGTSTP, handler);
    printf("PID: %d\n", getpid());
    printf("Press Ctrl+Z to suspend.\n");

    while (1) {
        printf("Running...\n");
        sleep(1);
    }
    return 0;
}
