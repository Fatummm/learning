#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    int n;
    puts("Enter a number: ");
    scanf("%d", &n);
    int *arr = (int *) calloc(n, sizeof(int));
    for (int i = 0; i != n; ++i) {
        *(arr + i) = rand() % 101;
    }
    for (int i = 0; i != n; ++i) {
        printf("%d ", *(arr+i));
    }
    free(arr);
}