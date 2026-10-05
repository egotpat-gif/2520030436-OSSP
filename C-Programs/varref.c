#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[50];
    char *value;

    printf("Enter variable name: ");
    scanf("%49s", name);

    value = getenv(name);
    if (value != NULL)
        printf("%s=%s\n", name, value);
    else
        printf("Variable is undefined.\n");

    return 0;
}
