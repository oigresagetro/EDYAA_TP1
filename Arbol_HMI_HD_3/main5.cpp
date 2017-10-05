#include "ArbolE.h"
#include <iostream>

typedef Nodo3 * Nodo;

using namespace std;
int main(){
	ArbolE arbol;
	arbol.ponerRaiz('a');
	Nodo raiz = arbol.raiz();
	arbol.agregarHijo(raiz,1,'b');
	arbol.agregarHijo(raiz,2,'c');
	arbol.agregarHijo(raiz,3,'d');
	Nodo hmi = arbol.hijoMasIzq(raiz);
	cout<<arbol.etiqueta(arbol.padre(hmi))<<endl;
	return 0;
}
