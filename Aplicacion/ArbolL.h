#ifndef _ARBOLL
#define _ARBOLL
#include "ListaP.h"
#include "CajaP.h"
#include "SubLista.h"
#include "CajaSub.h"
typedef char Etiqueta;
typedef CajaP* Nodo;

class ArbolL{
	private:
		ListaP * listaP;
	public:
		ArbolL();
		~ArbolL();
		void borrado(Nodo);
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