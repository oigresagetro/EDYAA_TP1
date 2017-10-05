#include "ArbolD.h"

ArbolD::ArbolD(){
	sRaiz = 0;
	numNodos = 0;
}

ArbolD::~ArbolD(){
	if(!this->vacia()){
		this->posOrdenB(sRaiz);
	}
}

bool ArbolD::vacia(){
	return this->sRaiz == 0;
}

void ArbolD::vaciar(){
	delete this;
	sRaiz = 0;
}

void ArbolD::posOrdenB(Nodo n){
	Nodo nh = this->hijoMasIzq(n);
	while(nh!=0){
		this->posOrdenB(nh);
		nh = this->hermanoDer(nh);
	}
	delete n;
}


void ArbolD::ponerRaiz(Etiqueta et){
	sRaiz = new Nodo2(et);
	sRaiz->stePadre = true;
	++numNodos;
}


Nodo2 * ArbolD::raiz(){
	return this->sRaiz;
}

Nodo ArbolD::hijoMasIzq(Nodo nodo){
	return nodo->hijoMasI;
}

Nodo ArbolD::hermanoDer(Nodo nodo){
	if(nodo->stePadre == true){
		return 0;
	}else{
		return nodo->hermanoD;
	}
}

Nodo ArbolD::padre(Nodo nodo){

	if(nodo->stePadre == true){
		return nodo->hermanoD;
	}else{
		Nodo iter = nodo;
		while(!iter->stePadre){
			iter = iter->hermanoD;
		}
		return iter->hermanoD;
	}
}

bool ArbolD::hoja(Nodo nodo){
	return nodo->hijoMasI == 0;
}

Etiqueta ArbolD::etiqueta(Nodo nodo){
	return nodo->etiqueta;
}

int ArbolD::gnumNodos(){
	return this->numNodos;
}


int ArbolD::numHijos(Nodo padre){
	int numHijos = 0;
	if(padre->hijoMasI != NULL){
		numHijos = 1;
		Nodo iter = padre->hijoMasI;
		while(iter->stePadre==false){
			iter = iter->hermanoD;
			++numHijos;
		}
	}
	return numHijos;
}

void ArbolD::modificarEtiq(Nodo nodo, Etiqueta et){
	nodo->etiqueta = et;
}

void ArbolD::agregarHijo(Nodo padre, int i, Etiqueta et){
	if(i == 1){
		if(padre->hijoMasI==0){
			padre->hijoMasI = new Nodo2(et);
			padre->hijoMasI->hermanoD = padre;
			padre->hijoMasI->stePadre = true;
			++numNodos;
		}else{
			Nodo temp = padre->hijoMasI;
			padre->hijoMasI = new Nodo2(et);
			padre->hijoMasI->hermanoD = temp;
			++numNodos;
		}
	}else{
		Nodo iter = padre->hijoMasI; // se coloca al hermano izq de donde se desea agregar
		for(int j = 1; j < i - 1 ; ++j ){
			iter = iter->hermanoD;
		}
		if(iter->stePadre){
			iter->hermanoD = new Nodo2(et);
			iter->hermanoD->hermanoD = padre;
			iter->stePadre = false;
			iter->hermanoD->stePadre = true;
			++numNodos;
		}else{
			Nodo temp = iter->hermanoD;
			iter->hermanoD = new Nodo2(et);
			iter->hermanoD->hermanoD = temp;
			++numNodos;
		}
	}
}

void ArbolD::borrarHoja(Nodo nPorBorrar){
	if(hoja(nPorBorrar)){
	 Nodo p = this->padre(nPorBorrar);
	 Nodo iter = p->hijoMasI;
	 if(iter == nPorBorrar){
		 if(iter->stePadre == true){
			 p->hijoMasI = 0;
			 --numNodos;
		 }else{
			 Nodo temp = nPorBorrar->hermanoD;
			 p->hijoMasI = temp;
			 nPorBorrar->hermanoD = 0;
			 --numNodos;
		 }
	 }else{
		 while(iter->hermanoD != nPorBorrar){
			iter = iter->hermanoD;
		 }
		 if(iter->hermanoD->stePadre){
			 iter->hermanoD = p;
			 iter->stePadre = true;
			 --numNodos;
		 }else{
			 iter->hermanoD = iter->hermanoD->hermanoD;
			 --numNodos;
		 }
		}
	}
}
