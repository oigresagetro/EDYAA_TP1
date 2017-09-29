#include "Nodo.h"
#include "ArbolC.h"
#include <iostream>
using namespace std;

int main(){
      ArbolC arbol;
      arbol.ponerRaiz('S');
      Nodo * raiz = arbol.raiz();
      /*
      //cout<< arbol.etiqueta(raiz)<<endl;
      arbol.agregarHijo(raiz,1,'P');
      Nodo * hijo = arbol.hijoMasIzq(raiz);
      //cout << arbol.etiqueta(hijo)<<endl;
      arbol.agregarHijo(raiz,2,'Q');
      //Nodo * hd = arbol.hermanoDer(hijo);
      //cout<< arbol.etiqueta(hd)<<endl;
      arbol.agregarHijo(raiz,3,'R');
      //Nodo * hd2 = arbol.hermanoDer(hd);
      //cout<< arbol.etiqueta(hd2)<<endl;
      arbol.agregarHijo(raiz,2,'T');
      Nodo * hermanoDer = arbol.hermanoDer(hijo);
      for(int i=1; i<4; ++i){
        cout<< arbol.etiqueta(hermanoDer)<<endl;
        hermanoDer = arbol.hermanoDer(hermanoDer);
      }
      */
      /*
      arbol.agregarHijo(raiz,1,'P');
      Nodo * HMI = arbol.hijoMasIzq(raiz);
      cout<< arbol.etiqueta(HMI)<<endl;
      cout<<arbol.hoja(HMI)<<endl;
      cout<<arbol.gnumNodos()<<endl;
      */

      arbol.agregarHijo(raiz,1,'P');
      Nodo * HMI = arbol.hijoMasIzq(raiz);
      arbol.agregarHijo(raiz,2,'Q');
      arbol.agregarHijo(raiz,2,'E');
      cout<<arbol.numHijos(raiz)<<endl;
      //arbol.modificarEtiq(HMI,'R');
      cout<<arbol.etiqueta(HMI)<<endl;


      return 0;
}
