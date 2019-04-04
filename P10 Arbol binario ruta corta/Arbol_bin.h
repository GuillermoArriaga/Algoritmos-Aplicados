/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  LISTA DOUBLE                   =
    =                                                                       =
    =========================================================================*/

// Guillermo Arriaga Garcia: Clase Lista doblemente ligada y no circular.

#ifndef ARBOL_BIN_H
#define ARBOL_BIN_H
#include "NODO_ARBOL_BIN.h"

class ARBOL_BIN
{
   private:
            NODO_ARBOL_BIN* raiz;
            NODO_ARBOL_BIN* ubicador;
            NODO_ARBOL_BIN* final;
            int *vector;
            int *vv;     // Indicador para distancias relativas
            int ccpp;    // Cantidad de posiciones utilizadas

   public:
            ARBOL_BIN();               // Constructor default 
            ~ARBOL_BIN();              // Destructor
            ARBOL_BIN(double cont);
            ARBOL_BIN(int elem);       // Crea un árbol binario con n elementos
                                       // de arriba a abajo y de izq. a derecha.

   // Métodos
            // Ubicacion
            void start(); // Nos ubica en el inicio
            void end();   // Nos lleva al último nodo
            void go_to(int posicion);   // Nos desplaza a tal posición
            
            void forth(NODO_ARBOL_BIN* &ubi);
            void forth(); // Nos desplaza a la derecha
            void back();  // Se desplaza a la izquierda
            void up();    // Se desplaza hacia arriba
            void left();  // Se desplaza al hijo izquierdo
            void right(); // Se desplaza al hijo derecho

            int  existe(int posicion);  // Indica si está disponible
            NODO_ARBOL_BIN* apuntador_a(int posicion);
            NODO_ARBOL_BIN* ubica(); // Da la posicion en la que estamos
            
            void obtener_posiciones();  // Brinda las posiciones disponibles
            void cantidad_posiciones(NODO_ARBOL_BIN* nodo,int &cantidad);
            void guardar_posiciones(NODO_ARBOL_BIN* nodo,int *vector,int &i);
            
            // Impresiones Especiales
            void imprimir_posiciones();
            void imprimir_valores();
            void imprimir_distancias();
            template<class G> void printnode(G x, int h);
            void show(NODO_ARBOL_BIN* t, int h);
            void show_val(NODO_ARBOL_BIN* t, int h);
            void show_dist(NODO_ARBOL_BIN* t, int h);
            
            // Distancias relativas a un nodo
            void calcular_distancias(int posicion);
            void limpiar_distancias(NODO_ARBOL_BIN* nodo);
            int  buscar(int pos);
            void caldis(NODO_ARBOL_BIN* nodo);  // Recursiva
            int  calcular_dist(int p1,int p2);   // Con cola

            // Impresiones Usuales
            void imprimirPreorden();       // yo izq der     Desde raiz
            void imprimirPostorden();      // izq der yo
            void imprimirInorden();        // izq yo der
            void imprimirPreorden(NODO_ARBOL_BIN* nodo);  // Desde cualquier
            void imprimirPostorden(NODO_ARBOL_BIN* nodo); // nodo
            void imprimirInorden(NODO_ARBOL_BIN* nodo);  
            void imprimirAnchura();


            // Modificadores
            void agregar_inicio(double cont);
            void agregar(double cont);     // en el primer hueco
            void agregar(double cont,char hijo,NODO_ARBOL_BIN* papa);
            void modificar(int pos, double cont);
            
            // Eliminaciones
            void limpiar(NODO_ARBOL_BIN* nodo);
            
};

#endif
