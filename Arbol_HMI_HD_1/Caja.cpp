#include "Caja.h"

Caja::Caja(){
	this->etiqueta = 0;
	this->hijoMasI = 0;
	this->hermanoD = 0;

}
Caja::Caja(char e){
	this->etiqueta = e;
	this->hijoMasI = 0;
	this->hermanoD = 0;
}

Caja::~Caja(){

}
