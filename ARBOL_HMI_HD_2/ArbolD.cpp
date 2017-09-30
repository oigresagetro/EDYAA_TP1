#include "ArbolD.h"

ArbolD::ArbolD(){
	sHijoMI = 0;
	numNodos = 0;
}

ArbolD::~ArbolD(){
	if(this->sHijoMI){
		delete this->sHijoMI;
	}
}

void ArbolD::vaciar(){
	this->sHijoMI = 0;
}

bool ArbolD::vacia(){
	return this->sHijoMI == 0;
}

void ArbolD::ponerRaiz(char et){
	Nodo2 * raiz = new Nodo2(et);
	this->sHijoMI = raiz;
	++numNodos;
}


Nodo2 * ArbolD::raiz(){
	return sHijoMI;
}

Nodo2 * ArbolD::hijoMasIzq(Nodo2 * nodo){
	return nodo->hijoMasI;
}

Nodo2 * ArbolD::hermanoDer(Nodo2 * nodo){
	if(nodo->stePadre == true){
		return 0;
	}else{
		return nodo->hermanoD;
	}
}

Nodo2 * ArbolD::padre(Nodo2 * nodo){
	if(nodo->stePadre == true){
		return nodo->hermanoD;
	}else{
		Nodo2 * iter = nodo;
		while(!iter->stePadre){
			iter = iter->hermanoD;
		}
		return iter->hermanoD;
	}
}

bool ArbolD::hoja(Nodo2 * nodo){
	return nodo->hijoMasI == 0;
}

char ArbolD::etiqueta(Nodo2 * nodo){
	return nodo->getEtiqueta();
}
int ArbolD::gnumNodos(){
	return this->numNodos;
}


int ArbolD::numHijos(Nodo2 * padre){
	int numHijos = 0;
	if(padre->hijoMasI != NULL){
		numHijos = 1;
		Nodo2 * iter = padre->hijoMasI->hermanoD;
		while(!iter->stePadre){
			++numHijos;
			iter = iter->hermanoD;
		}
		++numHijos;
	}
	return numHijos;
}

void ArbolD::modificarEtiq(Nodo2 * nodo, char et){
	nodo->setEtiqueta(et);
}

void ArbolD::agregarHijo(Nodo2 * padre, int i, char et){
	if(i == 1){
		if(padre->hijoMasI==0){
			Nodo2 * nuevoHMI = new Nodo2(et);
			padre->hijoMasI = nuevoHMI;
			++numNodos;
		}else{
			Nodo2 * temp = padre->hijoMasI;
			Nodo2 * nuevoHMI = new Nodo2(et);
			padre->hijoMasI = nuevoHMI;
			padre->hijoMasI->hermanoD = temp;
			if(padre->hijoMasI->hermanoD == 0){
				padre->hijoMasI->hermanoD = padre;
			}
			++numNodos;
		}
	}else{
		Nodo2 * iter = padre->hijoMasI; // se coloca al hermano izq de donde se desea agregar
		for(int j = 1; j < i - 1 ; ++j ){
			iter = iter->hermanoD;
		}
		if(iter->hermanoD == padre){
			Nodo2 * nuevoHD = new Nodo2(et);
			iter->hermanoD = nuevoHD;
			nuevoHD->hermanoD = padre;
			++numNodos;
		}else{
				Nodo2 * nuevoHD = new Nodo2(et);
				Nodo2 * temp = iter->hermanoD;
				iter->hermanoD = nuevoHD;
				nuevoHD->hermanoD = temp;
				++numNodos;
		}
	}
}

void ArbolD::borrarHoja(Nodo2 * nPorBorrar){
	 Nodo2 * p = this->padre(nPorBorrar);
	 bool borrado = 0;
	 bool primero = false;
	 Nodo2 * iter = nPorBorrar;
	 //Nodo2 * iter = p->hijoMasI;
	 while(!borrado){
		 if(iter->hermanoD == p){
			 iter = iter->hermanoD;
			 primero = true;
		 }else{
			if(primero){
				if(iter->hijoMasI == nPorBorrar){
					iter->hijoMasI = iter->hijoMasI->hermanoD;
					borrado = true;
				}else{
					iter = iter->hijoMasI;
				}
			}else{
				if(iter->hermanoD == nPorBorrar){
					if(iter->hermanoD->stePadre){
						iter->hermanoD = p;
						iter->stePadre = true;
						borrado = true;
					}else{
						iter->hermanoD = iter->hermanoD->hermanoD;
						borrado = true;
					}
				}else{
					iter = iter->hermanoD;
				}
			}
	 }
 }
 }
