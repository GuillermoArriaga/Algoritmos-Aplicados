
// Guillermo Arriaga Garcia: Clase Lista doblemente ligada y no circular.

#ifndef Lista_H
#define Lista_H
#include "Nodo_h.h"

class LISTA
{
   private:
            NODO* raiz;
            NODO* fin;

   public:
            LISTA();                   // Constructor default 
            LISTA(int pos_, int cont_, int vacio); //Constructor
            ~LISTA();                  // Destructor
            LISTA(int N);              // Crea lista de N elementos con contenido = cero
            LISTA(int N, int VAL);     // Crea lista de N elementos con contenido = VAL
            
            void insertaInicio(int VAL);
            void insertaFinal(int VAL);
            void cambioValor(int Posicion, int VAL);
            void cambioPosicion(int Posicion1, int Posicion2);
            void eliminar_Josephus(NODO* ubicacion);
            void eliminar(int Posicion);
            void quitaPrimero();       // Quita el primer nodo y lo destruye.
            void quitaUltimo();        // Quita el ultimo nodo y lo destruye.
            void limpiar();            // Borra toda la lista
            void renumerar();          // Asigna el nuevo orden de posiciones.
            int encuentra(int VAL);    // Regresa la posicion del primer valor idéntico encontrado.
            int longitud();            // Regresa el número de nodos de la lista.
            NODO* regresaNth(int Posicion); // Regresa el apuntador al item de la posicion N-ésima o Null si no existe.
            NODO* inicio();            // Regresa el valor del apuntador base (raiz).
            NODO* final();             // Regresa el valor del apuntador final.
};

#endif


