#include <stdio.h>
#include <stdlib.h>


int main() {
	short day;
	scanf("%d", &day);

	switch(day) {
		case 1:
			puts("Sunday");
			break;
		case 2:
			puts("Monday");
			break;
		case 3:
			puts("Tuesday");
			break;
		case 4:
			puts("Wednesday");
			break;
		case 5:
			puts("Thursday");
			break;
		case 6:
			puts("Friday");
			break;
		case 7:
			puts("Saturday");
			break;
		default:
			puts("Exception: unexpected value.");
			exit(1);
	}

	return 0;
}