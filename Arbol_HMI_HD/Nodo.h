#ifndef _Nodo
#define _Nodo
#include <iostream>
using namespace std;

struct Nodo{
	public:
		char c;
		Nodo * hijoMasI;
		Nodo * hermanoD;
		Nodo(char);
		~Nodo();
		//bool operator==(const Nodo&);
};
#endif