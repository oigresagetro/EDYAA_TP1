#include "ArbolC.h"

ArbolC::ArbolC(){
	sRaiz = 0;
	numNodos = 0;
}

ArbolC::~ArbolC(){ //hay que arreglar esto
	/*
	if(!this->vacia()){
		this->posOrdenB(sRaiz);
	}*/
}

void ArbolC::vaciar(){
	delete this;
	sRaiz = 0;
}

void ArbolC::posOrdenB(Nodo n){
	Nodo nh = this->hijoMasIzq(n);
	while(nh!=0){
		this->posOrdenB(nh);
		nh = this->hermanoDer(nh);
	}
	delete n;
}

bool ArbolC::vacia(){
	return sRaiz == 0;
}

void ArbolC::ponerRaiz(Etiqueta et){
	sRaiz = new Caja(et);
	++numNodos;
}


Nodo ArbolC::raiz(){
	return sRaiz;
}

Nodo ArbolC::hijoMasIzq(Nodo nodo){
	return nodo->hijoMasI;
}

Nodo ArbolC::hermanoDer(Nodo nodo){
	return nodo->hermanoD;
}

Nodo ArbolC::padre(Nodo n){
	bool encontrado = false;
	Nodo p = 0;
	p = this->preOrdenR(this->raiz(),n,encontrado);
	return p;
}

bool ArbolC::hoja(Nodo nodo){
	return nodo->hijoMasI == 0;
}

Etiqueta ArbolC::etiqueta(Nodo nodo){
	return nodo->etiqueta;
}
int ArbolC::gnumNodos(){
	return numNodos;
}


int ArbolC::numHijos(Nodo nodo){
	int numHijos = 0;
	if(nodo->hijoMasI != 0){
		numHijos = 1;
		Nodo iter = nodo->hijoMasI->hermanoD;
		while(iter != 0){
			++numHijos;
			iter = iter->hermanoD;
		}
	}
	return numHijos;
}

void ArbolC::modificarEtiq(Nodo nodo, Etiqueta et){
	nodo->etiqueta = et;
}

void ArbolC::agregarHijo(Nodo padre, int i, Etiqueta et){
	//if(padre->hijoMasI != 0){
		if(i == 1){
			Nodo temp = padre->hijoMasI;
			Nodo nuevoHMI = new Caja(et);
			padre->hijoMasI = nuevoHMI;
			padre->hijoMasI->hermanoD = temp;
			++numNodos;
		}else{
			Nodo iter = padre->hijoMasI; // se coloca al hermano izq de donde se desea agregar
			for(int j = 1; j < i - 1 ; ++j ){
				iter = iter->hermanoD;
			}
			if(iter->hermanoD == 0){
				Nodo nuevoHD = new Caja(et);
				iter->hermanoD = nuevoHD;
				++numNodos;
			}else{
					Nodo nuevoHD = new Caja(et);
					Nodo temp = iter->hermanoD;
					iter->hermanoD = nuevoHD;
					nuevoHD->hermanoD = temp;
					++numNodos;
			}
		}
	}
//}
void ArbolC::borrarHoja(Nodo nodo){
	if(this->hoja(nodo)){
		bool borrado = false;
	 	Nodo padre = this->padre(nodo);
	 	Nodo iter = padre->hijoMasI;
	 	if(iter == nodo){
		 	Nodo temp = nodo->hermanoD;
			padre->hijoMasI = temp;
			//nodo->hermanoD = 0;
			--numNodos;
			//delete nodo;
	 	}else{
	 		while(iter!=0 && !borrado){
				iter = iter->hermanoD;
		 		if(iter == nodo && nodo == padre->hijoMasI->hermanoD){
			 		Nodo temp = iter->hermanoD;
			 		padre->hijoMasI->hermanoD = temp;
					nodo->hermanoD = 0;
					//delete nodo;
			 		borrado = true;
					--numNodos;
		 		}else{
					Nodo temp = iter;
					iter = iter->hermanoD;
			 		if(iter == nodo){
				 		temp->hermanoD = iter->hermanoD;
						nodo->hermanoD = 0;
						//delete nodo;
				 		borrado = true;
						--numNodos;
			 		}
		 		}
	 		}
 		}
 	}
}

Nodo ArbolC::preOrdenR(Nodo raiz, Nodo n, bool &encontrado){
	Nodo nh = this->hijoMasIzq(raiz);
	while(nh!=0 && !encontrado){
		if(nh!=n){
			this->preOrdenR(nh,n,encontrado);
			nh = this->hermanoDer(nh);
		}else{
			if(nh == n){
				encontrado = true;
				return raiz;
			}
		}
	}
	return 0;
}
