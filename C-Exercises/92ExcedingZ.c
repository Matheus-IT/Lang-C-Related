#include <stdio.h>

int minimumExceedsZ(int n1, int n2) {
	int sum = 0, numOfTimes = 0;

	for (int i = n1; i < n2; i++) {
		numOfTimes++;
		sum += i;
		if (sum > n2)
			return numOfTimes;
	}
}

int main() {
	int x, z;

	scanf("%d", &x);

	do {
		scanf("%d", &z);
	} while(z <= x);

	int result = minimumExceedsZ(x, z);

	printf("%d\n", result);
	return 0;
}
