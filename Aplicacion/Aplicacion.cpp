#include "Aplicacion.h"

#include <iostream>
using namespace std;
void Aplicacion::ejecutar(){
    int eleccion = -1;
  do{   cout<< "Eliga el modelo que quiere utilizar"<<endl
        << "1.Arbol"<<endl
        << "2.Cola"<<endl;
    cin >> eleccion;
    switch (eleccion){
      case 1:
            this->eleccionArbol();
      break;
      case 2:
            this->eleccionCola();
      break;
    }
  }while(eleccion!=0);
}

void Aplicacion::eleccionArbol(){
       Arbol arbol;
       int eleccion;
     do{
       cout <<endl<< "Eliga el operador de arbol que desea utilizar."<<endl
       << "1.ponerRaiz" <<endl
       << "2.raiz"<<endl
       << "3.hijoMasIzq"<<endl
       << "4.agregarHijo"<<endl
       << "5.vaciar"<<endl
       << "6.vacia"<<endl
       << "7.borrarHoja"<<endl
       << "8.hermanoDererecho"<<endl
       << "9.padre"<<endl
       << "10.hoja"<<endl
       << "11.etiqueta"<<endl
       << "12.numNodos"<<endl
       << "13.numHijos"<<endl
       << "14.modificarEtiq"<<endl;

       cin>>eleccion;

       switch (eleccion) {
         case 1:
               char et;
               cin>>et;
               arbol.ponerRaiz(et);
         break;
         case 2:
               cout << arbol.etiqueta(arbol.raiz())<<endl;
         break;
         case 3:
               char nodo;
               cin>>nodo;
               cout<< arbol.etiqueta(arbol.hijoMasIzq(nodo))<<endl;
         break;
         case 4:

         break;
         case 5:
               arbol.vaciar();
         break;
         case 6:
               if(arbol.vacia()){
                 cout<< "Arbol vacio"<<endl;
               }else{
                   cout<< "Arbol no vacio."<<endl;
               }
         break;
         case 7:

         break;
         case 8:

         break;
         case 9:

         break;
         case 10:

         break;
         case 11:

         break;
         case 12:
               cout<< arbol.gnumNodos()<<endl;
         break;
         case 13:

         break;
         case 14:

         break;
     }
   }while(eleccion!=0);
   delete arbol;
}
void Aplicacion::eleccionCola(){
    Cola cola;
    int eleccion;
    do{
        cout<<endl<<"Eliga el operador de Cola que desea utilizar."<<endl
            << "1.Vacia."<<endl
            << "2.Vaciar."<<endl
            << "3.Encolar."<<endl
            << "4.Desencolar"<<endl
            << "5.Frente."<<endl
            << "6.NumElem."<<endl;

        cin >> eleccion;

        switch (eleccion){
          case 1:
                if(cola.vacia()){
                  cout<<"La cola esta vacia."<<endl;
                }else{
                  cout<<"La cola no esta vacia."<<endl;
                }
          break;
          case 2:
                cola.vaciar();
                cout<<"Acaba de vaciar la cola."<<endl;
          break;
          case 3:
                int elemento;
                cout<<"Puede encolar numeros enteros. Digitelo acontinuacion."<<endl;
                cin>>elemento;
                cola.encolar(elemento);
          break;
          case 4:
                cola.desencolar();
                cout<< "Acaba de desencolar."<<endl;
          break;
          case 5:
                cout<<cola.frente()<<endl;
          break;
          case 6:
                cout<<cola.numElem()<<endl;
          break;
      }
    }while(eleccion!=0);
}
