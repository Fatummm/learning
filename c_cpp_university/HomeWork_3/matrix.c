#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ** createMatrix(int n, int m) {
	srand(time(NULL));
	int ** matrix = (int **) malloc(n * sizeof(int*));
	for (int i = 0; i != n; ++i) {
		*(matrix + i) = (int *) malloc(m * sizeof(int));
		for (int j = 0; j != m; ++j) {
			*(*(matrix + i) + j) = rand() % 101;
		}
	}
	return matrix;
}

void printMatrix(int ** m, int a, int b) {
	for (int i = 0; i != a; ++i) {
		for (int j = 0; j != b; ++j) {
			printf("%5d", *(*(m + i) + j));
		}
		printf("\n");
	}
}

void freeMatrix(int *** m, int ln) {
	for (int i = 0; i != ln; ++i){
		free(*(*m + i));
	}
	free(*m);
	printf("Succeeded!\n");
}

void swapRows(int ** a, int ** b) {
	int * temp = *a;
	*a = *b;
	*b = temp;
}

void swapColumns(int *** matrix, int first, int second, int rows) {
	for (int i = 0; i != rows; ++i) {
		int temp = *(*(*matrix + i) + first);
		*(*(*matrix + i) + first) = *(*(*matrix + i) + second);
		*(*(*matrix + i) + second) = temp;
	}
}

int getNumberFromString(char * ptr) {
	int a = *(ptr) - '0';
	while (*(ptr + 1)) {
		a *= 10;
		a += (*(ptr + 1) - '0');
		ptr++;
	}
	return a;
}

int greater(int a, int b) {
	return a < b;
}

int smaller(int a, int b) {
	return b < a;
}

void sortRows(int *** matrix, int column, int rows, int columns, int (*operation)(int, int)) {
	for (int i = 0; i != rows - 1; ++i) {
		for (int j = i + 1; j != rows; ++j) {
			int a = *(*(*matrix + i) + column);
			int b = *(*(*matrix + j) + column);
			if (operation(a, b)) {
				int * ptr1 = *(*matrix + i);
				swapRows(&*(*matrix + i), &*(*matrix + j));
			}
		}
	}
}

void sortColumns(int *** matrix, int row, int rows, int columns, int (*operation)(int, int)) {
	for (int i = 0; i != columns - 1; ++i) {
		for (int j = i + 1; j != columns; ++j) {
			int a = *(*(*matrix + row) + i);
			int b = *(*(*matrix + row) + j);
			if (operation(a, b)) {
				swapColumns(matrix, i, j, rows);
			}
		}
	}

}

typedef void (*sorting)(int ***, int, int, int, int (*)(int, int));
typedef int (*p_to_p)(int, int);

sorting getSorting() {
	printf("Sorting by the row or by the column? ('0' for rows, '1' for columns)\n");
	char c = getchar(); if (c == '\n') c = getchar();
	sorting ans = NULL;
	if (c == '0') ans = &sortColumns;
	else if (c == '1') ans =  &sortRows;
	else printf("Error getSorting...");
	return ans;
}

int checkForChange() {
	printf("Do you want to change the matrix? [Y/n] ");
	char c;
	c = getchar(); if (c == '\n') c = getchar();
	if (c == 'Y' || c == 'y') return 1;
	else if (c == 'N' || c == 'n') return 0;
	else {
		printf("Error checkForChange");
		return 0;
	}
}

int getIndex(sorting kind, int a, int b) {
	int ans = -1;
	if (kind == sortRows) {
		printf("Enter a position of the column: \n");
		scanf("%d", &ans);
		if (ans >= b) {
			printf("Error getIndex...");
			ans = -1;
		}
	}
	else if (kind == sortColumns) {
		printf("Enter a position of the row: \n");
		scanf("%d", &ans);
		if (ans >= a) {
			printf("Error getIndex...");
			ans = -1;
		}
	}
	return ans;
}

p_to_p getKindOfSorting() {
	printf("What kind of sorting? ('0' for descending order, '1' for ascending order)):\n");
	p_to_p ans = NULL;
	char c = getchar(); if (c == '\n') c = getchar();
	if (c == '0') ans = greater;
	else if (c == '1') ans = smaller;
	else printf("Error getKindOfSorting...");
	return ans;
}

void working(char * first, char * second) {
	
	int a = getNumberFromString(first);
	int b = getNumberFromString(second);
	int ** m = 0;
	m = createMatrix(a, b);
	while (1) {
		printf("The current matrix is:\n");
		printMatrix(m, a, b);
		if (!checkForChange()) break;
		sorting choice = getSorting();
		if (choice == NULL) break;
		p_to_p parameter = getKindOfSorting();
		if (parameter == NULL) break;
		int index = getIndex(choice, a, b);
		if (index == -1) break;
		choice(&m, index, a, b, parameter);
	}
	freeMatrix(&m, a);
	
}

int main(int argc, char* argv[])
{
	working(argv[1], argv[2]);
}
