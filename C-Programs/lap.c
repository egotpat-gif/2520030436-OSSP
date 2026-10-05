#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    clock_t start = clock();

    for (int i = 0; i < 3; i++) {
        if (fork() == 0) {
            printf("Pipeline job %d, PID=%d\n", i + 1, getpid());
            sleep(1);
            return 0;
        }
    }

    for (int i = 0; i < 3; i++)
        wait(NULL);

    clock_t end = clock();
    printf("All jobs completed.\n");
    printf("CPU time: %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
