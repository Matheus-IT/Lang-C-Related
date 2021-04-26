#include <cstdio>

struct Bota {
	unsigned num;	// M
	char pe;		// L
	bool par; 
};

int main () {
	FILE *fp;
	unsigned N, cont;
	fp = fopen("botas.in", "r");
	if (fp) {
		while (fscanf(fp, "%u", &N) && N) {
			struct Bota P[N];
			cont = 0;
			for(unsigned i = 0; i < N; i++) {
				fscanf(fp, "%u %c", &P[i].num, &P[i].pe);
				P[i].par = false;
			}
			for (unsigned i = 0; i < N-1; i++) {
				if (P[i].par) continue; 
				for (unsigned j = i+1; j < N; j++) {
					if (P[j].par) continue;
					if (P[i].num == P[j].num && P[i].pe != P[j].pe) {
						P[i].par = P[j].par = true;
						cont++;
						break;
					}
				}
			}
			printf("%u\n", cont);
		}
		fclose(fp);
	}
	
	return 0;
}