#include <stdio.h>
#include <string.h>

#define MAX 5

int main() {
    char history[MAX][100];
    int count = 0;
    char cmd[100];

    for (int i = 0; i < MAX; i++) {
        printf("Command %d: ", i + 1);
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = '\0';
        strcpy(history[count++], cmd);
    }

    printf("\nHistory:\n");
    for (int i = 0; i < count; i++)
        printf("%d: %s\n", i + 1, history[i]);

    return 0;
}
