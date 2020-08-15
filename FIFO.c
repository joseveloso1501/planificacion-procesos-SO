#include<stdio.h>

int main(int n, char **args) {
	printf("FCFS: FIRST COME FIRST SERVERED");

	int np=11, procesos[10];
	double tf = 0, tp;// tiempo promedio.
	
	while (np > 10 || np <= 0) {
		printf("\nNumero de procesos: ");
		scanf("%d", &np);
	}
	//para i=0, mientras i<np, hacer:...
	// pedimos el tamaño de cada proceso.
	
	for(int i=0; i<np; i++) {
		printf("\nInserte el proceso %d :", i+1);
		scanf("%d", &procesos[i]);
	}
	// Algoritmo FCFS
	
	for(int i=0; i<np; i++) {
		tf += procesos[i];
		tp = tp + tf;
		printf("\nProceso %d, concluye en %2.1f", i+1, tf);
	}
	
	printf("\n-------------------------------");
	printf("\nLa suma de los procesos %2.1f", tp);
	tp = tp / np;
	printf("\n\nTiempo promedio en FCFS fue de: %2.2f:", tp);
	
	return 0;
}