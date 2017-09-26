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
	return sHijo == 0;
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

Nodo ArbolC::padre(Nodo * n){
	if(sHijoMI->hijoMasI == ){
		
	}else{
		
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
	int iter = 0;
	int numHijos = 0;
	for(iter; iter < ultimo; ++iter){
		if(nodoPadre[iter]==n){
			numHijos++;
		}
	}
	return numHijos;
}

void ArbolC::modificarEtiq(Nodo n, char c){
	etiquetas[n-1] = c;
}

void ArbolC::agregarHijo(Nodo * padre, int i, char c){
	if(padre->hijoMasI != NULL){
		if(i == 1){
			Nodo * temp = padre->hijoMasI;
			padre->hijoMasI = new Nodo(c);
			padre->hijoMasI->hermanoDer = temp;
		}else{
			Nodo * temp = padre->hijoMasI; // esta donde se desea eliminar
			Nodo * iter = padre->hijoMasI; // esta un nodo antes del que se desea eliminar
			for(int j = 1; j < i ; ++j ){
				temp = temp->hermanoDer;
				if(2 >= j){
					iter = iter->hermanoDer;
				}
			}
			iter->hermanoDer = new Nodo(c); // No se si esto afectara la orignal o solo iter
			iter->hermanoDer->hermanoDer = temp;
		}
	}else{
		padre->hijoMasI = new Nodo(c);
	}
}



 void ArbolC::borrarHoja(Nodo n){
	 int iter = n-1;
	 while(iter < ultimo-1){
		 etiquetas[iter] = etiquetas[iter+1];
		 nodoPadre[iter] = nodoPadre[iter+1];
		 iter++;
	 }
	 ultimo--;
 }

 void ArbolC::preOrdenR(Nodo * n){
	 Nodo * nh = this->hijoMasIzq(n);
	 while(nh!=NULL){
		 preOrdenR(nh);
	 }
 }