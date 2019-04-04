/*  =========================================================================
    =                                                                       =
    =          Guillermo Arriaga García  ARBOL BINARIO DE BUSQUEDA          =
    =                                                                       =
    =                     (BST)      TAREA  20                              =
    =                                                                       =
    =========================================================================*/


#ifndef BST_H
#define BST_H
#include "NODO_BST.h"

class BST
{
   private:
            NODO_BST* raiz;
            NODO_BST* ubicador;
            NODO_BST* final;
            int *vector;
            int *vv;     // Indicador para distancias relativas
            int ccpp;    // Cantidad de posiciones utilizadas

   public:
            BST();               // Constructor default 
            ~BST();              // Destructor
            BST(double cont);
            BST(int elem);       // Crea un árbol binario con n elementos
                                       // de arriba a abajo y de izq. a derecha.

   // Métodos propios de un BST
            
            NODO_BST* minimo(NODO_BST* nod);
            NODO_BST* maximo(NODO_BST* nod);
            NODO_BST* sucesor(NODO_BST* nod);
            NODO_BST* predecesor(NODO_BST* nod);
            NODO_BST* buscar_val(double val);
            NODO_BST* buscar_val(NODO_BST* nod, double val);
            
            double valor_de(int pos);
            double select(int pos_ord); // Se pide el k-ésimo elemento de los datos ordenados
            void select_Inorden(NODO_BST* nodo,int &c,int &p,NODO_BST* &u);
            
            void insertar(double val);
            void borrar_nodo(NODO_BST* z);
            void rotar_der(NODO_BST* x);//, NODO_BST* y);
            void rotar_izq(NODO_BST* y);//, NODO_BST* y);
            
            void asignar_posiciones();
            void asignar_posiciones(NODO_BST* nod);
            
   // Métodos varios útiles 
            // Ubicacion
            void start(); // Nos ubica en el inicio
            void end();   // Nos lleva al último nodo
            void go_to(int posicion);   // Nos desplaza a tal posición
            
            void forth(NODO_BST* &ubi);
            void forth(); // Nos desplaza a la derecha
            void back();  // Se desplaza a la izquierda
            void up();    // Se desplaza hacia arriba
            void left();  // Se desplaza al hijo izquierdo
            void right(); // Se desplaza al hijo derecho

            int  existe(int posicion);  // Indica si está disponible
            NODO_BST* apuntador_a(int posicion);
            NODO_BST* ubica(); // Da la posicion en la que estamos
            
            void obtener_posiciones();  // Brinda las posiciones disponibles
            void cantidad_posiciones(NODO_BST* nodo,int &cantidad);
            void guardar_posiciones(NODO_BST* nodo,int *vector,int &i);
            
            // Impresiones Especiales
            void imprimir_posiciones();
            void imprimir_valores();
            void imprimir_distancias();
            template<class G> void printnode(G x, int h);
            void show(NODO_BST* t, int h);
            void show_val(NODO_BST* t, int h);
            void show_dist(NODO_BST* t, int h);
            
            // Distancias relativas a un nodo
            void calcular_distancias(int posicion);
            void limpiar_distancias(NODO_BST* nodo);
            int  buscar(int pos);
            void caldis(NODO_BST* nodo);  // Recursiva
            int  calcular_dist(int p1,int p2);   // Con cola

            // Impresiones Usuales
            void imprimirPreorden();       // yo izq der     Desde raiz
            void imprimirPostorden();      // izq der yo
            void imprimirInorden();        // izq yo der
            void imprimirPreorden(NODO_BST* nodo);  // Desde cualquier
            void imprimirPostorden(NODO_BST* nodo); // nodo
            void imprimirInorden(NODO_BST* nodo);  
            void imprimirAnchura();


            // Modificadores
            void agregar_inicio(double cont);
            void agregar(double cont);     // en el primer hueco
            void agregar(double cont,char hijo,NODO_BST* papa);
            void modificar(int pos, double cont);
            
            // Eliminaciones
            void limpiar(NODO_BST* nodo);
            
};

#endif
