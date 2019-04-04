/* ==========================================================================
   =                                                                        =
   =          Guillermo Arriaga García   BIBLIOTECA DE COMPLEJOS            =
   =                                                                        =
   ==========================================================================*/


#include <iostream>
using namespace std;

#ifndef COMPLEJO_H
#define COMPLEJO_H

class complejo
{
   public:
            // Constructores y destructor
            complejo();                     
            complejo(double r, double i);   
            ~complejo();
            
            // Funciones utiles
            double norma();                // Tambien con el operador ++
            void captura(double r, double i);
            double r();                    // Para enviar la parte real
            double i();                    // Para enviar la parte imaginaria
            complejo conjugado();          // Tambien con el operador !

            
            // Sobrecarga de operadores
            complejo operator+(const complejo& a);  
            complejo operator+(const double a);    // Suma de un real
            complejo operator-(const complejo& a);
            complejo operator-(const double a);    // Resta de un real
            complejo operator*(const complejo& a);
            complejo operator*(const double a);    // Producto por un real
            complejo operator/(const complejo& a);
            complejo operator/(const double a);    // Division entre un real
            // Un real entre un complejo
            friend complejo operator/(const double izq ,const complejo& der); 
            // Complejo a una potencia entera (+,0,-)
            complejo operator^(const int a);

            complejo operator+=(const complejo& a);  
            complejo operator+=(const double a);    // Suma de un real
            complejo operator-=(const complejo& a);
            complejo operator-=(const double a);    // Resta de un real
            complejo operator*=(const complejo& a);
            complejo operator*=(const double a);    // Producto por un real
            complejo operator/=(const complejo& a);
            complejo operator/=(const double a);    // Division entre un real


            // Igualaciones
            complejo operator=(const double a)     // Igualación a un real
                     { re=a; im=0; return *this;}
            complejo operator=(const complejo& a)  // Igualación a un complejo
                     { re=a.re; im=a.im; return *this;}
                     
            // Sobrecarga especial de unarios
            friend complejo operator- (const complejo& a);  // Negativo
            friend complejo operator! (const complejo& a);  // Conjugado
            friend double   operator++(const complejo& a);  // Norma

            // Comparacion de normas (clases de equivalencia)
            int operator==(const complejo& a)const;
            int operator!=(const complejo& a)const;
            int operator< (const complejo& a)const;
            int operator<=(const complejo& a)const;
            int operator>=(const complejo& a)const;
            int operator> (const complejo& a)const;
            
                        
            // Sobrecarga de << y >> para imprimir con cin y cout
            friend ostream& operator<<(ostream& salida, const complejo& z);
            friend istream& operator>>(istream& entrada, complejo& z);
            

   private:
            double re,im;

};

#endif
