#include "ArbolL.h"
#include <iostream>
using namespace std;

ArbolL::ArbolL(){
	listaP = 0;
}

ArbolL::~ArbolL(){

}

void ArbolL::borrado(Nodo c){
	CajaSub * iter;
	Nodo victima;
	while(c->siguiente != 0){
		victima = c;
		if(!hoja(c)){
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

Nodo ArbolL::raiz(){
	return listaP->primera();
}

Nodo ArbolL::hijoMasIzq(Nodo caja){
	return caja->getSub()->primera()->getPrincipal();
}

Nodo ArbolL::hermanoDer(Nodo caja){
	Nodo papa = padre(caja);
	Nodo hd = NULL;
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

Nodo ArbolL::padre(Nodo caja){
	bool encontrado = false;
	Nodo iterP = listaP->primera();
	CajaSub * iterSub;
	Nodo papa = NULL;
	while(!encontrado && iterP->getSiguiente() != 0){
		if(!hoja(iterP) && iterP != caja){
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

bool ArbolL::hoja(Nodo caja){
	return caja->getSub() == 0;
}

Etiqueta ArbolL::etiqueta(Nodo caja){
	return caja->getEtiqueta();
}

int ArbolL::gnumNodos(){//Se hace en tiempo constante pues se tiene una variable de longitud en la clase lista.
	return this->listaP->getLongitud();
}

int ArbolL::numHijos(Nodo caja){
	int numHijos = 0;
	if(!hoja(caja)){
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

void ArbolL::modificarEtiq(Nodo caja, Etiqueta e){
	caja->setEtiqueta(e);
}

void ArbolL::agregarHijo(Nodo caja, int i, Etiqueta e){
	this->listaP->insertar(e, 1);//se agrega despues de la raiz
	Nodo nuevo = this->listaP->primera()->getSiguiente();//El recien insertado.
	if (caja->getSub() == 0){
		caja->setSub(nuevo);
	}
	else if(caja->getSub()->getLongitud() > 0){
		caja->sub->insertar(i,nuevo);
	}
}

void ArbolL::borrarHoja(Nodo caja){
	bool encontrado = false;
	Nodo iterP = listaP->primera();
	Nodo papa = padre(caja);
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
	Nodo raiz = new CajaP(e);
	this->listaP = new ListaP(raiz);
}