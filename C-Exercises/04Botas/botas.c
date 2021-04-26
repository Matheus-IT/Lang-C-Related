#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Bota {
	unsigned int num;
	char pe;
	bool par;
};

int main() {
	FILE *fp = NULL;
	unsigned int N;

	// I need to finish this program

	fp = fopen(".\\botas.in", "rt");

	if (fp) {
		unsigned int cont;

		while (fscanf(fp, "%u", &N) && N) {
			cont = 0;
			struct Bota P[N];

			for (unsigned int i = 0; i < N; i++) {
				fscanf(fp, "%u %c", &P[i].num, &P[i].pe);
				printf("%d %c \n", P[i].num, P[i].pe);
			}

			for (unsigned int i = 0; i < N-1; i++) {
				if (P[i].par)
					continue;

				for (unsigned int j = i + j; j < N; j++) {
					if (P[j].par)
						continue;
					
					if (P[i].num == P[j].num && P[i].pe != P[j].pe) {
						P[i].par = P[j].par = true;
						cont++;
						break;
					}
				}
			}

			printf("%d \n", cont);
		}
		
		fclose(fp);
	}

	return 0;
}
