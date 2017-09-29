#include "ArbolD.h"

ArbolD::ArbolD(){
	sHijoMI = NULL;
	numNodos = 0;
}

ArbolD::~ArbolD(){
	if(sHijoMI){
		delete sHijoMI;
	}
}

void ArbolD::vaciar(){
	sHijoMI = 0;
}

bool ArbolD::vacia(){
	return sHijoMI == 0;
}

void ArbolD::ponerRaiz(char et){
	Nodo * raiz = new Nodo(char);
	sHijoMI->hijoMasI = raiz;
}


Nodo * ArbolD::raiz(){
	return sHijoMI->hijoMasI;
}
 
Nodo * ArbolD::hijoMasIzq(Nodo * n){
	return n->hijoMasI;
}

Nodo * ArbolD::hermanoDer(Nodo * n){
	if(n->stePadre == true){
		return 0;
	}else{
		return (n->hermanoD);
	}
}

Nodo * ArbolD::padre(Nodo2 * n){
	if(n->stePadre == true){
		return n->hermanoD;
	}else{
		Nodo2 * iter = n;
		while(!iter->stePadre){
			iter = iter->hermanoD;
		}
		return iter->hermanoD;
	}
}

bool ArbolD::hoja(Nodo * n){
	return n->hijoMasI == 0;
}

char ArbolD::etiqueta(Nodo * n){
	return *(n->c);
}
int ArbolD::gnumNodos(){
	return numNodos;
}


int ArbolD::numHijos(Nodo * padre){
	int numHijos = 0;
	if(padre->hijoMasI != NULL){
		numHijos = 1;
		Nodo * iter = padre->hijoMasI->hermanoD;
		while(!iter->stePadre){
			numHijos++;
			iter = iter->hermanoD;
		}
		numHijos++;
	}
	return numHijos;
}

void ArbolD::modificarEtiq(Nodo * n, char et){
	n->c = et;
}

void ArbolD::agregarHijo(Nodo * padre, int i, char c){
	if(padre->hijoMasI != NULL){
		if(i == 1){
			Nodo * temp = padre->hijoMasI;
			padre->hijoMasI = new Nodo(c);
			padre->hijoMasI->hermanoD = temp;
			padre->hijoMasI->stePadre = false;
		}else{
			Nodo * iter = padre->hijoMasI; // se coloca al hermano izq de donde se desea agregar
			for(int j = 1; j < i - 1 ; ++j ){
				iter = iter->hermanoD;
			}
			Nodo * temp = iter->hermanoD;
			iter->hermanoD = new Nodo(c);
			if(temp == 0){
				iter->hermanoD->hermanoD = padre;
				iter->hermanoD->stePadre = true;
			}else{
				iter->hermanoD->hermanoD = temp;
				iter->hermanoD->stePadre = false;
			}
		}
	}else{
		padre->hijoMasI = new Nodo(c);
		padre->hijoMasI->hermanoD = padre;
		padre->hijoMasI->stePadre = true;
	}
}



 void ArbolD::borrarHoja(Nodo * nPorBorrar){
	 Nodo * p = this->padre(nPorBorrar);
	 bool borrado = 0;
	 bool primero = false;
	 Nodo * iter = nPorBorrar;
	 //Nodo * iter = p->hijoMasI;
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
