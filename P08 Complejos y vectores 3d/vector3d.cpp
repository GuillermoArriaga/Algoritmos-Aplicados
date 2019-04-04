
// GAG Biblioteca de VECTORES 3D


#include "vector3d.h"   // Sólo comillas, no <>
#include <math.h>

vector3d::vector3d()   // Vacio
{  xx1=xx2=xx3=0; 
}

vector3d::vector3d(float x1, float x2, float x3) // Constructor: asignación inicial
{  xx1=x1;   
   xx2=x2;
   xx3=x3;
}

void vector3d::captura(float x1, float x2, float x3)
{  xx1=x1;   
   xx2=x2;
   xx3=x3;
}


vector3d::~vector3d() // Destructor (necesario si asignas memoria dinamica malloc)
{
  // Destruir la memoria asignada free o delete si hay apuntadores
}


float vector3d::norma()
{  return sqrt(xx1*xx1+xx2*xx2+xx3*xx3);
}


vector3d vector3d::operator+(const vector3d& a)
{    vector3d suma(xx1+a.xx1,xx2+a.xx2,xx3+a.xx3);
     return suma;
}


vector3d vector3d::operator-(const vector3d& a)
{    vector3d resta(xx1-a.xx1,xx2-a.xx2,xx3-a.xx3);
     return resta;
}


vector3d vector3d::operator/(const float escalar)
{    vector3d division_escalar(xx1/escalar,xx2/escalar,xx3/escalar);
     return division_escalar;
}

float vector3d::operator/(const vector3d& a) // division punto
{return(xx1/a.xx1+xx2/a.xx2+xx3/a.xx3);}


vector3d vector3d::operator*(const float escalar)
{    vector3d producto_escalar(xx1*escalar,xx2*escalar,xx3*escalar);
     return producto_escalar;
}

float vector3d::operator*(const vector3d& a) // producto punto
{return(xx1*a.xx1+xx2*a.xx2+xx3*a.xx3);}

float vector3d::prod_punto(vector3d& a)
{  return(xx1*a.xx1+xx2*a.xx2+xx3*a.xx3);
}
 
 
 
float vector3d::x1()
{return xx1;
}

float vector3d::x2()
{return xx2;
}

float vector3d::x3()
{return xx3;
}


// SOBRECARGA DE << Y >> PARA USAR CIN Y COUT

std::istream& operator>>(std::istream& entrada, vector3d& z)
{ 
  entrada>>z.xx1>>z.xx2>>z.xx3; 
  return entrada;
}
        
std::ostream& operator<<(std::ostream& salida, const vector3d& z)
{ salida<<" ("<<z.xx1<<" , "<<z.xx2<<" , "<<z.xx3<<") ";
  return salida; 
}


