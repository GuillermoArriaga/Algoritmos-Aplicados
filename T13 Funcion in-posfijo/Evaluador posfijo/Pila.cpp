
#include "Pila.h"
#include <stdlib.h>


// PUSH
                         void PILA::push(int VAL)
                         {     NODO *a=new NODO((fin->posicion+1),VAL,fin,NULL);
                               fin->siguiente=a;
                               fin=a;
                         }


// POP
                         int PILA::pop()
                         { int valor=fin->contenido;
                           if(fin->anterior!=NULL)
                             {
                               fin=fin->anterior;
                               delete fin->siguiente;
                               fin->siguiente=NULL;
                               return valor;
                             }
                           fin->contenido=0;
                           return valor;
                         }

// VER CIMA
                         int PILA::verCima()
                         { return fin->contenido;
                         }

// CANTIDAD DE ELEMENTOS 
                         int PILA::longitud()
                         { return (fin->posicion);
                         }




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
                       }


// Inicializa N elementos
                         PILA::PILA(int N)   
                         { raiz=NULL;
                           for(int i=0;i<N;i++)
                              { NODO *a=new NODO(N-i,0,NULL,raiz);
                                raiz=a;
                                if(i==0)fin=a;
                                if(i!=0)((a->siguiente)->anterior)=raiz;
                              }
                         }

// Inicializa N elementos con valor = VAL
                         PILA::PILA(int N, int VAL)  
                         { raiz=NULL;
                           for(int i=0;i<N;i++)
                              { NODO *a=new NODO(N-i,VAL,NULL,raiz);
                                raiz=a;
                                if(i==0)fin=a;       
                                if(i!=0)((a->siguiente)->anterior)=raiz;
                              }
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

                         
// Eliminar un nodo
                         void PILA::eliminar(int Posicion)
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
                         


// Quitar el último                         
                         void PILA::quitaUltimo()
                         { eliminar(fin->posicion); }
                         

// Limpiar Pila
                         void PILA::limpiar()
                         { int i;
                           for(i=fin->posicion;i>=raiz->posicion;i--)
                              eliminar(i);
                         }
