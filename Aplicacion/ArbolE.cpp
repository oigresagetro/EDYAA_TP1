#include "ArbolE.h"

ArbolE::ArbolE(){
	sRaiz = NULL;
	numNodos = 0;
}

ArbolE::~ArbolE(){
	if(!this->vacia()){
		this->posOrdenB(sRaiz);
	}
}

void ArbolE::vaciar(){
	delete this;
	sRaiz = 0;
}

bool ArbolE::vacia(){
	return sRaiz == 0;
}

void ArbolE::posOrdenB(Nodo n){
	Nodo nh = this->hijoMasIzq(n);
	while(nh!=0){
		this->posOrdenB(nh);
		nh = this->hermanoDer(nh);
	}
	delete n;
}


void ArbolE::ponerRaiz(Etiqueta et){
	sRaiz = new Nodo3(et);
	numNodos++;
}


Nodo ArbolE::raiz(){
	return sRaiz;
}

Nodo ArbolE::hijoMasIzq(Nodo n){
	return n->hijoMasI;
}

Nodo ArbolE::hermanoDer(Nodo n){
	return (n->hermanoD);
}

Nodo ArbolE::padre(Nodo n){
	return n->ptrPadre;
}

bool ArbolE::hoja(Nodo n){
	return n->hijoMasI == 0;
}

Etiqueta ArbolE::etiqueta(Nodo n){
	return (n->c);
}
int ArbolE::gnumNodos(){
	return numNodos;
}

int ArbolE::numHijos(Nodo padre){
	int numHijos = 0;
	if(padre->hijoMasI != NULL){
		numHijos = 1;
		Nodo iter = padre->hijoMasI->hermanoD;
		while(iter != NULL){
			numHijos++;
			iter = iter->hermanoD;
		}
	}
	return numHijos;
}

void ArbolE::modificarEtiq(Nodo n, Etiqueta et){
	n->c = et;
}

void ArbolE::agregarHijo(Nodo padre, int i, Etiqueta c){
	if(padre->hijoMasI != NULL){
		if(i == 1){
			Nodo temp = padre->hijoMasI;
			padre->hijoMasI = new Nodo3(c);
			padre->hijoMasI->hermanoD = temp;
			padre->hijoMasI->ptrPadre = padre;
			padre->hijoMasI->hermanoD->hermanoI = padre->hijoMasI;
		}else{
			Nodo iter = padre->hijoMasI; // se coloca al hermano izq de donde se desea agregar
			for(int j = 1; j < i - 1 ; ++j ){
				iter = iter->hermanoD;
			}
			Nodo temp = iter->hermanoD;
			iter->hermanoD = new Nodo3(c);
			if(temp != 0){
				iter->hermanoD->hermanoD = temp;
				iter->hermanoD->hermanoD->hermanoI = iter->hermanoD;
				iter->hermanoD->ptrPadre = padre;
				iter->hermanoD->hermanoI = iter;
			}else{
				iter->hermanoD->ptrPadre = padre;
				iter->hermanoD->hermanoI = iter;
			}
		}
	}else{
		padre->hijoMasI = new Nodo3(c);
		padre->hijoMasI->ptrPadre = padre;
	}
	++numNodos;
}


void ArbolE::borrarHoja(Nodo nPorBorrar){
	 Nodo father = this->padre(nPorBorrar);
	 if(father->hijoMasI == nPorBorrar){
		 father->hijoMasI = nPorBorrar->hermanoD;
	 }else{
		 if(this->hermanoDer(nPorBorrar) == 0){
			 nPorBorrar->hermanoI->hermanoD = 0;
		 }else{
			 nPorBorrar->hermanoD->hermanoI = nPorBorrar->hermanoI;
			 nPorBorrar->hermanoI->hermanoD = nPorBorrar->hermanoD;
		 }
	 }
	 --numNodos;
}
