#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("location of the program: %p\n", main);
    printf("location of the heap: %p\n", malloc(1));
    int x = 1;
    printf("location of the stack: %p\n", &x);

    return 0;
}