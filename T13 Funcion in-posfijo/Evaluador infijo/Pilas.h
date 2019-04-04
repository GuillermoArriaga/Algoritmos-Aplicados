/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  PILA STRING                    =
    =                                                                       =
    =========================================================================*/

// Guillermo Arriaga Garcia: Clase Lista doblemente ligada y no circular.

#ifndef PILAS_H
#define PILAS_H
#include "Nodos.h"

class PILAS
{
   private:
            NODOS* raiz;
            NODOS* fin;

   public:
            PILAS();                   
            ~PILAS();                  
            PILAS(int N);              // Crea PILA de N elem. con contenido = ""
            PILAS(int N, string VAL);  // Crea ubi de N elem. con contenido = VAL

            // Funciones de pila
            void push(string VAL);
            string pop();
            string see();
            void set(int Pos, string VAL);
            string get(int Pos);
            
            // Funciones extras
            void limpiar();
            void imprimir();
            int longitud();           
            void insertaInicio(string VAL);
            void insertaFinal(string VAL);
            void cambioValor(int Posicion, string VAL);
            void cambioPosicion(int P1, int P2);
            void eliminar(int Posicion);
            void renumerar();          // Asigna el nuevo orden de posiciones.
            int encuentra(string VAL);    // Regresa la posicion del primer valor idéntico encontrado.

            NODOS* regresaNth(int Posicion); // Regresa el apuntador al item de la posicion N-ésima o Null si no existe.
            NODOS* inicio();            // Regresa el valor del apuntador base (raiz).
            NODOS* final();             // Regresa el valor del apuntador final.
            
};

#endif
