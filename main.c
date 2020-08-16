#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <time.h>

///////////////////////////--RR--///////////////////////////////////////////////
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


///////////////////////////--FIFO--///////////////////////////////////////////////

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
//////////////////////////////--LOOP--//////////////////////////////////////////////
int loop() {
	int hasta;
	srand(time(NULL));
	hasta = (rand() % 10) + 1; //generacion de numeros aleatorios del 1 al 10
	for(int i = 0 ; i <= hasta ; i++) { //Asuma que todos los procesos entran al mismo instante de tiempo y los tiempos de r´afaga son desconocidos, 
										//estos dependen del valor final del for en “loop” y la velocidad de su m´aquina


		sleep(1);
	}
	return 0;
}

///////////////////////////--COLA--///////////////////////////////////////////////

typedef struct Element
{
    struct Element *next; //Proximo elemento
    int dato;//Nombre del elemento
}Element;

Element *first=NULL; //primer elemento
Element *last=NULL; // ultimo elemento

//Crear el elemento
void createElement(Element *_Element, int dato )
{   
    //Se le asigna un dato al nuevo elemento
    _Element->dato=dato;
}

void push(Element *_Element){
    
    _Element->next=NULL;
    
    if(first==NULL){//Si el primero no existe quiere decir que no hay nada en la cola y esta vacia
        first=_Element; //El primer elemento será el nuevo elemento creado
        last=_Element; //Y también será el ultimo dado que solo existe uno en la cola
    }
    else{
        last->next=_Element; 
        last=_Element;
    }
}

Element * pop(){
    
    if(first==NULL)
        return NULL;
    //Decimos que el primer elemento en la cola es el que se va a devolver para imprimir
    Element * _Element_Return=first;
    //Y ahora el primer elemento es elemento proximo en la cola
    first=first->next;

    return _Element_Return;
}

//Desencolar e imprimir
void printAndPop(){
    //Obtiene el primer elemento de la cola
    Element *i=pop();
    //Mientras todavia haya elementos en cola que los imprima
    while(i)
    {
        printf("%i\n",i->dato);
        //Vuelvo a obtener el primer elemento
        i=pop();
    }
}

int cola (){
    
    Element *_Element = (Element *) malloc (sizeof(Element));
    Element *_Element2 = (Element *) malloc (sizeof(Element));
    //Element *_Element;

    createElement(_Element,1);
    createElement(_Element,loop());

    //Encolar
    push(_Element);
    push(_Element2);
    //Desconlar e imprimir
    printAndPop();

    free(_Element);
    free(_Element2);
    return 0;
}

//////////////////////////////////////////////////////////////////////////
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