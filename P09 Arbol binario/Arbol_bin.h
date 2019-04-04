/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  LISTA DOUBLE                   =
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
            NODO_ARBOL_BIN* ubicador;
            NODO_ARBOL_BIN* final;

   public:
            ARBOL_BIN();                   // Constructor default 
            ~ARBOL_BIN();                  // Destructor
            ARBOL_BIN(double cont);
            ARBOL_BIN(int elem);           // Crea un árbol binario con n elementos
                                           // de arriba a abajo y de izq. a derecha.

   // Métodos
            // Ubicacion
            void start(); // Nos ubica en el inicio
            void forth(); // Nos desplaza a la derecha
            void end();   // Nos lleva al último nodo
            void go_to(int posicion);   // Nos desplaza a tal posición
            NODO_ARBOL_BIN* apuntador_a(int posicion);
            NODO_ARBOL_BIN* ubica(); // Da la posicion en la que estamos
            void left();
            void right();
            
            // Impresiones
            void imprimir_posiciones();
            void printnode(int x, int h);
            void show(NODO_ARBOL_BIN* t, int h);

            void imprimirPreorden();       // yo izq der     Desde raiz
            void imprimirPostorden();      // izq der yo
            void imprimirInorden();        // izq yo der

            void imprimirPreorden(NODO_ARBOL_BIN* nodo);  // Desde cualquier
            void imprimirPostorden(NODO_ARBOL_BIN* nodo); // nodo
            void imprimirInorden(NODO_ARBOL_BIN* nodo);  
            
            void imprimirAnchura();


            // Modificadores
            void agregar(double cont);
            void agregar(double cont,char hijo,NODO_ARBOL_BIN* papa);
            void modificar(int pos, double cont);
            
            // Eliminaciones
            void limpiar(NODO_ARBOL_BIN* nodo);
            
};

#endif
