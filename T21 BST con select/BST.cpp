/*  =========================================================================
    =                                                                       =
    =          Guillermo Arriaga García  ARBOL BINARIO DE BUSQUEDA          =
    =                                                                       =
    =                     (BST)      TAREA  20                              =
    =                                                                       =
    =========================================================================*/


#include "BST.h"
#include <cstdlib>
#include <iostream>
using namespace std;


/*  =========================================================================
    =                                                                       =
    =                       Destructor y constructores                      =
    =                                                                       =
    =========================================================================*/

    BST::~BST() 
    { if (raiz!=NULL) 
      { limpiar(raiz); 
        delete raiz;
      }
    }

    BST::BST()  
      { raiz=NULL;
        ubicador=NULL;
        final=NULL;
      }


    BST::BST(double cont)
      { NODO_BST* a=new NODO_BST();
        a->contenido=cont;
        raiz=a;
        ubicador=a;
        final=a;
        obtener_posiciones();
      }
      
    BST::BST(int elem)              // Crea un árbol binario con n elementos
      { NODO_BST* a=new NODO_BST(); // de arriba a abajo y de izq. a derecha.
        raiz=a;
        ubicador=a;
        final=a;
        if (elem<1) elem=1;
        for(int i=1;i<elem;i++) agregar_inicio(0);
        obtener_posiciones();
      }


/*  =========================================================================
    =                                                                       =
    =                          Métodos propios de ub BST                    =
    =                                                                       =
    =========================================================================*/



     NODO_BST* BST::minimo(NODO_BST* nod)
     { NODO_BST* ub=nod;
       while(ub->izq!=NULL)
       { ub=ub->izq;
       }
       return ub;
     }
     
     NODO_BST* BST::maximo(NODO_BST* nod)
     { NODO_BST* ub=nod;
       while(ub->der!=NULL)
       { ub=ub->der;
       }
       return ub;
     }
     
     NODO_BST* BST::sucesor(NODO_BST* nod)  // Mínimo valor >= a nod->contenido
     { if(nod->der!=NULL)
         return minimo(nod->der);
       NODO_BST* y=nod->padre;
       while(y!=NULL && nod==y->der)
            { nod=y;
              y=y->padre;
            }
       return y;     
     }
     
     NODO_BST* BST::predecesor(NODO_BST* nod) // Máximo valor <= a nod->contenido
     { if(nod->izq!=NULL)
         return maximo(nod->izq);
       NODO_BST* y=nod->padre;
       while(y!=NULL && nod==y->der)
            { nod=y;
              y=y->padre;
            }
       return y;     
     }

     NODO_BST* BST::buscar_val(double val)
     { return buscar_val(raiz,val);
     }

     NODO_BST* BST::buscar_val(NODO_BST* nod, double val)
     { if(nod==NULL||val==nod->contenido)
          return nod;
       if (val<nod->contenido)
          return buscar_val(nod->izq,val);
       else 
          return buscar_val(nod->der,val);
     }
            
     double BST::valor_de(int pos)
     { if(apuntador_a(pos)!=NULL)
          return apuntador_a(pos)->contenido;
       return -123456789;   
     }
     
     // El recorrido en orden recorre los elementos de modo creciente,
     // así que el posicion_ordenada requerido se obtiene con este recorrido.
     double BST::select(int pos_ord) 
     { int conta=0;
       NODO_BST *ubi2=NULL,*ubi=raiz; 
       if(ubi!=NULL) select_Inorden(ubi,conta,pos_ord,ubi2);
       if(ubi2!=NULL) return ubi2->contenido;
       return -123456789;
     }

    
    void BST::select_Inorden(NODO_BST* nodo,int &c,int &p,NODO_BST* &u)
    { if(c>p) return;
      if(nodo->izq!=NULL) select_Inorden(nodo->izq,c,p,u);
      c++;
      if(c==p) { u=nodo; return;}
      if(nodo->der!=NULL) select_Inorden(nodo->der,c,p,u);
    }



     void BST::insertar(double val)
     { NODO_BST* z=new NODO_BST;
       z->contenido=val;

       NODO_BST* y=NULL;
       NODO_BST* x=raiz;
       
       while(x!=NULL)
          { y=x;
            if(z->contenido<x->contenido)
              x=x->izq;
            else 
              x=x->der;
          }
            
       z->padre=y;
       if(y==NULL)
         { raiz=z;  // El arbol estaba vacío
           z->posicion=1;
         }  
       else if(z->contenido<y->contenido)
               { y->izq=z;
                 z->posicion=y->posicion*2;
               }  
            else
            { y->der=z;
              z->posicion=y->posicion*2+1;
            }  
          
     obtener_posiciones(); // Propio de mi modo de programar
     }
     
     void BST::borrar_nodo(NODO_BST* z)
     { NODO_BST* y;
       NODO_BST* x;

       if(z->izq==NULL||z->der==NULL)
         y=z;
       else y=sucesor(z);
       
       if(y->izq!=NULL)
         x=y->izq;
       else
         x=y->der;
       
       if(x!=NULL)
         x->padre=y->padre;
       
       if(y->padre==NULL)
         raiz=x;
       else if(y==y->padre->izq)
               y->padre->izq=x;
            else
               y->padre->der=x;
       if(y!=z)
         z->contenido=y->contenido;
         
       delete y;
         
     }
     
     // Para hacer rotaciones SIN FALLA los nodos deben tener dos hijos cada uno.
     
     void BST::rotar_der(NODO_BST* x) // Hijo izquierdo <-> su Padre
     { if(x==NULL) 
       return;
       // si x es la raiz se debe redirigir la operacion a:
       if(x==raiz&&x->der!=NULL)
         { rotar_der(x->izq); 
           return;
         }
       // x debe ser hijo izquierdo, si no se redirige a:
       if(x!=x->padre->izq&&x->der!=NULL)
         { rotar_der(x->izq); 
           return;
         }
       
       // Cumpliendo lo anterior, a rotar...
       NODO_BST* y=x->padre;
       y->izq=x->der;
       if(x->der!=NULL)
         x->der->padre=y;
       x->padre=y->padre;
       if(y->padre==NULL)
         raiz=x;
       else if(y==y->padre->izq)
               y->padre->izq=x;
            else 
               y->padre->der=x;
       x->der=y;
       y->padre=x;
       
       asignar_posiciones(); // Propio de mi modo de programar
       obtener_posiciones();       
     }



/*
     void BST::rotar_der(NODO_BST* y) // Hijo izquierdo <-> su Padre
     { NODO_BST* x=y->izq;
       y->izq=x->der;
       if(x->der!=NULL)
         x->der->padre=y;
       x->padre=y->padre;
       if(y->padre==NULL)
         raiz=x;
       else if(y==y->padre->izq)
               y->padre->izq=x;
            else 
               y->padre->der=x;
       x->der=y;
       y->padre=x;
       
       asignar_posiciones(); // Propio de mi modo de programar
       obtener_posiciones();       
     }

     
     void BST::rotar_izq(NODO_BST* x) // Hijo derecho <-> su Padre
     { 
       NODO_BST* y=x->der;
       
       x->der=y->izq;
       if(y->izq!=NULL)
         y->izq->padre=x;
       
       y->padre=x->padre;
       if(x->padre==NULL)
         raiz=y;
       else if(x==x->padre->izq)
               x->padre->izq=y;
            else 
               x->padre->der=y;
       y->izq=x;
       x->padre=y;
       
       asignar_posiciones(); // Propio de mi modo de programar
       obtener_posiciones();
     }
*/

     void BST::rotar_izq(NODO_BST* y) // Hijo derecho <-> su Padre
     { if(y==NULL) 
       return;
       // si y es la raiz se debe redirigir la operacion a:
       if(y==raiz)
         { rotar_izq(y->der);
           return;
         }
       // y debe ser hijo derecho, si no se redirige a:
       if(y!=y->padre->der)
         { rotar_izq(y->der);
           return;
         }
       
       // Cumpliendo lo anterior, a rotar...
       NODO_BST* x=y->padre;
       x->der=y->izq;
       if(y->izq!=NULL)
         y->izq->padre=x;
       y->padre=x->padre;
       if(x->padre==NULL)
         raiz=y;
       else if(x==x->padre->izq)
               x->padre->izq=y;
            else 
               x->padre->der=y;
       y->izq=x;
       x->padre=y;
       
       asignar_posiciones(); // Propio de mi modo de programar
       obtener_posiciones();
     }
     
     
     void BST::asignar_posiciones()
     { raiz->posicion=1;
       asignar_posiciones(raiz);
     }

     void BST::asignar_posiciones(NODO_BST* nod)
     { if(nod->izq!=NULL)
         { nod->izq->posicion=nod->posicion*2;
           asignar_posiciones(nod->izq);
         }  
       if(nod->der!=NULL)
         { nod->der->posicion=nod->posicion*2+1;
           asignar_posiciones(nod->der);
         }  
          
     }

/*  =========================================================================
    =                                                                       =
    =                          Métodos varios útiles                        =
    =                                                                       =
    =========================================================================*/


/*  =========================================================================
    =                                                                       =
    =                              Ubicación                                =
    =                                                                       =
    =========================================================================*/


    void BST::start() // Nos ubica en el inicio
         { ubicador=raiz; }
    
    void BST::forth() // Nos desplaza a la derecha
         { 
           if(ubicador==final) return;
           obtener_posiciones();
           int i,j;
           for(i=0;i<ccpp;i++) if(ubicador->posicion==vector[i]){j=i;i=ccpp;}
           ubicador=apuntador_a(vector[j+1]);
         } 

    void BST::forth(NODO_BST* &ubi)
         { if(ubi==final) return;
           obtener_posiciones();
           int i,j;
           for(i=0;i<ccpp;i++) if((ubi->posicion)==vector[i]) {j=i; i=ccpp;}
           ubi=apuntador_a(vector[j+1]);
         } 


    void BST::back()  // Se desplaza a la izquierda
         { if(ubicador==raiz) return;
           obtener_posiciones();
           int i,j;
           for(i=0;i<ccpp;i++) if(ubicador->posicion==vector[i]){j=i;i=ccpp;}
           ubicador=apuntador_a(vector[j]);
         }
         
    void BST::up()    // Se desplaza hacia arriba
         { if(ubicador!=raiz) ubicador=ubicador->padre; }
         
    void BST::end()   // Nos lleva al último nodo
         { ubicador=final; }
         
    void BST::go_to(int posicion)   // Nos desplaza a tal posición
         { if(1==existe(posicion)) ubicador=apuntador_a(posicion);}
         
    int BST::existe(int posicion)
         { obtener_posiciones();
           for(int i=0;i<ccpp;i++) {if(posicion==vector[i]) return 1;}
           return 0; }

    NODO_BST* BST::ubica() // Da la posicion en la que estamos
         { return ubicador; }

    void BST::left()                             // Se va al hijo izq
         {if(ubicador->izq!=NULL) ubicador=ubicador->izq;}

    void BST::right()                            // Se va al hijo der
         {if(ubicador->der!=NULL) ubicador=ubicador->der;}


         
    NODO_BST* BST::apuntador_a(int posicion)
         { NODO_BST* ubi=raiz;
           
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

    void BST::agregar_inicio(double cont)  // Agrega en anchura inicial
         { if(raiz==NULL) 
             { NODO_BST* a=new NODO_BST; 
               a->contenido=cont;
               a->posicion=1;
               raiz=final=ubicador=a;
               return;
             }
           if (final==raiz)                                    // Primogénito
             { NODO_BST* a=new NODO_BST(cont,raiz,'i');
               raiz->izq=a;
               final=a;
               return;
             }
           NODO_BST* ubi;
           int pos_rel=final->posicion;
                                            // Si el último es hijo izquierdo
           if((pos_rel%2)==0) 
             { pos_rel/=2; // Posicion del padre
               ubi=apuntador_a(pos_rel);
               NODO_BST* a=new NODO_BST(cont,ubi,'d');
               ubi->der=a;
               final=a;
               return;
             }
           if((pos_rel%2)==1)                 // Si el último es hijo derecho
             { pos_rel++; pos_rel/=2; // Posicion del padre
               ubi=apuntador_a(pos_rel);
               NODO_BST* a=new NODO_BST(cont,ubi,'i');
               ubi->izq=a;
               final=a;
               return;
             }
         }

    void BST::agregar(double cont) // Agrega en el primer hueco (anchura)
         { if(raiz==NULL) 
             { NODO_BST* a=new NODO_BST; 
               a->contenido=cont;
               a->posicion=1;
               raiz=final=ubicador=a;
               return;
             }
           obtener_posiciones();
           // Detecta el primer hueco
           int i,j=-1;
           for(i=0;i<ccpp-1;i++)if(vector[i+1]>vector[i]+1){j=vector[i];i=ccpp;}
           if(j==-1) j=vector[ccpp-1];
           
           // Inserta en el primer hueco
                      
           if (j==1)                                           // Primogénito
             { NODO_BST* a=new NODO_BST(cont,raiz,'i');
               raiz->izq=a;
               obtener_posiciones();
               return;
             }
           NODO_BST* ubi;
                                            // Si el último es hijo izquierdo
           if((j%2)==0) 
             { j/=2; // Posicion del padre
               ubi=apuntador_a(j);
               NODO_BST* a=new NODO_BST(cont,ubi,'d');
               ubi->der=a;
               obtener_posiciones();
               return;
             }
           if((j%2)==1)                      // Si el último es hijo derecho
             { j++; j/=2; // Posicion del padre
               ubi=apuntador_a(j);
               NODO_BST* a=new NODO_BST(cont,ubi,'i');
               ubi->izq=a;
               obtener_posiciones();
               return;
             } 
         }

         
    void BST::agregar(double cont,char hijo,NODO_BST* papa)
         { if(hijo!='d'&&hijo!='D') hijo='i'; // Ajuste de datos
           if(hijo=='i'||hijo=='I')                    // Si es hijo izquierdo
             { if (papa->izq==NULL) 
                  { NODO_BST* a=new NODO_BST(cont,papa,'i');
                    papa->izq=a;
                  }
               else {limpiar(papa->izq);
                     NODO_BST* a=new NODO_BST(cont,papa,'i');
                     papa->izq=a;
                    }
             }
           if(hijo=='d'||hijo=='D')                      // Si es hijo derecho
             { if (papa->der==NULL) 
                  { NODO_BST* a=new NODO_BST(cont,papa,'d');
                    papa->der=a;
                  }
               else {limpiar(papa->der);
                     NODO_BST* a=new NODO_BST(cont,papa,'d');
                     papa->der=a;
                    }
             }
         }

    
    void BST::modificar(int pos, double cont)
         { if(existe(pos)==1) apuntador_a(pos)->contenido=cont; }



/*  =========================================================================
    =                                                                       =
    =                          Eliminaciones                                =
    =                                                                       =
    =========================================================================*/

    void BST::limpiar(NODO_BST* nodo)
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
    void BST::printnode(G x, int h)
    { for(int i=0;i<h;i++) cout<<"    ";
      if(x==-1.00923004) cout<<" *"<<"\n\t";
      else cout<<" "<<x<<"\n\t";
    }

    void BST::show(NODO_BST* t, int h)
    { if(t==0) { printnode(-1.00923004,h); return; }
      show(t->der,h+1);
      printnode(t->posicion,h);
      show(t->izq,h+1);
    }

    void BST::imprimir_posiciones()
    { if(raiz==NULL) return;
      cout<<"\n\n\tEl arbol actual tiene tales posiciones habilitadas:\n\t";
      obtener_posiciones(); for(int i=0;i<ccpp;i++) cout<<vector[i]<<" ";
      cout<<"\n\n\n\t";
      show(raiz,0);
    }

    void BST::imprimir_valores()
    { if(raiz==NULL) return;
      cout<<"\n\n\tLos valores son:\n\n\n\t"; show_val(raiz,0); }

    void BST::show_val(NODO_BST* t, int h)
    { if(t==0)  return; 
      show_val(t->der,h+1);
      printnode(t->contenido,h);
      show_val(t->izq,h+1);
    }


    void BST::imprimir_distancias()
    { if(raiz==NULL) return;
      cout<<"\n\n\tLas distancias relativas son:\n\n\n\t"; show_dist(raiz,0); }


    void BST::show_dist(NODO_BST* t, int h)
    { if(t==0) return;
      show_dist(t->der,h+1);
      printnode(t->distancia,h);
      show_dist(t->izq,h+1);
    }

    int BST::calcular_dist(int p1,int p2)
    { if(existe(p1)==0||existe(p2)==0) return -1;
         
      PILA cola;
      
      limpiar_distancias(raiz); // ... y pone que no han sido visitados.
            
      int encontrado=0;
      int pos;
      NODO_BST *ubi=apuntador_a(p1);
      
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

    
    void BST::calcular_distancias(int posicion)
    { if(existe(posicion)==0) return;
      NODO_BST *ubi;
      ubi=apuntador_a(posicion);
      limpiar_distancias(raiz);
      obtener_posiciones();
      
      delete vv;
      vv=new int[ccpp+1];   // Almacena si ya se pasó por tal posicion.(~vector)
      for(int i=0;i<=ccpp;i++) {vv[i]=1;} vv[0]=0;      
      
      caldis(ubi);
    }  
    
    void BST::caldis(NODO_BST *ubi)
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
    
    int BST::buscar(int pos)
        { for(int i=0;i<ccpp;i++) if(vector[i]==pos) return i+1;  return 0;}
    
    void BST::limpiar_distancias(NODO_BST* nodo)
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
    void BST::imprimirPreorden()
    { if(raiz==NULL) return;
      cout<<"\n\n\tIMPRESION EN PREORDEN (Y,I,D) : \n\t";
      NODO_BST* ubi=raiz;
      imprimirPreorden(ubi);
      cout<<"\n\n\t"; system("pause");
    }
    
    void BST::imprimirPreorden(NODO_BST* nodo)       // yo izq der
    { cout<<"\n\t[ "<<nodo->posicion<<" ]\t=   "<<nodo->contenido;
      if(nodo->izq!=NULL) imprimirPreorden(nodo->izq);
      if(nodo->der!=NULL) imprimirPreorden(nodo->der);
    }


    // Postorden
    void BST::imprimirPostorden()
    { if(raiz==NULL) return;
      cout<<"\n\n\tIMPRESION EN POSTORDEN (I,D,Y) : \n\t";
      NODO_BST* ubi=raiz;
      imprimirPostorden(ubi);
      cout<<"\n\n\t"; system("pause");
    }

    void BST::imprimirPostorden(NODO_BST* nodo)      // izq der yo
    { if(nodo->izq!=NULL) imprimirPostorden(nodo->izq);
      if(nodo->der!=NULL) imprimirPostorden(nodo->der);
      cout<<"\n\t[ "<<nodo->posicion<<" ]\t=   "<<nodo->contenido;
    }


    // Inorden
    void BST::imprimirInorden()
    { if(raiz==NULL) return;
      cout<<"\n\n\tIMPRESION EN INORDEN (I,Y,D) : \n\t";
      NODO_BST* ubi=raiz;
      imprimirInorden(ubi);
      cout<<"\n\n\t"; system("pause");
    }
    
    void BST::imprimirInorden(NODO_BST* nodo)        // izq yo der
    { if(nodo->izq!=NULL) imprimirInorden(nodo->izq);
      cout<<"\n\t[ "<<nodo->posicion<<" ]\t=   "<<nodo->contenido;
      if(nodo->der!=NULL) imprimirInorden(nodo->der);
    }


    void BST::imprimirAnchura()
    { if(raiz==NULL) return;
      cout<<"\n\n\tIMPRESION EN ANCHURA : \n\t";
      NODO_BST* ubi=raiz;
      for(int i=0;i<ccpp;i++)
      { cout<<"\n\t[ "<<ubi->posicion<<" ]\t=   "<<ubi->contenido;
         forth(ubi);
      }
      
      cout<<"\n\n\t"; system("pause");
    }


    // Obtener de posiciones
    
    void BST::obtener_posiciones()
    { if(raiz==NULL) return;
      NODO_BST* ubic=raiz;
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

    void BST::cantidad_posiciones(NODO_BST* nodo,int &cantidad)
    { if(nodo->izq!=NULL) cantidad_posiciones(nodo->izq,cantidad);
      if(nodo->der!=NULL) cantidad_posiciones(nodo->der,cantidad);
      cantidad++;
    }

    void BST::guardar_posiciones(NODO_BST* nodo,int *vector,int &i)
    { vector[i]=nodo->posicion; i++;
      if(nodo->izq!=NULL) guardar_posiciones(nodo->izq,vector,i);
      if(nodo->der!=NULL) guardar_posiciones(nodo->der,vector,i);
    }
