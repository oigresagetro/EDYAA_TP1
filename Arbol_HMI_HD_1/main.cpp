#include "Caja.h"
#include "ArbolC.h"
#include <iostream>
using namespace std;

typedef Caja* Nodo;

int main(){
  ArbolC arbol;
	arbol.ponerRaiz('a');
	Nodo raiz = arbol.raiz();
	arbol.agregarHijo(raiz,1,'b');
	arbol.agregarHijo(raiz,2,'c');
	arbol.agregarHijo(raiz,3,'d');
  Nodo hmi = arbol.hijoMasIzq(raiz);
  cout<<arbol.hoja(arbol.hermanoDer(hmi))<<endl;
  arbol.borrarHoja(hmi);
  cout<<arbol.etiqueta(arbol.hijoMasIzq(raiz))<<endl;
  cout<<arbol.etiqueta(arbol.hermanoDer(hmi))<<endl;
	return 0;
}
