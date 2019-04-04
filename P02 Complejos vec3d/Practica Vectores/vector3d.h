
// GAG 4-2-11 Biblioteca de VECTORES 3D

// VECTORES en 3d

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
            vector3d operator+(vector3d& a);        // & enviamos la direccion
            vector3d operator-(vector3d& a);
            vector3d operator*(float escalar);      // Producto escalar
};

#endif
