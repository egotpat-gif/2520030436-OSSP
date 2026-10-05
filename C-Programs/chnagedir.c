#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
    char path[PATH_MAX];

    printf("Enter directory: ");
    scanf("%s", path);

    if (chdir(path) == -1) {
        perror("chdir");
        return 1;
    }

    if (getcwd(path, sizeof(path)) != NULL)
        printf("Current directory: %s\n", path);

    return 0;
}
