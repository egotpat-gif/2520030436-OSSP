#include <stdio.h>
#include <string.h>

int main() {
    char input[] = "hello\\ world";
    char output[100];
    int j = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\\' && input[i + 1] != '\0')
            i++;
        output[j++] = input[i];
    }
    output[j] = '\0';

    printf("Parsed: %s\n", output);
    return 0;
}
