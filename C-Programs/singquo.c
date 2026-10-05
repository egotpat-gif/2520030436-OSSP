#include <stdio.h>

int main() {
    char input[] = "'hello $USER world'";
    printf("Single quoted string: %s\n", input);
    printf("Content inside single quotes is treated literally.\n");
    return 0;
}
