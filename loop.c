#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
	int hasta;
	srand(time(NULL));
	hasta = (rand() % 10) + 1; //generacion de numeros aleatorios del 1 al 10
	for(int i = 0 ; i <= hasta ; i++) { //Asuma que todos los procesos entran al mismo instante de tiempo y los tiempos de r´afaga son desconocidos, 
										//estos dependen del valor final del for en “loop” y la velocidad de su m´aquina


		sleep(1);
	}
	return 0;
}