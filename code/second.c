#include <stdio.h>
	
int main() {
    int x = 11;
    int *xPtr = &x;
    printf("x = %d\n", *xPtr);
    *xPtr = 77;
    printf("x = %d", *xPtr);
}