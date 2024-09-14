#include <stdio.h>
// symbols counting

int *func(int lst[], int size) {
    for (int i = 0; i != size; i++) {
        lst[i] = lst[i] * lst[i];
    }
    return lst;
}

int func1(int lst[], int size) {
    for (int i = 0; i != size; i++) {
        lst[i] = lst[i] * lst[i];
    }
    return 0;
}

void print_array(int lst[], int size) {
    int arr[] = lst;
    for (int i = 0; i != size; ++i) {
        printf("%d\t", lst[i]);
    }
}

int main()
{
    int ar[5] = {1, 2, 3, 4, 5};
    int *r = func(ar, 5);
    print_array(ar, 5);
    printf("\n");
    r++;
    printf("%d", *r);
}
