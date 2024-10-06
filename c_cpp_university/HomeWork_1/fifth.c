	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	
	
	#define N 3
	#define SPACES 5
	
	int count_symb(int x) {
	    if (x == 0) return 1;
	    int count = 0;
	    if (x < 0) count++;
	    x = abs(x);
	    while (x != 0) {
	        x /= 10;
	        count++;
	    }
	    return count;
	}
	
	void print_matrix(int m[N][N]) {
	    for (int i = 0; i != N; ++i) {
	        for (int j = 0; j != N; ++j) {
	            int temp = SPACES - count_symb(m[i][j]);
	            for (int sep = 0; sep != temp; ++sep) {
	                printf(" ");
	            }
	            printf("%d", m[i][j]);
	        }
	        printf("\n");
	    }
	}
	
	int main()
	{
	    srand(time(NULL));
	    int a[N][N];
	    for (int i = 0; i != N; ++i) {
	        for (int j = 0; j != N; ++j) {
	            a[i][j] = rand() % 199 - 99;
	        }
	    }
	    printf("General matrix:\n");
	    print_matrix(a);
	    printf("\nMatrix reflected by main diagonal\n");
	
	    // main diagonal
	    for (int i = 0; i != N; ++i) {
	        for (int j = i; j != N; ++j) {
	            int temp = a[i][j];
	            a[i][j] = a[j][i];
	            a[j][i] = temp;
	        }
	    }
	
	    print_matrix(a);
	
	    for (int i = 0; i != N; ++i) {
	        for (int j = 0; j != N - i; ++j) {
	            int temp = a[i][j];
	            a[i][j] = a[N - 1 - j][N - 1 - i];
	            a[N - 1 - j][N - 1 - i] = temp;
	        }
	    }
	    printf("\nMatrix reflected by second diagonal:\n");
	    print_matrix(a);
	}