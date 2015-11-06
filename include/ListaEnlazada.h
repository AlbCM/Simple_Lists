#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <Nodo.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class ListaEnlazada
{
    public:
        ListaEnlazada();
        virtual ~ListaEnlazada();
        Nodo* GetCabeza(){ return Cabeza;}
        void SetCabeza(Nodo* cab){ Cabeza = cab;}
        Nodo* Ultimo(){
            Nodo* temp = Cabeza;
            while(temp != NULL){
                if(temp->GetSiguiente()== NULL){
                    break;
                }else{
                    temp = temp->GetSiguiente();
                }
            }
            return temp;
        }
        int ContarNodos(){
            int contador = 0;
            Nodo* temp = Cabeza;
            while(temp != NULL){
                contador++;
                temp = temp->GetSiguiente();
            }
            return contador;
        }
        void Agregar(Nodo* nuevo){
            if(Cabeza == NULL){
                Cabeza = nuevo;
            }else{
                Ultimo()->SetSiguiente(nuevo);
            }
        }
        Nodo* Buscar(int cod){
            Nodo* temp = Cabeza;
            while(temp != NULL){
                if(temp->GetCodigo()== cod){
                    break;
                }else{
                    temp = temp->GetSiguiente();
                }
            }
            return temp;
        }
        void Eliminar(Nodo* nd){
            Nodo* Anterior;
            if(nd == Cabeza){
                Cabeza = Cabeza->GetSiguiente();
            }else{
                Anterior = Cabeza;
                while(Anterior->GetSiguiente()!= nd){
                    Anterior = Anterior->GetSiguiente();
                }
                Anterior->SetSiguiente(nd->GetSiguiente());
                }
                nd->SetSiguiente(NULL);
                delete nd;
        }
        double promedioGeneral(){
            int cantidad = 0;
            double Pgen=0,suma = 0;
            Nodo* temp = Cabeza;
            while( temp!= NULL){
                cantidad++;
                suma = suma + temp->Definitiva();
                temp = temp->GetSiguiente();
            }
            if( cantidad > 0){
             Pgen = (suma/cantidad);
             return Pgen;
            }
            else{
                return 0;
            }
        }
        double MaximaDefinitiva(){
            double def, Max;
            Max = 0;
            Nodo* temp = Cabeza;
            while(temp != NULL){
                def = temp->Definitiva();
                if(def > Max){
                    Max = def;
                }
                temp = temp->GetSiguiente();
            }
            return Max;
        }

        int Aprobados(){
          int cant;
            double def;
            cant = 0;
            Nodo *temp = Cabeza;
            while(temp != NULL){
              def = temp->Definitiva();
                if(def > 3){
                    cant++;
                }

                temp = temp->GetSiguiente();
           }
            return cant;
     }

        void limpiar(){
            while(Cabeza != NULL){
                    Eliminar(Cabeza);
            }
        }
        void llenar(Nodo* nod){
            int cod;
            string nom;
            double n1,n2,n3;
            cout << "\n\tDigite Codigo del Estudiante: ";
            cin >>cod;
            nod->SetCodigo(cod);
            cout << "\n\tDigite Nombre del Estudiante: ";
            cin >>nom;
            nod->SetNombre(nom);
            cout << "\n\tDigite La Nota 1: ";
            cin >> n1;
            nod->SetNota1(n1);
            cout << "\n\tDigite La Nota 2: ";
            cin >> n2;
            nod->SetNota2(n2);
            cout << "\n\tDigite La Nota 3: ";
            cin >> n3;
            nod->SetNota3(n3);
        }
        void Mostrar(Nodo* nod){
            cout << "\tCodigo: " << nod->GetCodigo() <<endl;
            cout << "\tNombre: " << nod->GetNombre() <<endl;
            cout << "\tNota 1: " << nod->GetNota1() <<endl;
            cout << "\tNota 2: " << nod->GetNota2() <<endl;
            cout << "\tNota 3: " << nod->GetNota3() <<endl;
            cout << "\tDefinitiva: " << nod->Definitiva() <<endl;
            cout << "\n";
        }


        void Listar(Nodo* nod){
            Nodo* temp = nod;
            while(temp != NULL){

                Mostrar(temp);
                temp = temp->GetSiguiente();
            }
        }
        int Menu(){
            int opcion = 0;
            cout << "________________________________________________________________________________\n";
            cout << "\n\t\t\t ESCOJA UNA OPCION DEL MENU \n";
            cout << "________________________________________________________________________________\n\n";
            cout << "\n\t1. Agregar Nodo\n";
            cout << "\t2. Buscar Nodo\n";
            cout << "\t3. Cantidad de Nodos en la Lista\n";
            cout << "\t4. Promedio General\n";
            cout << "\t5. Maxima Nota Promedio\n";
            cout << "\t6. Listar Nodos\n";
            cout << "\t7. Limpiar Lista\n";
            cout << "\t8. Salir\n";
            cout << "________________________________________________________________________________\n";
            do{
                cout << "\nSeleccione una opcion del 1 al 8: ";
                cin >> opcion;
            }while(opcion <= 0 || opcion > 8);
            return opcion;
        }
    protected:
    private:
        Nodo* Cabeza;
};

#endif // LISTAENLAZADA_H
