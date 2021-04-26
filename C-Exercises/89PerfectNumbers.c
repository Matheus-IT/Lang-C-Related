#include <stdio.h>

int isPerfect(int n) {
    int count = 0;

    for (int i = 1; i <= n/2; i++) {
       if (n % i == 0)
          count += i;
    }

    return count == n;
}

int main() {
    int numOfCases;
    scanf("%d", &numOfCases);
    
    for (int i = 0; i < numOfCases; i++) {
        int n;
        scanf("%d", &n);
        
        if (isPerfect(n))
            printf("%d eh perfeito\n", n);
        else
            printf("%d nao eh perfeito\n", n);
    }
    return 0;
}