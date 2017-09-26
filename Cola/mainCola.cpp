#include <iostream>
#include "Cola.h"
#include <iostream>
using namespace std;

int main(){
//	Cola cola;
//	cola.encolar(3);
//	cola.encolar(53);
//	cola.encolar(34);
//	cola.encolar(4);
//	cout << cola.frente() << endl;
//	cola.desencolar();
//	cout << cola.frente() << endl;
//  cola.desencolar();
//  cout<< cola.frente()<<endl;
//  cout<< cola.numElem() << endl;
    
//    Cola cola;
//    cola.desencolar();
//    cola.encolar(10);
//    cout<< cola.frente()<<endl;
//    cout<< cola.Vacia()<<endl;
//    cola.desencolar();
//    cout<< cola.vacia()<<endl;
    
    Cola cola;
    for(int i=1; i<TAM; ++i){
        cola.encolar(i);
        cout<<cola.frente()<<endl;
        cola.desencolar();
    }
	return 0;
}
