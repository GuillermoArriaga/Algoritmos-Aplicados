
#include "Lista.h"
#include <stdlib.h>

LISTA::LISTA()     // Constructor default
{  
   NODO* a=new NODO(0,NULL);
   a->next=NULL;
   raiz=a;
}

LISTA::~LISTA()    // Destructor
{ NODO* ubicador;
  ubicador=raiz;
  
  while(ubicador!=NULL)
     {  ubicador=ubicador->next;
        delete raiz;
        raiz=ubicador;
     }
  delete ubicador;
  delete raiz;
}

LISTA::LISTA(int N)   // Inicializa N elementos
{ raiz=NULL;
  for(int i=0;i<N;i++)
     { NODO *a=new NODO(0,NULL);
       a->next=raiz;
       raiz=a;
     }
}

LISTA::LISTA(int N, int VAL)  // Inicializa N elementos con valor = VAL
{ raiz=NULL;
  for(int i=0;i<N;i++)
     { NODO *a=new NODO(VAL,NULL);
       a->next=raiz;
       raiz=a;
     }
}

void LISTA::insertaInicio(int VAL)
{ 

    NODO *a=new NODO(VAL,NULL);
    a->item=VAL;
    a->next=raiz;
    raiz=a;

}

int LISTA::encuentra(int VAL)
{ NODO* ubicador;
  int contador;
  ubicador=raiz;
  contador=0;
  
  while(ubicador->next!=NULL)
    {  if (ubicador->item==VAL)return contador;
       else {contador++;
             ubicador=ubicador->next;
            } 
    }
  if (ubicador->item==VAL)return contador;
  return -1;  
}

NODO* LISTA::inicio()
{ return raiz;
}
