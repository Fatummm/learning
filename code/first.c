#include <stdio.h>
	
int main() {
    int x = 5;
    double y = 1.618f;
    int *xPtr = &x;
    double *yPtr = &y;
    printf("xPtr = %x || x = %d\n", xPtr, *xPtr);
    printf("yPtr = %x || x = %f", yPtr, *yPtr);
}