/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  NODO DOUBLE                    =
    =                                                                       =
    =========================================================================*/


#ifndef NODOD_H
#define NODOD_H
#include "Figura.h"


class NODOD
{
   private:

   public:
            Figura* contenido;
            int posicion;
            NODOD* siguiente;
            NODOD* anterior;
            NODOD(int pos_, Figura* cont_, NODOD* ant_, NODOD* sig_);   // Constructor
            NODOD();                 // Constructor default
            ~NODOD();                // Destructor
            
};

#endif

