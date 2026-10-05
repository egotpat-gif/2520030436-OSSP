#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("output (2).txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("output (2).txt");
        return 1;
    }

    dup2(fd, STDOUT_FILENO);
    close(fd);

    printf("This line is appended.\n");
    return 0;
}
