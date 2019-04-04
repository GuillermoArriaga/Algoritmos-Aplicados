// COMPLEJO.CPP  Instrucciones para la biblioteca   Codeblocks: Proyecto add files para usar esto

#include "complejo.h"   // Sólo comillas, no <>
#include <math.h>

complejo::complejo()   // Vacio
{  re=im=0; }

complejo::complejo(float r, float i)   // Constructor: asignación inicial
{  re=r;   
   im=i;
}

void complejo::captura(float r, float i)
{  re=r;   
   im=i;
}

complejo::~complejo()   // Destructor (necesario si asignas memoria dinamica malloc)
{ // Destruir la memoria asignada free o delete si hay apuntadores
}


float complejo::norma()
{  return sqrt(re*re+im*im);
}


complejo complejo::operator+(complejo& a)
{
     complejo suma(re+a.re,im+a.im);
     return suma;
}


complejo complejo::operator-(complejo& a)
{
     complejo resta(re-a.re,im-a.im);
     return resta;
}


complejo complejo::operator*(complejo& a)
{
     complejo producto(re*a.re-im*a.im, re*a.im+im*a.re);
     return producto;
}



complejo complejo::conjugado()   // define variable (complejo) + nombre de la clase (complejo) :: nombre de la funcion
{
     complejo conjugado(re,(-1)*im);
     return (conjugado);
}


float complejo::r()
{return re;}

float complejo::i()
{return im;}

complejo complejo::prod_escalar(float escalar)
{ complejo com_esc(re*escalar,im*escalar);
  return com_esc;
}
