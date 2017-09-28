#include "Nodo.h"

Nodo::Nodo(){
	this->etiqueta = 0;
	this->hijoMasI = 0;
	this->hermanoD = 0;

}
Nodo::Nodo(char e){
	this->etiqueta = e;
	this->hijoMasI = 0;
	this->hermanoD = 0;
}

Nodo::~Nodo(){
	if(hermanoD){
		delete hermanoD;
	}
	if(hijoMasI){
		delete hijoMasI;
	}
}
void Nodo::setEtiqueta(char e){
	this->etiqueta = e;
}
char Nodo::getEtiqueta(){
	return this->etiqueta;
}
bool Nodo::operator==(const Nodo& otro){
	return this->etiqueta == otro.etiqueta;
}
