#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return 1;
    }

    printf("Current directory: %s\n", cwd);
    printf("Type 'exit' in a shell to process an exit request.\n");
    return 0;
}
