#include "CajaSub.h"

CajaSub::CajaSub(CajaP* correspondiente){
	this->siguiente = 0;
	this->principal = correspondiente;
}

CajaSub::~CajaSub(){

}

CajaP * CajaSub::getPrincipal(){
	return this->principal;
}

CajaSub* CajaSub::getSiguiente(){
	return this->siguiente;
}

void CajaSub::setSiguiente(CajaSub* caja){
	this->siguiente = caja;
}