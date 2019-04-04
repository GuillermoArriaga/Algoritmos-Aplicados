/* ==========================================================================
   =                                                                        =
   =         GUILLERMO ARRIAGA GARCÍA : PROBLEMA 3 EXAMEN 1                 = 
   =                                                                        =
   =                   EVALUADOR DE FUNCIONES INFIJAS                       =
   =                                                                        =
   =      Basado en el problema 3 del examen y la práctica 8(strings)       =
   =                                                                        =
   ========================================================================== */

/*  Implementado para expresiones posfijas con números de sólo un dígito
    y operadores +,*       p.ej: 598+46**7+*                                 */
    

/*
1)  Dada una expresión aritmética que tiene números de un dígito (ejemplo ‘0’,
    ‘7’, etc.), operadores “+”, y “*”, y las variables “x” y “y”, mandar a 
    pantalla el conjunto de evaluaciones (matriz) para la función f(x,y) que 
    representa. 
    
    Por ejemplo, para la función  F(x,y) = ((x+5)*(y*7) )*x  se mandará al 
    programa los siguientes 5 parámetros separados por espacio:
    (((x+5)*(y*7))*x) 2 5 4 8

    Donde “2 5” indica que x tomará valores en el rango [2 3 4 5] y “4 8” 
    indica que y tomará valores en el rango [4 5 6 7 8].

2)  Pare ello, se debe de usar el convertidor de infijo a posfijo y el 
    evaluador de expresiones posfijas vistos en clase.
3)  La salida del programa es el conjunto de valores en pantalla que toma 
    f(x,y) para todas las combinaciones x,y. En el ejemplo de arriba son 
    4*5=20 valores de la funcion f(x,y).
*/


#include <cstdlib>
#include <iostream>
#include <cstring>
#include "Pila.h"
#include "Nodo_h.h"
#include "Pilas.h"
#include "Nodos.h"

using namespace std;

void evaluador_infijo(string& str1,int a,int b,int c,int d);
int  evaluador_posfijo(string& posfijo,int& valor, int xx, int yy);

int main(int cant, char* cad[])
{
    int seleccion=1;


/*         ============================================================
           =                                                          =
           =                 RECEPCIÓN POR PARÁMETROS                 =
           =                                                          =
           ============================================================ */

    
    if(cant==6)  // Si se reciben parametros desde consola
      { string infijo=cad[1];
        int a=(atoi(cad[2]));
        int b=(atoi(cad[3]));
        int c=(atoi(cad[4]));
        int d=(atoi(cad[5]));
        
        evaluador_infijo(infijo,a,b,c,d);
               
        seleccion=0;
      }// Cierre del if... hacia la salida del programa


/*         ============================================================
           =                                                          =
           =                   RECEPCIÓN POR INTERFAZ                 =
           =                                                          =
           ============================================================ */


    string infijo="(((x+5)*(y*7))*x)";
    int a,b,c,d; a=2; b=5; c=4; d=8;

    while(seleccion!=0)
    {               
      system("cls");
      cout<<"\n\tGuillermo Arriaga Garcia\n\t"
            "Evaluador de funciones infijas (((x+5)*(y*7))*x) a b c d"
            "\n\tdonde x e[a,b] y e[c,d]\n\n\n"
          "\t1.- Ingresar una expresion en posfijo.\n"
          "\t2.- Evaluar expresion."
          "\n\n\t0.- Salir del programa.\n\n\tSELECCION: ";
      fflush(stdin);
      cin>>seleccion;
      
      switch(seleccion)
        { case 0: cout<<"\n\n\tFIN DEL PROGRAMA\n\n\t"; system("pause");
                  break;
                       
          case 1: cout<<"\n\n\tIngresa f(x,y) a b c d : "; 
                  cin>>infijo>>a>>b>>c>>d;
                  break;

          case 2: evaluador_infijo(infijo,a,b,c,d);
                  break;

          default: break;
        }  // Cierre del switch
   } // Cierre del while  
return 0;
} // Cierre del main



/* ==========================================================================
   =                                                                        =
   =                   EVALUADOR DE LA FUNCIÓN INFIJA                       =  
   =                                                                        =
   ========================================================================== */


void evaluador_infijo(string& str1,int a,int b,int c,int d)
{
     // Acomodo de a b c d
     int i;
     if(a>b) { i=a; a=b; b=i; }
     if(c>d) { i=c; c=d; d=i; }

/*         ============================================================
           =                                                          =
           =              CONVERSIÓN A EXPRESIÓN POSFIJA              =  
           =                                                          =
           ============================================================ */

     PILAS ps;
     string posfijo;
     int corrupcion=1;
     int accion=0;
     string cc;
     i=0;

  // Si al final no hay paréntesis de cierre, lo agrega.
  if(str1[str1.size()-1]!=')') { str1="("+str1+")"; } 


  while(str1[i]!='\0'&&corrupcion!=0)
     { accion=0;
       cc=str1[i];
       // Numero a la cadena 'posfijo'
       if(cc<="9"&&cc>="0") { posfijo+=cc; accion=1; }

       // + y * al stack de strings
       if(cc=="+") { ps.push(cc); accion=1; }
       if(cc=="*") { ps.push(cc); accion=1; }
       if(cc=="(") { accion=1;} // Ignorado
       if(cc==")") { posfijo+=(ps.pop()); accion=1; }
       if(cc=="x") { posfijo+=cc; accion=1; }
       if(cc=="X") { posfijo+="x"; accion=1; }
       if(cc=="y") { posfijo+=cc; accion=1; }
       if(cc=="Y") { posfijo+="y"; accion=1; }
       // Si hay un caracter inválido no hay corrupción
       if(accion==0) { corrupcion=0; }
       else i++;
     }// Cierre del while


/*         ============================================================
           =                                                          =
           =     EVALUACIÓN DE POSFIJO EN LAS COMBINACIONES X Y       =  
           =                                                          =
           ============================================================ */

  
  int j,posible,val;   
  int dx=b-a, dy=d-c;
  if(dx<0) dx*=-1;
  if(dy<0) dy*=-1;
    
  if(corrupcion==0) cout<<"\n\tNo es posible evaluar "<<posfijo<<"\n\n";
  else
  { cout<<"\n\n\tExpresion en infijo: f(x,y) = "<<str1
            <<"\n\n\t\tcon x en["<<a<<","<<b<<"] , y en["<<c<<","<<d<<"]\n\n";
    cout<<"\tExpresion en posfijo: f(x,y) = "<<posfijo<<"\n";
    for(i=0;i<=dx;i++) for(j=0;j<=dy;j++)
     { // Realiza la evaluación si es posible
       posible=evaluador_posfijo(posfijo,val,(a+i),(c+j));
       
       // Revisa si es posible la evaluación
       if(posible==0) 
         {cout<<"\n\tNo es posible evaluar "<<posfijo<<"\n\n"; i=b; j=d;}

       // Impresion de resultado
       else cout<<"\n\tf("<<a+i<<","<<c+j<<") = "<<val;
       
       // Pausa para leer los resultados 
       if((i+j+1)%70==0) 
         { cout<<"\n\n\t"; system("pause"); cout<<"\n"; }
     }//cierre del for
   }//cierre del else
 cout<<"\n\n\t"; system("pause"); cout<<"\n";
}



/* ==========================================================================
   =                                                                        =
   =            EVALUADOR DE CIERTAS EXPRESIONES POSFIJAS                   =  
   =                                                                        =
   ========================================================================== */

int evaluador_posfijo(string& posfijo,int& valor, int xx, int yy)
{ 
  int i=0,accion=0,corrupcion=1;
  PILA p;

  
  while(posfijo[i]!='\0'&&corrupcion!=0)  // el while recorre el string
     { accion=0;
       // Ingresa numero
       if((posfijo[i]<='9')&&(posfijo[i]>='0')) 
          { p.push((posfijo[i]-'0')); accion=1; }

       // Ingresa numeros x y
       if(posfijo[i]=='x') { p.push(xx);  accion=1; }
       if(posfijo[i]=='y') { p.push(yy);  accion=1; }

       // Suma 
       if(posfijo[i]=='+')
         { if(p.longitud()>1) { p.push((p.pop()+p.pop())); accion=1;}
           else corrupcion=0;
         }
       
       // Multiplica
       if(posfijo[i]=='*'&&p.longitud()>1) 
         { if(p.longitud()>1) { p.push((p.pop()*p.pop())); accion=1;}
           else corrupcion=0;
         }
       
       // Si hay un caracter inválido
       if(accion==0) corrupcion=0;
       else i++;
     }// Cierre del while

  valor=p.pop();

  if(corrupcion==0) return 0;

  return 1;
}// Cierre de evaluador de posfijo
