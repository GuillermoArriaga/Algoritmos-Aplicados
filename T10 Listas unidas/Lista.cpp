
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
                                                  

// Buscar un valor
                         int LISTA::encuentra(int VAL)
                         { NODO* ubicador;
                           int contador;
                           ubicador=raiz;
                           contador=0;
  
                           while(ubicador!=NULL)
                                {  if (ubicador->contenido==VAL)return contador;
                                   else { contador++;
                                          ubicador=ubicador->siguiente;
                                        } 
                                }
                           return -1;  
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
                           
                           renumerar();   // Numeracion relativa a esta lista
                           
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


// Longitud de la lista
                         int LISTA::longitud()
                         { renumerar();  // Renumeracion relativa a esta lista
                           return fin->posicion;}
                         
                         
// Cambio de valor en tal posicion
                         void LISTA::cambioValor(int Posicion, int VAL)
                         { NODO* ubicador;
                           ubicador=regresaNth(Posicion);
                           if(ubicador!=NULL) ubicador->contenido=VAL;
                         }
                         

// Cambio de posicion  (no necesario)
                         void LISTA::cambioPosicion(int Posicion1, int Posicion2)
                         { NODO* posic_ini, posic_fin;
                           int i;
/*                           
                           posic_ini=regresaNth(Posicion1);
                           posic_fin=regresaNth(Posicion2);
                           
                           if(posic_ini!=NULL||posic_fin!=NULL)
                             { // Desligarlo de su lugar inicial
                               if(posic_ini->anterior!=NULL)
                                  { posic_ini->anterior->siguiente=posic_ini->siguiente;  // El anterior apunta al siguiente.
                                    posic_ini->siguiente->anterior=posic_ini->anterior;
                               else (posic_ini->siguiente)->anterior=NULL;   
                               if(posic_fin->siguiente!=NULL)
                                  posic_ini->siguiente->anterior=posic_ini->anterior;   // El siguiente apunta al anterior.
                               else (posic_fin->anterior)->siguiente=NULL;
                                                                         // Los if son por si hay cambios en las fronteras.
                               // Ligarlo en su nuevo lugar
                               posic_ini->siguiente=posic_fin->siguiente;
                               posic_ini->anterior=posic_fin->anterior;
                               posic_fin->anterior=posic_ini;
                               
                               posic_fin->anterior->siguiente=posic_ini;
                               if(posic_fin->siguiente!=NULL)
                                  posic_fin->siguiente->anterior=posic_ini;
                               else posic_ini->siguiente=NULL;  
                               
                               //Cambio de valor de posicion
                               posic_ini->posicion=Posicion2;
                               
                               //Renumeracion
                               renumerar();
                             }  
*/                         }


// Eliminar un nodo
                         void LISTA::eliminar(int Posicion)
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


// Quitar el primero                         
                         void LISTA::quitaPrimero()
                         { eliminar(1); renumerar();}
                         


// Quitar el úlimio                         
                         void LISTA::quitaUltimo()
                         { eliminar(fin->posicion); }
                         

// Limpiar Lista
                         void LISTA::limpiar()
                         { int i;
                           renumerar(); // Posicion relativa de esta lista 
                           for(i=fin->posicion;i>=raiz->posicion;i--)
                              eliminar(i);                              
                         }


// Eliminar un nodo para Josephus
                         void LISTA::eliminar_Josephus(NODO* ubicador)
                         { (ubicador->anterior)->siguiente=ubicador->siguiente;
                           (ubicador->siguiente)->anterior=ubicador->anterior;
                           raiz=fin=ubicador->siguiente;
                           delete ubicador;
                         }


// Union de listas
                        void LISTA::unir(LISTA& lis, int posicion)
                        { fin->siguiente=lis.regresaNth(posicion);
                          fin=lis.final();
                        }
