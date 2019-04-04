/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  COLA DOUBLE                    =
    =                                                                       =
    =========================================================================*/

// Guillermo Arriaga Garcia: Clase Lista doblemente ligada y no circular.

#ifndef Cola_H
#define Cola_H
#include "Nodod.h"

class COLA
{
   private:
            NODOD* raiz;
            NODOD* fin;
            lista_arbol list;

   public:
            COLA();                   // Constructor default 
            ~COLA();                  // Destructor
            COLA(int N);              // Crea lista de N elementos con contenido = cero
            COLA(int N, double VAL);  // Crea lista de N elementos con contenido = VAL

            // Funciones  FIFO (cola) (tail)
            void push(double VAL);
            double pop();
            double see();
            void set(int Pos, double VAL);
            double get(int Pos);
            int longitud();

            // Funciones útiles
            void imprimir();
            void insertaFinal(double VAL);
            void cambioValor(int Posicion, double VAL);
            void cambioPosicion(int P1, int P2);
            void eliminar(int Posicion);
            void limpiar();            // Borra toda la cola
            void renumerar();          // Asigna el nuevo orden de posiciones.
            int encuentra(double VAL);    // Regresa la posicion del primer valor idéntico encontrado.

            NODOD* regresaNth(int Posicion); // Regresa el apuntador al item de la posicion N-ésima o Null si no existe.
            NODOD* inicio();            // Regresa el valor del apuntador base (raiz).
            NODOD* final();             // Regresa el valor del apuntador final.
            
};

#endif
