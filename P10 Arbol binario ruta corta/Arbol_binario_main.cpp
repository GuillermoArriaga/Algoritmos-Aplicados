/*  =========================================================================
    ==                                                                     == 
    ==        GUILLERMO ARRIAGA GARCÍA           5/04/11                   == 
    ==                                                                     == 
    ==        PRÁCTICA 9 :         ÁRBOL BINARIO                           == 
    ==                                                                     == 
    ========================================================================= */


#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "Arbol_bin.h"

#define AMARILLO system("COLOR 0E");
#define AZUL     system("COLOR 09");
#define BLANCO   system("COLOR 07");
#define CIELO    system("COLOR 0B");
#define ROJO     system("COLOR 0C");
#define VERDE    system("COLOR 0A");
#define PAUSA    cout<<"\n\n\t";system("PAUSE");cout<<"\n\n";
#define LIMPIAR  system("CLS");
#define FINAL    LIMPIAR AMARILLO cout<<"\n\n\n\t\tFIN DEL PROGRAMA"; PAUSA

using namespace std;


/*  =========================================================================
    ==                                                                     == 
    ==                               MAIN                                  == 
    ==                                                                     == 
    ========================================================================= */


int main()
{
   int seleccion=1,i,j=1,k,l;
   double valor;
   char hijo;
   
   VERDE
   
   ARBOL_BIN arbol(15);
   

    while(seleccion!=0)
    { LIMPIAR
      cout<<"\n\n\n\t\tGuillermo Arriaga Garcia"
            "\n\n\t\tARBOL BINARIO "
            "\n\n\n\t0.- Salir del programa."
            "\n\t11.- Agregar en el primer hueco."
            "\n\t12.- Agregar arbitrariamente."
            "\n\t13.- Modificar valor."
            "\n\t14.- Eliminar nodo."
            "\n\t15.- Limpiar todo."
            "\n\t16.- Imprimir pre-in-post orden y anchura."
            "\n\t17.- Imprimir valores."
            "\n\t18.- Imprimir distancias relativas."
            "\n\t19.- Calcular la minima distancia entre dos nodos."
            "\n\n\tMOVIMIENTOS DEL UBICADOR"
            "\n\t(1) Izq., (2) Der., (3) Arriba, (4) Hijo izq., (5) Hijo der."
            "\n\t(6) Ir a, (7) Inicio, (8) Final.";
      arbol.imprimir_posiciones();
      cout<<"\n\n\tUBICADOR: Posicion = "<<(arbol.ubica()->posicion)<<"  Valor = "<<(arbol.ubica()->contenido);
      cout<<"\n\n\tSELECCION: ";
      fflush(stdin);
      cin>>seleccion;
      
      switch(seleccion)
      { default: break;

         case 1:  arbol.back();   break;
         case 2:  arbol.forth();  break;
         case 3:  arbol.up();     break;
         case 4:  arbol.left();   break;
         case 5:  arbol.right();  break;
         case 6:  cout<<"\n\tIngresa la posicion del nodo a llegar: "; cin>>i;
                  arbol.go_to(i); break;
         case 7:  arbol.start();  break;
         case 8:  arbol.end();    break;

         
         case 11: cout<<"\n\n\tIngresa el valor del nuevo hijo: "; cin>>valor;
                  arbol.agregar(valor);
                  break;

         case 12: cout<<"\n\tIngresa la posicion del papa: "; cin>>i;
                  cout<<"\n\tIngresa el valor del hijo: "; cin>>valor;
                  cout<<"\n\tIngresa el tipo de hijo (i,d): "; cin>>hijo;
                  arbol.agregar(valor,hijo,arbol.apuntador_a(i)); j=0;
                  break;
         
         case 13: cout<<"\n\tIngresa la posicion del nodo a cambiar: "; cin>>i;
                  cout<<"\n\tIngresa el nuevo valor: "; cin>>valor;
                  arbol.modificar(i,valor);
                  break;
         
         case 14: cout<<"\n\tIngresa la posicion del nodo a borrar: "; cin>>i;
                  arbol.limpiar(arbol.apuntador_a(i));
                  break;

         case 15: arbol.limpiar(arbol.apuntador_a(1));
                  break;

         case 16: arbol.imprimirPreorden();
                  arbol.imprimirInorden();
                  arbol.imprimirPostorden();
                  arbol.imprimirAnchura();
                  break;

         case 17: arbol.imprimir_valores();    PAUSA break;

         case 18: cout<<"\n\n\tCon respecto a que posicion: "; cin>>i;
                  arbol.calcular_distancias(i);
                  arbol.imprimir_distancias(); PAUSA break;

         case 19: cout<<"\n\n\tDe que nodo: "; cin>>i;
                  cout<<"\n\tA que nodo: "; cin>>l;
                  cout<<"\n\tLa distancia es: "<<arbol.calcular_dist(i,l);
                      
                  // Recursivamente: arbol.calcular_distancias(i); 
                  //                 arbol.go_to(l); (arbol.ubica()->distancia);    
                  PAUSA break;


      }// Cierre del switch      
    }// Cierre de interfaz (while)
    
    FINAL
    return EXIT_SUCCESS;
}
