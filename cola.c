#include <stdio.h>
#include <stdlib.h>

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

int main (){
    
    Element *_Element = (Element *) malloc (sizeof(Element));
    Element *_Element2 = (Element *) malloc (sizeof(Element2));
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