/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  LISTA STRING                   =
    =                                                                       =
    =========================================================================*/

// Guillermo Arriaga Garcia: Clase Lista doblemente ligada y no circular.

#ifndef Listas_H
#define Listas_H
#include "Nodos.h"

class LISTAS
{
   private:
            NODOS* raiz;
            NODOS* fin;

   public:
            LISTAS();                   // Constructor default 
            ~LISTAS();                  // Destructor
            LISTAS(int N);              // Crea LISTAS de N elementos con contenido = ""
            LISTAS(int N, string VAL);     // Crea ubi de N elementos con contenido = VAL
            
            void imprimir();
            void insertaInicio(string VAL);
            void insertaFinal(string VAL);
            void cambioValor(int Posicion, string VAL);
            void cambioPosicion(int P1, int P2);
            void eliminar_nodo_circular(NODOS* ubicacion);  // Elimina NODOS de ubi circular
            void eliminar(int Posicion);
            void quitaPrimero();       // Quita el primer NODOS y lo destruye.
            void quitaUltimo();        // Quita el ultimo NODOS y lo destruye.
            void limpiar();            // Borra toda la ubi
            void renumerar();          // Asigna el nuevo orden de posiciones.
            int encuentra(string VAL);    // Regresa la posicion del primer valor idéntico encontrado.
            int longitud();            // Regresa el número de NODOSs de la ubi.
            NODOS* regresaNth(int Posicion); // Regresa el apuntador al item de la posicion N-ésima o Null si no existe.
            NODOS* inicio();            // Regresa el valor del apuntador base (raiz).
            NODOS* final();             // Regresa el valor del apuntador final.
            
            // Funciones extras para usar la ubi como FIFO (cola) o LIFO (pila)
            void push(string VAL);
            string lifopop();
            string fifopop();
            string lifosee();
            string fifosee();
            void set(int Pos, string VAL);
            string get(int Pos);
            
};

#endif
