/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  ARBOL BINARIO                  =
    =                                                                       =
    =========================================================================*/


#include "Arbol_bin.h"
#include <cstdlib>
#include <iostream>
using namespace std;


/*  =========================================================================
    =                                                                       =
    =                       Destructor y constructores                      =
    =                                                                       =
    =========================================================================*/

    ARBOL_BIN::~ARBOL_BIN() { limpiar(raiz); delete raiz;}

    ARBOL_BIN::ARBOL_BIN()  
      { NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN();
        raiz=a;
        ubicador=a;
        final=a;
      }

    ARBOL_BIN::ARBOL_BIN(double cont)
      { NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN();
        a->contenido=cont;
        raiz=a;
        ubicador=a;
        final=a;
      }
      
    ARBOL_BIN::ARBOL_BIN(int elem)              // Crea un árbol binario con n elementos
      { NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(); // de arriba a abajo y de izq. a derecha.
        raiz=a;
        ubicador=a;
        final=a;
        if (elem<1) elem=1;
        for(int i=1;i<elem;i++) agregar(1.2);
      }


/*  =========================================================================
    =                                                                       =
    =                                Métodos                                =
    =                                                                       =
    =========================================================================*/


/*  =========================================================================
    =                                                                       =
    =                              Ubicación                                =
    =                                                                       =
    =========================================================================*/


    void ARBOL_BIN::start() // Nos ubica en el inicio
         {ubicador=raiz;}
    
    void ARBOL_BIN::forth() // Nos desplaza a la derecha
         { int i=1;
           if (ubicador->posicion+1<=final->posicion)
               { if(ubicador->posicion+1!=NULL)
                    ubicador=apuntador_a(ubicador->posicion+1);
                 else 
                  { while(ubicador->posicion+i<=final->posicion &&
                          apuntador_a(ubicador->posicion+i)==NULL) i++;
                    if(ubicador->posicion+i<=final->posicion)
                       ubicador=apuntador_a(ubicador->posicion+i);
                    else ubicador=final;   
                  }
               }  
         }
         
    void ARBOL_BIN::end()   // Nos lleva al último nodo
         { ubicador=final;}
         
    void ARBOL_BIN::go_to(int posicion)   // Nos desplaza a tal posición
         { if(posicion<=final->posicion) ubicador=apuntador_a(posicion);}
         
    NODO_ARBOL_BIN* ARBOL_BIN::apuntador_a(int posicion)
         { if(posicion>final->posicion) return NULL;
           
           // Busqueda de la trayectoria
           PILA pil;                  // Para guardar la trayectoria
           int pos_rel=posicion,contador=0;
           while(pos_rel>0) {pil.push(pos_rel); contador++; pos_rel/=2; }
           pil.pop(); start(); contador--;
           
           // Seguimiento de la trayectoria
           while(contador!=0)         // Mueve a ubicador desde la raiz hasta 
            { int p=pil.pop();        // la posicion deseada a través de padres
              if (p%2==0) left();     
              else right();
              if (ubicador==NULL) return NULL;
              contador--;
            }
           return ubicador;
         }

         
    NODO_ARBOL_BIN* ARBOL_BIN::ubica() // Da la posicion en la que estamos
         { return ubicador; }

    void ARBOL_BIN::left() {ubicador=ubicador->izq;} // Se va al hijo izq
    void ARBOL_BIN::right(){ubicador=ubicador->der;} // Se va al hijo der






/*  =========================================================================
    =                                                                       =
    =                          Modificaciones                               =
    =                                                                       =
    =========================================================================*/

    void ARBOL_BIN::agregar(double cont)
         { if (final==raiz)                // Si es el primer hijo
             { NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,raiz,'i');
               raiz->izq=a;
               final=a;
               return;
             }
/*           if (final->posicion==2)        // Si es el segundo hijo
             { NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,raiz,'d');
               raiz->der=a;
               final=a;
               return;
             }
*/             
           int pos_rel=final->posicion;
           // Si el último es hijo izquierdo
           if((pos_rel%2)==0) 
             { pos_rel/=2; // Posicion del padre
               ubicador=apuntador_a(pos_rel);
               NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,ubicador,'d');
               ubicador->der=a;
               final=a;
               return;
             }
           if((pos_rel%2)==1)  // Si el último es hijo derecho
             { pos_rel++; pos_rel/=2; // Posicion del padre
               ubicador=apuntador_a(pos_rel);
               NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,ubicador,'i');
               ubicador->izq=a;
               final=a;
               return;
             }
         }
         
    void ARBOL_BIN::agregar(double cont,char hijo,NODO_ARBOL_BIN* papa)
         { if(hijo!='d'&&hijo!='D') hijo='i'; // Ajuste de datos
           if(hijo=='i'||hijo=='I') // Si es hijo izquierdo
             { if (papa->izq==NULL) 
                  { NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,papa,'i');
                    papa->izq=a;
                  }
               else {cout<<"\n\tNo se puede agregar en esa posicion."; system("pause");}
             }
           if(hijo=='d'||hijo=='D') // Si es hijo derecho
             { if (papa->der==NULL) 
                  { NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,papa,'d');
                    papa->der=a;
                  }
               else {cout<<"\n\tNo se puede agregar en esa posicion."; system("pause");}
             }
         }

    
    void ARBOL_BIN::modificar(int pos, double cont)
         { if(pos<=final->posicion) apuntador_a(pos)->contenido=cont; }



/*  =========================================================================
    =                                                                       =
    =                          Eliminaciones                                =
    =                                                                       =
    =========================================================================*/

    void ARBOL_BIN::limpiar(NODO_ARBOL_BIN* nodo)
         { if(nodo->izq!=NULL) limpiar(nodo->izq);
           if(nodo->der!=NULL) limpiar(nodo->der);
           nodo->izq=NULL;
           nodo->der=NULL;
           if(nodo==raiz) return;
           if((nodo->posicion)%2==0)
             apuntador_a((nodo->posicion)/2)->izq=NULL;
           if((nodo->posicion)%2==1)
             apuntador_a((nodo->posicion)/2)->der=NULL;
           delete nodo;
         }



/*  =========================================================================
    =                                                                       =
    =                            Impresión                                  =
    =                                                                       =
    =========================================================================*/

    void ARBOL_BIN::printnode(int x, int h)
    { for(int i=0;i<h;i++) cout<<"  ";
      if(x==-1) cout<<" *"<<"\n\t";
      else cout<<x<<"\n\t";
    }

    void ARBOL_BIN::show(NODO_ARBOL_BIN* t, int h)
    { if(t==0) { printnode(-1,h); return; }
      show(t->der,h+1);
      printnode(t->posicion,h);
      show(t->izq,h+1);
    }

    void ARBOL_BIN::imprimir_posiciones()
    { cout<<"\n\n\tEl arbol actual tiene tales posiciones habilitadas: [1,"
          <<final->posicion<<"]\n\n\t";
      show(raiz,0);
    }


    // Preorden    
    void ARBOL_BIN::imprimirPreorden()
    { cout<<"\n\n\tIMPRESION EN PREORDEN (Y,I,D) : \n\t";
      start();
      imprimirPreorden(ubicador);
      cout<<"\n\n\t"; system("pause");
    }
    
    void ARBOL_BIN::imprimirPreorden(NODO_ARBOL_BIN* nodo)       // yo izq der
    { cout<<"\n\t[ "<<nodo->posicion<<" ]\t=\t"<<nodo->contenido;
      if(nodo->izq!=NULL) imprimirPreorden(nodo->izq);
      if(nodo->der!=NULL) imprimirPreorden(nodo->der);
    }


    // Postorden
    void ARBOL_BIN::imprimirPostorden()
    { cout<<"\n\n\tIMPRESION EN POSTORDEN (I,D,Y) : \n\t";
      start();
      imprimirPostorden(ubicador);
      cout<<"\n\n\t"; system("pause");
    }

    void ARBOL_BIN::imprimirPostorden(NODO_ARBOL_BIN* nodo)      // izq der yo
    { if(nodo->izq!=NULL) imprimirPostorden(nodo->izq);
      if(nodo->der!=NULL) imprimirPostorden(nodo->der);
      cout<<"\n\t[ "<<nodo->posicion<<" ]\t=\t"<<nodo->contenido;
    }


    // Inorden
    void ARBOL_BIN::imprimirInorden()
    { cout<<"\n\n\tIMPRESION EN INORDEN (I,Y,D) : \n\t";
      start();
      imprimirInorden(ubicador);
      cout<<"\n\n\t"; system("pause");
    }
    
    void ARBOL_BIN::imprimirInorden(NODO_ARBOL_BIN* nodo)        // izq yo der
    { if(nodo->izq!=NULL) imprimirInorden(nodo->izq);
      cout<<"\n\t[ "<<nodo->posicion<<" ]\t=\t"<<nodo->contenido;
      if(nodo->der!=NULL) imprimirInorden(nodo->der);
    }


    void ARBOL_BIN::imprimirAnchura()
    { cout<<"\n\n\tIMPRESION EN ANCHURA : \n\t";
      start();
      while (ubicador->posicion<final->posicion)
       { cout<<"\n\t[ "<<ubicador->posicion<<" ]\t=\t"<<ubicador->contenido;
         forth();
       }
      cout<<"\n\t[ "<<ubicador->posicion<<" ]\t=\t"<<ubicador->contenido;
      cout<<"\n\n\t"; system("pause");
      start();
    }
