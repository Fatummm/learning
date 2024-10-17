#include <stdio.h>
#include <stdlib.h>

typedef char * (*operation) (char *, char *);

char * getNumber() {
    char c;
    char * bin_number = (char *) calloc(100, sizeof(char));
    int index = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') break;
        *(bin_number + index) = c;
        index++;
    }
    return bin_number;
}

int getNumberLength(char * s) {
    int index = 0;
    while (s[index] == '1' || s[index] == '0') ++index;
    return index;
}

char * computeSum(char * a, char * b) {
    int ln_a = getNumberLength(a);
    int ln_b = getNumberLength(b);
    char * res = (char *) calloc(ln_a + 1, sizeof(char));
    int next = 0;
    for (int i = 1; i != ln_a + 1; ++i) {
        res[i] = a[i - 1];
    }
    res[0] = '0';
    int r = ln_a - ln_b;
    for (int j = ln_b - 1; j != -1; --j) {
        int ans = res[j + r + 1]  - '0' + b[j] - '0' + next;
        //printf("%d - ", j);
        //printf("%c", res[j + r + 1]);
        switch (ans) {
            case 0: {
                res[j + r + 1] = '0';
                next = 0;
                break;
            }
            case 1: {
                res[j + r + 1] = '1';
                next = 0;
                break;
            }
            case 2: {
                res[j + r + 1] = '0';
                next = 1;
                break;
            }
            case 3: {
                res[j + r + 1] = '1';
                next = 1;
                break;
            }
        }
    }
    if (next) {
        for (int i = ln_a - ln_b; i != -1; --i) {
            if (res[i] == '1') {
                res[i] = '0';
            }
            else {
                res[i] = '1';
                break;
            }
        }
    }
    return res;
}

char * computeDifference(char * a, char * b) {
    int ln_a = getNumberLength(a);
    int ln_b = getNumberLength(b);
    int r = ln_a - ln_b, next = 0;
    char * res = (char *) calloc(ln_a, sizeof(char));
    for (int i = 0; i != ln_a; ++i) {
        res[i] = a[i];
    }
    for (int j = ln_b - 1; j !=-1; --j) {
        int ans = res[j + r] - b[j];
        switch (ans) {
            case -1: {
                for (int x = j + r - 1; x != -1; --x) {
                    if (res[x] == '0') res[x] = '1';
                    else {
                        res[x] = '0';
                        break;
                    }
                }
                res[j + r] = '1';
                break;
            }
            case 0: {
                res[j + r] = '0';
                break;
            }
            case 1: {
                res[j + r] = '1';
                break;
            }

        }
    }
    return res;
}

char * moveToLeft(char * s, char * b) {
    int ln = getNumberLength(s);
    char * res = (char *) calloc (ln + *b, sizeof(char));
    for (int i = 0; i != ln + *b; ++i) {
        if (i >= ln) res[i] = '0';
        else res[i] = s[i];
        
    }
    return res;
}

char * moveToRight(char * s, char * b) {
    int ln = getNumberLength(s);
    char * res = (char *) calloc(ln - *b, sizeof(char));
    for (int i = 0; i != ln - *b; ++i) {
        res[i] = s[i];
    }
    return res;
}

void print(char * s) {
    int ln = getNumberLength(s);
    int flag = 1;
    for (int i = 0; i != ln; ++i){
        if (s[i] == '0' && flag) continue;
        if (flag && s[i] == '1') flag = 0;
        if (s[i] == '0' || s[i] == '1') printf("%c", s[i]);
    }
    if (flag) printf("0");
    printf("\n");
}

void checkForExit(int * flag) {
    printf("Do you want to continue? [Y/n] ");
    char c = getchar(); if (c == '\n') c = getchar();
    if (c == 'n' || c == 'N') {
        *flag = 0;
    }
    else if (c == 'y' || c == 'Y') {
        *flag = 1;
    }
    else {
        printf("Error!!\n");
        *flag = 0;
    }
    getchar();
}

operation getOperation() {
    char op[2] = {'0', '0'};
    int index = 0;
    char c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') break;
        if (index == 2) break;
        op[index] = c;
        index++;
    }
    if (op[0] == '+' && op[1] == '0') {
        return &computeSum;
    }
    if (op[0] == '-' && op[1] == '0') {
        return &computeDifference;
    }
    if (op[0] == '<' && op[1] == '<') {
        return &moveToLeft;
    }
    if (op[0] == '>' && op[1] == '>') {
        return &moveToRight;
    }
    //printf("%c, %c", op[0], op[1]);
    return NULL;
}

void Calculator() {
    char * a = 0;
    char * b = 0;
    char * res = 0;
    operation op = 0;
    printf("Hello!!! It's binary calculator\n");
    int flag = 1;
    while (flag) {
        printf("Enter an operation(+, -, >>, <<):\n");
        op = getOperation(); //op = &moveToLeft;
        if (op == NULL) break;
        if (op == &moveToLeft || op == &moveToRight) {
            printf("Enter a number:\n");
            a = getNumber();
            int n;
            printf("Enter a number of digits to move:\n");
            scanf("%d", &n);
            char ch = n;
            char * x = &ch;
            res = op(a, x);
        }
        else {
            printf("Enter two numbers:\n");
            a = getNumber();
            b = getNumber();
            res = op(a, b);
        }
        
        printf("The result is: ");
        print(res);

        free(a); free(b); free(res);
        checkForExit(&flag);
    }
}

int main() {
    Calculator();
}