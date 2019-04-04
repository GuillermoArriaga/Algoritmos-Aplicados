
#include "Lista.h"
#include <stdlib.h>


// Constructor default
                       LISTA::LISTA()     
                       {  NODO* a=new NODO();
                          raiz=a;
                          fin=a;
                       }


// Constructor
                       LISTA::LISTA(int pos_, int cont_, int vacio)
                       {  NODO* a=new NODO(pos_,cont_,NULL,NULL);
                          a->siguiente=NULL;
                          a->anterior=NULL;
                          raiz=a;
                          fin=a;
                       }

                       
// Destructor
                       LISTA::~LISTA()    
                       { limpiar();
                         delete raiz;
                       }


// Inicializa N elementos
                         LISTA::LISTA(int N)   
                         { raiz=NULL;
                           for(int i=0;i<N;i++)
                              { NODO *a=new NODO(N-i,0,NULL,raiz);
                                raiz=a;
                                if(i==0)fin=a;
                                if(i!=0)((a->siguiente)->anterior)=raiz;
                              }
                         }

// Inicializa N elementos con valor = VAL
                         LISTA::LISTA(int N, int VAL)  
                         { raiz=NULL;
                           for(int i=0;i<N;i++)
                              { NODO *a=new NODO(N-i,VAL,NULL,raiz);
                                raiz=a;
                                if(i==0)fin=a;       
                                if(i!=0)((a->siguiente)->anterior)=raiz;
                              }
                         }


// Insertar al Inicio
                         void LISTA::insertaInicio(int VAL)
                         { NODO *a=new NODO(0,VAL,NULL,raiz);
                           raiz->anterior=a;
                           raiz=a;
                           renumerar();
                         }


// Inserta al Final
                         void LISTA::insertaFinal(int VAL)
                         { NODO *a=new NODO((fin->posicion+1),VAL,fin,NULL);
                           fin->siguiente=a;
                           fin=a;
                         }

                         
// Renumeración        
                         void LISTA::renumerar()
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
                         NODO* LISTA::inicio()
                         { return raiz; }


// Apuntador al final
                         NODO* LISTA::final()
                         { return fin; }


// Apuntador del n-esimo elemento
                         NODO* LISTA::regresaNth(int Posicion)
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

                         
// Eliminar un nodo
                         void LISTA::eliminar(int Posicion)
                         { NODO* ubicador;
                           
                           ubicador=regresaNth(Posicion);
                           
                           if(ubicador->siguiente!=fin->siguiente) // No es el ultimo
                             { if (ubicador->anterior!=NULL) // No es ultimo ni primero
                                   {(ubicador->anterior)->siguiente=ubicador->siguiente;
                                    (ubicador->siguiente)->anterior=ubicador->anterior;
                                   } 
                               else{ raiz=ubicador->siguiente; // Es el primero y no ultimo
                                     raiz->anterior=NULL;
                                   }
                             }
                           else { if (ubicador->anterior!=fin->siguiente) // Es el ultimo y no primero
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


// Quitar el primero                         
                         void LISTA::quitaPrimero()
                         { eliminar(1); renumerar();}
                         


// Quitar el úlimio                         
                         void LISTA::quitaUltimo()
                         { eliminar(fin->posicion); }
                         

// Limpiar Lista
                         void LISTA::limpiar()
                         { int i;
                           for(i=fin->posicion;i>=raiz->posicion;i--)
                              eliminar(i);
                         }


// Nueva: para el examen 1: El apuntador final apunta a algun elemento de su lista
                         void LISTA::mover_final(int Posicion)
                         { fin->siguiente=regresaNth(Posicion);
                         }

