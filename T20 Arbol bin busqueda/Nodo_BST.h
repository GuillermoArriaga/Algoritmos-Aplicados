/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  NODO DE BST                    =
    =                                                                       =
    =========================================================================*/

/*                             padre
                                 |
                               nodo
                               /  \
                             Izq   Der
*/


#ifndef NODO_BST_H
#define NODO_BST_H

#include <iostream>
#include "Pila.h"
using namespace std;

class NODO_BST
{
   private:

   public:
            NODO_BST(double cont,NODO_BST* papa,char hijo);
            NODO_BST();
            ~NODO_BST();

            double contenido;
            int posicion;
            int distancia;
            int visitado;
            NODO_BST* izq;
            NODO_BST* der;
            NODO_BST* padre;
            
            
            friend istream& operator>>(istream& entrada, NODO_BST& nod);
            friend ostream& operator<<(ostream& salida, const NODO_BST& nod);

};

#endif

