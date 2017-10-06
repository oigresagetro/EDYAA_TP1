#ifndef SUBLISTA
#define SUBLISTA
#include "CajaSub.h"
#include "CajaP.h"

class SubLista{
	private:
		//class CajaSub;
		//class CajaP;
		CajaSub * primero;
		CajaSub * ultimo;
		int longitud;
	public:
		SubLista();
		~SubLista();
		SubLista(CajaP*);
		void insertar(int, CajaP*);
		void agrAlFinal(CajaP*);
		void agrAlInicio(CajaP*);
		void borrar(CajaSub*);
		CajaSub * primera();
		CajaSub * ultima();
		CajaSub * siguiente(CajaSub*);
		CajaP * recuperar(CajaSub*);
		int getLongitud();
};
#endif