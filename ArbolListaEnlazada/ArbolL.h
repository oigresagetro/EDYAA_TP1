#ifndef _ARBOLL
#define _ARBOLL
#include <iostream>
typedef char Etiqueta;
using namespace std;

class ArbolL{
	class ListaP;
	class SubLista;
	class CajaP;
	class CajaSub;
	private:
		ListaP * listaP;
		class ListaP{
			public:
				class CajaP;
				CajaP * primero;
				CajaP * ultimo;
				int longitud;
				class CajaP{
					public:
						Etiqueta etiq;
						CajaP * siguiente;
						SubLista * sub;
						CajaP(Etiqueta);
						~CajaP();
				};
				ListaP();
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
		};
		class SubLista{
			public:
				class CajaP;
				class CajaSub;
				CajaSub * primero;
				CajaSub * ultimo;
				int longitud;
				class CajaSub{
					public:
						CajaSub * siguiente;
						CajaP * principal;//Al que corresponde en lista principal
						CajaSub(CajaP*);//ParametroL: caja en lista principal
						~CajaSub();
				};
				SubLista();
				~SubLista();
				void insertar(int, CajaP*);
				void agrAlFinal(CajaP*);
				void agrAlInicio(CajaP*);
				void borrar(CajaSub*);
				CajaSub * primera();
				CajaSub * ultima();
				CajaSub * siguiente(CajaSub*);
				CajaP * recuperar(CajaSub*);
		};
	public:
		ArbolL();
		~ArbolL();
		void vaciar();
		bool vacia();
		CajaP * raiz();
		CajaP * hijoMasIzq(CajaP*);
		CajaP * hermanoDer(CajaP*);
		CajaP * padre(CajaP*);
		bool esHoja(CajaP*);
		Etiqueta etiqueta(CajaP*);
		int gnumNodos();
		int numHijos(CajaP&);
		void modificarEtiq(CajaP*, Etiqueta);
		void agregarHijo(CajaP*, Etiqueta);
		void borrarHoja(CajaP*);//Cual tipo de nodo es
		void ponerRaiz(Etiqueta);
};
#endif