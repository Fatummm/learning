	#include <stdio.h>
	
	
	int main()
	{
	    char a[100], c;
	    int counter = 0;
	    while ((c = getchar()) != EOF) {
	        a[counter] = c;
	        counter++;
	    }
	    for (int i = 0; i != counter; ++i) {
	        for (int j = counter - 1; j != -1; --j) {
	            if (a[i] > a[j]) {
	                char tmp = a[i];
	                a[i] = a[j];
	                a[j] = tmp;
	            }
	        }
	    }
	    for (int i = 0; i != counter; ++i) {
	        printf("%c", a[i]);
	    }
	}