// COMPLEJO.CPP  Instrucciones para la biblioteca   Codeblocks: Proyecto add files para usar esto

#include "complejo.h"   // Sólo comillas, no <>
#include <math.h>

template <class T>
complejo<T>::complejo()   // Vacio
{  re=im=0; }

template <class T>
complejo<T>::complejo(T r, T i)   // Constructor: asignación inicial
{  re=r;   
   im=i;
}

template <class T>
void complejo<T>::captura(T r, T i)
{  re=r;   
   im=i;
}

template <class T>
complejo<T>::~complejo()   // Destructor (necesario si asignas memoria dinamica malloc)
{ // Destruir la memoria asignada free o delete si hay apuntadores
}

template <class T>
float complejo<T>::norma()
{  return sqrt(re*re+im*im);
}

template <class T>
complejo<T> complejo<T>::operator+(const complejo<T>& a)
{
     complejo<T> suma(re+a.re,im+a.im);
     return suma;
}

template <class T>
complejo<T> complejo<T>::operator-(const complejo<T>& a)
{
     complejo<T> resta(re-a.re,im-a.im);
     return resta;
}

template <class T>
complejo<T> complejo<T>::operator*(const complejo<T>& a)
{
     complejo<T> producto(re*a.re-im*a.im, re*a.im+im*a.re);
     return producto;
}


template <class T>
complejo<T> complejo<T>::conjugado()   // define variable (complejo) + nombre de la clase (complejo) :: nombre de la funcion
{
     complejo<T> conjugado(re,(-1)*im);
     return (conjugado);
}

template <class T>
float complejo<T>::r()
{return re;}

template <class T>
float complejo<T>::i()
{return im;}

template <class T>
complejo<T> complejo<T>::prod_escalar(float escalar)
{ complejo<T> com_esc(re*escalar,im*escalar);
  return com_esc;
}
