	#include <stdio.h>
	
	void print(int lst[]) {
	    // digits
	    printf("--DIGITS--\n");
	    for (int i = 0; i != 10; ++i) {
	        printf("%d - %d\n", i, lst[i]);
	    }
	
	    // symbols
	    printf("--ALPHABET--\n");
	    for (int i = 10; i != 36; ++i) {
	        printf("%c - %d\n", i + 97 - 10, lst[i]);
	    }
	
	    // separators
	    printf("---------\n");
	    printf("Separators - %d\n", lst[36]);
	
	    // other
	    printf("---------\n");
	    printf("Others - %d\n", lst[37]);
	    printf("---------");
	}
	
	int char_process(char c) {
	    if (c >= '0' && c <= '9') {
	        return (c - 48); // 48 = '0'
	    }
	    else if (c >= 'a' && c <= 'z') {
	        return (c - 87); // - 97('a') + 10
	    }
	    else if (c >= 'A' && c <= 'Z') {
	        return (c - 55); // - 65 + 10
	    }
	    else if (c == ' ' || c == '\n' || c == '\t') {
	        return 36;
	    }
	    else {
	        return 37;
	    }
	}
	
	int main()
	{
	    // 0-9 digits
	    // 10-35 alphabet
	    // 36 - separators
	    // 37 - other
	    int a[38];
	    for (int i = 0; i != 38; ++i) {
	        a[i] = 0;
	    }
	    char c;
	    while ((c = getchar()) != EOF) {
	        int index = char_process(c);
	        a[index]++;
	    }
	    print(a);
	}