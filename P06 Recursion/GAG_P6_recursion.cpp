
// Recursion cpp

// Descripcion de funciones


#include "GAG_P6_recursion_h.h"


long unsigned int factorial(long unsigned int numero) // n!=n(n-1)!
{ if(numero==0)return 1;
  return numero*factorial(numero-1);
}

//++++++++++++++++++++++++++++++++++++++++++++++++

long double potencia(long double numero, int n)  // n^m=n*n^m-1
{ if(n>0)  return numero*potencia(numero,n-1);
  if(n==0) return 1;
  if(n<0)  return (1/numero)*potencia(numero,n+1);
}

//++++++++++++++++++++++++++++++++++++++++++++++++


int mcd(int a, int b)   // mcd(a,b)=mcd(b%a,a)
{ int c;
    if(a<0) a=-a;
    if(b<0) b=-b;
    if(a<b) {c=a; a=b; b=c;}   // para tener a>b
    if(a%b==0)  return b;
    return mcd(b,a%b);
}

//++++++++++++++++++++++++++++++++++++++++++++++++


int mcm(int a, int b)
{ return (a*b)/mcd(a,b);
}

//++++++++++++++++++++++++++++++++++++++++++++++++


double f_(int n, float a, float b, float c)
{ if(n==0) return 1;
  if(n==1) return -1;
  if(n==2) return 2;
  return a*f_(n-3,a,b,c)+b*f_(n-2,a,b,c)+c*f_(n-1,a,b,c);
}

//++++++++++++++++++++++++++++++++++++++++++++++++

  // f_0=1  f_1=-1  f_2=2  f_n=a*f_(n-3)+b*f_(n-2)+c*f(n-1)  para n>2
int sumar_elem_arreglo(int* arreglo,int dimension)    // Partiendo en dos el arreglo
{ if(dimension==0) return 0;
  return arreglo[dimension-1]+sumar_elem_arreglo(arreglo,dimension-1);
}

//++++++++++++++++++++++++++++++++++++++++++++++++

double minimo_elem_arreglo(int* arreglo,int dimension)
{  if(dimension==0) return arreglo[0];
   if(arreglo[dimension-1]<minimo_elem_arreglo(arreglo,dimension-1))
      return arreglo[dimension-1];
   return minimo_elem_arreglo(arreglo,dimension-1);
}
