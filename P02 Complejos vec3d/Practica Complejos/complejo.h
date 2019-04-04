
// GAG 4-2-11 Biblioteca de complejos

// COMPLEJO.H

#ifndef COMPLEJO_H
#define COMPLEJO_H

class complejo
{
   public:
//            float re,im;                  // Se usan adentro y afuera del programa 
            complejo();                   // Para definir el vacio
            complejo(float r, float i);   // Constructor, captura un complejo
            ~complejo();                  // Destructor de punteros
            float norma();                
            void captura(float r, float i);
            float r();                    // Para enviar la parte real
            float i();                    // Para enviar la parte imaginaria
            complejo conjugado();
            complejo prod_escalar(float escalar);
            //complejo operator+(float& a);
            complejo operator+(complejo& a);    // & enviamos la direccion de la variable para no crear más variables
            complejo operator-(complejo& a);
            complejo operator*(complejo& a);

   private:
            float re,im;  // Sólo son validas en este programa

};

#endif
