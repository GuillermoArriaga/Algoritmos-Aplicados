/*  =========================================================================
    ==                                                                     == 
    ==        GUILLERMO ARRIAGA GARCÍA          03/06/11                   == 
    ==                                                                     == 
    ==        EXAMEN 3 :  PROBLEMA 3  SEPARANDO PALABRAS                   == 
    ==                                                                     == 
    ========================================================================= */


#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Diccionario.h"

#define AMARILLO system("COLOR 0E");
#define VERDE    system("COLOR 0A");
#define PAUSA    cout<<"\n\n\t";system("PAUSE");cout<<"\n\n";
#define LIMPIAR  system("CLS");
#define FINAL    LIMPIAR AMARILLO cout<<"\n\n\n\t\tFIN DEL PROGRAMA"; PAUSA

using namespace std;


int main()
{
    int seleccion=1,i,j,k;
    VERDE

    DICCIONARIO d;
    char palabra[41];
    char letra;

    while(seleccion!=0)
    { LIMPIAR
      cout<<"\n\n\n\t\tGuillermo Arriaga Garcia"
            "\n\n\t\tPROGRAMA: Separando palabras minusculas (sin ~n)"
            "\n\n\n\t0.- Salir del programa."
            "\n\t1.- Introducir palabra: "
            "\n\t2.- Listar palabras que empiecen por ..."
            "\n\t3.- Listar todas las palabras"
            "\n\t4.- Capturar desde _Entrada.txt"
            "\n\n\tSELECCION: ";
      fflush(stdin);
      cin>>seleccion;
      
      switch(seleccion)
      { default: break;
         case 0: break;
         
         case 1: cout<<"\n\n\tIntroduce la palabra en minusculas: ";
                 cin>>palabra;
                 d.insertar(palabra);
                 break;
         
         case 2: cout<<"\n\n\tIntroduce la letra (minuscula): ";
                 cin>>letra;
                 d.listarpor(letra);
                 break;
         
         case 3: d.listar();
                 break;

         case 4: ifstream in("_Entrada.txt");
                 while(in>>palabra)
                 { d.insertar(palabra);
                 }
                 in.close();
                 break;
         
      }
    }
    
    FINAL
    return EXIT_SUCCESS;
}
