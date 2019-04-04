/*  GAG PROGRAMS POLINOMIOS  3 FEB 2011
    Algoritmos Tarea 3   Sin apuntadores, con variables globales
    PROGRAMA QUE RECIBE UN POLINOMIO, CALCULA SU VALOR EN CUALQUIER PUNTO 
    Y BUSCA RAÍCES EN CIERTOS INTERVALOS */


#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

#define MAX 100                                                 // Grado maximo


double polinomio[MAX];                                    // Variables globales
int i,grado,capturado=0,impreso=0;


void presentacion();                                               // Funciones
void captura_polinomio();
void evaluar_polinomio();
void raiz_polinomio();
void ejemplo_raiz();
double ejemplo_funcion(double punto);
double evalPolin(double punto);



int main()
{ presentacion();
  return(0); 
}


void presentacion()
{ int seleccion;
   
  
  system("cls");
  cout << "\n\nPROGRAMA SOBRE POLINOMIOS DE GRADO POSITIVO: Captura, "
          "evaluaciones, raices.\n\nSelecciona alguna opcion:\n\n"
          "1.- Capturar polinomio.\n"
          "2.- Calcular el valor del polinomio en algun punto.\n"
          "3.- Buscar una raiz en cierto intervalo.\n"
          "4.- Buscar una raiz de f(x)=(x^5-3)*(x^2-1.5)-4.4 en [a,b].\n\n"
          "0.- Salir del programa\n\n\nSeleccion: ";
  fflush(stdin);                                          // Limpieza de buffer
  cin >> seleccion ;

  switch(seleccion)
        { case 0: exit(0);                            // Para salir del programa
          case 1: capturado=1;captura_polinomio();presentacion();
          case 2: if (capturado==1) evaluar_polinomio(); presentacion();
          case 3: if (capturado==1) raiz_polinomio(); presentacion();
          case 4: ejemplo_raiz(); presentacion();
          default: presentacion();
        }
}



void captura_polinomio()
{
   cout << "\n\nIngresa el grado (positivo y maximo "<< MAX <<"): ";
   cin >> grado ;
   grado=abs(grado);                             // Ajuste del grado a positivo
   cout << "\n\nAhora ingresa los coeficientes:\n";

   for(i=grado;i>=0;i--)
      { cout << "\tx^" << i << "= ";
        cin >> polinomio[i] ;
      }  
}



void evaluar_polinomio()
{  double punto;
   
   cout << "\n\nIngresa el punto a evaluar: ";
   cin >> punto;
   cout << "\n\nEl valor del polinomio es: " << evalPolin(punto);
   cout << "\n\n\t"; system("pause");                    // Para ver la corrida
}


double evalPolin(double punto)
{  double valor=0;
   int j;
   
   for(j=grado;j>=0;j--)
       valor += polinomio[j]*pow(punto,j);
   
   return (valor);
}



void raiz_polinomio()
{  double a,b,c;
   cout << "\n\nIngresa el intervalo [a,b] (a espacio b enter): ";
   cin >> a >> b;
   
   c=(a+b-abs(b-a))/2;    // Ajuste de intervalos: a<b
   b=(a+b+abs(b-a))/2;    // Maximo
   a=c;                   // Minimo
   i=0;
   
   if(evalPolin(a)*evalPolin(b)>0)
     cout << "\n\nNo hay suficiente informacion para saber "
             "si hay alguna raiz en ese intervalo.";
   else
     { c=(a+b)/2; 

       if(abs(evalPolin(c))<=pow(10.,-6.))
          cout << "\nLa raiz es " << c << " con presicion de 1x10^-6, "
                  "f(c)= "<< evalPolin(c);
         
       else
         { for(i=0;i<40;i++)
           { c=(a+b)/2;
             if(abs(evalPolin(c))<=pow(10.,-6.)&&i!=39)
               { cout << "\nLa raiz es " << c << " con presicion de 1x10^-6, "
                         "f(c)= "<< evalPolin(c)<<"\nIteraciones: " << i+1; 
                 impreso=1; break; 
               }
             if(evalPolin(a)*evalPolin(c)<=0) {b=c; continue;}
             if(evalPolin(c)*evalPolin(b)<0) a=c;
           }
           if(impreso==0) 
              cout << "\nDespues de 40 iteraciones, la aproximacion a "
                      "la raiz es " << c << "\ncon f(c)= " << evalPolin(c);
         }
      }
  impreso=0;
  cout << "\n\n\t"; system("pause");                     // Para ver la corrida
}


void ejemplo_raiz()
{ double a,b,c;

  cout << "\n\nIngresa el intervalo [a,b] (a espacio b enter) (a<b): ";
  cin >> a >> b;

   c=(a+b-abs(b-a))/2;    // Ajuste de intervalos: a<b
   b=(a+b+abs(b-a))/2;    // Maximo
   a=c;                   // Minimo
   i=0;
  
  if(ejemplo_funcion(a)*ejemplo_funcion(b)>0)
     cout << "\n\nNo hay suficiente informacion para saber "
             "si hay alguna raiz en ese intervalo.";
  else
     { c=(a+b)/2;

       if(abs(ejemplo_funcion(a)*ejemplo_funcion(c))<=pow(10.,-6.))
          cout << "\nLa raiz es " << c << " con presicion de 1x10^-6, "
                  "f(c)= "<< ejemplo_funcion(c);
         
       else
         { for(i=0;i<40;i++)
           { c=(a+b)/2;
             if(abs(ejemplo_funcion(c))<=pow(10.,-6.)&&i!=39)
               { cout << "\nLa raiz es " << c << " con presicion de 1x10^-6, "
                         "f(c)= "<< ejemplo_funcion(c) << "\nIteraciones: " << i+1; 
                 impreso=1; break; }
             if(ejemplo_funcion(a)*ejemplo_funcion(c)<=0) {b=c; continue;}
             if(ejemplo_funcion(c)*ejemplo_funcion(b)) a=c;
           }
           if(impreso==0) 
              cout << "\nDespues de 40 iteraciones, la aproximacion a la"
                      " raiz es " << c << "\ncon f(c)= " << ejemplo_funcion(c);
         }
     }
  impreso=0;
  cout << "\n\n\t"; system("pause");                     // Para ver la corrida
}

double ejemplo_funcion(double punto)
{ return((pow(punto,5)-3)*(pow(punto,2)-1.5)-4.4); }
