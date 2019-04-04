/*  =========================================================================
    ==                                                                     == 
    ==        GUILLERMO ARRIAGA GARCÍA          25/03/11                   == 
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
   int seleccion=1,i,j,k;
   
   VERDE
   
   ARBOL_BIN arbol(34);
   arbol.agregarRaiz(35,'i');
   arbol.agregarRaiz(36,'d');
//   arbol.agregar(37,'i',(arbol.inicio()->izq));
//   arbol.agregar(38,'d',(arbol.inicio()->der));
   

         /* =========================================================
            =                                                       =
            =               PARAMETROS DESDE INTERFAZ               =
            =                                                       =
            =========================================================*/

    while(seleccion!=0)
    { LIMPIAR
      cout<<"\n\n\n\t\tGuillermo Arriaga Garcia"
            "\n\n\t\tPROGRAMA: ARBOL BINARIO"
            "\n\n\n\t0.- Salir del programa."
            "\n\t1.- Imprimir arbol en preorden."
            "\n\t2.- Imprimir arbol en postorden."
            "\n\t3.- Imprimir arbol en inorden."
            "\n\n\tSELECCION: ";
      fflush(stdin);
      cin>>seleccion;
      
      switch(seleccion)
      { default: break;
         case 0: break;
         
         case 1: arbol.imprimirPreorden(); PAUSA
                 break;
         
         case 2: arbol.imprimirPostorden(); PAUSA
                 break;
         
         case 3: arbol.imprimirInorden(); PAUSA
                 break;
         
      }// Cierre del switch      
    }// Cierre de interfaz (while)
    
    FINAL
    return EXIT_SUCCESS;
}
