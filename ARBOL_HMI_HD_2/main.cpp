#include "Nodo2.h"
#include "ArbolD.h"
#include <iostream>
using namespace std;

int main(){
      ArbolD arbol;
      arbol.ponerRaiz('J');
      Nodo2 * raiz = arbol.raiz();
      //cout<< arbol.etiqueta(raiz)<<endl;
      arbol.agregarHijo(raiz,1,'P');
      arbol.agregarHijo(raiz,2,'Q');
      arbol.agregarHijo(raiz,3,'R');
      arbol.agregarHijo(raiz,2,'S');
      //cout << arbol.etiqueta(HMI)<<endl;
      Nodo2 * hn = arbol.hijoMasIzq(raiz);
      for(int i=1; i<5; ++i){
        cout<<arbol.etiqueta(hn)<<endl;
        hn = arbol.hermanoDer(hn);
      }
      cout<<arbol.gnumNodos()<<endl;
      return 0;
}
