/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  NODO CPP                       =
    =                                                                       =
    =========================================================================*/


#include "Nodos.h"
#include <stdlib.h>



/*  =========================================================================
    =                                                                       =
    =                      CONTRUCTORES Y DESTRUCTOR                        =
    =                                                                       =
    =========================================================================*/

    NODOS::NODOS()  // Constructor default
        {  posicion=0;
           contenido="";
           anterior=NULL;
           siguiente=NULL;
        }


    NODOS::NODOS(int pos_, string cont_, NODOS* ant_, NODOS* sig_)
        {  posicion=pos_;
           contenido=cont_;
           anterior=ant_;
           siguiente=sig_;
        }

    NODOS::~NODOS() // Destructor default
        {}
