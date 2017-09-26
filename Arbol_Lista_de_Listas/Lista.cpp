#include "Lista.h"

Lista::Nodo::Nodo(Elemento e){
	this->elemento = e;
	this->siguiente = 0;
}

Lista::Nodo::~Nodo(){
	if(this->siguiente){//si tiene siguiente
		delete this->siguiente;
	}
}

Lista::Lista(){
	primero = 0;
	ultimo = 0;
	longitud = 0;
}

Lista::~Lista(){
	if(primero){
		delete primero;
	}
}

void Lista::insertar(Elemento e/*, POSICION?*/){//HACER

}

void Lista::agrAlFinal(Nodo * n){
	Nodo * iter = primero;
	while(iter->siguiente != 0){
		iter = iter->siguiente;
	}
	iter->siguiente = n;
	++longitud;
}

void Lista::borrar(Nodo * n){
	Nodo * victima;
	if(n == primero){//Al inicio
		victima = primero;
		primero = primero->siguiente;
		delete victima;
	}
	else if(n == ultimo){//Al final
		Nodo * iter = primero;
		victima = ultimo;
		while(iter->siguiente != ultimo){//Queda en el penultimo
			iter = iter->siguiente;
		}
		ultimo = iter;
		iter->siguiente = 0;
		delete victima;
	}
	else{//En el "medio"
		Nodo * iter = primero; 
		victima = n;
		while(iter->siguiente != n){
			iter = iter->siguiente;
		}
		iter->siguiente = n->siguiente;
		delete victima;
	}
	--longitud;
}

void Lista::Nodo::modificar(Nodo * n, Elemento el){
	n->elemento = el;
}

Lista::Nodo* Lista::primera(){
	return primero;
}

Lista::Nodo* Lista::ultima(){
	return ultimo;
}

Lista::Nodo* Lista::siguiente(Nodo * n){
	return n->siguiente;
}

Elemento Lista::recuperar(Nodo * n){
	return n->elemento;
}