/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  DICCIONARIO                    =
    =                                                                       =
    =========================================================================*/

// El profesor permitió la lista doblemente ligada

#ifndef Diccionario_H
#define Diccionario_H
#include "Listas.h"

class DICCIONARIO
{
   private:
            LISTAS dic[26];

   public:
            DICCIONARIO();                   // Constructor default 
            ~DICCIONARIO();                  // Destructor
            
            void insertar(char* palabra);
            void listarpor(char letra);
            void listar();
            int  num(char* palabra);
            int  num(char letra);
};

#endif
