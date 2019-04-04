/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  NODO INT                       =
    =                                                                       =
    =========================================================================*/


#ifndef NODOI_H
#define NODOI_H


class NODOI
{
   private:

   public:
            int contenido;
            int posicion;
            NODOI* siguiente;
            NODOI* anterior;
            NODOI(int pos_, int cont_, NODOI* ant_, NODOI* sig_);   // Constructor
            NODOI();                 // Constructor default
            ~NODOI();                // Destructor
            
};

#endif

