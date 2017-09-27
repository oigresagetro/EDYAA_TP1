#include "ArbolC.h"

ArbolC::ArbolC(){
	sHijoMI = NULL;
	numNodos = 0;
}

ArbolC::~ArbolC(){
	if(sHijoMI){
		delete sHijoMI;
	}
}

void ArbolC::vaciar(){
	sHijoMI = 0;
}

bool ArbolC::vacia(){
	return sHijoMI == 0;
}

void ArbolC::ponerRaiz(char et){
	Nodo * raiz = new Nodo(char);
	sHijoMI->hijoMasI = raiz;
}


Nodo * ArbolC::raiz(){
	return sHijoMI->hijoMasI;
}
 
Nodo * ArbolC::hijoMasIzq(Nodo * n){
	return n->hijoMasI;
}

Nodo * ArbolC::hermanoDer(Nodo * n){
	return (n->hermanoDer);
}

Nodo * ArbolC::padre(Nodo * n){
	bool encontrado = false;
	Nodo * padre = 0;
	this->preOrdenR(this->raiz(),n,&encontrado,padre);
	if(encontrado){
		return padre;
	}else{
		return 0;
	}
}

bool ArbolC::hoja(Nodo * n){
	return n->hijoMasI == 0;
}

char ArbolC::etiqueta(Nodo * n){
	return *(n->c);
}
int ArbolC::gnumNodos(){
	return numNodos;
}


int ArbolC::numHijos(Nodo n){
	int numHijos = 0;
	if(padre->hijoMasI != NULL){
		numHijos = 1;
		Nodo * iter = padre->hijoMasI->hermanoD;
		while(iter != NULL){
			numHijos++;
			iter = iter->hermanoD;
		}
	}
	return numHijos;
}

void ArbolC::modificarEtiq(Nodo n, char et){
	n->c = et;
}

void ArbolC::agregarHijo(Nodo * padre, int i, char c){
	if(padre->hijoMasI != NULL){
		if(i == 1){
			Nodo * temp = padre->hijoMasI;
			padre->hijoMasI = new Nodo(c);
			padre->hijoMasI->hermanoD = temp;
		}else{
			Nodo * iter = padre->hijoMasI; // se coloca al hermano izq de donde se desea agregar
			for(int j = 1; j < i - 1 ; ++j ){
				iter = iter->hermanoD;
			}
			Nodo * temp = iter->hermanoD;
			iter->hermanoD = new Nodo(c);
			iter->hermanoD->hermanoD = temp;
		}
	}else{
		padre->hijoMasI = new Nodo(c);
	}
}



 void ArbolC::borrarHoja(Nodo n){
	 Nodo * p = this->padre(nPorBorrar);
	 bool borrado = 0;
	 Nodo * iter = p->hijoMasI;
	 while(iter!=NULL && !borrado){
		 if(p->hijoMasI == nPorBorrar){
			 Nodo * temp = p->hijoMasI->hermanoD;
			 p->hijoMasI = temp;
			 borrado = true;
		 }else{
			 if(iter->hermanoD == nPorBorrar){
				 iter->hermanoD = iter->hermanoD->hermanoD; 
				 borrado = true;
			 }
			 iter = iter->der;
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