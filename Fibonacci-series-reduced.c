#include <stdio.h>

int DAT[1000];

int fibo(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    if (DAT[n] != 0)
        return DAT[n];

    DAT[n] = fibo(n - 1) + fibo(n - 2);
    return DAT[n];
}

int main() {
    int n = 50;
    for (int i = 0; i < n; i++) {
        printf("%d ", fibo(i));
    }
    printf("\n");
    return 0;
}
