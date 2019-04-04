/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  NODOD CPP                      =
    =                                                                       =
    =========================================================================*/


#include "Nodo_arbol_bin.h"
#include <stdlib.h>


/*  =========================================================================
    =                                                                       =
    =                      CONTRUCTORES Y DESTRUCTOR                        =
    =                                                                       =
    =========================================================================*/

    NODO_ARBOL_BIN::NODO_ARBOL_BIN()  // Constructor default
        {  posicion=1;
           contenido=-717;
           izq=NULL;
           der=NULL;
           padre=NULL;
        }


    NODO_ARBOL_BIN::NODO_ARBOL_BIN(double cont, NODO_ARBOL_BIN* papa,char hijo)
        {  if(hijo!='d'&&hijo!='D') hijo='i'; // Ajuste de datos
           if(hijo=='i'||hijo=='I') // Si es hijo izquierdo
             { posicion=(papa->posicion)*2; }
           if(hijo=='d'||hijo=='D') // Si es hijo derecho
             { posicion=(((papa->posicion)*2)+1); }
           padre=papa;
           contenido=cont;
           izq=NULL;
           der=NULL;
        }

    NODO_ARBOL_BIN::~NODO_ARBOL_BIN() // Destructor
        {}


        /* =========================================================
           =                                                       =
           =                  IMPRESIÓN Y CAPTURA                  =
           =                                                       =
           =========================================================*/

    istream& operator>>(istream& entrada, NODO_ARBOL_BIN& nod)
           { entrada>>nod.contenido; return entrada; }
           
    ostream& operator<<(ostream& salida, const NODO_ARBOL_BIN& nod)
           { salida<<nod.contenido; return salida; }
