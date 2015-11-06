#include <iostream>
#include <ListaEnlazada.h>
#include <Nodo.h>
using namespace std;

int main()
{
    system("color 1F");
    ListaEnlazada* obj = new ListaEnlazada();
    Nodo* aux;
    int opc, cod;
    do{
        opc = obj->Menu();
        switch(opc){
            case 1:system("cls");
                cout << "________________________________________________________________________________\n";
                cout << "\n\t\t\t AGREGAR UN NODO A LA LISTA \n";
                cout << "________________________________________________________________________________\n\n";
                aux = new Nodo();
                obj->llenar(aux);
                obj->Agregar(aux);
                system("cls");
            break;
            case 2:system("cls");
                cout << "________________________________________________________________________________\n";
                cout << "\n\t\t\t BUSCAR UN NODO EN LA LISTA \n";
                cout << "________________________________________________________________________________\n\n";
                cout << "\tDIGITE CODIGO A BUSCAR: ";
                cin >> cod;
                cout << "\n";
                aux = obj->Buscar(cod);
                if(aux != NULL){
                    obj->Mostrar(aux);
                }else{
                    cout << "\tCodigo no encontrado";
                }
                cout << "\n\t";
                system("pause\n\t");
                system("cls");
            break;
            case 3:system("cls");
                cout << "________________________________________________________________________________\n";
                cout << "\n\t\t\t NUMERO DE NODO REGISTRADOS \n";
                cout << "________________________________________________________________________________\n\n";
                cout << "\tCANTIDAD DE NODOS EN LA LISTA: " << obj->ContarNodos();
                cout << "\n\t";
                system("pause\n\t");
                system("cls");
            break;
            case 4:system("cls");
                cout << "________________________________________________________________________________\n";
                cout << "\n\t\t\t PROMEDIO DE LAS NOTAS DEFINITIVAS \n";
                cout << "________________________________________________________________________________\n\n";
                cout << "\tPROMEDIO GENERAL: " << obj->promedioGeneral();
                cout << "\n\t";
                system("pause\n\t");
                system("cls");
            break;
            case 5:system("cls");
                cout << "________________________________________________________________________________\n";
                cout << "\n\t\t\t MAXIMA NOTA DE LAS DEFINITIVAS \n";
                cout << "________________________________________________________________________________\n\n";
                cout << "\tMAXIMA NOTA DEFINITIVA: " <<obj->MaximaDefinitiva();
                cout << "\n\t";
                system("pause\n\t");
                system("cls");
            break;
            case 6:system("cls");
                cout << "________________________________________________________________________________\n";
                cout << "\n\t\t\t LISTAR LOS NODOS DE LA LISTA \n";
                cout << "________________________________________________________________________________\n\n";
                if ( obj->GetCabeza()!=NULL){
                    obj->Listar(obj->GetCabeza());
                    cout << "\n\t";
                    system("pause\n\t");
                    system("cls");
                }else{
                    cout <<"\n\t Lista vacia";
                    cout << "\n\t";
                    system("pause\n\t");
                    system("cls");
                }
            break;
            case 7:system("cls");
                cout << "\n";
                obj->limpiar();
                cout << "\n\tLista vacia...";
                cout << "\n\t";
                system("pause\n\t");
                system("cls");
            break;
            case 8:
            break;
        }
    }while(opc != 8);
    delete obj;
    return 0;
    }
