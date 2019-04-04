/* ==========================================================================
   =                                                                        =
   =          Guillermo Arriaga García   BIBLIOTECA DE COMPLEJOS            =
   =                                                                        =
   ==========================================================================*/


   #include "complejo.h"
   #include <math.h>


/* ==========================================================================
   =                                                                        =
   =                    CONSTRUCTORES Y DESTRUCTOR                          =
   =                                                                        =
   ==========================================================================*/

   complejo::complejo()  {  re=im=0; }
   complejo::complejo(double r, double i) {  re=r; im=i;  }
   complejo::~complejo() {} // No se usó NEW


/* ==========================================================================
   =                                                                        =
   =                          MÉTODOS VARIOS                                =
   =                                                                        =
   ==========================================================================*/

   // SINTAXIS: lo que regresa + nombre de la clase :: nombre de la funcion

   void complejo::captura(double r, double i) {  re=r;  im=i; }
   double complejo::r() {return re;} // Para ver la parte real
   double complejo::i() {return im;} //     " "     imaginaria
   double complejo::norma() {  return sqrt(re*re+im*im); }   
   complejo complejo::conjugado() { complejo cj(re,(-1)*im); return cj; }
   // Hay una sobrecarga especial para la norma(&) y conjugado(|)



/* ==========================================================================
   =                                                                        =
   =                SOBRECARGA DE OPERADORES ARITMÉTICOS                    =
   =                                                                        =
   ==========================================================================*/

   complejo complejo::operator+(const complejo& a)
       { complejo suma(re+a.re,im+a.im); return suma; }

   complejo complejo::operator+(const double a)  // suma de un real
       { complejo suma(re+a,im); return suma; }

   complejo complejo::operator-(const complejo& a)
       { complejo resta(re-a.re,im-a.im); return resta; }

   complejo complejo::operator-(const double a)  // resta de un real
       { complejo resta(re-a,im-a); return resta; }

   complejo complejo::operator*(const complejo& a)
       { complejo prd(re*a.re-im*a.im, re*a.im+im*a.re); return prd; }
   
   complejo complejo::operator*(const double a) // producto por un real
       { complejo prd(re*a, im*a); return prd; }

   complejo complejo::operator/(const complejo& a)
       { complejo div((re*a.re+im*a.im)/(a.re*a.re+a.im*a.im),
                      (re*a.im-im*a.re)/(a.re*a.re+a.im*a.im)); return div; }

   complejo complejo::operator/(const double a) // division entre un real
       { complejo div(re/a, im/a); return div; }
   
   // Real entre complejo       
   complejo operator/(const double izq,const complejo& der)
       { complejo div((izq*der.re)/(der.re*der.re+der.im*der.im),
                      (izq*(-1)*der.im)/(der.re*der.re+der.im*der.im)); 
         return div; }
         
   // Complejo elevado a potencia entera  (+,0,-)
   complejo complejo::operator^(const int a)
       { complejo potente(1,1);
         complejo inicial=(*this);
         if(a<0&&inicial.re==0&&inicial.im==0) return inicial; // No inverso de (0,0)
         if(a==0) return potente;
         potente=inicial;
         if(a<0) { for(int i=1;i<(-1*a);i++) potente*=inicial;
                   return (1/potente);}
         if(a>0) { for(int i=1;i<a;i++)      potente*=inicial; 
                   return potente; } 
       }


   // OPERADORES += -= *= /=

   complejo complejo::operator+=(const complejo& a)
       { re=re+a.re; im=im+a.im; return *this; }

   complejo complejo::operator+=(const double a)  // suma de un real
       { re=re+a; return *this; }

   complejo complejo::operator-=(const complejo& a)
       { re=re-a.re; im=im-a.im; return *this; }

   complejo complejo::operator-=(const double a)  // resta de un real
       { re=re-a; return *this; }

   complejo complejo::operator*=(const complejo& a)
       { double x=re, y=im;
         re=x*a.re-y*a.im; im=x*a.im+y*a.re; return *this; }
   
   complejo complejo::operator*=(const double a) // producto por un real
       { re=re*a; im=im*a; return *this; }

   complejo complejo::operator/=(const complejo& a)
       { double x=re, y=im;
         re=(x*a.re+y*a.im)/(a.re*a.re+a.im*a.im);
         im=(x*a.im-y*a.re)/(a.re*a.re+a.im*a.im); return *this; }

   complejo complejo::operator/=(const double a) // division entre un real
       { re=re/a; im=im/a; return *this; }
   
   


/* ==========================================================================
   =                                                                        =
   =    SOBRECARGA ESPECIAL DE UNARIOS ++ norma , ! conjugado , - neg        =
   =                                                                        =
   ==========================================================================*/

 
   complejo operator-(const complejo& a)        // Negativo   -complejo
       { complejo c((-1)*a.re, (-1)*a.im); return c;  }

   complejo operator!(const complejo& a)        // Conjugado  !complejo
       { complejo c(a.re, (-1)*a.im); return c;  }
   
   double operator++(const complejo& a)         // Norma      ++complejo
       { return sqrt(a.re*a.re+a.im*a.im);  }



/* ==========================================================================
   =                                                                        =
   =          SOBRECARGA DE OPERADORES DE CAPTURA E IMPRESION               =
   =                                                                        =
   ==========================================================================*/

   using namespace std;  // i/ostream en vez de std::i/ostream

   istream& operator>>(istream& entrada, complejo& z)
       { entrada>>z.re>>z.im;   return entrada;   }
        
   ostream& operator<<(ostream& salida, const complejo& z)
       { if(z.im<0) salida<<" ("<<z.re<<" - "<<((-1)*z.im)<<" i) "; 
         else salida<<" ("<<z.re<<" + "<<z.im<<" i) "; 
         return salida; 
       }


/* ==========================================================================
   =                                                                        =
   =          SOBRECARGA DE OPERADORES RELACIONALES (usan normas)           =
   =                                                                        =
   ==========================================================================*/

   // FALSO==0, CIERTO!=0;

   int complejo::operator==(const complejo& a) const
       { if((sqrt(re*re+im*im))==(sqrt(a.re*a.re+a.im*a.im))) return 1;
         else return 0; }

   int complejo::operator!=(const complejo& a) const
       { if((sqrt(re*re+im*im))!=(sqrt(a.re*a.re+a.im*a.im))) return 1;
         else return 0; }

   int complejo::operator<(const complejo& a) const
       { if((sqrt(re*re+im*im))<(sqrt(a.re*a.re+a.im*a.im))) return 1;
         else return 0; }

   int complejo::operator<=(const complejo& a) const
       { if((sqrt(re*re+im*im))<=(sqrt(a.re*a.re+a.im*a.im))) return 1;
         else return 0; }

   int complejo::operator>=(const complejo& a) const
       { if((sqrt(re*re+im*im))>=(sqrt(a.re*a.re+a.im*a.im))) return 1;
         else return 0; }

   int complejo::operator>(const complejo& a) const
       { if((sqrt(re*re+im*im))>(sqrt(a.re*a.re+a.im*a.im))) return 1;
         else return 0; }
