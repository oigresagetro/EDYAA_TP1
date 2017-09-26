#include "ArbolA.h"

ArbolA::ArbolA(){
	ultimo = -1;
	numNodos = 0;
}

ArbolA::~ArbolA(){
}

void ArbolA::vaciar(){
	ultimo = -1;
}

bool ArbolA::vacia(){
	return ultimo == -1;
}

void ArbolA::ponerRaiz(char et){
	ultimo++;
	etiquetas[ultimo] = et;
	nodo[ultimo] = ultimo;
	numNodos++;
}


Nodo ArbolA::raiz(){
	return nodo[0];
}
 
Nodo ArbolA::hijoMasIzq(Nodo n){
	int iter = 0;
	bool encontrado = false;
	Nodo hmi = 0;
	while(!encontrado && iter < ultimo){
		if(nodoPadre[iter]==n){
			hmi = iter;
			encontrado = true;
		}
	}
	return nodo[hmi];
}

Nodo ArbolA::hermanoDer(Nodo n){
	int iter = 0;
	bool encontrado = false;
	Nodo hd = -1;
	while(iter < ultimo-1){
		if(nodoPadre[iter]==n && nodoPadre[iter+1]==nodoPadre[iter]){
			hd = iter+1;
			encontrado = true;
		}
	}
	return nodo[hd];
}

Nodo ArbolA::padre(Nodo n){
	return nodoPadre[n];
}

bool ArbolA::hoja(Nodo n){
	bool esHoja = false;
	for(int iter = 0; !esHoja && iter < ultimo; ++iter){
		if(nodoPadre[iter]==n){
			esHoja=true;
		}
	}
	return esHoja;
}

char ArbolA::etiqueta(Nodo n){
	return etiquetas[n];
}

int ArbolA::gnumNodos(){
	return numNodos;
}


int ArbolA::numHijos(Nodo n){
	int numHijos = 0;
	for(int iter = 0; iter <= ultimo; ++iter){
		if(nodoPadre[iter]==n){
			numHijos++;
		}
	}
	return numHijos;
}

void ArbolA::modificarEtiq(Nodo n, char c){
	etiquetas[n] = c;
}

// Tal que los hijos son agregados en orden
void ArbolA::agregarHijo(Nodo padre, int i, char c){
	//int iter = padre + i;
	if(ultimo == padre){
		etiquetas[ultimo + i] = c;
		nodoPadre[ultimo + i] = padre;
		nodo[ultimo + i] = ultimo + i;
	}else{
		etiquetas[ultimo + i + padre] = c;
		nodoPadre[ultimo + i + padre] = padre;
		nodo[ultimo + i + padre] = ultimo + i + padre;

	}
	numNodos++;
	ultimo++;
}


 void ArbolA::borrarHoja(Nodo n){
	 int iter = n;
	 while(iter < ultimo){
		 etiquetas[iter] = etiquetas[iter+1];
		 nodoPadre[iter] = nodoPadre[iter+1];
		 iter++;
	 }
	 ultimo--;
 }
