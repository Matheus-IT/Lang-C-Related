#include <stdio.h>


int main() {
	for (unsigned n = 1; n <= 1000000; n++) {
		if (n % 11 == 0 && n % 13 == 0 && n % 17 == 0) {
			printf("%u", n);
			break;
		}
	}

	return 0;
}
