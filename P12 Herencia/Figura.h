/*  =========================================================================
    =                                                                       =
    =             Guillermo Arriaga García  FIGURAS Tr,Cua,Pen,Cir          =
    =                                                                       =
    =========================================================================*/


#ifndef FIGURA_H
#define FIGURA_H

class Figura
{
      public:
             int num_lad;
             
             Figura();
             ~Figura();
             
             double area();        // Nada hacen, lo que pasa es que es un ejemplo
             double perimetro();   // en el que hay métodos con nombres iguales.
};



class Triangulo : public Figura
{ 
      private:
              
              float a,b,c; // lados
              
      public:
             
             Triangulo();
             ~Triangulo();
             Triangulo(float a,float b,float c);
             
             void lados(float a,float b,float c);
             double area();
             double perimetro();
};

class Cuadrado : public Figura
{
      private:
              
              float a; // lados
              
      public:
             
             Cuadrado();
             ~Cuadrado();
             Cuadrado(float a);
             
             void lado(float a);
             double area();
             double perimetro();
};


class Pentagono : public Figura //regular
{ 
      private:
              
              float a; // a = lado
              
      public:
             
             Pentagono();
             ~Pentagono();
             Pentagono(float a);
             
             void lado(float a);
             double area();
             double perimetro();
};


class Circulo : public Figura
{ 
      private:
              
              float r; // r = radio
              #define PI 3.1415926536
              
      public:
             
             Circulo();
             ~Circulo();
             Circulo(float r);
             
             void radio(float r);
             double area();
             double perimetro();
};

#endif
