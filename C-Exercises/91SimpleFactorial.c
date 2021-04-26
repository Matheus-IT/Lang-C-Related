#include <stdio.h>

int calcFactorial(int n) {
    if (n == 1)
        return 1;
    return n * calcFactorial(n - 1);
}
 
int main() {
    int n;
    scanf("%d", &n);

    int result = calcFactorial(n);

    printf("%d\n", result);
    return 0;
}