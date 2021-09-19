#include <stdio.h>

long fibo();

void main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    long result = fibo(n);
    printf("Fibonacci %d: %ld\n", n, result);

}
long fibo(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n > 2) return fibo(n-1) + fibo(n-2);
}

