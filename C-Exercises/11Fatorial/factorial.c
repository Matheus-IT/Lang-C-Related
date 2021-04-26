#include <stdio.h>

int calcFact(int val) {
    int fat = 1;
    for (; val > 0; val--) {   
        fat *= val;
    }
    return fat;
}

int findClosestFactorialNum(int n) {
	int i = n+1, fact = 0;
	do {
		i--;
		fact = calcFact(i);
	} while (fact > n);
	return i;
}

int main() {
	int n;
	scanf("%d", &n);

	int count = 0;
	int temp = n;
	do {
	int closest = findClosestFactorialNum(temp);
	temp -= calcFact(closest);
	count++;
	} while(temp > 0);

	printf("%d", count);
	return 0;
}
