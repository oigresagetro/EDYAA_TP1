#include "CajaP.h"
#include "SubLista.h"
CajaP::CajaP(Etiqueta e){
	this->etiq = e;
	this->siguiente = 0;
	this->sub = 0;
}

CajaP::~CajaP(){//Para borrar todos consecutivamente.
	
}

SubLista* CajaP::getSub(){
	return this->sub;
}

void CajaP::setSub(CajaP* caja){//para cuando esta vacio
	sub = new SubLista(caja);
}

CajaP* CajaP::getSiguiente(){
	return this->siguiente;
}

Etiqueta CajaP::getEtiqueta(){
	return this->etiq;
}

void CajaP::setEtiqueta(Etiqueta e){
	this->etiq = e;
}

void CajaP::setSiguiente(CajaP* caja){
	this->siguiente = caja;
}