/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  NODO DOUBLE                    =
    =                                                                       =
    =========================================================================*/


#include "Nodod.h"
#include <stdlib.h>


/*  =========================================================================
    =                                                                       =
    =                      CONTRUCTORES Y DESTRUCTOR                        =
    =                                                                       =
    =========================================================================*/

    NODOD::NODOD()  // Constructor default
        {  posicion=0;
           contenido=NULL;
           anterior=NULL;
           siguiente=NULL;
        }


    NODOD::NODOD(int pos_, Figura* cont_, NODOD* ant_, NODOD* sig_)
        {  posicion=pos_;
           contenido=cont_;
           anterior=ant_;
           siguiente=sig_;
        }

    NODOD::~NODOD() // Destructor default
        {}
