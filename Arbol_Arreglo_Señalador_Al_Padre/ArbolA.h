#ifndef _ARBOLSENYA
#define _ARBOLSENYA
#define TAM 20
#include<iostream>

typedef int Nodo;

using namespace std;

class ArbolA{
	private:
		char etiquetas[TAM];
		Nodo nodoPadre[TAM];
		Nodo nodo[TAM];
		int ultimo;
		int numNodos;
	public:
		ArbolA();
		~ArbolA();
		void vaciar();
		bool vacia();
		Nodo raiz();
		Nodo hijoMasIzq(Nodo);
		Nodo hermanoDer(Nodo);
		Nodo padre(Nodo);
		bool hoja(Nodo);
		char etiqueta(Nodo);
		int gnumNodos();
		int numHijos(Nodo);
		void modificarEtiq(Nodo, char);
		void agregarHijo(Nodo, int, char);
		void borrarHoja(Nodo);
		void ponerRaiz(char);
};

#endif