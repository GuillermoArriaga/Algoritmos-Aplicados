/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  NODO H                         =
    =                                                                       =
    =========================================================================*/


#ifndef NODOS_H
#define NODOS_H
#include <iostream>
#include <cstring>
using namespace std;

class NODOS
{
   private:

   public:
            string contenido;
            int posicion;
            NODOS* siguiente;
            NODOS* anterior;
            NODOS(int pos_, string cont_, NODOS* ant_, NODOS* sig_);   // Constructor
            NODOS();                 // Constructor default
            ~NODOS();                // Destructor
            
};

#endif

