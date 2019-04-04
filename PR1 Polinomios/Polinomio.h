/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  POLINOMIO                      =
    =                                                                       =
    =========================================================================*/

// Guillermo Arriaga Garcia: Polinomio con lista doble

#ifndef POLINOMIO_H
#define POLINOMIO_H
#include <cstring>
#include <fstream>
#include "Monomio.h"

using namespace std;


class POLINOMIO
{
   private:
            MONOMIO* raiz;
            MONOMIO* fin;

   public:
            POLINOMIO();
            ~POLINOMIO();
            POLINOMIO(std::string);

            void demostracion_archivo();
            void capturar(std::string);
            double conversor(std::string);
            double evaluar(double eval);
            void imprimir();
            void insertaInicio(double VAL,int exp);
            void insertaFinal(double VAL,int exp);
            void cambioValor(int Posicion, double VAL,int exp);
            void cambioPosicion(int P1, int P2);
            void eliminar(int Posicion);
            void quitaPrimero();
            void quitaUltimo(); 
            void limpiar();     
            void renumerar();          // Asigna el nuevo orden de posiciones.
            int encuentra(int exp);    // Regresa la posicion del exponente.
            int longitud(); 
            MONOMIO* regresaNth(int Posicion); // Regresa el apuntador al item de la posicion N-ésima o Null si no existe.
            MONOMIO* inicio();
            MONOMIO* final(); 
            
            // SOBRECARGAS DE OPERADORES
            void operator = (const POLINOMIO& P);
            POLINOMIO operator + (const POLINOMIO& P1);
            POLINOMIO operator - (const POLINOMIO& P1);
            POLINOMIO operator * (const POLINOMIO& P1);
            friend istream& operator >> (istream& entrada, POLINOMIO& p);
            friend ostream& operator << (ostream& salida, const POLINOMIO& p);
            friend ofstream& operator << (ofstream& salida, const POLINOMIO& p);
            
};

#endif
