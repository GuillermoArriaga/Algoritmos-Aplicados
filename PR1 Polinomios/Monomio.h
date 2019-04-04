/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  NODO H                         =
    =                                                                       =
    =========================================================================*/


#ifndef MONOMIO_H
#define MONOMIO_H


class MONOMIO
{
   private:

   public:
            double contenido;
            int posicion;
            int exponente;
            MONOMIO* siguiente;
            MONOMIO* anterior;

            MONOMIO(int pos_, double cont_,int exp, MONOMIO* ant_, MONOMIO* sig_);
            MONOMIO();
            ~MONOMIO();
            
};

#endif

