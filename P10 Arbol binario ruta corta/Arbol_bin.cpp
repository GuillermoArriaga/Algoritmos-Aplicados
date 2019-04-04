/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  ARBOL BINARIO                  =
    =                                                                       =
    =                       PRÁCTICA 10 ( y 9 )                             =
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
        obtener_posiciones();
      }

    ARBOL_BIN::ARBOL_BIN(double cont)
      { NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN();
        a->contenido=cont;
        raiz=a;
        ubicador=a;
        final=a;
        obtener_posiciones();
      }
      
    ARBOL_BIN::ARBOL_BIN(int elem)              // Crea un árbol binario con n elementos
      { NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(); // de arriba a abajo y de izq. a derecha.
        raiz=a;
        ubicador=a;
        final=a;
        if (elem<1) elem=1;
        for(int i=1;i<elem;i++) agregar_inicio(0);
        obtener_posiciones();
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
         { ubicador=raiz; }
    
    void ARBOL_BIN::forth() // Nos desplaza a la derecha
         { 
           if(ubicador==final) return;
           obtener_posiciones();
           int i,j;
           for(i=0;i<ccpp;i++) if(ubicador->posicion==vector[i]){j=i;i=ccpp;}
           ubicador=apuntador_a(vector[j+1]);
         } 

    void ARBOL_BIN::forth(NODO_ARBOL_BIN* &ubi)
         { if(ubi==final) return;
           obtener_posiciones();
           int i,j;
           for(i=0;i<ccpp;i++) if((ubi->posicion)==vector[i]) {j=i; i=ccpp;}
           ubi=apuntador_a(vector[j+1]);
         } 


    void ARBOL_BIN::back()  // Se desplaza a la izquierda
         { if(ubicador==raiz) return;
           obtener_posiciones();
           int i,j;
           for(i=0;i<ccpp;i++) if(ubicador->posicion==vector[i]){j=i;i=ccpp;}
           ubicador=apuntador_a(vector[j]);
         }
         
    void ARBOL_BIN::up()    // Se desplaza hacia arriba
         { if(ubicador!=raiz) ubicador=ubicador->padre; }
         
    void ARBOL_BIN::end()   // Nos lleva al último nodo
         { ubicador=final; }
         
    void ARBOL_BIN::go_to(int posicion)   // Nos desplaza a tal posición
         { if(1==existe(posicion)) ubicador=apuntador_a(posicion);}
         
    int ARBOL_BIN::existe(int posicion)
         { obtener_posiciones();
           for(int i=0;i<ccpp;i++) {if(posicion==vector[i]) return 1;}
           return 0; }

    NODO_ARBOL_BIN* ARBOL_BIN::ubica() // Da la posicion en la que estamos
         { return ubicador; }

    void ARBOL_BIN::left()                             // Se va al hijo izq
         {if(ubicador->izq!=NULL) ubicador=ubicador->izq;}

    void ARBOL_BIN::right()                            // Se va al hijo der
         {if(ubicador->der!=NULL) ubicador=ubicador->der;}


         
    NODO_ARBOL_BIN* ARBOL_BIN::apuntador_a(int posicion)
         { NODO_ARBOL_BIN* ubi=raiz;
           
           // Busqueda de la trayectoria
           PILA pil;                  // Para guardar la trayectoria
           int pos_rel=posicion,contador=0;
           while(pos_rel>0) {pil.push(pos_rel); contador++; pos_rel/=2; }
           pil.pop(); contador--;
           
           // Seguimiento de la trayectoria
           while(contador!=0)         // Mueve a ubicador desde la raiz hasta 
            { int p=pil.pop();        // la posicion deseada a través de padres
              if (p%2==0) ubi=ubi->izq;
              else ubi=ubi->der;
              if (ubi==NULL) return NULL;
              contador--;
            }
           return ubi;
         }

    



/*  =========================================================================
    =                                                                       =
    =                          Modificaciones                               =
    =                                                                       =
    =========================================================================*/

    void ARBOL_BIN::agregar_inicio(double cont)  // Agrega en anchura inicial
         { if (final==raiz)                                    // Primogénito
             { NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,raiz,'i');
               raiz->izq=a;
               final=a;
               return;
             }
           NODO_ARBOL_BIN* ubi;
           int pos_rel=final->posicion;
                                            // Si el último es hijo izquierdo
           if((pos_rel%2)==0) 
             { pos_rel/=2; // Posicion del padre
               ubi=apuntador_a(pos_rel);
               NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,ubi,'d');
               ubi->der=a;
               final=a;
               return;
             }
           if((pos_rel%2)==1)                 // Si el último es hijo derecho
             { pos_rel++; pos_rel/=2; // Posicion del padre
               ubi=apuntador_a(pos_rel);
               NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,ubi,'i');
               ubi->izq=a;
               final=a;
               return;
             }
         }

    void ARBOL_BIN::agregar(double cont) // Agrega en el primer hueco (anchura)
         { obtener_posiciones();
           // Detecta el primer hueco
           int i,j=-1;
           for(i=0;i<ccpp-1;i++)if(vector[i+1]>vector[i]+1){j=vector[i];i=ccpp;}
           if(j==-1) j=vector[ccpp-1];
           
           // Inserta en el primer hueco
                      
           if (j==1)                                           // Primogénito
             { NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,raiz,'i');
               raiz->izq=a;
               obtener_posiciones();
               return;
             }
           NODO_ARBOL_BIN* ubi;
                                            // Si el último es hijo izquierdo
           if((j%2)==0) 
             { j/=2; // Posicion del padre
               ubi=apuntador_a(j);
               NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,ubi,'d');
               ubi->der=a;
               obtener_posiciones();
               return;
             }
           if((j%2)==1)                      // Si el último es hijo derecho
             { j++; j/=2; // Posicion del padre
               ubi=apuntador_a(j);
               NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,ubi,'i');
               ubi->izq=a;
               obtener_posiciones();
               return;
             } 
         }

         
    void ARBOL_BIN::agregar(double cont,char hijo,NODO_ARBOL_BIN* papa)
         { if(hijo!='d'&&hijo!='D') hijo='i'; // Ajuste de datos
           if(hijo=='i'||hijo=='I')                    // Si es hijo izquierdo
             { if (papa->izq==NULL) 
                  { NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,papa,'i');
                    papa->izq=a;
                  }
               else {limpiar(papa->izq);
                     NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,papa,'i');
                     papa->izq=a;
                    }
             }
           if(hijo=='d'||hijo=='D')                      // Si es hijo derecho
             { if (papa->der==NULL) 
                  { NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,papa,'d');
                    papa->der=a;
                  }
               else {limpiar(papa->der);
                     NODO_ARBOL_BIN* a=new NODO_ARBOL_BIN(cont,papa,'d');
                     papa->der=a;
                    }
             }
         }

    
    void ARBOL_BIN::modificar(int pos, double cont)
         { if(existe(pos)==1) apuntador_a(pos)->contenido=cont; }



/*  =========================================================================
    =                                                                       =
    =                          Eliminaciones                                =
    =                                                                       =
    =========================================================================*/

    void ARBOL_BIN::limpiar(NODO_ARBOL_BIN* nodo)
         { if(nodo->izq!=NULL) limpiar(nodo->izq);
           if(nodo->der!=NULL) limpiar(nodo->der);
           if(nodo==raiz) return;
           if((nodo->posicion)%2==0) nodo->padre->izq=NULL;
           else nodo->padre->der=NULL;
           delete nodo;
         }



/*  =========================================================================
    =                                                                       =
    =                        Impresiones Especiales                         =
    =                                                                       =
    =========================================================================*/

    template<class G>
    void ARBOL_BIN::printnode(G x, int h)
    { for(int i=0;i<h;i++) cout<<"    ";
      if(x==-1) cout<<" *"<<"\n\t";
      else cout<<" "<<x<<"\n\t";
    }

    void ARBOL_BIN::show(NODO_ARBOL_BIN* t, int h)
    { if(t==0) { printnode(-1,h); return; }
      show(t->der,h+1);
      printnode(t->posicion,h);
      show(t->izq,h+1);
    }

    void ARBOL_BIN::imprimir_posiciones()
    { cout<<"\n\n\tEl arbol actual tiene tales posiciones habilitadas:\n\t";
      obtener_posiciones(); for(int i=0;i<ccpp;i++) cout<<vector[i]<<" ";
      cout<<"\n\n\n\t";
      show(raiz,0);
    }

    void ARBOL_BIN::imprimir_valores()
    { cout<<"\n\n\tLos valores son:\n\n\n\t"; show_val(raiz,0); }

    void ARBOL_BIN::show_val(NODO_ARBOL_BIN* t, int h)
    { if(t==0)  return; 
      show_val(t->der,h+1);
      printnode(t->contenido,h);
      show_val(t->izq,h+1);
    }


    void ARBOL_BIN::imprimir_distancias()
    { cout<<"\n\n\tLas distancias relativas son:\n\n\n\t"; show_dist(raiz,0); }


    void ARBOL_BIN::show_dist(NODO_ARBOL_BIN* t, int h)
    { if(t==0) return;
      show_dist(t->der,h+1);
      printnode(t->distancia,h);
      show_dist(t->izq,h+1);
    }

    int ARBOL_BIN::calcular_dist(int p1,int p2)
    { if(existe(p1)==0||existe(p2)==0) return -1;
         
      PILA cola;
      
      limpiar_distancias(raiz); // ... y pone que no han sido visitados.
            
      int encontrado=0;
      int pos;
      NODO_ARBOL_BIN *ubi=apuntador_a(p1);
      
      cola.push(p1);           // Primer nodo visitado
      
      
      while(encontrado==0)
      {
        pos=cola.pop_cola();
        ubi=apuntador_a(pos);
        ubi->visitado=0;
        
        if(pos==p2) { encontrado=1; return ubi->distancia; }
        
        if(ubi->padre!=NULL&&ubi->padre->visitado==1) // Si el padre existe
         { ubi->padre->distancia=ubi->distancia+1; 
           cola.push(ubi->padre->posicion);
         }
        
        if(ubi->izq!=NULL&&ubi->izq->visitado==1) // Si el izq existe
         { ubi->izq->distancia=ubi->distancia+1; 
           cola.push(ubi->izq->posicion);
         }

        if(ubi->der!=NULL&&ubi->der->visitado==1) // Si el der existe
         { ubi->der->distancia=ubi->distancia+1; 
           cola.push(ubi->der->posicion);
         }
      }  
    }

    
    void ARBOL_BIN::calcular_distancias(int posicion)
    { if(existe(posicion)==0) return;
      NODO_ARBOL_BIN *ubi;
      ubi=apuntador_a(posicion);
      limpiar_distancias(raiz);
      obtener_posiciones();
      
      delete vv;
      vv=new int[ccpp+1];   // Almacena si ya se pasó por tal posicion.(~vector)
      for(int i=0;i<=ccpp;i++) {vv[i]=1;} vv[0]=0;      
      
      caldis(ubi);
    }  
    
    void ARBOL_BIN::caldis(NODO_ARBOL_BIN *ubi)
    { if(ubi==NULL) return;

      // Asignaciones de distancias alrededor de ubi (nodo)

      vv[buscar(ubi->posicion)]=0;                // Marca de que ha pasado
      
      if(ubi->izq!=NULL) if(vv[buscar(ubi->izq->posicion)]==1)    // Izquierdo
        { ubi->izq->distancia=ubi->distancia+1; }
      if(ubi->der!=NULL) if(vv[buscar(ubi->der->posicion)]==1)      // Derecho
        { ubi->der->distancia=ubi->distancia+1; }
      if(ubi->padre!=NULL) if(vv[buscar(ubi->padre->posicion)]==1)     // Papa
        { ubi->padre->distancia=ubi->distancia+1; }

      // Recursividad si los nodos de alrededor no son null o visitados
      if(ubi->izq!=NULL) if(vv[buscar(ubi->izq->posicion)]==1) caldis(ubi->izq);
      if(ubi->der!=NULL) if(vv[buscar(ubi->der->posicion)]==1) caldis(ubi->der);
      if(ubi->padre!=NULL) if(vv[buscar(ubi->padre->posicion)]==1) caldis(ubi->padre);

    }
    
    int ARBOL_BIN::buscar(int pos)
        { for(int i=0;i<ccpp;i++) if(vector[i]==pos) return i+1;  return 0;}
    
    void ARBOL_BIN::limpiar_distancias(NODO_ARBOL_BIN* nodo)
    { nodo->distancia=0; nodo->visitado=1;
      if(nodo->izq!=NULL) limpiar_distancias(nodo->izq);
      if(nodo->der!=NULL) limpiar_distancias(nodo->der);
    }


/*  =========================================================================
    =                                                                       =
    =                        Impresiones Usuales                            =
    =                                                                       =
    =========================================================================*/


    // Preorden    
    void ARBOL_BIN::imprimirPreorden()
    { cout<<"\n\n\tIMPRESION EN PREORDEN (Y,I,D) : \n\t";
      NODO_ARBOL_BIN* ubi=raiz;
      imprimirPreorden(ubi);
      cout<<"\n\n\t"; system("pause");
    }
    
    void ARBOL_BIN::imprimirPreorden(NODO_ARBOL_BIN* nodo)       // yo izq der
    { cout<<"\n\t[ "<<nodo->posicion<<" ]\t=   "<<nodo->contenido;
      if(nodo->izq!=NULL) imprimirPreorden(nodo->izq);
      if(nodo->der!=NULL) imprimirPreorden(nodo->der);
    }


    // Postorden
    void ARBOL_BIN::imprimirPostorden()
    { cout<<"\n\n\tIMPRESION EN POSTORDEN (I,D,Y) : \n\t";
      NODO_ARBOL_BIN* ubi=raiz;
      imprimirPostorden(ubi);
      cout<<"\n\n\t"; system("pause");
    }

    void ARBOL_BIN::imprimirPostorden(NODO_ARBOL_BIN* nodo)      // izq der yo
    { if(nodo->izq!=NULL) imprimirPostorden(nodo->izq);
      if(nodo->der!=NULL) imprimirPostorden(nodo->der);
      cout<<"\n\t[ "<<nodo->posicion<<" ]\t=   "<<nodo->contenido;
    }


    // Inorden
    void ARBOL_BIN::imprimirInorden()
    { cout<<"\n\n\tIMPRESION EN INORDEN (I,Y,D) : \n\t";
      NODO_ARBOL_BIN* ubi=raiz;
      imprimirInorden(ubi);
      cout<<"\n\n\t"; system("pause");
    }
    
    void ARBOL_BIN::imprimirInorden(NODO_ARBOL_BIN* nodo)        // izq yo der
    { if(nodo->izq!=NULL) imprimirInorden(nodo->izq);
      cout<<"\n\t[ "<<nodo->posicion<<" ]\t=   "<<nodo->contenido;
      if(nodo->der!=NULL) imprimirInorden(nodo->der);
    }


    void ARBOL_BIN::imprimirAnchura()
    { cout<<"\n\n\tIMPRESION EN ANCHURA : \n\t";
      NODO_ARBOL_BIN* ubi=raiz;
      for(int i=0;i<ccpp;i++)
      { cout<<"\n\t[ "<<ubi->posicion<<" ]\t=   "<<ubi->contenido;
         forth(ubi);
      }
      
      cout<<"\n\n\t"; system("pause");
    }


    // Obtener de posiciones
    
    void ARBOL_BIN::obtener_posiciones()
    { NODO_ARBOL_BIN* ubic=raiz;
                             // Encuentra la cantidad de posiciones utilizadas
      ccpp=0;
      cantidad_posiciones(ubic,ccpp);
                              // Crea un vector que almacene dichas posiciones
      int i=0; ubic=raiz;
      delete vector; vector=new int[ccpp];
      guardar_posiciones(ubic,vector,i);
                          // Acomodo de posiciones de menor a mayor con Bubble
      for(int j=ccpp-1;j>0;j--) for(int k=2;k<=j;k++)
      { if(vector[k-1]>vector[k])
          {i=vector[k-1]; vector[k-1]=vector[k]; vector[k]=i;} }
      
      final=apuntador_a(vector[ccpp-1]);
      // Ahora ya están actualizadas las variables globales vector y ccpp
      // Y el final apunta al último
    }

    void ARBOL_BIN::cantidad_posiciones(NODO_ARBOL_BIN* nodo,int &cantidad)
    { if(nodo->izq!=NULL) cantidad_posiciones(nodo->izq,cantidad);
      if(nodo->der!=NULL) cantidad_posiciones(nodo->der,cantidad);
      cantidad++;
    }

    void ARBOL_BIN::guardar_posiciones(NODO_ARBOL_BIN* nodo,int *vector,int &i)
    { vector[i]=nodo->posicion; i++;
      if(nodo->izq!=NULL) guardar_posiciones(nodo->izq,vector,i);
      if(nodo->der!=NULL) guardar_posiciones(nodo->der,vector,i);
    }
