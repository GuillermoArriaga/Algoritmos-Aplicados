/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  GUIA TELEFÓNICA                =
    =                                                                       =
    =========================================================================*/


#ifndef GUIA_TELEFONICA_H
#define GUIA_TELEFONICA_H

#include <string>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;

class GUIA_TELEFONICA
{
   private:
            map<string,string> guia;

   public:
            GUIA_TELEFONICA();
            ~GUIA_TELEFONICA();
            string buscar(const string& nombre) const;
            void capturar();  // Desde _Entrada.txt
            void insertar(const string& nombre, const string& numero);
            void modificar(const string& nombre,const string& numero);
            void eliminar(const string& nombre);
            void mostrar(); // Tambien envia a _Salida.txt
            
};

#endif

