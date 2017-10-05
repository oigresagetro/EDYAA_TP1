#include "ArbolA.h"
#include <iostream>
typedef int Nodo;
using namespace std;

int main(){
	ArbolA arbol;
	arbol.ponerRaiz('a');
	Nodo raiz = arbol.raiz();
	arbol.agregarHijo(raiz,1,'b');
	arbol.agregarHijo(raiz,2,'c');
	arbol.agregarHijo(raiz,3,'d');
	cout<<arbol.gnumNodos()<<endl;
	Nodo hmi = arbol.hijoMasIzq(raiz);
	cout << arbol.etiqueta(arbol.padre(hmi))<<endl;

	return 0;
}
