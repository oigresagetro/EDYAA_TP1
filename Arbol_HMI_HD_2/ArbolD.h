#ifndef _ARBOLHMIHDULTIMOALPADRE
#define _ARBOLHMIHDULTIMOALPADRE
#define TAM 20
#include<iostream>
#include "Nodo2.h"

typedef Nodo2* Nodo;
typedef char Etiqueta; 

using namespace std;

class ArbolD{
	private:
		Nodo sRaiz;
		int numNodos;
	public:
		ArbolD();
		~ArbolD();
		void posOrdenB(Nodo);
		void vaciar();
		bool vacia();
		Nodo raiz();
		Nodo hijoMasIzq(Nodo);
		Nodo hermanoDer(Nodo);
		Nodo padre(Nodo);
		bool hoja(Nodo);
		Etiqueta etiqueta(Nodo);
		int gnumNodos();
		int numHijos(Nodo);
		void modificarEtiq(Nodo, Etiqueta);
		void agregarHijo(Nodo, int, Etiqueta);
		void borrarHoja(Nodo);
		void ponerRaiz(Etiqueta);
};

#endif