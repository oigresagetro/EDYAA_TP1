#ifndef _ARBOLHMIHD
#define _ARBOLHMIHD
#define TAM 20
#include<iostream>
#include "Nodo.h"

using namespace std;

class ArbolC{
	private:
		Nodo * sHijoMI;
		int numNodos;
	public:
		ArbolC();
		~ArbolC();
		void preOrdenR(Nodo *);
		void vaciar();
		bool vacia();
		Nodo *raiz();
		Nodo *hijoMasIzq(Nodo*);
		Nodo *hermanoDer(Nodo*);
		Nodo *padre(Nodo*);
		bool hoja(Nodo*);
		char etiqueta(Nodo*);
		int gnumNodos();
		int numHijos(Nodo*);
		void modificarEtiq(Nodo*, char);
		void agregarHijo(Nodo*, int, char);
		void borrarHoja(Nodo*);
		void ponerRaiz(char);
};

#endif