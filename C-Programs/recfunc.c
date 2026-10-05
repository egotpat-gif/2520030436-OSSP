#include <stdio.h>
#include <string.h>

#define MAX_HISTORY 5

int main() {
    char history[MAX_HISTORY][100];
    int count = 0;
    char command[100];

    printf("Enter commands (type history to display, exit to stop).\n");
    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0)
            break;

        if (strcmp(command, "history") == 0) {
            for (int i = 0; i < count; i++)
                printf("%d  %s\n", i + 1, history[i]);
            continue;
        }

        if (count < MAX_HISTORY)
            strcpy(history[count++], command);
    }
    return 0;
}
