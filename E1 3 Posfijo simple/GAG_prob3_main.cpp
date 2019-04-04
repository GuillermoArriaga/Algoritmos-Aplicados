/* ==========================================================================
   =                                                                        =
   =         GUILLERMO ARRIAGA GARCÍA : PROBLEMA 3 EXAMEN 1                 = 
   =                                                                        =
   =                 EVALUADOR DE EXPRESIONES POSFIJAS                      =
   =                                                                        =
   =          Basado en la tarea 9 y la práctica 8(strings)                 =
   =                                                                        =
   ========================================================================== */

/*  Implementado para expresiones posfijas con números de sólo un dígito
    y operadores +,*       p.ej: 598+46**7+*                                 */
    

#include <cstdlib>
#include <iostream>
#include <cstring>
#include "Pila.h"
#include "NODO_H.h"

using namespace std;

int evaluador(string& str1,int& valor);

int main()
{
    int seleccion=1,posible,valor=0;
    string posfijo=("598+46**7+*");

    while(seleccion!=0)
    {               
      system("cls");
      cout<<"\n\tGuillermo Arriaga Garcia\n\t"
            "Evaluador de posfijo con nums. de 1 digito y +,*\n\n\n"
          "\t1.- Ingresar una expresion en posfijo.\n"
          "\t2.- Evaluar expresion."
          "\n\n\t0.- Salir del programa.\n\n\tSELECCION: ";
      fflush(stdin);
      cin>>seleccion;
      
      switch(seleccion)
        { case 0: break;
                       
          case 1: cout<<"\n\n\tExpresion en posfijo: "; cin>>posfijo;
                  break;

          case 2: posible=evaluador(posfijo,valor);
                  if(posible==0) cout<<"\n\n\tNo es posible evaluar "<<posfijo;
                  else cout<<"\n\n\tEl valor de "<<posfijo<<" es "<<valor;
                  cout<<"\n\n\t"; system("pause");
                  break;

          default: break;
        }  // Cierre del switch
   } // Cierre del while  
cout<<"\n\n\tFIN DEL PROGRAMA\n\n\t"; system("pause");   
return 0;
} // Cierre del main




/* ==========================================================================
   =                                                                        =
   =            EVALUADOR DE CIERTAS EXPRESIONES POSFIJAS                   =  
   =                                                                        =
   ========================================================================== */

int evaluador(string& str1,int& valor)
{ 
  int i=0,accion=0;
  PILA p;
   
  while(str1[i]!='\0')  // el while recorre el string
     { 
       // Ingresa numero
       if((str1[i]<='9')&&(str1[i]>='0')) 
          { p.push((str1[i]-'0')); 
            accion=1; 
          }

       // Suma 
       if(str1[i]=='+')
         { if(p.longitud()>1) { p.push((p.pop()+p.pop())); accion=1;}
           else return 0;
         }
       
       // Multiplica
       if(str1[i]=='*'&&p.longitud()>1) 
         { if(p.longitud()>1) { p.push((p.pop()*p.pop())); accion=1;}
           else return 0;
         }
       
       // Si hay un caracter inválido
       if(accion==0) return 0;
       
       // Siguiente bucle
       i++;
       accion=0;
     }// Cierre del while
  valor=p.pop();
  return 1;
}// Cierre de evaluador
