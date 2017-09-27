#include "Nodo.h"

Nodo::Nodo(char c){
	this->c = c;
	hijoMasI = 0;
	hermanoD = 0;
}

Nodo::~Nodo(){
	if(hermanoD){
		delete hermanoD;
	}
	if(hijoMasI){
		delete hijoMasI;
	}
}
/*
bool Nodo::operator==(const Nodo& otro){
	return this->c == otro.c;
}
*/