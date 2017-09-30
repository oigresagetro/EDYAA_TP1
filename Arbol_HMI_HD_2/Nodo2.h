#ifndef _Nodo2
#define _Nodo2
#include <iostream>
using namespace std;

class Nodo2{
	private:
		char etiqueta;
	public:
		Nodo2 * hijoMasI;
		Nodo2 * hermanoD; // o padre;
		bool stePadre;
		Nodo2(char);
		~Nodo2();
		void setEtiqueta(char);
		char getEtiqueta();
		//bool operator==(const Nodo2&);
};
#endif
