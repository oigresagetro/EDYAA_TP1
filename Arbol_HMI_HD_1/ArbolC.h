#ifndef _ARBOLHMIHD
#define _ARBOLHMIHD
#define TAM 20
#include<iostream>
#include "Caja.h"

typedef Caja* Nodo;
typedef char Etiqueta;

using namespace std;

class ArbolC{
	private:
		Nodo sRaiz; //señalador al HMI
		int numNodos;
	public:
		ArbolC();
		~ArbolC();
		Nodo preOrdenR(Nodo, Nodo, bool&);
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
