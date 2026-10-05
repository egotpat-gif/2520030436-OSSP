#include <stdio.h>
#include <string.h>

int main() {
    char input[200];
    char *token;

    printf("Enter command: ");
    fgets(input, sizeof(input), stdin);

    token = strtok(input, " \t\n");
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " \t\n");
    }
    return 0;
}
