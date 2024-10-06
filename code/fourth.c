#include <stdio.h>
	
int main() {
    int x = 45;
    int *p = &x;
    int **pp = &p;
    printf("*p = %d\n", *p);
    printf("**pp = %d", **pp);
}