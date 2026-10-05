#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("combined.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
        return 1;

    dup2(fd, STDOUT_FILENO);
    dup2(fd, STDERR_FILENO);
    close(fd);

    printf("Standard output message.\n");
    fprintf(stderr, "Standard error message.\n");
    return 0;
}
