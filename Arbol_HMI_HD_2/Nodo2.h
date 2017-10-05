#ifndef _Nodo2
#define _Nodo2
#include <iostream>
using namespace std;

struct Nodo2{
		char etiqueta;
		Nodo2 * hijoMasI;
		Nodo2 * hermanoD; // o padre;
		bool stePadre;
		Nodo2(char);
		~Nodo2();
};
#endif
