#ifndef _COLA
#define _COLA
#include<iostream>
#define SIZE 10
using namespace std;

class Cola{
	private:
		int arreglo[SIZE];
		int primero;
		int ultimo;
		int numeroElem;
	public:
		Cola();
		~Cola();
		bool vacia();
		void vaciar();
		void encolar(int);
		void desencolar();
		int frente();
    int numElem();
};

#endif
