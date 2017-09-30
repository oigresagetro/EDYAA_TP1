#include "Nodo2.h"

Nodo2::Nodo2(char c){
	this->etiqueta = c;
	hijoMasI = 0;
	hermanoD = 0;
	stePadre = 0;
}

Nodo2::~Nodo2(){
	if(this->hermanoD){
		delete this->hermanoD;
	}
	if(this->hijoMasI){
		delete this->hijoMasI;
	}
}
void Nodo2::setEtiqueta(char etiqueta){
	this->etiqueta = etiqueta;
}
char Nodo2::getEtiqueta(){
	return this->etiqueta;
}
