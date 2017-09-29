#ifndef _ARBOLHMIHDULTIMOALPADRE
#define _ARBOLHMIHDULTIMOALPADRE
#define TAM 20
#include<iostream>
#include "Nodo2.h"

using namespace std;

class ArbolD{
	private:
		Nodo2 * sHijoMI;
		int numNodos;
	public:
		ArbolD();
		~ArbolD();
		void preOrdenR(Nodo2 *);
		void vaciar();
		bool vacia();
		Nodo2 *raiz();
		Nodo2 *hijoMasIzq(Nodo2*);
		Nodo2 *hermanoDer(Nodo2*);
		Nodo2 *padre(Nodo2*);
		bool hoja(Nodo2*);
		char etiqueta(Nodo2*);
		int gnumNodos();
		int numHijos(Nodo2*);
		void modificarEtiq(Nodo2*, char);
		void agregarHijo(Nodo2*, int, char);
		void borrarHoja(Nodo2*);
		void ponerRaiz(char);
};

#endif