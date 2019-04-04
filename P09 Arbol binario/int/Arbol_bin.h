/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  LISTA int                   =
    =                                                                       =
    =========================================================================*/

// Guillermo Arriaga Garcia: Clase Lista doblemente ligada y no circular.

#ifndef ARBOL_BIN_H
#define ARBOL_BIN_H
#include "NODO_ARBOL_BIN.h"

class ARBOL_BIN
{
   private:
            NODO_ARBOL_BIN* raiz;
            //void *ListaUbicacion;

   public:
            ARBOL_BIN();                   // Constructor default 
            ~ARBOL_BIN();                  // Destructor
            ARBOL_BIN(int cont);

            // Métodos
            void agregarRaiz(int cont,char hijo);
            void agregar(int cont,char hijo,NODO_ARBOL_BIN* papa);
            void imprimirPreorden();       // yo izq der
            void imprimirPostorden();      // izq der yo
            void imprimirInorden();        // izq yo der
            
            NODO_ARBOL_BIN* inicio();            // Regresa el valor del apuntador base (raiz).
};

#endif
