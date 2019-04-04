/*  =========================================================================
    ==                                                                     == 
    ==        GUILLERMO ARRIAGA GARCÍA          24/05/11                   == 
    ==                                                                     == 
    ==        PRÁCTICA 14             STL: Uso de map                      == 
    ==                                                                     == 
    ========================================================================= */

         /* =========================================================
            =                                                       =
            =        Indica cuántas veces se repite cada            =
            =          palabra recibida de archivo                  =
            =                                                       =
            =========================================================*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <map>

#define AMARILLO system("COLOR 0E");
#define VERDE    system("COLOR 0A");
#define PAUSA    cout<<"\n\n\t";system("PAUSE");cout<<"\n\n";
#define LIMPIAR  system("CLS");
#define FINAL    LIMPIAR AMARILLO cout<<"\n\n\n\t\tFIN DEL PROGRAMA"; PAUSA

using namespace std;


int main()
{
    int i,j,k;
    VERDE

    ifstream in("_Entrada.txt");
    string str;
    map<string,int> m;
    
    
    while(in>>str)
    {
      if(m.count(str))
      { m[str]++;
      }
      else
      { m[str]=1;
      }
    }
    
    in.close();
    
    map<string,int>::iterator it;


    // Impresión en archivo
    ofstream out("_Salida.txt");
    for(it=m.begin() ; it!=m.end() ; it++)
       out<<"\n"<<it->first<<"    \taparecio\t"<<it->second<<"\tveces.";
    
    out.close();




    // Impresión en pantalla
    i=1;
    for(it=m.begin() ; it!=m.end() ; it++)
       { cout<<"\n"<<it->first<<"   \taparecio\t"<<it->second<<"\tveces.";
         i++;
         if((i%100)==0)
           { cout<<"\n\n\t";
             system("PAUSE");
             cout<<"\n\n";
           }
       }
    


    PAUSA
    
    FINAL
    return EXIT_SUCCESS;
}
