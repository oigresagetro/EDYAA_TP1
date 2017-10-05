#include "ArbolL.h"
#include <iostream>
using namespace std;
int main(){
	ArbolL arbol;
	arbol.ponerRaiz('a');
	CajaP * raiz = arbol.raiz();
	cout << "Es hoja: " <<  arbol.esHoja(raiz) << endl;
	arbol.modificarEtiq(raiz, 'E');
	cout << arbol.etiqueta(raiz) << endl;
	arbol.agregarHijo(raiz, 'b', 0);//agrega b como primer hijo de a
	cout << arbol.etiqueta(arbol.hijoMasIzq(raiz)) << endl;
	CajaP* b = arbol.hijoMasIzq(raiz);
	arbol.agregarHijo(raiz, 'c', 1); //Agrega c como segundo hijo de a
	CajaP* c = arbol.hermanoDer(b);
	cout << arbol.etiqueta(c) << endl;
	arbol.agregarHijo(b, 'd', 0);//Agrega d como primer hijo de b
	cout << arbol.etiqueta(arbol.hijoMasIzq(b)) << endl;
	cout << "Arbol vacio?: " << arbol.vacia() << endl;
	cout << "Cantidad de nodos: " << arbol.numNodos() << endl;
	cout << "Num hijos de raiz: " <<  arbol.numHijos(raiz) << endl;
	cout << "Num hijos de b: " <<  arbol.numHijos(b) << endl;
	return 0;
}