// COMPLEJO.CPP  Instrucciones para la biblioteca   Codeblocks: Proyecto add files para usar esto

#include "vector_nd.h"   // Sólo comillas, no <>
#include <math.h>
#include <stdio.h>



// Constructor de tamaño
vector::vector(int tamano)
{ n=tamano;                   // 'n' está en la clase 
  datos=new double[tamano];   // En vez de malloc (C), new -> c++
  for(int i=0;i<tamano;i++)
      datos[i]=0;
}

// Destructor
vector::~vector()
{ if(datos!=NULL)       // Para no borrar algo no asignado -> error, no sabe que hacer la funcion delete
     { delete[] datos;  // delete[] + nombre de arreglo
       datos=NULL;
     }  
}

// Constructor default
vector::vector()
{ n=0;                  // Dimension cero
}


// Constructor
vector::vector(int tamano, double* arr)
{ n=tamano;
  datos=new double[tamano]; 
  for (int i=0;i<n;i++)
       datos[i]=arr[i];                // Asigna los datos  
       
}

// Devuelve el tamaño
int vector::size()
{ return (n);
}

// Devuelve el producto punto
double vector::ProductoPunto (vector &a)
{ double producto=0;
  for (int i=0;i<n;i++)
      producto+=datos[i]*a.get(i);
  return(producto);
}

// Para modificar valores desde el programa (main)
void vector::set(int pos, double val)
{ datos[pos]=val;
}

// Para enviar el valor en cierta posicion al main
double vector::get(int pos)
{ return datos[pos];
}

// Para dar un valor a todas las componentes de un vector
void vector::set(double val)
{ for(int i=0;i<n;i++)
     datos[i]=val;
}

// Para dar un valor a todas las componentes del intervalo [ini,fin]
void vector::set(int ini, int fin, double val)
{ for(int i=ini;i<=fin;i++)
     datos[i]=val;
}


// Guardar en archivo
void vector::guarda(char* file)
{ FILE* archivo=fopen(file,"w");
  for(int i=0;i<n;i++)                      // 'n' viene de la clase
      fprintf(archivo,"%lf ",datos[i]);
  fclose(archivo);    
}


// ++++++++++++++++++++++++ OPERADORES ++++++++++++++++++++++++++++++++++++

// Suma de dos vectores
vector vector::operator+(vector &a)
{ if (n==a.size())
  {
      vector c(n);
      for(int i=0;i<n;i++)
          c.set(i,datos[i]+a.get(i));
      return c;
  }
  else return vector();//Regresa un vector vacio si no son de la misma dimension
}

// Resta de dos vectores
vector vector::operator-(vector &a)
{ if (n==a.size())
  {
      vector c(n);
      for(int i=0;i<n;i++)
          c.set(i,datos[i]-a.get(i));
      return c;
  }
  else return vector();//Regresa un vector vacio si no son de la misma dimension
}

// Producto por escalar
vector vector::operator*(double c)
{     vector b(n);
      for(int i=0;i<b.n;i++)
          b.set(i,datos[i]*c);
      return b;
}

