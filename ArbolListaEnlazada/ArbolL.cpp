#include "ArbolL.h"
#include <iostream>
using namespace std;

ArbolL::ArbolL(){
	listaP = 0;
}

ArbolL::~ArbolL(){

}

void ArbolL::borrado(CajaP * c){
	CajaSub * iter;
	CajaP * victima;
	while(c->siguiente != 0){
		victima = c;
		if(!esHoja(c)){
			iter = c->sub->primera();
			while(iter->siguiente != 0){
				delete iter;
				iter = iter->siguiente;
			}
		}
		c = c->siguiente;
		delete victima;
	}
}

void ArbolL::vaciar(){
	if(!vacia()){
		borrado(listaP->primera());
	}
}

bool ArbolL::vacia(){
	return listaP == 0;
}

CajaP * ArbolL::raiz(){
	return listaP->primera();
}

CajaP * ArbolL::hijoMasIzq(CajaP * caja){
	return caja->getSub()->primera()->getPrincipal();
}

CajaP * ArbolL::hermanoDer(CajaP * caja){
	CajaP * papa = padre(caja);
	CajaP * hd = NULL;
	bool encontrado = false;
	SubLista * hijos = papa->getSub();
	CajaSub * iter = hijos->primera();//ERROR AQUI
	while(iter->getSiguiente() != 0 && !encontrado){
		if(iter->getPrincipal() == caja){
			hd = iter->getSiguiente()->getPrincipal();//como sí importa el orden.
			encontrado = true;
		}
		iter = iter->getSiguiente();
	}
	return hd;
}

CajaP * ArbolL::padre(CajaP * caja){
	bool encontrado = false;
	CajaP * iterP = listaP->primera();
	CajaSub * iterSub;
	CajaP* papa = NULL;
	while(!encontrado && iterP->getSiguiente() != 0){
		if(!esHoja(iterP) && iterP != caja){
			iterSub = iterP->getSub()->primera();
			while(iterSub->getSiguiente() != 0 && !encontrado){
				if(iterSub->getPrincipal() == caja){
					encontrado = true;
					papa = iterP;
				}
				iterSub = iterSub->getSiguiente();
			}
		}
		iterP = iterP->getSiguiente();
	}
	return papa;
}

bool ArbolL::esHoja(CajaP* caja){
	return caja->getSub() == 0;
}

Etiqueta ArbolL::etiqueta(CajaP* caja){
	return caja->getEtiqueta();
}

int ArbolL::numNodos(){//Se hace en tiempo constante pues se tiene una variable de longitud en la clase lista.
	return this->listaP->getLongitud();
}

int ArbolL::numHijos(CajaP* caja){
	int numHijos = 0;
	if(!esHoja(caja)){
		SubLista * hijos = caja->getSub();
		CajaSub * iter = hijos->primera();
		++numHijos;
		while(iter->getSiguiente() != 0){
			++numHijos;
			iter = iter->getSiguiente();
		}
	}
	return numHijos;
}

void ArbolL::modificarEtiq(CajaP* caja, Etiqueta e){
	caja->setEtiqueta(e);
}

void ArbolL::agregarHijo(CajaP* caja, Etiqueta e, int i){
	this->listaP->insertar(e, 1);//se agrega despues de la raiz
	CajaP * nuevo = this->listaP->primera()->getSiguiente();//El recien insertado.
	if (caja->getSub() == 0){
		caja->setSub(nuevo);
	}
	else if(caja->getSub()->getLongitud() > 0){
		caja->sub->insertar(i,nuevo);
	}
}

void ArbolL::borrarHoja(CajaP* caja){
	bool encontrado = false;
	CajaP * iterP = listaP->primera();
	CajaP * papa = padre(caja);
	CajaSub * iterSub = papa->sub->primera();
	while(iterSub->siguiente != 0 && !encontrado){
		if(iterSub->getPrincipal() == caja){
			papa->sub->borrar(iterSub);
			encontrado = true;
		}
		else{
			iterSub = iterSub->siguiente;
		}
	}
	this->listaP->borrar(caja);
}

void ArbolL::ponerRaiz(Etiqueta e){//Solo si esta vacio
	CajaP * raiz = new CajaP(e);
	this->listaP = new ListaP(raiz);
}