/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  NODOD CPP                      =
    =                                                                       =
    =========================================================================*/


#include "Monomio.h"
#include <stdlib.h>


/*  =========================================================================
    =                                                                       =
    =                      CONTRUCTORES Y DESTRUCTOR                        =
    =                                                                       =
    =========================================================================*/

    MONOMIO::MONOMIO()  // Constructor default
        {  posicion=0;
           contenido=0;
           exponente=0;
           anterior=NULL;
           siguiente=NULL;
        }


    MONOMIO::MONOMIO(int pos_, double cont_,int exp, MONOMIO* ant_, MONOMIO* sig_)
        {  posicion=pos_;
           contenido=cont_;
           exponente=exp;
           anterior=ant_;
           siguiente=sig_;
        }

    MONOMIO::~MONOMIO() // Destructor default
        {}
