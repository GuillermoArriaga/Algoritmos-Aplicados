/* ==========================================================================
   =                                                                        =
   =    Guillermo Arriaga García   BIBLIOTECA DE COMPLEJOS CON TEMPLATE     =
   =                                                                        =
   ==========================================================================*/


#include <iostream>
#include <math.h>
using namespace std;

#ifndef COMPLEJOT_H
#define COMPLEJOT_H

template<class T>
class complejot
{
   public:
            complejot();                   // Para definir el vacio
            complejot(T r, T i);   // Constructor, captura un complejot
            ~complejot();                  // Destructor de punteros

            void captura(T r, T i);
            T norma();                
            T r();                    // Para enviar la parte real
            T i();                    // Para enviar la parte imaginaria
            complejot conjugado();

            complejot operator+(const complejot<T>& a);
            complejot operator+(const T a);
            complejot operator-(const complejot<T>& a);
            complejot operator-(const T a);
            complejot operator*(const complejot<T>& a);
            complejot operator*(const T a);  // producto escalar
            complejot operator/(const complejot<T>& a);
            complejot operator/(const T a);  // division escalar
            complejot operator=(const T a){ re=a; im=0; return *this;}
            complejot operator=(const complejot<T>& a){ re=a.re; im=a.im; return *this;}
            // Un real entre un complejo
            friend complejot operator/<>(const double izq ,const complejot<T>& der); 
            // Complejo a una potencia entera (+,0,-)
            complejot operator^(const int a);

            
            // Sobrecarga de << y >>
            friend ostream& operator<< (ostream& salida, const complejot<T>& z)
                   { if(z.im<0) salida<<" ("<<z.re<<" - "<<((-1)*z.im)<<" i) "; 
                     else salida<<" ("<<z.re<<" + "<<z.im<<" i) "; return salida; }

            friend istream& operator>> (istream& entrada, complejot<T>& z)
                   { entrada>>z.re>>z.im; return entrada; }
            
            //Sobrecarga de +=
            complejot operator+=(const complejot<T>& a);  
            complejot operator+=(const double a);    // Suma de un real
            complejot operator-=(const complejot<T>& a);
            complejot operator-=(const double a);    // Resta de un real
            complejot operator*=(const complejot<T>& a);
            complejot operator*=(const double a);    // Producto por un real
            complejot operator/=(const complejot<T>& a);
            complejot operator/=(const double a);    // Division entre un real
            
            // Sobrecarga especial de unarios
            friend complejot operator-(const complejot<T>& a)  // Negativo
                  { complejot<T> c((-1)*a.re, (-1)*a.im); return c;  }
            friend complejot operator!(const complejot<T>& a)  // Conjugado
                  { complejot<T> c(a.re, (-1)*a.im); return c;  }            
            friend double    operator++(const complejot<T>& a)  // Norma
                  { return (T)sqrt(a.re*a.re+a.im*a.im);  }


            // Comparacion de normas (clases de equivalencia)
            int operator==(const complejot<T>& a)const;
            int operator!=(const complejot<T>& a)const;
            int operator< (const complejot<T>& a)const;
            int operator<=(const complejot<T>& a)const;
            int operator>=(const complejot<T>& a)const;
            int operator> (const complejot<T>& a)const;
            

            

   private:
            T re,im;  // Sólo son validas en este programa

};

// #endif al final


/* ==========================================================================
   =                                                                        =
   =                       CONSTRUCTORES Y DESTRUCTOR                       =
   =                                                                        =
   ==========================================================================*/

   template<class T> complejot<T>::complejot()  {  re=im=0; }
   template<class T> complejot<T>::complejot(T r, T i)  { re=r; im=i; }
   template<class T> complejot<T>::~complejot()  {}


/* ==========================================================================
   =                                                                        =
   =                                MÉTODOS                                 =
   =                                                                        =
   ==========================================================================*/
   
   template<class T> void complejot<T>::captura(T r, T i) { re=r; im=i; }
   template<class T> T complejot<T>::norma() { return (T)sqrt(re*re+im*im); }
   template<class T> T complejot<T>::r() {return re;}
   template<class T> T complejot<T>::i() {return im;}
   template<class T> complejot<T> complejot<T>::conjugado()
           { complejot<T> conjugado(re,(-1)*im); return (conjugado); }


/* ==========================================================================
   =                                                                        =
   =                     SOBRECARGA DE OPERADORES                           =
   =                                                                        =
   ==========================================================================*/

   template<class T> complejot<T> complejot<T>::operator+(const complejot<T>& a)
           { complejot<T> suma((T)re+a.re,(T)im+a.im); return suma; }
   template<class T> complejot<T> complejot<T>::operator+(const T a)
           { complejot<T> cmpl((T)re+a,(T)im); return cmpl; }
           
   template<class T> complejot<T> complejot<T>::operator-(const complejot<T>& a)
           { complejot<T> resta((T)re-a.re,(T)im-a.im); return resta; }
   template<class T> complejot<T> complejot<T>::operator-(const T a)
           { complejot<T> cmpl((T)re-a,(T)im); return cmpl; }

   template<class T> complejot<T> complejot<T>::operator*(const complejot<T>& a)
           { complejot<T> prod((T)re*a.re-im*a.im,(T)re*a.im+im*a.re); return prod; }
   template<class T> complejot<T> complejot<T>::operator*(const T a)
           { complejot<T> cmpl((T)re*a,(T)im*a); return cmpl; }

   template<class T> complejot<T> complejot<T>::operator/(const complejot<T>& a)
           { complejot<T> div((T)(re*a.re+im*a.im)/(a.re*a.re+a.im*a.im), 
                              (T)(re*a.im-im*a.re)/(a.re*a.re+a.im*a.im));
             return div; }

   template<class T> complejot<T> complejot<T>::operator/(const T a)
           { complejot<T> cmpl((T)re/a,(T)im/a); return cmpl; }

   // (T) es el cast a la variable T

   // Real entre complejo       
   template<class T> complejot<T> operator/(const double izq,const complejot<T>& der)
       { complejot<T> div((T)(izq*der.re)/(der.re*der.re+der.im*der.im),
                      (T)(izq*(-1)*der.im)/(der.re*der.re+der.im*der.im)); 
         return div; }
         
   // Complejo elevado a potencia entera  (+,0,-)
   template<class T> complejot<T> complejot<T>::operator^(const int a)
       { complejot<T> potente(1,1);
         complejot<T> inicial=(*this);
         if(a<0&&inicial.re==0&&inicial.im==0) return inicial; // No inverso de (0,0)
         if(a==0) return potente;
         potente=inicial;
         if(a<0) { for(int i=1;i<(-1*a);i++) potente*=inicial;
                   return (1/potente);}
         if(a>0) { for(int i=1;i<a;i++)      potente*=inicial; 
                   return potente; } 
       }



/* ==========================================================================
   =                                                                        =
   =          SOBRECARGA DE OPERADORES RELACIONALES (usan normas)           =
   =                                                                        =
   ==========================================================================*/

   // FALSO==0, CIERTO!=0;
   template<class T>
   int complejot<T>::operator==(const complejot<T>& a) const
       { if((sqrt(re*re+im*im))==(sqrt(a.re*a.re+a.im*a.im))) return 1;
         else return 0; }

   template<class T>
   int complejot<T>::operator!=(const complejot<T>& a) const
       { if((sqrt(re*re+im*im))!=(sqrt(a.re*a.re+a.im*a.im))) return 1;
         else return 0; }

   template<class T>
   int complejot<T>::operator<(const complejot<T>& a) const
       { if((sqrt(re*re+im*im))<(sqrt(a.re*a.re+a.im*a.im))) return 1;
         else return 0; }

   template<class T>
   int complejot<T>::operator<=(const complejot<T>& a) const
       { if((sqrt(re*re+im*im))<=(sqrt(a.re*a.re+a.im*a.im))) return 1;
         else return 0; }

   template<class T>
   int complejot<T>::operator>=(const complejot<T>& a) const
       { if((sqrt(re*re+im*im))>=(sqrt(a.re*a.re+a.im*a.im))) return 1;
         else return 0; }

   template<class T>
   int complejot<T>::operator>(const complejot<T>& a) const
       { if((sqrt(re*re+im*im))>(sqrt(a.re*a.re+a.im*a.im))) return 1;
         else return 0; }



/* ==========================================================================
   =                                                                        =
   =    SOBRECARGA ESPECIAL DE UNARIOS ++ norma , ! conjugado , - neg       =
   =                                                                        =
   ==========================================================================*/

   template<class T> 
   complejot<T> operator-(const complejot<T>& a)    // Negativo   -complejo
       { complejot<T> c((-1)*a.re, (-1)*a.im); return c;  }

   template<class T>
   complejot<T> operator!(const complejot<T>& a)    // Conjugado  !complejo
       { complejot<T> c(a.re, (-1)*a.im); return c;  }
   
   template<class T>   
   double operator++(const complejot<T>& a)         // Norma      ++complejo
       { return (T)sqrt(a.re*a.re+a.im*a.im);  }



/* ==========================================================================
   =                                                                        =
   =                     SOBRECARGA DE (+,-,*,/)=                           =
   =                                                                        =
   ==========================================================================*/


   template<class T> 
   complejot<T> complejot<T>::operator+=(const complejot<T>& a)
       { re=re+a.re; im=im+a.im; return *this; }

   template<class T> 
   complejot<T> complejot<T>::operator+=(const double a)  // suma de un real
       { re=re+a; return *this; }

   template<class T> 
   complejot<T> complejot<T>::operator-=(const complejot<T>& a)
       { re=re-a.re; im=im-a.im; return *this; }

   template<class T> 
   complejot<T> complejot<T>::operator-=(const double a)  // resta de un real
       { re=re-a; return *this; }

   template<class T> 
   complejot<T> complejot<T>::operator*=(const complejot<T>& a)
       { T x=re, y=im;
         re=x*a.re-y*a.im; im=x*a.im+y*a.re; return *this; }
   
   template<class T>    
   complejot<T> complejot<T>::operator*=(const double a) // producto por un real
       { re=re*a; im=im*a; return *this; }

   template<class T> 
   complejot<T> complejot<T>::operator/=(const complejot<T>& a)
       { T x=re, y=im;
         re=(x*a.re+y*a.im)/(a.re*a.re+a.im*a.im);
         im=(x*a.im-y*a.re)/(a.re*a.re+a.im*a.im); return *this; }

   template<class T> 
   complejot<T> complejot<T>::operator/=(const double a) // division entre un real
       { re=re/a; im=im/a; return *this; }


#endif
