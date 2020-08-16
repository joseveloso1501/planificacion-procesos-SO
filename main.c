#include<stdio.h>
#include <stdlib.h>
#include <string.h>


void rr(int np, int quantum) {

	printf("ROUND ROBIN");
	
	//int np=11, procesos[10], quantum = 0, nq = 0;
	int procesos[10], nq = 0;
	double tp = 0;// tiempo promedio.
	
	int finalizado = 0;
	
	//while (np > 10 || np <= 0) {
	//	printf("\nNumero de procesos(%d): ", np);
	//	scanf("%d", &np);
	//}

	printf("\nNumero de procesos: %d", np);

	//para i=0, mientras i<np, hacer:...
	// pedimos el tamaño de cada proceso.


	for(int i=0; i<np; i++) {
		printf("\nInserte el proceso %d :", i+1);
		scanf("%d", &procesos[i]);
	}
	
	while (quantum <= 0) {
		printf("Tamaño de quantum:");
		scanf("%d", &quantum);
	}
	// Algoritmo RR
	
	while(finalizado == 0) {
		finalizado = 1;// Sí finalizado
		for(int i=0; i<np; i++) {
			if(procesos[i] > 0) {
				procesos[i] -= quantum;
				nq++;
				printf("\nQuantum[%d] proceso %d",nq, i+1);
				if (procesos[i]>0) {
					finalizado = 0; //No finalizado
				} else {
					tp += nq*quantum;
				}
			}
		}
	}
	
	tp = tp / np;
	
	printf(" \nTiempo promedio RR %f:", tp);

}



void fifo(int np){
	printf("FIFO");
	//int np=atoi(argv[2]), procesos[10];
	int procesos[10];
	double tf = 0, tp;// tiempo promedio.
	
	//while (np > 10 || np <= 0) {
	//	printf("\nNumero de procesos: ");
	//	scanf("%d", &np);
	//}

	printf("\nNumero de procesos: %d", np);

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

}

int main(int argc, char *argv[]) {
	printf("\nAlgoritmo escogido: ");

	if (!(strcmp(argv[1], "-F"))){
		fifo(atoi(argv[2]));
	} else{
		if (!(strcmp(argv[1], "-R")) && !(strcmp(argv[3], "-Q"))){
			rr(atoi(argv[2]), atoi(argv[4]));
		} else{
			if (!(strcmp(argv[1], "-P")) && !(strcmp(argv[3], "-p"))){
				printf("\nVUELVA PRONTO\n");
				//prio(atoi(argv[2]), atoi(argv[4]));
			} else{
				printf("\nPARÁMETRO INGRESADO NO VALIDO\n");
			}
		}
	}
	printf("\nFin del programa\n");
	return 0;
}