#include <stdio.h>
// symbols counting

int scoreOfString(char* s) {
    int sm = 0;
    
    while (*(s + 1)) {
        if (*(s + 1) - *s >= 0) {
            sm += (*(s + 1) - *s);
        }
        else {
            sm += (*s - *(s + 1));
        }
        s++;
    }
    return sm;
}

int main()
{
    char s[] = "hello";
    int sm = scoreOfString(s);
    
}
