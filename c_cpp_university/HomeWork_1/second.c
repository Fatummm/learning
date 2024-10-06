	#include <stdio.h>
	
	int main()
	{
	    char a[100], b[100], c;
	    int counter = 0;
	    for (; counter != 100; ++counter) {
	        c = getchar();
	        if (c == EOF) break;
	        a[counter] = c;
	        b[99 - counter] = c;
	    }
	    for (; counter != -1; --counter) {
	        putchar(b[99 - counter]);
	    }
	}