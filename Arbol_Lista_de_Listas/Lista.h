#ifndef _LISTAAUX
#define _LISTAAUX
#include <iostream>
using namespace std;

typedef int Elemento;
class Lista{
	class Nodo;
	private:
		Nodo * primero;
		Nodo * ultimo;
		int longitud;

		class Nodo{
			public:
				Elemento elemento;
				Nodo * siguiente;
				Nodo(Elemento);
				~Nodo();
		};

	public:
		Lista();
		~Lista();
		void insertar(Elemento);//USAR ITERADOR??
		void agrAlFinal(Nodo*);
		void borrar(Nodo*);
		void modificar(Nodo*, Elemento);
		Nodo * primera();
		Nodo * ultima();
		Nodo * siguiente();
		Elemento recuperar(Nodo);

};

#endif