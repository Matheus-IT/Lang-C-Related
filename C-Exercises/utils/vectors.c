void printVect(int nums[], int length) {
	printf("[");
	for (int i = 0; i < length; i++)
		if (i == length - 1)
			printf(" %d", nums[i]);
		else
			printf(" %d,", nums[i]);
	printf("]\n");
}