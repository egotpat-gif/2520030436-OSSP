#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Demo signal received: %d\n", sig);
}

int main() {
    signal(SIGUSR1, handler);
    printf("OSSP Demo\n");
    printf("PID: %d\n", getpid());
    printf("Feature 1: Process execution\n");
    printf("Feature 2: Pipelines\n");
    printf("Feature 3: Signal handling\n");
    printf("Sending demonstration signal...\n");
    raise(SIGUSR1);
    printf("Final project review completed.\n");
    return 0;
}
