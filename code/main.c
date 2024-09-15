#include <stdio.h>
#include <stdlib.h>

void Process(int* n) {
    if (*n % 2 == 0) {
        *n /= 2;
    }
    else {
        *n = (*n - 1);
    }
}

int numberOfSteps(int num) {
    int steps = 0;
    while (num) {
        Process(&num);
        steps++;
    }
    return steps;
}

int main()
{
    int n = 8;
    printf("%d", numberOfSteps(n));
    
}
