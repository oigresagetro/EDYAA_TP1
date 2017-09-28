#include "ArbolC.h"

ArbolC::ArbolC(){
	sHijoMI = 0;
	numNodos = 0;
}

ArbolC::~ArbolC(){
	if(sHijoMI){
		delete sHijoMI;
	}
}

void ArbolC::vaciar(){
	if(!vacio()){
		sHijoMI = 0;
	}
}

bool ArbolC::vacio(){
	return sHijoMI == 0;
}

void ArbolC::ponerRaiz(char et){
	Nodo * raiz = new Nodo(et);
	sHijoMI->hijoMasI = raiz;
}


Nodo * ArbolC::raiz(){
	return sHijoMI->hijoMasI;
}

Nodo * ArbolC::hijoMasIzq(Nodo * nodo){
	return nodo->hijoMasI;
}

Nodo * ArbolC::hermanoDer(Nodo * nodo){
	return nodo->hermanoD;
}

Nodo * ArbolC::padre(Nodo * numNodos){
	bool encontrado = false;
	Nodo * padre = 0;
	this->preOrdenR(this->raiz(),n,&encontrado,padre);
	if(encontrado){
		return padre;
	}else{
		return 0;
	}
}

bool ArbolC::hoja(Nodo * nodo){
	return nodo->hijoMasI == 0;
}

char ArbolC::etiqueta(Nodo * nodo){
	return nodo->getEtiqueta();
}
int ArbolC::gnumNodos(){
	return numNodos;
}


int ArbolC::numHijos(Nodo * nodo){
	int numHijos = 0;
	if(nodo->hijoMasI != 0){
		numHijos = 1;
		Nodo * iter = nodo->hijoMasI->hermanoD;
		while(iter != 0){
			++numHijos;
			iter = iter->hermanoD;
		}
	}
	return numHijos;
}

void ArbolC::modificarEtiq(Nodo * nodo, char et){
	nodo->setEtiqueta(et);
}

void ArbolC::agregarHijo(Nodo * padre, int i, char et){
	if(padre->hijoMasI != 0){
		if(i == 1){
			Nodo * temp = padre->hijoMasI;
			Nodo * nuevoHMI = new Nodo(et);
			padre->hijoMasI = nuevoHMI;
			padre->hijoMasI->hermanoD = temp;
			++numNodos;
		}else{
			Nodo * iter = padre->hijoMasI; // se coloca al hermano izq de donde se desea agregar
			for(int j = 1; j < i - 1 ; ++j ){
				iter = iter->hermanoD;
			}
			if(iter == 0){
				Nodo * nuevoHD = new Nodo(et);
				padre->hijoMasI->hermanoD = nuevoHD;
				++numNodos;
			}else{
				Nodo * nuevoHD = new Nodo(et);
				padre->hijoMasI->hermanoD = nuevoHD;
				nuevoHD->hermanoD = iter;
				++numNodos;
			}
		}
	}
}
void ArbolC::borrarHoja(Nodo * nodo){
	if(hoja(nodo)){
		bool borrado = false;
	 	Nodo * padre = this->padre(nodo);
	 	Nodo * iter = padre->hijoMasI;
	 	if(iter == nodo){
		 	Nodo * temp = nodo->hermanoD;
			padre->hijoMasI = temp;
			nodo->hermanoD = 0;
			delete nodo;
	 	}else{
	 		while(iter!=0 && !borrado){
				iter = iter->hermanoD;
		 		if(iter == nodo && nodo->hermanoD != 0 && nodo == padre->hijoMasI->hermanoD){
			 		Nodo * temp = iter->hermanoD;
			 		padre->hijoMasI->hermanoD = temp;
					nodo->hermanoD = 0;
					delete nodo;
			 		borrado = true;
		 		}else{
					Nodo * temp = iter;
					iter = iter->hermanoD;
			 		if(iter == nodo){
				 			temp->hermanoD = iter->hermanoD;
							nodo->hermanoD = 0;
							delete nodo;
				 			borrado = true;
			 		}
		 		}
	 		}
 		}
 	}
}

  void ArbolC::preOrdenR(Nodo * raiz,Nodo * n, bool &encontrado, Nodo * padre){
	 Nodo * nh = this->hijoMasIzq(rec);
	 //padre = rec;
	 while(nh!=NULL && !encontrado){
		 if(nh == n){
			 encontrado = true;
			 padre = raiz;
		 }else{
			 preOrdenR(nh,n,encontrado,padre);
			 nh = this->hermanoDer(nh);
		 }
	 }
 }
