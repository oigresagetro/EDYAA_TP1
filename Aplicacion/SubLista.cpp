#include "SubLista.h"

SubLista::SubLista(){
	primero = 0;
	ultimo = 0;
	longitud = 0;
}

SubLista::~SubLista(){

}

SubLista::SubLista(CajaP* caja){
	CajaSub * nuevo = new CajaSub(caja);
	primero = ultimo = nuevo;
	longitud = 1;
}

int SubLista::getLongitud(){
	return this->longitud;
}

void SubLista::insertar(int indice, CajaP* correspondiente){
	if(indice == this->longitud){//ultimo
		this->agrAlFinal(correspondiente);
	}
	else{
		if(indice == 0){//Primero
			this->agrAlInicio(correspondiente);
		}
		else{
			CajaSub * nueva = new CajaSub(correspondiente);
			CajaSub * iterador = primero;
			int contador = 0;
			while(contador != indice-1){//queda en el anterior a la posicion deseada.
				iterador = iterador->getSiguiente();
				++contador;
			}
			nueva->setSiguiente(iterador->getSiguiente());
			iterador->setSiguiente(nueva);
			++longitud;
		}
	}
}

void SubLista::agrAlFinal(CajaP* correspondiente){
	CajaSub * nueva = new CajaSub(correspondiente);
	if(this->ultimo){
		this->ultimo->setSiguiente(nueva);
		this->ultimo = nueva;
	}
	else{
		primero = ultimo = nueva;
	}
	++longitud;
}

void SubLista::agrAlInicio(CajaP* correspondiente){
	CajaSub* nueva = new CajaSub(correspondiente);
	if(this->primero){
		nueva->setSiguiente(this->primero);
		this->primero = nueva;
	}
	else{
		primero = ultimo = nueva;
	}
	++longitud;
}

void SubLista::borrar(CajaSub* caja){
	CajaSub * victima;
	if(caja == primero){//Al inicio
		victima = primero;
		primero = primero->siguiente;
		delete victima;
	}
	else if(caja == ultimo){//Al final
		CajaSub * iter = primero;
		victima = ultimo;
		while(iter->getSiguiente() != ultimo){//Queda en el penultimo
			iter = iter->siguiente;
		}
		ultimo = iter;
		ultimo->siguiente = 0;
		delete victima;
	}
	else{//En el "medio"
		CajaSub * iter = primero; 
		victima = caja;
		while(iter->getSiguiente() != caja){
			iter = iter->siguiente;
		}
		iter->siguiente = caja->siguiente;
		delete victima;
	}
	--longitud;
}

CajaSub * SubLista::primera(){
	return this->primero;
}

CajaSub * SubLista::ultima(){
	return this->ultimo;
}

CajaSub * SubLista::siguiente(CajaSub* c){
	return c->getSiguiente();
}

CajaP* SubLista::recuperar(CajaSub* c){
	return c->getPrincipal();
}