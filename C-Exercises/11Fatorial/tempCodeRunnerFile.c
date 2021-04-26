int n = 10;

	int temp = n;
	do {
	int closest = findClosestFactorialNum(temp);
	temp -= calcFact(closest);
	printf("%d", closest);
	} while(temp > 0);