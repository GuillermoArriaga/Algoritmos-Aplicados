/* ==========================================================================
   =                                                                        =
   =          Guillermo Arriaga García   COMPLEJOS Y VECTORES 3D            =
   =                                                                        =
   ==========================================================================*/

// Marzo de 2011

#include <cstdlib>
#include <iostream>
#include "complejo.h"
#include "vector3d.h"
#include "complejot.h"

using namespace std;

void presentacion();

void impresion_complejos(complejo& A, complejo& B);
template <class T> void impresion_complejos(complejot<T>& A, complejot<T>& B);

void impresion_vectores(vector3d& A, vector3d& B);

int main()
{   
    presentacion();
    
    cout<<"\n\n\tFIN DEL PROGRAMA\n\n\t"; system("pause");
    return EXIT_SUCCESS;
}    


void presentacion()
{    
  int seleccion=1;
  complejo A(3,4),B(-1,-3);
  complejot<int> ci1(1,5),ci2(2,-4);
  complejot<float> cf1(3.7,-2.8),cf2(-0.4,0.7);
  vector3d V1(2,4,6),V2(-3,6,-9);
  int potencia,i,j,k;
    
  while(seleccion!=0)
  { 
    system("cls");
    cout<<"\n\n\t\tGuillermo Arriaga Garcia\n\n\t\tCOMPLEJOS Y VECTORES 3D\n"
          "\n\t0.- Salir de la presentacion."
          "\n\t1.- Demostracion de complejos usando templates."
          "\n\t2.- Demostracion de vectores 3d usando templates."
          "\n\t3.- Cambiar datos de dos complejos."
          "\n\t4.- Cambiar datos de dos vectores."
          "\n\t5.- Demostracion de complejos."
          "\n\t6.- Demostracion de vectores."
          "\n\n\tSELECCION: "; cin>>seleccion;
    
    switch(seleccion)
    { default: break;
      case 0: break;
      case 1: impresion_complejos(ci1,ci2);
              impresion_complejos(cf1,cf2);
              break;
              
      case 2: break;
      
      case 3: cout<<"\n\nComplejo A (re im): "; cin>>A;        
              cout<<"\n\nComplejo B (re im): "; cin>>B;
              break;
      
      case 4: cout<<"\n\nVector 3d A (x y z): "; cin>>V1;
              cout<<"\n\nVector 3d B (x y z): "; cin>>V2;
              break;
              
      case 5: impresion_complejos(A,B);
              break;
              
      case 6: impresion_vectores(V1,V2);
              break;
       
    }// Cierre switch
  }// Cierre while
}// Cierre de presentacion



/* ==========================================================================
   =                                                                        =
   =             FUNCIONES DE IMPRESION DE DEMOSTRACIONES                   =
   =                                                                        =
   ==========================================================================*/


template <class T> void impresion_complejos(complejot<T>& A, complejot<T>& B)
{
  cout<<"\n\n\tLos complejos <int> tienen division de enteros.\n";
  cout<<"\n\n\tCon los complejos A="<<A<<" y B="<<B
      <<" se puede:\n\n"<<"\tA+B="<<A+B<<"\t\tA-B="<<A-B
      <<"\n\tA*B="<<A*B<<"\tA/B="<<A/B<<"\n\tA*3="<<(A*3)
      <<"\t\tB*(-2)="<<(B*(-2))<<"\n\t|A|= "<<++A<<"\t\t\t"
        "|B|= "<<++B<<"\n\tConj(A)="<<!A<<"\t-B="<<-B;
  if(A<B)  cout<<"\n\n\tLa relacion por las normas es : A < B\n";
  if(A==B) cout<<"\n\n\tLa relacion por las normas es : A = B\n";
  if(A>B)  cout<<"\n\n\tLa relacion por las normas es : A > B\n";
        
  cout<<"\n\tA=3"<<(A=3)<<"\t\tB/2="<<(B/2)
      <<"\n\tA+5"<<(A+5)<<"\t\tB-7="<<(B-7)
      <<"\n\tA=B=";
  A=B; 
  B=0; 
  cout<<A<<"\t\tB=0"<<B
      <<"\n\tA="<<A<<"\t\tB="<<B;
  cout<<"\n\n\t"; system("pause");
}


void impresion_complejos(complejo& A, complejo& B)
{
  cout<<"\n\n\tCon los complejos A="<<A<<" y B="<<B
      <<" se puede:\n\n"<<"\tA+B="<<A+B<<"\t\tA-B="<<A-B
      <<"\n\tA*B="<<A*B<<"\tA/B="<<A/B<<"\n\tA*3="<<(A*3)
      <<"\t\tB*(-2)="<<(B*(-2))<<"\n\t|A|= "<<++A<<"\t\t\t"
        "|B|= "<<++B<<"\n\tConj(A)="<<!A<<"\t-B="<<-B;
  if(A<B)  cout<<"\n\n\tLa relacion por las normas es : A < B\n";
  if(A==B) cout<<"\n\n\tLa relacion por las normas es : A = B\n";
  if(A>B)  cout<<"\n\n\tLa relacion por las normas es : A > B\n";
        
  cout<<"\n\tA=3"<<(A=3)<<"\t\tB/2="<<(B/2)
      <<"\n\tA+5"<<(A+5)<<"\t\tB-7="<<(B-7)
      <<"\n\tA=B=";
  A=B; 
  B=0; 
  cout<<A<<"   \tB=0"<<B
      <<"\n\tA="<<A<<"\t\tB="<<B;
  cout<<"\n\n\t"; system("pause");
}


void impresion_vectores(vector3d& A, vector3d& B)
{
  cout<<"\n\n\tLos vectores <int> tienen division de enteros.\n";
  cout<<"\n\n\tCon los vectores A="<<A<<" y B="<<B
      <<" se puede:\n\n"<<"\tA+B="<<A+B<<"\t\tA-B="<<A-B
      <<"\n\tA*B="<<A*B<<"\t\t\t\tA/B="<<A/B<<"\n\tA*3="<<(A*3)
      <<"\t\tB*(-2)="<<(B*(-2))<<"\n\t|A|= "<<A.norma()<<"\t\t\t"
      <<"|B|= "<<B.norma();
  if(A.norma()<B.norma())  cout<<"\n\n\tLa relacion por las normas es : A < B\n";
  if(A.norma()==B.norma()) cout<<"\n\n\tLa relacion por las normas es : A = B\n";
  if(A.norma()>B.norma())  cout<<"\n\n\tLa relacion por las normas es : A > B\n";
        
  cout<<"\n\tA=3"<<(A=3)<<"\t\tB/2="<<(B/2)
      <<"\n\tA=B=";
  A=B; 
  B=0; 
  cout<<A<<"\t\tB=0"<<B
      <<"\n\tA="<<A<<"\t\tB="<<B;
  cout<<"\n\n\t"; system("pause");
}
