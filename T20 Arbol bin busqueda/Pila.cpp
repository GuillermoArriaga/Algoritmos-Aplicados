/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  PILA  int                   =
    =                                                                       =
    =========================================================================*/


#include "Pila.h"
#include <cstdlib>
#include <iostream>
using namespace std;


/*  =========================================================================
    =                                                                       =
    =                       Destructor y constructores                      =
    =                                                                       =
    =========================================================================*/

    PILA::~PILA() { limpiar(); delete raiz; }

    PILA::PILA()  { NODOD* a=new NODOD(1,-123456789,NULL,NULL); raiz=a; fin=a; }

    PILA::PILA(int N)  // N elementos con contenido cero
         { raiz=NULL;
           for(int i=0;i<N;i++)
              { NODOD *a=new NODOD(N-i,0,NULL,raiz);
                raiz=a;
                if(i==0)fin=a;
                if(i!=0)((a->siguiente)->anterior)=raiz;
              }
         }

    PILA::PILA(int N, int VAL)  // N elemetos con contenido VAL
         { raiz=NULL;
           for(int i=0;i<N;i++)
              { NODOD *a=new NODOD(N-i,VAL,NULL,raiz);
                raiz=a;
                if(i==0)fin=a;       
                if(i!=0)((a->siguiente)->anterior)=raiz;
              }
         }


/*  =========================================================================
    =                                                                       =
    =                                Métodos                                =
    =                                                                       =
    =========================================================================*/

    NODOD* PILA::inicio() { return raiz; }             // Apuntador al inicio
    NODOD* PILA::final()  { return fin; }              // Apuntador al final

    // Inserta al Final
    void PILA::insertaFinal(int VAL)
      { NODOD *a=new NODOD((fin->posicion+1),VAL,fin,NULL); 
        fin->siguiente=a; fin=a; }

    // Longitud de la lista
    int PILA::longitud() {return fin->posicion;}
                                                  
    // Buscar un valor y regresa la posicion
    int PILA::encuentra(int VAL)
      { NODOD* ubicador; int contador=0; ubicador=raiz;
        while(ubicador!=NULL)
          { if (ubicador->contenido==VAL) return contador;
            else { contador++; ubicador=ubicador->siguiente; }}
        return -1; }

    // Regresa el apuntador al n-esimo elemento
    NODOD* PILA::regresaNth(int Posicion)
      { NODOD* ubicador;
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


/*  =========================================================================
    =                                                                       =
    =                       PUSH Y POP DE LIFO PILA STACK                   =
    =                                                                       =
    =========================================================================*/

    void PILA::push(int VAL)
      { if(fin->contenido==-123456789) fin->contenido=VAL;
        else insertaFinal(VAL); 
      }

    int PILA::pop()
      { int val=(fin->contenido); quitaUltimo(); return val; }
    
    int PILA::pop_cola()
      { int val=(raiz->contenido); eliminar(1); return val; }
          
    int PILA::see()
      { return (fin->contenido); } 

    void PILA::set(int Pos, int Val)
      { if(Pos>0&&Pos<=(fin->posicion)) cambioValor(Pos,Val); } 

    int PILA::get(int Pos)
      { if(Pos>0&&Pos<=(fin->posicion)) return ((regresaNth(Pos)->contenido));
        else return -1; }



/*  =========================================================================
    =                                                                       =
    =                          Modificaciones                               =
    =                                                                       =
    =========================================================================*/

    // Cambio de valor en tal posicion
    void PILA::cambioValor(int Posicion, int VAL)
      { if(Posicion>0&&Posicion<=(fin->posicion))
          { NODOD* ubicador; 
            ubicador=regresaNth(Posicion);
            if(ubicador!=NULL) ubicador->contenido=VAL;
      }   }
                         
    // Cambio de posicion  (CAMBIA LOS VALORES)
    void PILA::cambioPosicion(int P1, int P2)
      { if(P1>0&&P1<=(fin->posicion)&&P2>0&&P2<=(fin->posicion))
          { int val=(regresaNth(P2)->contenido);
            (regresaNth(P2)->contenido)=(regresaNth(P1)->contenido);
            (regresaNth(P1)->contenido)=val;
      }   }

    // Renumerador
    void PILA::renumerar()
      { NODOD* ubicador; int i; ubicador=raiz;
        for(i=1;ubicador!=fin;i++) 
           { ubicador->posicion=i; ubicador=ubicador->siguiente; }
        fin->posicion=i; }


/*  =========================================================================
    =                                                                       =
    =                          Eliminaciones                                =
    =                                                                       =
    =========================================================================*/


    // Eliminar un nodo
    void PILA::eliminar(int Posicion)
      { if(Posicion>0&&Posicion<=(fin->posicion))
          { NODOD* ubi=regresaNth(Posicion);
            if(ubi->siguiente!=NULL)                     // No es el ultimo
              { if(ubi->anterior!=NULL)          // No es ultimo ni primero
                  {(ubi->anterior)->siguiente=ubi->siguiente;
                   (ubi->siguiente)->anterior=ubi->anterior;
                  } 
                else{ raiz=ubi->siguiente;     // Es el primero y no ultimo
                      raiz->anterior=NULL;
              }     }

            else { if(ubi->anterior!=NULL) // Es el ultimo y no primero
                     { (ubi->anterior)->siguiente=NULL; fin=ubi->anterior; }  
                   else   // Si es el primero y el último, deja con valor cero
                     { raiz=fin=ubi;
                       ubi->contenido=-123456789; // Para identificar lo nuevo
                       ubi->posicion=1;
                       ubi->anterior=NULL;
                       ubi->siguiente=NULL;
                     }
                 }
                           
            if (raiz!=fin) { delete ubi; renumerar(); }
      }   }

    
    // Quitar el úlimio
    void PILA::quitaUltimo()  { eliminar(fin->posicion); }
                         
    // Limpiar Pila
    void PILA::limpiar()
      { int i; for(i=fin->posicion;i>=raiz->posicion;i--) eliminar(i); }



/*  =========================================================================
    =                                                                       =
    =                            Impresión                                  =
    =                                                                       =
    =========================================================================*/

    void PILA::imprimir()
      { NODOD* ubi=raiz;  
        cout<<"\n\n";
        for(int i=1;i<=(fin->posicion);i++)
          {cout<<"\n\t["<<ubi->posicion<<"] = ";
           if(ubi->contenido==-123456789) cout<<" \\ VACIO / ";
           else cout<<(ubi->contenido); 
           ubi=ubi->siguiente; }
        cout<<"\n\n";   
      }
