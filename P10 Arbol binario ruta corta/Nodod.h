/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  NODO DOUBLE                    =
    =                                                                       =
    =========================================================================*/


#ifndef NODOD_H
#define NODOD_H


class NODOD
{
   private:

   public:
            int contenido;
            int posicion;
            NODOD* siguiente;
            NODOD* anterior;
            NODOD(int pos_, int cont_, NODOD* ant_, NODOD* sig_);   // Constructor
            NODOD();                 // Constructor default
            ~NODOD();                // Destructor
            
};

#endif

