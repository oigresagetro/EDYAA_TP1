#include "Cola.h"

Cola::Cola(){
	primero = 1;
	ultimo = 0;
	numeroElem = 0;
}


Cola::~Cola(){

}

void Cola::vaciar(){
    numeroElem=0;
		primero = 1;
		ultimo = 0;
}

void Cola::encolar(int e){
	ultimo = (ultimo+1)%10;
	arreglo[ultimo] = e;
	numeroElem++;
}

void Cola::desencolar(){
    if(!vacia()){
        arreglo[primero] = 0;
        primero = (primero+1)%10;
        --numeroElem;
    }
}

int Cola::frente(){
	return arreglo[primero];
}

int Cola::vacia(){
    int estaVacia=0;
    if(numeroElem==0){
        estaVacia=1;
    }
    return estaVacia;
}

int Cola::numElem(){
    return numeroElem;
}
