#include <stdio.h>


int main() {
	unsigned sum = 0;

	for (int n = 1; n <= 100; n++) {
		if (n % 3 == 0 || n % 5 == 0)
			continue;
		sum += n;
	}

	printf("%u", sum);
	return 0;
}