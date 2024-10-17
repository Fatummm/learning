#include <stdio.h>

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a > b) return gcd(b, a % b);
    return gcd(a, b % a); 
}

int main() {
    printf("%d", gcd(14, 35));
}