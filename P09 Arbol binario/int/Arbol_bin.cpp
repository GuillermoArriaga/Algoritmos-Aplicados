/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  ARBOL BINARIO                  =
    =                                                                       =
    =========================================================================*/


#include "Arbol_bin.h"
#include <cstdlib>
#include <iostream>
using namespace std;


/*  =========================================================================
    =                                                                       =
    =                       Destructor y constructores                      =
    =                                                                       =
    =========================================================================*/

    ARBOL_BIN::~ARBOL_BIN() { delete raiz; }

    ARBOL_BIN::ARBOL_BIN()  
      { NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN();
        raiz=a;
      }

    ARBOL_BIN::ARBOL_BIN(int cont)
      { NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN();
        a->contenido=cont;
        raiz=a;
      }


/*  =========================================================================
    =                                                                       =
    =                                Métodos                                =
    =                                                                       =
    =========================================================================*/

    NODO_ARBOL_BIN* ARBOL_BIN::inicio()
    { return raiz; }
    
    void ARBOL_BIN::agregarRaiz(int cont,char hijo)
    { NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,raiz,hijo);
      if(hijo!='d'&&hijo!='D') hijo='i'; // Ajuste de datos
      if(hijo=='i'||hijo=='I') raiz->izq=a;
      if(hijo=='d'||hijo=='D') raiz->der=a;
    }
    
    void ARBOL_BIN::agregar(int cont,char hijo,NODO_ARBOL_BIN* papa)
    { NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,papa,hijo);
      if(hijo!='d'&&hijo!='D') hijo='i'; // Ajuste de datos
      if(hijo=='i'||hijo=='I') papa->izq=a;
      if(hijo=='d'||hijo=='D') papa->der=a;
    }


    
    void ARBOL_BIN::imprimirPreorden()        // yo izq der
    { cout<<"\n\n\tPREORDEN: "<<(raiz->contenido)<<" "<<(raiz->izq->contenido)<<" "<<(raiz->der->contenido)<<"\n";
    }
    void ARBOL_BIN::imprimirPostorden()      // izq der yo
    { cout<<"\n\n\tPOSTORDEN: "<<(raiz->izq->contenido)<<" "<<(raiz->der->contenido)<<" "<<(raiz->contenido)<<"\n";
    }

    void ARBOL_BIN::imprimirInorden()        // izq yo der
    { cout<<"\n\n\tINORDEN: "<<(raiz->izq->contenido)<<" "<<(raiz->contenido)<<" "<<(raiz->der->contenido)<<"\n";
    }




/*  =========================================================================
    =                                                                       =
    =                          Modificaciones                               =
    =                                                                       =
    =========================================================================*/



/*  =========================================================================
    =                                                                       =
    =                          Eliminaciones                                =
    =                                                                       =
    =========================================================================*/




/*  =========================================================================
    =                                                                       =
    =                            Impresión                                  =
    =                                                                       =
    =========================================================================*/

