#include <stdio.h>
	
int main() {
    int arr[] = {0, 1, 2, 3, 4};
    for (int *ptr = arr ; ptr - &arr[0] != 5; ++ptr) {
        printf("%d ", *ptr);
    }
}