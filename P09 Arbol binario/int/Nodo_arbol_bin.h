/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  NODO H                         =
    =                                                                       =
    =========================================================================*/

/*                             padre
                                 |
                               nodo
                               /  \
                             Izq   Der
*/


#ifndef NODO_ARBOL_BIN_H
#define NODO_ARBOL_BIN_H

#include <iostream>
using namespace std;

class NODO_ARBOL_BIN
{
   private:

   public:
            NODO_ARBOL_BIN(int cont,NODO_ARBOL_BIN* papa,char hijo);
            NODO_ARBOL_BIN();
            ~NODO_ARBOL_BIN();

            int contenido;
            int posicion;
            NODO_ARBOL_BIN* izq;
            NODO_ARBOL_BIN* der;
            NODO_ARBOL_BIN* padre;
            
            
            friend istream& operator>>(istream& entrada, NODO_ARBOL_BIN& nod);
            friend ostream& operator<<(ostream& salida, const NODO_ARBOL_BIN& nod);

};

#endif

