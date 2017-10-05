#ifndef CAJASUB
#define CAJASUB
#include "CajaP.h"
class CajaSub{
	private:
		CajaP * principal;//Al que corresponde en lista principal
	public:
		CajaSub * siguiente;
		CajaSub(CajaP*);
		~CajaSub();
		CajaP* getPrincipal();
		CajaSub* getSiguiente();
		void setSiguiente(CajaSub*);
};	
#endif