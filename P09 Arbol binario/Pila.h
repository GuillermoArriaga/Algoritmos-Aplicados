/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  PILA DOUBLE                    =
    =                                                                       =
    =========================================================================*/

// Guillermo Arriaga Garcia: Clase Lista doblemente ligada y no circular.

#ifndef Pila_H
#define Pila_H
#include "Nodod.h"

class PILA
{
   private:
            NODOD* raiz;
            NODOD* fin;

   public:
            PILA();                   // Constructor default 
            ~PILA();                  // Destructor
            PILA(int N);              // Crea lista de N elementos con contenido = cero
            PILA(int N, int VAL);  // Crea lista de N elementos con contenido = VAL

            // Funciones  LIFO (pila) (stack)
            void push(int VAL);
            int pop();
            int see();
            void set(int Pos, int VAL);
            int get(int Pos);
            int longitud();

            // Funciones útiles
            void imprimir();
            void insertaFinal(int VAL);
            void cambioValor(int Posicion, int VAL);
            void cambioPosicion(int P1, int P2);
            void eliminar(int Posicion);
            void quitaUltimo();        // Quita el ultimo nodo y lo destruye.
            void limpiar();            // Borra toda la pila
            void renumerar();          // Asigna el nuevo orden de posiciones.
            int encuentra(int VAL);    // Regresa la posicion del primer valor idéntico encontrado.

            NODOD* regresaNth(int Posicion); // Regresa el apuntador al item de la posicion N-ésima o Null si no existe.
            NODOD* inicio();            // Regresa el valor del apuntador base (raiz).
            NODOD* final();             // Regresa el valor del apuntador final.
            
};

#endif
