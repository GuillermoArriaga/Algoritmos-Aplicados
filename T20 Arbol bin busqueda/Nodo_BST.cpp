/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  NODO DE BST                    =
    =                                                                       =
    =========================================================================*/


#include "Nodo_BST.h"
#include <stdlib.h>


/*  =========================================================================
    =                                                                       =
    =                      CONTRUCTORES Y DESTRUCTOR                        =
    =                                                                       =
    =========================================================================*/

    NODO_BST::NODO_BST()  // Constructor default
        {  posicion=1;
           contenido=0;
           izq=NULL;
           der=NULL;
           padre=NULL;
           distancia=0;
           visitado=1;
        }


    NODO_BST::NODO_BST(double cont, NODO_BST* papa,char hijo)
        {  if(hijo!='d'&&hijo!='D') hijo='i'; // Ajuste de datos
           if(hijo=='i'||hijo=='I') // Si es hijo izquierdo
             { posicion=(papa->posicion)*2; }
           if(hijo=='d'||hijo=='D') // Si es hijo derecho
             { posicion=(((papa->posicion)*2)+1); }
           padre=papa;
           contenido=cont;
           distancia=0;
           izq=NULL;
           der=NULL;
           visitado=1;
        }

    NODO_BST::~NODO_BST() // Destructor
        {}


        /* =========================================================
           =                                                       =
           =                  IMPRESIÓN Y CAPTURA                  =
           =                                                       =
           =========================================================*/

    istream& operator>>(istream& entrada, NODO_BST& nod)
           { entrada>>nod.contenido; return entrada; }
           
    ostream& operator<<(ostream& salida, const NODO_BST& nod)
           { salida<<nod.contenido; return salida; }
