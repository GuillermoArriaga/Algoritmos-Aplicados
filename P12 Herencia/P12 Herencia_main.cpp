/*  =========================================================================
    ==                                                                     == 
    ==        GUILLERMO ARRIAGA GARCÍA          10/05/11                   == 
    ==                                                                     == 
    ==        FIGURAS GEOMÉTRICAS     TEMA: HERENCIA DE CLASES             == 
    ==                                                                     == 
    ========================================================================= */

         /* =========================================================
            =                                                       =
            =                      DESCRIPCIÓN                      =
            =                                                       =
            =========================================================*/

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "Figura.h"
#include "Pila.h"
#include <cmath>

#define AMARILLO system("COLOR 0E");
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


int main(int argc, char *argv[])
{
   
   VERDE

        /* =========================================================
           =                                                       =
           =                      DEMOSTRACIÓN                     =
           =                                                       =
           =========================================================*/


    Figura* ftri=new Triangulo(3.0,4.0,5.0);
    Figura* fcua=new Cuadrado(3.0);
    Figura* fpen=new Pentagono(3.0);
    Figura* fcir=new Circulo(3.0);

    LIMPIAR

    cout<<"\n\n\n\tGuillermo Arriaga Garcia\tPractica 12: Herencias de clases";
    cout<<"\n\n\n\t\t\tDEMOSTRACION\n\n\n";

    cout<<"\n\tTriangulo:\tlados 3,4,5 \tarea = "<<((Triangulo*)(ftri))->area()
        <<"\tperimetro = "<<((Triangulo*)(ftri))->perimetro();
    cout<<"\n\tCuadrado:\tlado 3\t\tarea = "<<((Cuadrado*)(fcua))->area()
        <<"\tperimetro = "<<((Cuadrado*)(fcua))->perimetro();
    cout<<"\n\tPentagono:\tlado 3\t\tarea = "<<((Pentagono*)(fpen))->area()
        <<"\tperimetro = "<<((Pentagono*)(fpen))->perimetro();
    cout<<"\n\tCirculo:\tradio 3\t\tarea = "<<((Circulo*)(fcir))->area()
        <<"\tperimetro = "<<((Circulo*)(fcir))->perimetro();
   
   PAUSA
    
   delete ftri;
   delete fcua;
   delete fpen;
   delete fcir;     

    // Otro modo de trabajar con las figuras

   Triangulo* ftri2=new Triangulo(3.0,4.0,5.0);
   cout<<"\n\tTriangulo:\tlados 3,3,3 \tarea = "<<ftri2->area()
       <<"\tperimetro = "<<ftri2->perimetro();
   delete ftri2;
        
   Cuadrado* fcua2=new Cuadrado();
   fcua2->lado(5.0);
   cout<<"\n\tCuadrado:\tlado 5 \t\tarea = "<<fcua2->area()
       <<"\tperimetro = "<<fcua2->perimetro();    
   delete fcua2;

   PAUSA

   // Ahora con una lista de figuras random

   PILA Lista;
    
    int a=rand()%9+1,b=rand()%9+1;
    float c=sqrt(a*a+b*b);
    ftri=new Triangulo(a,b,c);
    fcua=new Cuadrado(a);
    fpen=new Pentagono(b);
    fcir=new Circulo(c);
    
    Lista.push(ftri);
    Lista.push(fcua);
    Lista.push(fpen);
    Lista.push(fcir);
    
    Figura* Fig;
    
    Fig=Lista.get(rand()%3+1);
    
    if(Fig->num_lad==-1)
    {
       cout<<"\n\tCirculo:\tradio "<<c<<"\tarea = "<<((Circulo*)(Fig))->area()
           <<"\tperimetro = "<<((Circulo*)(Fig))->perimetro();
    }       

    if(Fig->num_lad==3)
    {
     cout<<"\n\tTriangulo:\tlados "<<a<<","<<b<<","<<c<<"  area = "<<((Triangulo*)(ftri))->area()
         <<"\tperimetro = "<<((Triangulo*)(ftri))->perimetro();
    }       

    if(Fig->num_lad==4)
    {
      cout<<"\n\tCuadrado:\tlado "<<a<<"\t\tarea = "<<((Cuadrado*)(fcua))->area()
          <<"\tperimetro = "<<((Cuadrado*)(fcua))->perimetro();
    }       

    if(Fig->num_lad==5)
    {
      cout<<"\n\tPentagono:\tlado "<<b<<"\t\tarea = "<<((Pentagono*)(fpen))->area()
          <<"\tperimetro = "<<((Pentagono*)(fpen))->perimetro();
    }
    
    // Impresion de toda la lista
    
    cout<<"\n\n\tIMPRESION DE LA LISTA DE FIGURAS RANDOM\n\n\t";
    for(int i=1;i<=4;i++)
       { 
                Fig=Lista.get(i);
    
        if(Fig->num_lad==-1)
         cout<<"\n\tCirculo:\tradio "<<c<<"\tarea = "<<((Circulo*)(Fig))->area()
             <<"\tperimetro = "<<((Circulo*)(Fig))->perimetro();
    
        if(Fig->num_lad==3)
         cout<<"\n\tTriangulo:\tlados "<<a<<","<<b<<","<<c<<"  area = "<<((Triangulo*)(ftri))->area()
             <<"\tperimetro = "<<((Triangulo*)(ftri))->perimetro();

        if(Fig->num_lad==4)
         cout<<"\n\tCuadrado:\tlado "<<a<<"\t\tarea = "<<((Cuadrado*)(fcua))->area()
             <<"\tperimetro = "<<((Cuadrado*)(fcua))->perimetro();

        if(Fig->num_lad==5)
         cout<<"\n\tPentagono:\tlado "<<b<<"\t\tarea = "<<((Pentagono*)(fpen))->area()
             <<"\tperimetro = "<<((Pentagono*)(fpen))->perimetro();            
       }

   PAUSA    
        
   FINAL
   return EXIT_SUCCESS;
}
