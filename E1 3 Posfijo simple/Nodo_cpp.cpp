
#include "NODO_H.h"
#include <stdlib.h>

NODO::NODO()  // Constructor default
{  posicion=0;
   contenido=0;
   anterior=NULL;
   siguiente=NULL;
}

NODO::~NODO() // Destructor default
{}

NODO::NODO(int pos_, int cont_, NODO* ant_, NODO* sig_)
{  posicion=pos_;
   contenido=cont_;
   anterior=ant_;
   siguiente=sig_;
}
