
#ifndef NODO_H
#define NODO_H

class NODO
{
   private:

   public:
            int item;
            NODO *next;
            NODO(int x, NODO *t);   // Constructor
            NODO();                 // Constructor default
            ~NODO();                // Destructor
            
};

#endif

