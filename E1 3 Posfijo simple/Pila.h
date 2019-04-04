
// Guillermo Arriaga Garcia: Clase PILA

#ifndef PILA_H
#define PILA_H
#include "Nodo_h.h"

class PILA
{
   private:
            NODO* raiz;
            NODO* fin;

   public:
            PILA();                   // Constructor default 
            PILA(int pos_, int cont_, int vacio); //Constructor
            ~PILA();                  // Destructor
            PILA(int N);              // Crea lista de N elementos con contenido = cero
            PILA(int N, int VAL);     // Crea lista de N elementos con contenido = VAL
            
            void push(int VAL);
            int pop();
            int verCima();            // Permite ver el último elemento sin sacarlo
            int longitud();
            
            void eliminar(int Posicion);
            void quitaUltimo();        // Quita el ultimo nodo y lo destruye.
            void limpiar();            // Borra toda la lista
            void renumerar();          // Asigna el nuevo orden de posiciones.
            NODO* regresaNth(int Posicion); // Regresa el apuntador al item de la posicion N-ésima o Null si no existe.
            NODO* inicio();            // Regresa el valor del apuntador base (raiz).
            NODO* final();             // Regresa el valor del apuntador final.
            
};

#endif


