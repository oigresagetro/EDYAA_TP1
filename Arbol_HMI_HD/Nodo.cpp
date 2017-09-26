#include "Nodo.h"

Nodo::Nodo(char c){
	this->c = c;
	hijoMasI = 0;
	hermanoDer = 0;
}

Nodo::~Nodo(){
	if(hermanoDer){
		delete hermanoDer;
	}
	if(hijoMasI){
		delete hijoMasI;
	}
}

bool Nodo::operator==(const Nodo& otro){
	return this->c == otro.c;
}
