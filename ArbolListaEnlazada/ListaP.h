#ifndef LISTAP
#define LISTAP
#include "CajaP.h"

class ListaP{
	private:
		CajaP * primero;
		CajaP * ultimo;
		int longitud;
	public:
		ListaP();
		ListaP(CajaP*);
		~ListaP();
		void insertar(Etiqueta, int);
		void agrAlFinal(Etiqueta);
		void agrAlInicio(Etiqueta);
		void borrar(CajaP*);
		void modificar(CajaP*, Etiqueta);
		CajaP * primera();
		CajaP * ultima();
		CajaP * siguiente(CajaP*);
		Etiqueta recuperar(CajaP*);
		int getLongitud();
};
#endif