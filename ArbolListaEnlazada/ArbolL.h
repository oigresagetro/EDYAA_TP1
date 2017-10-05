#ifndef _ARBOLL
#define _ARBOLL
#include "ListaP.h"
#include "CajaP.h"
#include "SubLista.h"
#include "CajaSub.h"
typedef char Etiqueta;
typedef CajaP Nodo;

class ArbolL{
	private:
		ListaP * listaP;
	public:
		ArbolL();
		~ArbolL();
		void borrado(CajaP*);
		void vaciar();
		bool vacia();
		CajaP * raiz();
		CajaP * hijoMasIzq(CajaP*);
		CajaP * hermanoDer(CajaP*);
		CajaP * padre(CajaP*);
		bool esHoja(CajaP*);
		Etiqueta etiqueta(CajaP*);
		int numNodos();
		int numHijos(CajaP*);
		void modificarEtiq(CajaP*, Etiqueta);
		void agregarHijo(CajaP*, Etiqueta, int);
		void borrarHoja(CajaP*);//Cual tipo de nodo es
		void ponerRaiz(Etiqueta);
};
#endif