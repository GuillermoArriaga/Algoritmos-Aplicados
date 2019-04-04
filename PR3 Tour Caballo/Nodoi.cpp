/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  NODO INT                       =
    =                                                                       =
    =========================================================================*/


#include "Nodoi.h"
#include <stdlib.h>


/*  =========================================================================
    =                                                                       =
    =                      CONTRUCTORES Y DESTRUCTOR                        =
    =                                                                       =
    =========================================================================*/

    NODOI::NODOI()  // Constructor default
        {  posicion=0;
           contenido=0;
           anterior=NULL;
           siguiente=NULL;
        }


    NODOI::NODOI(int pos_, int cont_, NODOI* ant_, NODOI* sig_)
        {  posicion=pos_;
           contenido=cont_;
           anterior=ant_;
           siguiente=sig_;
        }

    NODOI::~NODOI() // Destructor default
        {}
