#ifndef _ARBOLSENYA
#define _ARBOLSENYA
#define TAM 30
#include<iostream>

typedef int Nodo;
typedef char Etiqueta;

using namespace std;

class Arbol{
	private:
		Etiqueta etiquetas[TAM];
		Nodo nodoPadre[TAM];
		int ultimo;
		int numNodos;
	public:
		Arbol();
		~Arbol();
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
