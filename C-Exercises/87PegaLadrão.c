#include <stdio.h>
#include <stdlib.h>

#define LENGTH 11

int main() {
	int distanciaLimite = 12; // nautical miles
	int VF[LENGTH] = {1, 10, 9, 5, 12, 77, 80, 76, 99, 39, 0}; 	// nautical mile / Hour
	int D[LENGTH] = {5, 12, 12, 10, 9, 93, 70, 5, 78, 62, 0}; 	// nautical mile
	int VG[LENGTH] = {12, 7, 10, 5, 15, 70, 74, 49, 81, 62, 0}; // nautical mile / Hour

	for (int i = 0; i < LENGTH; i++) {
		float tempoFugitivosAteOutroLado = (float) distanciaLimite / VF[i];
		float tempoGuardaAteFugitivos = (float) D[i] / (VG[i] - VF[i]/2.3);

		if (tempoGuardaAteFugitivos < tempoFugitivosAteOutroLado) {
			printf("S");
		} else {
			printf("N");
		}
	}
	return 0;
}
