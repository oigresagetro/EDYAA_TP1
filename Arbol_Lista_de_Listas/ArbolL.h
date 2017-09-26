#ifndef _ARBOLL
#define _ARBOLL
#include <iostream>
typedef int Elemento;
using namespace std;

class ArbolL{
	class ListaP;
	class SubLista;
	class NodoP;
	class NodoSub;
	private:
		ListaP * principal;
		class ListaP{
			public:
				NodoP * primero;
				NodoP * ultimo;
				int longitud;

				class NodoP{
					public:
						Elemento elemento;
						NodoP * siguiente;
						SubLista * sub;
						NodoP(Elemento);
						~NodoP();
				};

				ListaP();
				~ListaP();
				void insertar(Elemento /*,Posicion*/);//USAR ITERADOR??
				void agrAlFinal(NodoP*);
				void borrar(NodoP*);
				void modificar(NodoP*, Elemento);
				NodoP * primera();
				NodoP * ultima();
				NodoP * siguiente();
				Elemento recuperar(NodoP*);
		};

		class SubLista{
			public:
				NodoSub * primero;
				NodoSub * ultimo;
				int longitud;

				class NodoSub{
					public:
						NodoSub * siguiente;
						NodoP * nodo;//Al que corresponde en lista principal
						NodoSub();
						~NodoSub();
				};

				SubLista();
				~SubLista();
				void insertar(Elemento /*,Posicion*/);//USAR ITERADOR??
				void agrAlFinal(NodoSub*);
				void borrar(NodoSub*);
				void modificar(NodoSub*, Elemento);
				NodoSub * primera();
				NodoSub * ultima();
				NodoSub * siguiente();
				Elemento recuperar(NodoSub*);
		};
	public:
		ArbolL();
		~ArbolL();
		void vaciar();
		bool vacia();
		NodoP raiz();
		NodoP hijoMasIzq(NodoP);
		NodoP hermanoDer(NodoP);
		NodoP padre(NodoP);
		bool hoja(NodoP);
		char etiqueta(NodoP);
		int gnumNodos();
		int numHijos(NodoP);
		void modificarEtiq(NodoP, char);
		void agregarHijo(NodoP, int, char);
		void borrarHoja(NodoP);//Cual tipo de nodo es
		void ponerRaiz(char);
};
#endif