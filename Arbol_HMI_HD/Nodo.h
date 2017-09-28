#ifndef _Nodo
#define _Nodo
#include <iostream>
using namespace std;

struct Nodo{
	private:
		char etiqueta;

	public:
		Nodo * hijoMasI;
		Nodo * hermanoD;

		Nodo();
		Nodo(char);
		~Nodo();
		void setEtiqueta(char);
		char getEtiqueta();
		bool operator==(const Nodo&);
};
#endif
