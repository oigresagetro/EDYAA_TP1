#ifndef _ARBOLHMIHD4PUNTEROS
#define _ARBOLHMIHD4PUNTEROS
#define TAM 20
#include<iostream>
#include "Nodo3.h"

typedef Nodo3* Nodo;
typedef char Etiqueta;

using namespace std;

class ArbolE{
	private:
		Nodo sRaiz;
		int numNodos;
	public:
		ArbolE();
		~ArbolE();
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