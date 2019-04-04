
// GAG Biblioteca de VECTORES 3D

// VECTORES en 3d

#include <iostream>

#ifndef VECTOR3D_H
#define VECTOR3D_H

class vector3d
{
   private:
            float xx1,xx2,xx3;  // Sólo son validas en este programa

   public:
            vector3d();                            // Para definir el vacio
            vector3d(float x1, float x2, float x3);   // Constructor
            ~vector3d();                           // Destructor de punteros
            void captura(float x1, float x2, float x3);
            float norma();
            float prod_punto(vector3d& a);          // Producto punto                
            float x1();                             // Para enviar la parte x
            float x2();                             // Para enviar la parte y
            float x3();                             // Para enviar la parte z
            vector3d operator+(const vector3d& a);        // & enviamos la direccion
            vector3d operator-(const vector3d& a);
            vector3d operator/(const float escalar);// Division escalar
            float operator/(const vector3d& a);     // Division punto
            vector3d operator*(const float escalar);// Producto escalar
            float operator*(const vector3d& a);     // Producto punto 
            vector3d operator=(const float a)       // Igualacion a escalar
                     {xx1=xx2=xx3=a; return *this;}
            vector3d operator=(const vector3d& a)   // Igualacion de vectores
                     {xx1=a.xx1; xx2=a.xx2; xx3=a.xx3; return *this;}
                     
            // Sobrecarga de << y >>
            friend std::ostream& operator<<(std::ostream& salida, const vector3d& z);
            friend std::istream& operator>>(std::istream& entrada, vector3d& z);
            
};

#endif
