#ifndef _Nodo3
#define _Nodo3
#include <iostream>
using namespace std;

struct Nodo3{
	public:
		char c;
		Nodo3 * hijoMasI;
		Nodo3 * hermanoD; // o padre;
		Nodo3 * ptrPadre;
		Nodo3 * hermanoI;
		Nodo3(char);
		~Nodo3();
		//bool operator==(const Nodo2&);
};
#endif