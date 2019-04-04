/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  PILA STRING                    =
    =                                                                       =
    =========================================================================*/


#include "Pilas.h"
#include <cstdlib>
#include <iostream>
using namespace std;


/*  =========================================================================
    =                                                                       =
    =                       Destructor y constructores                      =
    =                                                                       =
    =========================================================================*/

    PILAS::~PILAS() { limpiar(); delete raiz; }

    PILAS::PILAS()  { NODOS* a=new NODOS(1,"v_a_c_i_o",NULL,NULL); raiz=a; fin=a; }

    PILAS::PILAS(int N)  // N elementos con contenido cero
         { raiz=NULL;
           for(int i=0;i<N;i++)
              { NODOS *a=new NODOS(N-i,"",NULL,raiz);
                raiz=a;
                if(i==0)fin=a;
                if(i!=0)((a->siguiente)->anterior)=raiz;
              }
         }

    PILAS::PILAS(int N, string VAL)  // N elemetos con contenido VAL
         { raiz=NULL;
           for(int i=0;i<N;i++)
              { NODOS *a=new NODOS(N-i,VAL,NULL,raiz);
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

    NODOS* PILAS::inicio() { return raiz; }             // Apuntador al inicio
    NODOS* PILAS::final()  { return fin; }              // Apuntador al final

    // Insertar al Inicio
    void PILAS::insertaInicio(string VAL)
      { NODOS *a=new NODOS(1,VAL,NULL,raiz); 
        raiz->anterior=a; raiz=a; renumerar(); }

    // Inserta al Final
    void PILAS::insertaFinal(string VAL)
      { NODOS *a=new NODOS((fin->posicion+1),VAL,fin,NULL); 
        fin->siguiente=a; fin=a; }

    // Longitud de la PILAS
    int PILAS::longitud() {return (fin->posicion);}
                                                  
    // Buscar un valor y regresa la posicion
    int PILAS::encuentra(string VAL)
      { NODOS* ubicador; int contador=0; ubicador=raiz;
        while(ubicador!=NULL)
          { if (ubicador->contenido==VAL) return contador;
            else { contador++; ubicador=ubicador->siguiente; }}
        return -1; }

    // Regresa el apuntador al n-esimo elemento
    NODOS* PILAS::regresaNth(int Posicion)
      { NODOS* ubicador;
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
    =                       PUSH Y POP DE LIFO pila                         =
    =                                                                       =
    =========================================================================*/

    void PILAS::push(string VAL)
      { if(fin->contenido=="v_a_c_i_o") fin->contenido=VAL;
        else insertaFinal(VAL); 
      }

    string PILAS::pop()
      { string VAL=(fin->contenido); eliminar(fin->posicion); return VAL; }
    
    string PILAS::see()
      { return (fin->contenido); }
      

    void PILAS::set(int Pos, string VAL)
      { if(Pos>0&&Pos<=(fin->posicion)) cambioValor(Pos,VAL); } 

    string PILAS::get(int Pos)
      { if(Pos>0&&Pos<=(fin->posicion)) return ((regresaNth(Pos)->contenido));
        else return " Posicion invalida "; }



/*  =========================================================================
    =                                                                       =
    =                          Modificaciones                               =
    =                                                                       =
    =========================================================================*/

    // Cambio de valor en tal posicion
    void PILAS::cambioValor(int Posicion, string VAL)
      { if(Posicion>0&&Posicion<=(fin->posicion))
          { NODOS* ubicador; 
            ubicador=regresaNth(Posicion);
            if(ubicador!=NULL) ubicador->contenido=VAL;
      }   }
                         
    // Cambio de posicion  (CAMBIA LOS VALORES)
    void PILAS::cambioPosicion(int P1, int P2)
      { if(P1>0&&P1<=(fin->posicion)&&P2>0&&P2<=(fin->posicion))
          { string VAL=(regresaNth(P2)->contenido);
            (regresaNth(P2)->contenido)=(regresaNth(P1)->contenido);
            (regresaNth(P1)->contenido)=VAL;
      }   }

    // Renumerador
    void PILAS::renumerar()
      { NODOS* ubicador; int i; ubicador=raiz;
        for(i=1;ubicador!=fin;i++) 
           { ubicador->posicion=i; ubicador=ubicador->siguiente; }
        fin->posicion=i; }


/*  =========================================================================
    =                                                                       =
    =                          Eliminaciones                                =
    =                                                                       =
    =========================================================================*/


    // Eliminar un NODO
    void PILAS::eliminar(int Posicion)
      { if(Posicion>0&&Posicion<=(fin->posicion))
          { NODOS* ubi=regresaNth(Posicion);
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
                       ubi->contenido="v_a_c_i_o";
                       ubi->posicion=1;
                       ubi->anterior=NULL;
                       ubi->siguiente=NULL;
                     }
                 }
                           
            if (raiz!=fin) { delete ubi; renumerar(); }
      }   }

                         
    // Limpiar PILAS
    void PILAS::limpiar()
      { int i; for(i=fin->posicion;i>=raiz->posicion;i--) eliminar(i); }



/*  =========================================================================
    =                                                                       =
    =                            Impresión                                  =
    =                                                                       =
    =========================================================================*/

    void PILAS::imprimir()
      { NODOS* ubi=raiz;
        string str;  
        cout<<"\n\n";
        for(int i=1;i<=(fin->posicion);i++)
          {cout<<"\n\t["<<ubi->posicion<<"] = ";
           str=ubi->contenido;
           cout<<str; 
           ubi=ubi->siguiente; }
        cout<<"\n\n";   
      }
