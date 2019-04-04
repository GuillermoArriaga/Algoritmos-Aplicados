/* ==========================================================================
   =                                                                        =
   =           Guillermo Arriaga García   FUNCIONES CON TEMPLATE            =
   =                                                                        =
   ==========================================================================*/


/* TEMPLATE se usa para definir una clase o funcion 
   en donde el tipo de variables (ej: int, float,...) varia */
// si falla un program despues de compilar es porque me metí a un lugar prohibido de memoria (punteros)

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
using namespace std;

template<class T>
class funciones
{
  public:
    T suma(T a, T b);
    T resta(T a, T b);
    T promedio(T* a, int n);   // T* a es un arreglo  n= cantidad de elementos
    T minimo(T* a, int n);     // sobrecarga '<' con la norma de complejo
    T potencia(double x, int n);
    T polinomio(T* coef, double x, int grado);  // evaluar un polinomio en x
    void impresion(T* a, int n);
    
    // Probar los metodos con las clases complejo y vector 3d (sobrecarga el igual).
};


// METODOS: Deben estar en el .h (no en .cpp aparte)

template<class T>                // Para saber a que se refiere T (como puede cambiar de tipo de dato desde el main 
T funciones<T>::suma(T a, T b)   // definicion de un metodo ,  <T> es la clase que recibe
 { return (a+b); }


template<class T>
T funciones<T>::resta(T a, T b)
 { return (a-b); }


template<class T>
T funciones<T>::promedio(T* a, int n)
 { int i;
   T sum_total;
   sum_total=0;   // para complejos debo recargar = para que asigne a a + bi con 0 + 0i
   for(i=0;i<n;i++) sum_total+=a[i];
   return (sum_total/n); 
 }

 
template<class T>
T funciones<T>::minimo(T* a, int n)
 { int i;
   T min_total;
   min_total=a[0];
   for(i=1;i<n;i++) 
       if(min_total>a[i]) min_total=a[i];
   return (min_total);
 }


template<class T>
T funciones<T>::potencia(double x, int n)  // Cambie T x a double x para funcionar con complejos
 { int i;
   double pot;
   pot=1;
   for(i=0;i<n;i++) pot*=x;
   return ((T)pot);
 }

    
template<class T>
T funciones<T>::polinomio(T* coef, double x, int grado)
 { int i;
   T valor;
   valor*=0;
   for(i=0;i<=grado;i++)
       valor+=((coef[i])*(potencia(x,i)));
   return valor;
 }

template<class T> 
void funciones<T>::impresion(T* a, int n)
{ for(int i=1;i<n;i++) cout<<"\n\t["<<i+1<<"] = "<<a[i];
}


#endif
