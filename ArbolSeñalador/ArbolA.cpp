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

void ArbolA::ponerRaiz(Etiqueta et){
	ultimo++;
	etiquetas[ultimo] = et;
	numNodos++;
}


Nodo ArbolA::raiz(){
	return 0;
}

Nodo ArbolA::hijoMasIzq(Nodo n){
	int iter = 0;
	bool encontrado = false;
	Nodo hmi = -1;
	while(!encontrado && iter <= ultimo){
		if(nodoPadre[iter]==n){
			hmi = iter;
			encontrado = true;
		}
		iter++;
	}
	return hmi;
}

Nodo ArbolA::hermanoDer(Nodo n){
	int iter = n+1;
	bool encontrado = false;
	Nodo hd = -1;
	while(iter <= ultimo && !encontrado){
		if(nodoPadre[n] == nodoPadre[iter]){
			hd = iter;
			encontrado = true;
		}
		iter++;
	}
	return hd;
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

Etiqueta ArbolA::etiqueta(Nodo n){
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

void ArbolA::modificarEtiq(Nodo n, Etiqueta c){
	etiquetas[n] = c;
}


void ArbolA::agregarHijo(Nodo padre, int i, Etiqueta c){
	int inicio = this->hijoMasIzq(padre) + (i-1);
	//cout << "inicio: "<< inicio << endl;
	if(inicio != -1){
		for(int j = ultimo; j >= inicio; j--){
			etiquetas[j+1] = etiquetas[j];
			if(nodoPadre[j] < inicio){
				nodoPadre[j+1] = nodoPadre[j];
			}else{
				nodoPadre[j+1] = nodoPadre[j] + 1;
			}
		}

		etiquetas[inicio] = c;
		nodoPadre[inicio] = padre;
		//cout << "agrega al nodo " << inicio << " el padre " << padre << endl;
	}else{
		etiquetas[ultimo + i] = c;
		nodoPadre[ultimo + i] = padre;
		//cout << "agrega al nodo " << ultimo+i << " el padre " << padre << endl;
	}
	++numNodos;
	++ultimo;
}

 void ArbolA::borrarHoja(Nodo n){
	 int iter = n;
	 while(iter < ultimo){
		 etiquetas[iter] = etiquetas[iter+1];
		 if(n < nodoPadre[iter+1]){
			nodoPadre[iter] = nodoPadre[iter+1] - 1;
		 }else{
			 nodoPadre[iter] = nodoPadre[iter+1];
		 }
		 ++iter;
	 }
	 --ultimo;
	 --numNodos;
 }
