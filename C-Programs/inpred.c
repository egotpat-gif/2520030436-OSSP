#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("input.txt", O_RDONLY);
    if (fd < 0) {
        perror("input.txt");
        return 1;
    }

    dup2(fd, STDIN_FILENO);
    close(fd);

    char buffer[100];
    if (fgets(buffer, sizeof(buffer), stdin))
        printf("Read from redirected input: %s", buffer);

    return 0;
}
