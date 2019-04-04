#include <string>
#include <iostream>
#include <fstream>
#include "GuiaTelefonica.h"

using namespace std;


GUIA_TELEFONICA::GUIA_TELEFONICA()
{}

GUIA_TELEFONICA::~GUIA_TELEFONICA()
{}


void GUIA_TELEFONICA::capturar()
{
    ifstream in("_Entrada.txt");
    string nombre, telefono;
    map<string,int> m;
    
    
    while(in>>nombre>>telefono)
    {
      guia[nombre]=telefono;
    }
    
    in.close();

}


string GUIA_TELEFONICA::buscar(const string& nombre) const
{   
/*    map<string,string>::iterator it;

    for(it=guia.begin() ; it!=guia.end() ; it++)
       { if(it->first==nombre)
           return it->second;
       }
    return "No se encuentra";
*/  return guia.find(nombre)->second;
}

void GUIA_TELEFONICA::insertar(const string& nombre, const string& numero)
{     guia[nombre]=numero;
      // Si el nombre ya estaba lo reemplaza (permitido)
      return;
}

void GUIA_TELEFONICA::modificar(const string& nombre,const string& numero)
{     if(guia.count(nombre))
      { guia[nombre]=numero;
      }
      else
      { 
          cout<<"\n\tEse nombre no esta en la guia, lo quiere agregar?";
          string str;
          cin>>str;
          if(str=="si"||str=="Si"||str=="SI")
            insertar(nombre,numero);
      }
      return;

}

void GUIA_TELEFONICA::eliminar(const string& nombre)
{   guia.erase(guia.find(nombre));
    return;
}


void GUIA_TELEFONICA::mostrar()
{
    map<string,string>::iterator it;

    // Impresión en archivo
    ofstream out("_Salida.txt");
    for(it=guia.begin() ; it!=guia.end() ; it++)
       out<<"\n"<<it->first<<" -> "<<it->second;
    out.close();


    // Impresión en pantalla
    int i=1;
    for(it=guia.begin() ; it!=guia.end() ; it++)
       { cout<<"\n"<<it->first<<"\t"<<it->second;
         i++;
         if((i%100)==0)
           { cout<<"\n\n\t";
             system("PAUSE");
             cout<<"\n\n";
           }
       }
    cout<<"\n\n\t";
    system("PAUSE");
    return;
}
