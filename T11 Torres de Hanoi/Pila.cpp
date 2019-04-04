
#include "Pila.h"
#include "Nodo_h.h"
#include <stdlib.h>


// Constructor default
                       PILA::PILA()     
                       {  NODO* a=new NODO();
                          raiz=a;
                          fin=a;
                       }


// Constructor
                       PILA::PILA(int pos_, int cont_, int vacio)
                       {  NODO* a=new NODO(pos_,cont_,NULL,NULL);
                          a->siguiente=NULL;
                          a->anterior=NULL;
                          raiz=a;
                          fin=a;
                       }

                       
// Destructor
                       PILA::~PILA()    
                       { limpiar();
                         delete raiz;
                         delete fin;
                       }



// POP: Extrae el último insertado. LIFO Last input first out
                         int PILA::pop()
                         { NODO* ubicador;
                           int valor;
                           ubicador=fin;
                           fin=fin->anterior;
                           valor=ubicador->contenido;
                           eliminar(ubicador->posicion);
                           return valor;
                         }


// PUSH: Inserta al Final. LIFO
                         void PILA::push(int VAL)
                         { NODO *a=new NODO((fin->posicion+1),VAL,fin,NULL);
                           fin->siguiente=a;
                           fin=a;
                         }

                         
// Renumeración        
                         void PILA::renumerar()
                         { NODO* ubicador;
                           int i;
                           ubicador=raiz;
                           for(i=1;ubicador!=fin;i++)
                              { ubicador->posicion=i;
                                ubicador=ubicador->siguiente;
                              }          
                           fin->posicion=i;                     
                         }
                                                  

// Apuntador al inicio
                         NODO* PILA::inicio()
                         { return raiz; }


// Apuntador al final
                         NODO* PILA::final()
                         { return fin; }


// Apuntador del n-esimo elemento
                         NODO* PILA::regresaNth(int Posicion)
                         { NODO* ubicador;
                           if(fin->posicion<Posicion) return NULL;
                           if((fin->posicion)-(Posicion)<(fin->posicion)/2) // Llega retrocediendo
                             { ubicador=fin;
                               for(int i=1;i<=(fin->posicion)-(Posicion);i++)
                                  { ubicador=ubicador->anterior; }
                               return ubicador;
                             } 
                           // Si no hizo lo anterior, ahora llega avanzando.
                           ubicador=raiz;
                           for(int i=1;i<Posicion;i++)
                              { ubicador=ubicador->siguiente; }
                           return ubicador;
                         }


// Longitud de la PILA
                         int PILA::longitud()
                         {return fin->posicion;}
                                                  



// Eliminar un nodo
                         void PILA::eliminar(int Posicion)
                         { NODO* ubicador;
                           
                           ubicador=regresaNth(Posicion);
                           
                           if(ubicador->siguiente!=NULL) // No es el ultimo
                             { if (ubicador->anterior!=NULL) // No es ultimo ni primero
                                   {(ubicador->anterior)->siguiente=ubicador->siguiente;
                                    (ubicador->siguiente)->anterior=ubicador->anterior;
                                   } 
                               else{ raiz=ubicador->siguiente; // Es el primero y no ultimo
                                     raiz->anterior=NULL;
                                   }
                             }
                           else { if (ubicador->anterior!=NULL) // Es el ultimo y no primero
                                      { (ubicador->anterior)->siguiente=NULL;
                                        fin=ubicador->anterior;
                                      }  
                                  else   // Si es el primero y el último lo deja con valor cero
                                      { raiz=fin=ubicador;
                                        ubicador->contenido=0;
                                        ubicador->posicion=1;
                                        ubicador->anterior=NULL;
                                        ubicador->siguiente=NULL;
                                      }  
                                }
                           
                           if (raiz!=fin) 
                               { delete ubicador;
                                 renumerar();
                               }  
                         }

                         

// Limpiar PILA
                         void PILA::limpiar()
                         { int i;
                           for(i=fin->posicion;i>=raiz->posicion;i--)
                              eliminar(i);
                         }


