#include "ListaP.h"
#include <iostream>
using namespace std;

ListaP::ListaP(){
	primero = 0;
	ultimo = 0;
	longitud = 0;
}

ListaP::~ListaP(){
	
}

ListaP::ListaP(CajaP* caja){//solo cuando esta vacio
	primero = ultimo = caja;
	longitud = 1;
}

int ListaP::getLongitud(){
	return this->longitud;
}

void ListaP::insertar(Etiqueta e, int indice){
	if(indice == longitud){//ultimo
		this->agrAlFinal(e);
	}
	else{
		if(indice == 0){//Primero
			this->agrAlInicio(e);
		}
		else{
			CajaP * nueva = new CajaP(e);
			CajaP * iterador = primero;
			int contador = 0;
			while(contador != indice-1){//queda en el anterior a la posicion deseada.
				iterador = iterador->getSiguiente();
				++contador;
			}
			nueva->siguiente = iterador->siguiente;
			iterador->siguiente = nueva;
			++longitud;
		}
	}	
}

void ListaP::agrAlFinal(Etiqueta e){
	CajaP * nueva = new CajaP(e);
	if(this->ultimo){
		this->ultimo->setSiguiente(nueva);
		this->ultimo = nueva;
	}
	else{
		primero = ultimo = nueva;
	}
	++longitud;
}

void ListaP::agrAlInicio(Etiqueta e){
	CajaP * nueva = new CajaP(e);
	if(this->primero){
		nueva->setSiguiente(this->primero);
		this->primero = nueva;
	}
	else{
		primero = ultimo = nueva;
	}
	++longitud;
}

void ListaP::borrar(CajaP * caja){
	CajaP * victima;
	if(caja == primero){//Al inicio
		victima = primero;
		primero = primero->siguiente;
		delete victima;
	}
	else if(caja == ultimo){//Al final
		CajaP * iter = primero;
		victima = ultimo;
		while(iter->getSiguiente() != ultimo){//Queda en el penultimo
			iter = iter->siguiente;
		}
		ultimo = iter;
		ultimo->siguiente = 0;
		delete victima;
	}
	else{//En el "medio"
		CajaP * iter = primero; 
		victima = caja;
		while(iter->getSiguiente() != caja){
			iter = iter->siguiente;
		}
		iter->siguiente = caja->siguiente;
		delete victima;
	}
	--longitud;
}

void ListaP::modificar(CajaP* caja, Etiqueta e){
	caja->setEtiqueta(e);
}

CajaP* ListaP::primera(){
	return this->primero;
}

CajaP* ListaP::ultima(){
	return this->ultimo;
}

CajaP* ListaP::siguiente(CajaP * c){
	return c->getSiguiente();
}

Etiqueta ListaP::recuperar(CajaP * c){
	return c->getEtiqueta();
}