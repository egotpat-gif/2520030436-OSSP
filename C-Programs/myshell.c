#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024

int main() {
    char input[MAX_INPUT];

    while (1) {
        printf("myshell> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0)
            break;

        if (strlen(input) == 0)
            continue;

        pid_t pid = fork();

        if (pid == 0) {
            char *args[64];
            int i = 0;

            char *token = strtok(input, " ");

            while (token != NULL && i < 63) {
                args[i++] = token;
                token = strtok(NULL, " ");
            }

            args[i] = NULL;

            execvp(args[0], args);

            perror("Command failed");
            exit(1);
        }
        else if (pid > 0) {
            wait(NULL);
        }
        else {
            perror("fork failed");
        }
    }

    printf("Shell exited.\n");
    return 0;
}
