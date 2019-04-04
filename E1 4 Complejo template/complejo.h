
// GAG 4-2-11 Biblioteca de complejos

// COMPLEJO.H

#ifndef COMPLEJO_H
#define COMPLEJO_H

template<class T>
class complejo
{
   public:
//            float re,im;                  // Se usan adentro y afuera del programa 
            complejo();                   // Para definir el vacio
            complejo(T r, T i);   // Constructor, captura un complejo
            ~complejo();                  // Destructor de punteros
            float norma();                
            void captura(T r, T i);
            float r();                    // Para enviar la parte real
            float i();                    // Para enviar la parte imaginaria
            complejo conjugado();
            complejo prod_escalar(float escalar);
            //complejo operator+(float& a);
            complejo operator+(const complejo<T>& a);    // & enviamos la direccion de la variable para no crear más variables
            complejo operator-(const complejo<T>& a);
            complejo operator*(const complejo<T>& a);

   private:
            T re,im;  // Sólo son validas en este programa

};

#endif

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
