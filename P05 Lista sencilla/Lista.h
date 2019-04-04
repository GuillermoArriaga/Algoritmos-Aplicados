

#ifndef Lista_H
#define Lista_H
#include "Nodo_h.h"

class LISTA
{
   private:
            NODO* raiz;

   public:
            LISTA();
            ~LISTA();
            LISTA(int N);
            LISTA(int N, int VAL);
            
            void insertaInicio(int VAL);
            int encuentra(int VAL);    // Regresa la posicion del primer valor idéntico encontrado
            NODO* inicio();            // Regresa el valor del apuntador base (raiz).
            
};

#endif


