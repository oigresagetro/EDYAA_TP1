#ifndef CAJAP
#define CAJAP
typedef char Etiqueta;

class SubLista;
class CajaP{
	private:
		Etiqueta etiq;
	public:
		CajaP * siguiente;
		SubLista * sub;
		CajaP(Etiqueta);
		~CajaP();
		SubLista * getSub();
		void setSub(CajaP*);
		CajaP * getSiguiente();
		void setSiguiente(CajaP*);
		Etiqueta getEtiqueta();
		void setEtiqueta(Etiqueta e);
};	
#endif