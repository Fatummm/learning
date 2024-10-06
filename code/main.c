#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main() {
    srand(time(NULL));
    int n, m;
    scanf("%d %d", &n, &m);
    // указатель на указатели
    int ** my_dinamic_arr = 0;

    my_dinamic_arr = (int **) calloc(n, sizeof(int));
    printf("----------\n");
    for (int i = 0; i != n; ++i) {
        *(my_dinamic_arr + i) = (int *) calloc(m, sizeof(int));
        for (int j = 0; j != m; ++j) {
            *(*(my_dinamic_arr + i) + j) = rand() % 90 + 10;
            printf("%d ", *(*(my_dinamic_arr + i) + j));
        }
        printf("\n");
    }
    printf("----------\n");
    while (1) {
        int x, y, elem;
        scanf("%d %d", &x, &y);
        if (x == -1 && y == -1) {
            break;
        }
        scanf("%d", &elem);
        *(*(my_dinamic_arr + x) + y) = elem;
        printf("----------\n");
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                printf("%d ", *(*(my_dinamic_arr + i) + j));
            }
            printf("\n");
        }
        printf("----------\n");
    }
    // освобождение памяти из-под внутренних массивов
    for (int i = 0; i != n; ++i) {
        free(*(my_dinamic_arr + i));
    }

    // освобождение памяти из-под внешнего массива
    free(my_dinamic_arr);
}
