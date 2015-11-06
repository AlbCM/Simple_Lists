#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;

class Nodo
{
    public:
        Nodo();
        virtual ~Nodo();
        int GetCodigo(){ return Codigo;}
        void SetCodigo(int cod){ Codigo = cod;}
        string GetNombre(){ return Nombre;}
        void SetNombre(string nom){ Nombre = nom;}
        double GetNota1(){ return Nota1;}
        void SetNota1(double n1){ Nota1 = n1;}
        double GetNota2(){ return Nota2;}
        void SetNota2(double n2){ Nota2 = n2;}
        double GetNota3(){ return Nota3;}
        void SetNota3(double n3){ Nota3 = n3;}
        Nodo* GetSiguiente(){ return Siguiente;}
        void SetSiguiente(Nodo* sig){ Siguiente = sig;}
        double Definitiva(){
            double Pro=0;
            Pro = (GetNota1()+GetNota2()+GetNota3())/3;
            return Pro;
        }
    protected:
    private:
        int Codigo;
        string Nombre;
        double Nota1;
        double Nota2;
        double Nota3;
        Nodo* Siguiente;
};

#endif // NODO_H
