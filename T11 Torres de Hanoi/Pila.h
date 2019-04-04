
// Guillermo Arriaga Garcia: Clase PILA doblemente ligada y no circular.

#ifndef Pila_H
#define Pila_H
#include "Nodo_h.h"

class PILA // STACK
{
   private:
            NODO* raiz;
            NODO* fin;

   public:
            PILA();                   // Constructor default
            ~PILA();                  // Destructor
            PILA(int pos_, int cont_, int vacio); // Constructor

            int pop();                 // Saca el último 
            void push(int VAL);        // Inserta al final 
            void renumerar();          // Asigna el nuevo orden de posiciones.
            void eliminar(int Posicion);
            void limpiar();            // Borra toda la lista
            int longitud();            // Regresa el número de nodos de la lista.
            NODO* regresaNth(int Posicion); // Regresa el apuntador al item de la posicion N-ésima o Null si no existe.
            NODO* inicio();            // Regresa el valor del apuntador base (raiz).
            NODO* final();             // Regresa el valor del apuntador final.
};

#endif


