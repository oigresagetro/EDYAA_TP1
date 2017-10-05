#ifndef _Caja
#define _Caja
#include <iostream>
using namespace std;

struct Caja{
	public:
		Caja * hijoMasI;
		Caja * hermanoD;
		char etiqueta;
		Caja();
		Caja(char);
		~Caja();
};
#endif
