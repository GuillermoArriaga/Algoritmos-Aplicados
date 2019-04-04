
#ifndef NODO_H
#define NODO_H

class NODO
{
   private:

   public:
            int contenido;
            int posicion;
            NODO* siguiente;
            NODO* anterior;
            NODO(int pos_, int cont_, NODO* ant_, NODO* sig_);   // Constructor
            NODO();                 // Constructor default
            ~NODO();                // Destructor
            
};

#endif

