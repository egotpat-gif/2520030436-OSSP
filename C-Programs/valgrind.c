#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(10 * sizeof(int));
    if (ptr == NULL)
        return 1;

    for (int i = 0; i < 10; i++)
        ptr[i] = i;

    printf("Memory allocated successfully.\n");
    free(ptr);
    printf("Memory released successfully.\n");

    return 0;
}
