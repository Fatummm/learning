#include <stdio.h>

int main()
{
    int s[100000];
    for (int i = 0; i != 100000; ++i) {
        s[i] = 0;
    }

    char input;
    int index = 0;
    while ((input = getchar()) != EOF) {
        if (index != 0 && input == ' ' && 
        (s[index - 1] == ' ' || s[index - 1] == 0)) {
            s[index] = 0;
        }
        else {
            s[index] = input;
        }
        index++;
    }
    for (int i = 0; i != 100000; ++i) {
        if (s[i] != 0) {
            putchar(s[i]);
        }
    }
    
}
