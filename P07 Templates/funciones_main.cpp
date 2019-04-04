/* ==========================================================================
   =                                                                        =
   =    Guillermo Arriaga García   PRACTICA 7 USO DE TEMPLATES              =
   =                                                                        =
   ==========================================================================*/

#include <cstdlib>
#include <iostream>
#include "funciones.h"
#include "complejot.h"

using namespace std;

template <class T> void impresion_datos (T& A, T& B);
template <class T> void impresion_listas (T*& A,int& C);

template <class R> void impresion_datos_c(complejot<R>& A, complejot<R>& B);
template <class R> void impresion_listas_c(complejot<R>*& A, int& C);


int main()
{ 
  int seleccion=1,cantidad,i;
  cantidad=10;

  // ++++++++++++++++++++++   Creacion de aleatorios   ++++++++++++++++++++++++
  
  int ai,bi;
  float af,bf;  
  double ad,bd;
  int* ail;         // a int lista = ail
  float* afl;
  double* adl;
    
  // Asignacion de valores aleatorios
  ai=1+rand()%100;
  bi=1+rand()%100;

  af=(1+rand()%10)*((float)ai/(float)bi);
  bf=(1+rand()%10)*((float)bi/(float)ai);
  
  ad=(1+rand()%10)*(af/bf);
  bd=(1+rand()%10)*(bf/af);
  
  
  // Asignacion de memoria y asignacion de valores aleatorios
  ail=new int[cantidad];    for(i=0;i<cantidad;i++) ail[i]=rand()%100;
  afl=new float[cantidad];  for(i=0;i<cantidad;i++) afl[i]=(rand()%10)*(af/bf);
  adl=new double[cantidad]; for(i=0;i<cantidad;i++) adl[i]=(rand()%10)*(ad/bd);
    
  // El polinomio se evaluara con estas listas en algun punto
  
  // Creacion de complejos
  complejot<int>    ci(ai,bi),*cil,ci2=(ci*3);
  complejot<float>  cf(af,bf),*cfl,cf2=(cf*4);
  complejot<double> cd(ad,bd),*cdl,cd2=(cd*5);

  cil=new complejot<int>[cantidad];    for(i=0;i<cantidad;i++) cil[i].captura((rand()%10),(1+rand()%10));
  cfl=new complejot<float>[cantidad];  for(i=0;i<cantidad;i++) cfl[i].captura((rand()%10)*(af/bf),(rand()%10)*(af/bf));
  cdl=new complejot<double>[cantidad]; for(i=0;i<cantidad;i++) cdl[i].captura((rand()%10)*(ad/bd),(rand()%10)*(ad/bd));

  
  // ++++++++++++++++++++++   Creacion de aleatorios   ++++++++++++++++++++++++  
  
  while(seleccion!=0)
  {
    system("cls");
    cout<<"\n\n\tGuillermo Arriaga Garcia\tPractica 7: Uso de Template\n"
          "\n\nCON DATOS ALEATORIOS:";
    cout<<  "\n\n\t1.- Datos enteros."
          "\n\t2.- Datos flotantes."
          "\n\t3.- Datos doble-flotante."
          "\n\nCON UNA LISTA ALEATORIA:"
          "\n\t4.- Datos enteros."
          "\n\t5.- Datos flotantes."
          "\n\t6.- Datos doble-flotante."
          "\n\nCON COMPLEJOS ALEATORIOS:"
          "\n\t7.- Datos enteros."
          "\n\t8.- Datos flotantes."
          "\n\t9.- Datos doble-flotante."
          "\n\t10.- Lista de enteros."
          "\n\t11.- Lista de flotantes."
          "\n\t12.- Lista de doble-flotante."
          "\n\nSELECCION: ";
    cin>>seleccion;      
            
    switch(seleccion)
    { default: break;
      case 1: impresion_datos(ai,bi);  break;
      case 2: impresion_datos(af,bf);  break;
      case 3: impresion_datos(ad,bd);  break;
      case 4: impresion_listas(ail,cantidad);  break;
      case 5: impresion_listas(afl,cantidad);  break;
      case 6: impresion_listas(adl,cantidad);  break;
      case 7: impresion_datos_c(ci,ci2);  break;
      case 8: impresion_datos_c(cf,cf2);  break;
      case 9: impresion_datos_c(cd,cd2);  break;
      case 10: impresion_listas_c(cil,cantidad);  break;
      case 11: impresion_listas_c(cfl,cantidad);  break;
      case 12: impresion_listas_c(cdl,cantidad);  break;
    }// Cierre del switch      
  }// Cierre del while

   // Liberacion de memoria
   delete [] ail; delete [] afl; delete [] adl;
   delete [] cil; delete [] cfl; delete [] cdl;

   cout<<"\n\n\tFIN DEL PROGRAMA\n\n\t"; 
   system("PAUSE");
   return EXIT_SUCCESS;
}// Cierre del Main



/* ==========================================================================
   =                                                                        =
   =                           FUNCIONES DE IMPRESION                       =
   =                                                                        =
   ==========================================================================*/
   
template <class T> void impresion_datos(T& A, T& B)
{
  funciones<T> fun;
  
  cout<<"\n\n\tLas operaciones con "<<A<<" y "<<B<<" son:\n\n\t"
      <<A<<" + "<<B<<" = "<<fun.suma(A,B)<<"\n\t" 
      <<A<<" - "<<B<<" = "<<fun.resta(A,B)<<"\n\t" 
      <<A<<"^3 = "<<fun.potencia(A,3)<<"\n\t" 
      <<B<<"^3 = "<<fun.potencia(B,3)<<"\n\n\t";
  system("pause");    
  
}


template <class T> void impresion_listas(T*& A,int& C)
{

  funciones<T> fun;
  
  cout<<"\n\n\tLa Lista es :\n"; fun.impresion(A,C);
  cout<<"\n\n\tEl promedio es: "<<fun.promedio(A,C)
      <<"\n\n\tEl minimo es: "<<fun.minimo(A,C)
      <<"\n\n\tComo funcion polinomica: Termino[i]=Lista[i]*x^i:"
      <<"\n\tf(0) = "<<fun.polinomio(A,0,(C-1))
      <<"\n\tf(1) = "<<fun.polinomio(A,1,(C-1))
      <<"\n\tf(-1) = "<<fun.polinomio(A,-1,(C-1))
      <<"\n\n\t";
  system("pause");
}  


template <class R> void impresion_datos_c(complejot<R>& A, complejot<R>& B)
{  
  
  funciones< complejot<R> > fun;
         
  cout<<"\n\n\tLas operaciones con "<<A<<" y "<<B<<" son:\n\n\t"
      <<A<<" + "<<B<<" = "<<fun.suma(A,B)<<"\n\t" 
      <<A<<" - "<<B<<" = "<<fun.resta(A,B)<<"\n\t" 
      <<A<<"^3 = "<<(A^3)<<"\n\t" 
      <<B<<"^3 = "<<(B^3)<<"\n\n\t";
  system("pause");    
  
}

template <class R> void impresion_listas_c(complejot<R>*& A, int& C)
{

  funciones< complejot<R> > fun;
  
  cout<<"\n\n\tLa Lista es :\n"; fun.impresion(A,C);
  cout<<"\n\n\tEl promedio es: "<<fun.promedio(A,C)
      <<"\n\n\tEl minimo es: "<<fun.minimo(A,C)
      <<"\n\n\tComo funcion polinomica: Termino[i]=Lista[i]*x^i:"
      <<"\n\tf(0) = "<<fun.polinomio(A,0,(C-1))
      <<"\n\tf(1) = "<<fun.polinomio(A,1,(C-1))
      <<"\n\tf(-1) = "<<fun.polinomio(A,-1,(C-1))
      <<"\n\n\t";
  system("pause");
}  

