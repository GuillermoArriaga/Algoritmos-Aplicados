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
   int seleccion=1,i,j=1,k;
   double valor;
   char hijo;
   
   VERDE
   
   ARBOL_BIN arbol(15);
   

         /* =========================================================
            =                                                       =
            =               PARAMETROS DESDE INTERFAZ               =
            =                                                       =
            =========================================================*/

    while(seleccion!=0)
    { LIMPIAR
      cout<<"\n\n\n\t\tGuillermo Arriaga Garcia"
            "\n\n\t\tARBOL BINARIO "
            "\n\n\n\t0.- Salir del programa."
            "\n\t1.- Agregar en anchura."
            "\n\t2.- Agregar arbitrariamente."
            "\n\t3.- Modificar valor."
            "\n\t4.- Eliminar nodo."
            "\n\t5.- Limpiar todo."
            "\n\t6.- Impresion de valores.";
      arbol.imprimir_posiciones();
      cout<<"\n\n\tSELECCION: ";
      fflush(stdin);
      cin>>seleccion;
      
      switch(seleccion)
      { default: break;
         
         case 1: if(j!=0){
                  cout<<"\n\n\tIngresa el valor del nuevo hijo: "; cin>>valor;
                  arbol.agregar(valor);
                  } else {cout<<"\n\n\tLimpia el arbol para agregar nodos";PAUSA}
                 break;

         case 2: cout<<"\n\nTen en cuenta que ya no podrás agregar en anchura,"
                       "\n\tIngresa la posicion del papa: "; cin>>i;
                 cout<<"\n\tIngresa el valor del hijo: "; cin>>valor;
                 cout<<"\n\tIngresa el tipo de hijo (i,d): "; cin>>hijo;
                 arbol.agregar(valor,hijo,arbol.apuntador_a(i)); j=0;
                 break;
         
         case 3: cout<<"\n\tIngresa la posicion del nodo a cambiar: "; cin>>i;
                 cout<<"\n\tIngresa el nuevo valor: "; cin>>valor;
                 arbol.modificar(i,valor);
                 break;
         
         case 4: cout<<"\n\nTen en cuenta que ya no podrás agregar en anchura,"
                       "\n\tIngresa la posicion del nodo a borrar: "; cin>>i;
                 arbol.limpiar(arbol.apuntador_a(i)); j=0;
                 break;

         case 5: arbol.limpiar(arbol.apuntador_a(1)); j=1;
                 break;

         case 6: arbol.imprimirPreorden();
                 arbol.imprimirInorden();
                 arbol.imprimirPostorden();
                 if(j!=0) 
                 arbol.imprimirAnchura();
                 break;

         
      }// Cierre del switch      
    }// Cierre de interfaz (while)
    
    FINAL
    return EXIT_SUCCESS;
}


/*  =========================================================================
    ==                                                                     == 
    ==                              FUNCIONES                              == 
    ==                                                                     == 
    ========================================================================= */



/*  =========================================================================
    ==                                                                     == 
    ==                                 |                                   == 
    ==                                                                     == 
    ========================================================================= */


        /* =========================================================
           =                                                       =
           =                           |                           =
           =                                                       =
           =========================================================*/
