// GAG Complejos 4-2-2011

#include <cstdlib>
#include <iostream>
#include "complejo.h"

using namespace std;

void impresion_complejo(complejo &comp);

int main(int argc, char *argv[])
{
    complejo c1,c2,c3;
    int salida=0,seleccion,capturado=0;
    float real,imaginaria,escalar;

    while(salida==0)   // Ciclo de la presentacion
    { system("cls");
      cout<<"\n\n\tGAG COMPLEJOS\n\n1.- Ingresar dos complejos\n"
      "2.- Sumarlos\n3.- Restarlos\n4.- Multiplicarlos\n"
      "5.- Obtener su producto por escalar\n6.- Obtener su norma\n"
      "7.- Obtener su conjugado\n\n0.- Salir\n\nSELECCION: ";
      cin>>seleccion;
            
      switch(seleccion)
         { case 0: salida=1;break;              
           case 1: capturado=1;
                   cout<<"\n\nIngresa a+bi del complejo1 (real imaginaria): ";
                   cin>>real>>imaginaria; c1.captura(real,imaginaria); 
                   cout<<"\n\nIngresa a+bi del complejo2 (real imaginaria): ";
                   cin>>real>>imaginaria; c2.captura(real,imaginaria); 
                   break;
           case 2: if (capturado==0)break; 
                   else{ c3=c1+c2;
                         cout<<"\n\n\tc1 + c2 = ";
                         impresion_complejo(c3);
                         cout<<"\n\n"; 
                         system("pause");
                         break;
                       }
           case 3: if (capturado==0)break; 
                   else{ c3=c1-c2;
                         cout<<"\n\n\tc1 - c2 = ";
                         impresion_complejo(c3);
                         cout<<"\n\n"; 
                         system("pause");
                         break;
                       }
           case 4: if (capturado==0)break; 
                   else{ c3=c1*c2;
                         cout<<"\n\n\tc1 * c2 = ";
                         impresion_complejo(c3);
                         cout<<"\n\n"; 
                         system("pause");
                         break;
                       }
           case 5: if (capturado==0)break; 
                   else{ cout<<"\nIngresa el escalar: ";
                         cin>>escalar;
                         c3=c1.prod_escalar(escalar);
                         cout<<"\n\n\tc1 * "<<escalar<<" = ";
                         impresion_complejo(c3);

                         c3=c2.prod_escalar(escalar);
                         cout<<"\n\tc2 * "<<escalar<<" = ";
                         impresion_complejo(c3);
                         cout<<"\n\n"; 
                         system("pause");
                         break;
                       }
           case 6: if (capturado==0)break; 
                   else{ cout<<"\n\n\t|c1| = "<<c1.norma();
                         cout<<"\n\n\t|c2| = "<<c2.norma();
                         cout<<"\n\n"; 
                         system("pause");
                         break;
                       }
           case 7: if (capturado==0)break; 
                   else{ cout<<"\n\n\t~c1 = ";
                         c3=c1.conjugado();
                         impresion_complejo(c3);
                         cout<<"\n\n\t~c2 = ";
                         c3=c2.conjugado();
                         impresion_complejo(c3);
                         cout<<"\n\n"; 
                         system("pause");
                         break;
                       }
           default: break;
          }  // cierre de switch
    } // cierre de while      
    return (0);
}


void impresion_complejo(complejo &comp)
{cout<<comp.r()<<" + ( "<<comp.i()<<" ) i";
}
