
#include "NODO_H.h"
#include <stdlib.h>

NODO::NODO()  // Constructor default
{  item=0;
   next=NULL;
}

NODO::~NODO() // Destructor default
{}

NODO::NODO(int x, NODO *t)
{  item=x;
   next=t;
}
