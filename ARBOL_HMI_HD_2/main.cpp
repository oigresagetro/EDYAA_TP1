#include "Nodo2.h"
#include "ArbolD.h"
#include <iostream>
using namespace std;

int main(){
      ArbolD arbol;
      arbol.ponerRaiz('J');
      Nodo2 * raiz = arbol.raiz();
      cout<< arbol.etiqueta(raiz)<<endl;
      arbol.agregarHijo(raiz,1,'P');
      cout<<9<<endl;
      Nodo2 * HMI = arbol.hijoMasIzq(raiz);
      cout<<11<<endl;
      cout << arbol.etiqueta(HMI)<<endl;
      cout <<12<<endl;
      cout<<arbol.gnumNodos()<<endl;
      return 0;
}
