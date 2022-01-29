#include <stdio.h>
#include <stdlib.h>

int main(){
    int var = 9;
    int *p = malloc(sizeof(int));
    *p = 10;

    printf("Simple int value: %d\n", var);
    printf("Pointer value: %p\n", p);
}