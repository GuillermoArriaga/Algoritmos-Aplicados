#include <cstdlib>
#include <iostream>
#include "GAG_P6_recursion_h.h"

using namespace std;

int main(int argc, char *argv[])
{  int seleccion=1, dimension=20;
   int a,b;
   double num,aa,bb,cc;
   int* vector=new int[dimension];
   
   for(a=0;a<dimension;a++) vector[a]=2+rand()%100;   // vector con aleatorios

   while(seleccion!=0)
   {  system("cls");
      cout<<"\n\n\tGuillermo Arraiga Garcia\tPractica 9: 4 de marzo de 2011\n"
            "\n\t\t\tFUNCIONES RECURSIVAS\n\n\n"
            "\t1.- Calcular el factorial de un entero.\n"
            "\t2.- Elevar un numero a la n-esima potencia (+,0,-).\n"
            "\t3.- Encontrar el maximo comun divisor de dos enteros.\n"
            "\t4.- Encontrar el minimo comun multiplo de dos enteros.\n"
            "\t5.- Calcular la funcion f(n)=a*f(n-3)+b*f(n-2)+c*f(n-1) \n\t\tcon f(0)=1 f(1)=-1 f(2)=2.\n"
            "\t6.- Sumar todos los elementos de un arreglo con enteros aleatorios.\n"
            "\t7.- Encontrar el elemento menor de un arreglo con enteros aleatorios.\n"
            "\n\n\t0.- Salir del programa\n\nSeleccion: "; cin>>seleccion;
      switch(seleccion)
      { default: break;
        case 0: delete [] vector; break;
        case 1: cout<<"\n\nIngresa el numero para calcular n!: "; cin>>a;
                if(a<0) a=(-1)*a;  // correccion de entrada
                cout<<"\nSu factorial es: "<<factorial(a);
                cout<<"\n\n"; system("pause"); break;

        case 2: cout<<"\n\nIngresa el numero y la potencia: ";  cin>>num>>a;
                cout<<"\nEl resultado es: "<<potencia(num,a);
                cout<<"\n\n"; system("pause"); break;
          
        case 3: cout<<"\n\nIngresa los dos enteros: "; cin>>a>>b;
                if(a<0) a=(-1)*a; if(b<0) a=(-1)*a;
                cout<<"\n("<<a<<","<<b<<") = "<<mcd(a,b);
                cout<<"\n\n"; system("pause"); break;
                
        case 4: cout<<"\n\nIngresa los dos enteros: "; cin>>a>>b;
                if(a<0) a=(-1)*a; if(b<0) a=(-1)*a;
                cout<<"\n["<<a<<","<<b<<"] = "<<mcm(a,b);
                cout<<"\n\n"; system("pause"); break;

        case 5: cout<<"\n\nIngresa n, a, b, c: "; cin>>a>>aa>>bb>>cc;
                cout<<"\nf("<<a<<") = "<<f_(a,aa,bb,cc);
                cout<<"\n\n"; system("pause"); break;
                
        case 6: cout<<"\n\nEl arreglo es:\n\n";
                for(a=0;a<dimension;a++) cout<<" "<<vector[a];  
                cout<<"\n\nLa suma es: "<<sumar_elem_arreglo(vector,dimension);                 
                cout<<"\n\n"; system("pause"); break;

        case 7: cout<<"\n\nEl arreglo es:\n\n";
                for(a=0;a<dimension;a++) cout<<" "<<vector[a];  
                cout<<"\n\nEl elemento menor es: "<<minimo_elem_arreglo(vector,dimension);
                cout<<"\n\n"; system("pause"); break;
                
                
      }// cierre del switch      
                        
            
   } // cierre del while
return EXIT_SUCCESS;
} // cierre del main
