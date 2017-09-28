#include "ArbolL.h"
//------------------CLASE LISTAP--------------------
ArbolL::ListaP::CajaP::CajaP(Etiqueta e){
	this->etiq = e;
	this->siguiente = 0;
	this->sub = 0;
}

ArbolL::ListaP::CajaP::~CajaP(){//Para borrar todos consecutivamente.
	if(this->siguiente){
		delete this->siguiente;
	}
}

ArbolL::ListaP::ListaP(){
	primero = 0;
	ultimo = 0;
	longitud = 0;
}

ArbolL::ListaP::~ListaP(){
	if(primero){
		delete primero;
	}
}

void ArbolL::ListaP::insertar(Etiqueta e, int indice){
	if(indice == longitud-1){//ultimo
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
				iterador = iterador->siguiente;
				++contador;
			}
			nueva->siguiente = iterador->siguiente;
			iterador->siguiente = nueva;
			++longitud;
		}
	}	
}

void ArbolL::ListaP::agrAlFinal(Etiqueta e){
	CajaP * nueva = new CajaP(e);
	if(this->ultimo){
		this->ultimo->siguiente = nueva;
		this->ultimo = nueva;
	}
	else{
		primero = ultimo = nueva;
	}
	++longitud;
}

void ArbolL::ListaP::agrAlInicio(Etiqueta e){
	CajaP * nueva = new CajaP(e);
	if(this->primero){
		nueva->siguiente = this->primero;
		this->primero = nueva;
	}
	else{
		primero = ultimo = nueva;
	}
	++longitud;
}

void ArbolL::ListaP::borrar(CajaP * caja){
	CajaP * victima;
	if(caja == primero){//Al inicio
		victima = primero;
		primero = primero->siguiente;
		delete victima;
	}
	else if(caja == ultimo){//Al final
		CajaP * iter = primero;
		victima = ultimo;
		while(iter->siguiente != ultimo){//Queda en el penultimo
			iter = iter->siguiente;
		}
		ultimo = iter;
		ultimo->siguiente = 0;
		delete victima;
	}
	else{//En el "medio"
		CajaP * iter = primero; 
		victima = caja;
		while(iter->siguiente != caja){
			iter = iter->siguiente;
		}
		iter->siguiente = caja->siguiente;
		delete victima;
	}
	--longitud;
}

void ArbolL::ListaP::modificar(CajaP* caja, Etiqueta e){
	caja->etiq = e;
}

ArbolL::ListaP::CajaP* ArbolL::ListaP::primera(){
	return this->primero;
}

ArbolL::ListaP::CajaP* ArbolL::ListaP::ultima(){
	return this->ultimo;
}

ArbolL::ListaP::CajaP* ArbolL::ListaP::siguiente(CajaP * c){
	return c->siguiente;
}

Etiqueta ArbolL::ListaP::recuperar(CajaP * c){
	return c->etiq;
}
//---------------------------CLASE SUBLISTA-------------------------
ArbolL::SubLista::CajaSub::CajaSub(CajaP* correspondiente){
	this->siguiente = 0;
	this->principal = correspondiente;
}

ArbolL::SubLista::CajaSub::~CajaSub(){
	if(this->siguiente){
		delete this->siguiente;
	}
}

ArbolL::SubLista::SubLista(){
	primero = 0;
	ultimo = 0;
	longitud = 0;
}

ArbolL::SubLista::~SubLista(){
	if(primero){
		delete primero;
	}
}

void ArbolL::SubLista::insertar(int indice, CajaP* correspondiente){
	if(indice == longitud-1){//ultimo
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
				iterador = iterador->siguiente;
				++contador;
			}
			nueva->siguiente = iterador->siguiente;
			iterador->siguiente = nueva;
			++longitud;
		}
	}
}

void ArbolL::SubLista::agrAlFinal(CajaP* correspondiente){
	CajaSub * nueva = new CajaSub(correspondiente);
	if(this->ultimo){
		this->ultimo->siguiente = nueva;
		this->ultimo = nueva;
	}
	else{
		primero = ultimo = nueva;
	}
	++longitud;
}

void ArbolL::SubLista::agrAlInicio(CajaP* correspondiente){
	CajaSub* nueva = new CajaSub(correspondiente);
	if(this->primero){
		nueva->siguiente = this->primero;
		this->primero = nueva;
	}
	else{
		primero = ultimo = nueva;
	}
	++longitud;
}

void ArbolL::SubLista::borrar(CajaSub* caja){
	CajaSub * victima;
	if(caja == primero){//Al inicio
		victima = primero;
		primero = primero->siguiente;
		delete victima;
	}
	else if(caja == ultimo){//Al final
		CajaSub * iter = primero;
		victima = ultimo;
		while(iter->siguiente != ultimo){//Queda en el penultimo
			iter = iter->siguiente;
		}
		ultimo = iter;
		ultimo->siguiente = 0;
		delete victima;
	}
	else{//En el "medio"
		CajaSub * iter = primero; 
		victima = caja;
		while(iter->siguiente != caja){
			iter = iter->siguiente;
		}
		iter->siguiente = caja->siguiente;
		delete victima;
	}
	--longitud;
}

ArbolL::SubLista::CajaSub * ArbolL::SubLista::primera(){
	return this->primero;
}

ArbolL::SubLista::CajaSub * ArbolL::SubLista::ultima(){
	return this->ultimo;
}

ArbolL::SubLista::CajaSub * ArbolL::SubLista::siguiente(CajaSub* c){
	return c->siguiente;
}

ArbolL::SubLista::CajaP* ArbolL::SubLista::recuperar(CajaSub* c){
	return c->principal;
}

ArbolL::ArbolL(){
	listaP = 0;
}

ArbolL::~ArbolL(){
	delete listaP;
}

void ArbolL::vaciar(){
	
}