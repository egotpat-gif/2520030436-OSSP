#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int a = 10, b = 20;
    printf("Module 1 result: %d\n", add(a, b));
    printf("End-to-end module test completed.\n");
    return 0;
}
