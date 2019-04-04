/*  GAG PROGRAMS POLINOMIOS  7 FEB 2011
    Algoritmos Tarea 3  Con apuntadores.
    PROGRAMA QUE RECIBE UN POLINOMIO, CALCULA SU VALOR EN CUALQUIER PUNTO 
    Y BUSCA RAÍCES EN CIERTOS INTERVALOS */


#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

#define MAX 100                                                 // Grado maximo


void presentacion(double *polinomio,int *grado, int capturado);    // Funciones
void captura_polinomio(double *polinomio,int *grado);
void evaluar_polinomio(double *polinomio,int *grado);
void raiz_polinomio(double *polinomio,int *grado);
void ejemplo_raiz();
double ejemplo_funcion(double punto);
double evalPolin(double *polinomio,int *grado, double punto);

void ejemplo_raiz2();  // Funciones agregadas
double biseccion(double a, double b, int iteraciones, double tolerancia, int *converge);  
// Nueva funcion, pedida por el profesor, es equivalente a evalPolinomio(...) 
// Se usará en la función de ejemplo, por lo que va a reemplazar ejemplo_raiz(...)


int main()
{ int grad, *grado, capturado=0;
  double *polinomio;
  polinomio=(double*)malloc(MAX*sizeof(double));
  grado=&grad;
    
  presentacion(polinomio,grado,capturado);
  return(0); 
}


void presentacion(double *polinomio,int *grado,int capturado)
{ int seleccion;
  
  system("cls");
  cout << "\n\nPROGRAMA SOBRE POLINOMIOS DE GRADO POSITIVO: Captura, "
          "evaluaciones, raices.\n\nSelecciona alguna opcion:\n\n"
          "1.- Capturar polinomio.\n"
          "2.- Calcular el valor del polinomio en algun punto.\n"
          "3.- Buscar una raiz en cierto intervalo.\n"
          "4.- Buscar una raiz de f(x)=(x^5-3)*(x^2-1.5)-4.4 en [a,b].\n"
          "5.- Hacer lo del 4) con la funcion pedida por el profesor.\n\n"
          "0.- Salir del programa\n\n\nSeleccion: ";
  fflush(stdin);                                          // Limpieza de buffer
  cin >> seleccion ;

  switch(seleccion)
        { case 0: free(polinomio);exit(0);   // Salir del programa
          case 1: capturado=1;captura_polinomio(polinomio,grado);
                  presentacion(polinomio,grado,capturado);
          case 2: if (capturado==1) evaluar_polinomio(polinomio,grado); 
                  presentacion(polinomio,grado,capturado);
          case 3: if (capturado==1) raiz_polinomio(polinomio,grado); 
                  presentacion(polinomio,grado,capturado);
          case 4: ejemplo_raiz(); presentacion(polinomio,grado,capturado);
          case 5: ejemplo_raiz2(); presentacion(polinomio,grado,capturado);          
          default: presentacion(polinomio,grado,capturado);
        }
}



void captura_polinomio(double *polinomio,int *grado)
{  int i;
   cout << "\n\nIngresa el grado (positivo y maximo "<< MAX <<"): ";
   cin >> *grado ;
   *grado=abs(*grado);                           // Ajuste del grado a positivo
   cout << "\n\nAhora ingresa los coeficientes:\n";

   for(i=*grado;i>=0;i--)
      { cout << "\tx^" << i << "= ";
        cin >> polinomio[i];
      }  
}



void evaluar_polinomio(double *polinomio,int *grado)
{  double punto;
   
   cout << "\n\nIngresa el punto a evaluar: ";
   cin >> punto;
   cout << "\n\nEl valor del polinomio es: "<<evalPolin(polinomio,grado,punto);
   cout << "\n\n\t"; system("pause");                    // Para ver la corrida
}


double evalPolin(double *polinomio,int *grado, double punto)
{  double valor=0;
   int i;
   
   for(i=0;i<=*grado;i++)
       valor+=(polinomio[i]*pow(punto,i));
   
   return (valor);
}



void raiz_polinomio(double *polinomio,int *grado)
{  int i,impreso=0;
   double a,b,c;
   
   cout << "\n\nIngresa el intervalo [a,b] (a espacio b enter): ";
   cin >> a >> b;
   
   c=(a+b-abs(b-a))/2;    // Ajuste de intervalos: a<b
   b=(a+b+abs(b-a))/2;    // Maximo
   a=c;                   // Minimo
   i=0;
   
   if(evalPolin(polinomio,grado,a)*evalPolin(polinomio,grado,b)>0)
     cout << "\n\nNo hay suficiente informacion para saber "
             "si hay alguna raiz en ese intervalo.";
   else
     { c=(a+b)/2; 

       if(abs(evalPolin(polinomio,grado,c))<=pow(10.,-6.))
          cout << "\nLa raiz es " << c << " con presicion de 1x10^-6, "
                  "f(c)= "<< evalPolin(polinomio,grado,c);
         
       else
         { for(i=0;i<40;i++)
           { c=(a+b)/2;
             if(abs(evalPolin(polinomio,grado,c))<=pow(10.,-6.)&&i!=39)
               { cout << "\nLa raiz es " << c << " con presicion de 1x10^-6, "
                 "f(c)= "<<evalPolin(polinomio,grado,c)<<"\nIteraciones: "<<i+1; 
                 impreso=1; break; 
               }
             if(evalPolin(polinomio,grado,a)*evalPolin(polinomio,grado,c)<=0) 
               {b=c; continue;}
             if(evalPolin(polinomio,grado,c)*evalPolin(polinomio,grado,b)<0)a=c;
           }
           if(impreso==0) 
              cout << "\nDespues de 40 iteraciones, la aproximacion a "
               "la raiz es "<<c<<"\ncon f(c)= " <<evalPolin(polinomio,grado,c);
         }
      }
  impreso=0;
  cout << "\n\n\t"; system("pause");                     // Para ver la corrida
}


void ejemplo_raiz()
{ int i,impreso=0;
  double a,b,c;

  cout << "\n\nIngresa el intervalo [a,b] (a espacio b enter) (a<b): ";
  cin >> a >> b;

   c=(a+b-abs(b-a))/2;    // Ajuste de intervalos: a<b
   b=(a+b+abs(b-a))/2;    // Maximo
   a=c;                   // Minimo
   i=0;

//  cout<<"\n\nSe buscara la raiz en [-1,-0.75]";   // Activar solo si se 
//  a=-1;                                           // quiere este intervalo
//  b=-0.75;
  
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
                         "f(c)= "<<ejemplo_funcion(c)<<"\nIteraciones: "<<i+1; 
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

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
double ejemplo_funcion(double punto)
{ return((pow(punto,5)-6)*(pow(punto,2)-7.5)-44); }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Funciones agregadas

void ejemplo_raiz2()
{ int i,iteraciones,converge=0;
  double a,b,c,tolerancia;

  cout << "\n\nIngresa el intervalo [a,b] (a espacio b enter) (a<b): ";
  cin >> a >> b;

   c=(a+b-abs(b-a))/2;    // Ajuste de intervalos: a<b
   b=(a+b+abs(b-a))/2;    // Maximo
   a=c;                   // Minimo
   i=0;

  cout << "\n\nIngresa las iteraciones maximas y la tolerancia (i t):";
  cin >> iteraciones >> tolerancia;

  c=biseccion(a,b,iteraciones,tolerancia,&converge);
  
  if (converge==1)
      cout << "\nLa raiz es " << c << " con presicion de "<<tolerancia
           << " y  con f(c)= "<< ejemplo_funcion(c);
  if (converge==0)
      cout << "\nDespues de "<<iteraciones<<" iteraciones, la aproximacion a la"
              " raiz es " << c << "\ncon f(c)= " << ejemplo_funcion(c);
  
  converge=0;
  cout << "\n\n\t"; system("pause");                     // Para ver la corrida
}


double biseccion(double a, double b, int iteraciones, double tolerancia, int *converge)
{ int i;
  double c;

  if(ejemplo_funcion(a)*ejemplo_funcion(b)>0)
     cout << "\n\nNo hay suficiente informacion para saber "
             "si hay alguna raiz en ese intervalo.";
  else
     { c=(a+b)/2;

       if(abs(ejemplo_funcion(a)*ejemplo_funcion(c))<=tolerancia)
          *converge=1;
         
       else
         { for(i=0;i<iteraciones;i++)
           { c=(a+b)/2;
             if(abs(ejemplo_funcion(c))<=tolerancia&&i!=iteraciones-1)
               { *converge=1; break; }
             if(ejemplo_funcion(a)*ejemplo_funcion(c)<=0) {b=c; continue;}
             if(ejemplo_funcion(c)*ejemplo_funcion(b)) a=c;
           }
         }
     }
  return (c);
} 
