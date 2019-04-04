/*  =========================================================================
    =                                                                       =
    =          Guillermo Arriaga García  ARBOL BINARIO DE BUSQUEDA          =
    =                                                                       =
    =                     (BST)      TAREA  20                              =
    =                                                                       =
    =========================================================================*/


#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "BST.h"

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
   int seleccion=1,i,j,k,l;
   double valor;
   char hijo;
   
   VERDE
   
   BST arbol;
   

    while(seleccion!=0)
    { LIMPIAR
      cout<<"\n\n\n\t\tGuillermo Arriaga Garcia"
            "\n\n\t\tARBOL BINARIO DE BUSQUEDA"
            "\n\n\n\t0.- Salir del programa."
            "\n\t1.- Insertar valor."
            "\n\t2.- Valor minimo absoluto."
            "\n\t3.- Valor maximo absoluto."
            "\n\t4.- Eliminar nodo."
            "\n\t5.- Limpiar todo."
            "\n\t6.- Imprimir pre-in-post orden y anchura."
            "\n\t7.- Imprimir posiciones."
            "\n\t8.- Rotar a la derecha."
            "\n\t9.- Rotar a la izquierda."
            "\n\t10.- Agregar n valores aleatorios."
            "\n\t11.- Buscar un valor.";
      arbol.imprimir_valores();
      cout<<"\n\n\tSELECCION: ";
      fflush(stdin);
      cin>>seleccion;
      
      switch(seleccion)
      { default: break;

         case 1:  cout<<"\n\n\tIngresa el valor: "; 
                  cin>>valor;
                  arbol.insertar(valor);
                  break;
                  
         case 2:  cout<<"\n\n\tEl minimo del arbol es "
                      <<arbol.minimo(arbol.apuntador_a(1))->contenido;
                  PAUSA
                  break;
                  
         case 3:  cout<<"\n\n\tEl maximo del arbol es "
                      <<arbol.maximo(arbol.apuntador_a(1))->contenido;
                  PAUSA
                  break;
                  
         case 4:  cout<<"\n\n\tPOSICIONES: "; 
                  arbol.imprimir_posiciones();
                  cout<<"\n\n\tIngresa la posicion a eliminar: "; 
                  cin>>i;
                  arbol.borrar_nodo(arbol.apuntador_a(i));
                  break;
                  
         case 5:  cout<<"\n\n\tIngresa el valor de la raiz: "; 
                  cin>>valor;
                  arbol.limpiar(arbol.apuntador_a(1));
                  arbol.modificar(1,valor);
                  break;
                  
         case 6:  arbol.imprimirPreorden();
                  arbol.imprimirInorden();
                  arbol.imprimirPostorden();
                  arbol.imprimirAnchura();
                  break;

         case 7:  arbol.imprimir_posiciones();    
                  PAUSA 
                  break;

         case 8:  cout<<"\n\n\tPOSICIONES: "; 
                  arbol.imprimir_posiciones();
                  cout<<"\n\n\tIngresa la posicion a rotar a la derecha: "; 
                  cin>>i;
                  arbol.rotar_der(arbol.apuntador_a(i));
                  break;
         
         case 9:  cout<<"\n\n\tPOSICIONES: "; 
                  arbol.imprimir_posiciones();
                  cout<<"\n\n\tIngresa la posicion a rotar a la izquierda: "; 
                  cin>>i;
                  arbol.rotar_izq(arbol.apuntador_a(i));
                  break;
                  
         case 10: cout<<"\n\n\tIngresa la cantidad de numeros aleatorios: "; 
                  cin>>i;
                  for(j=0;j<i;j++)
                      arbol.insertar(10+rand()%90);
                  break;
                  
         case 11: cout<<"\n\n\tIngresa el valor: "; 
                  cin>>valor;
                  if(arbol.buscar_val(valor)!=NULL)
                     { cout<<"\n\n\tEsta en la posicion: "
                           <<arbol.buscar_val(valor)->posicion;
                     }
                  else cout<<"\n\n\tNo se encuentra ese valor.";
                  PAUSA         
                  break;            

      }// Cierre del switch      
    }// Cierre de interfaz (while)
    
    FINAL
    return EXIT_SUCCESS;
}









//  MAIN ANTIGUO PARA CONSULTA DE FUNCIONES VARIAS ÚTILES

/*
int main()
{
   int seleccion=1,i,j=1,k,l;
   double valor;
   char hijo;
   
   VERDE
   
   BST arbol(1);
   

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
*/
