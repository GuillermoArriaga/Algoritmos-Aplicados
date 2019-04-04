#include <cstdlib>
#include <iostream>
#include "vector3d.h"

using namespace std;

void impresion_vector(vector3d &v3);

int main(int argc, char *argv[])
{
    vector3d v1,v2,v3;
    int salida=0,seleccion,capturado=0;
    float x1,x2,x3,escalar;

    while(salida==0)   // Ciclo de la presentacion
    { system("cls");
      cout<<"\n\n\tGAG VECTORES 3D\n\n1.- Ingresar dos vectores en 3d\n"
      "2.- Sumarlos\n3.- Restarlos\n4.- Obtener su producto punto\n"
      "5.- Obtener su producto por escalar\n"
      "6.- Obtener el modulo o norma\n\n0.- Salir\n\nSELECCION: ";
      cin>>seleccion;
            
      switch(seleccion)
         { case 0: salida=1;break;              
           case 1: capturado=1;
                   cout<<"\n\nIngresa las componentes de V1 (x1 x2 x3): ";
                   cin>>x1>>x2>>x3; v1.captura(x1,x2,x3); 
                   cout<<"\n\nIngresa las componentes de V2 (x1 x2 x3): ";
                   cin>>x1>>x2>>x3; v2.captura(x1,x2,x3);
                   break;
           case 2: if (capturado==0)break; 
                   else{ v3=v1+v2;
                         cout<<"\n\n\tv1 + v2 = ";
                         impresion_vector(v3);
                         cout<<"\n\n"; 
                         system("pause");
                         break;
                       }
           case 3: if (capturado==0)break; 
                   else{ v3=v1-v2;
                         cout<<"\n\n\tv1 - v2 = ";
                         impresion_vector(v3);
                         cout<<"\n\n"; 
                         system("pause");
                         break;
                       }
           case 4: if (capturado==0)break; 
                   else{ cout<<"\n\n\tv1 (*) v2 = "<<v1.prod_punto(v2);
                         cout<<"\n\n"; 
                         system("pause");
                         break;
                       }
           case 5: if (capturado==0)break; 
                   else{ cout<<"\nIngresa el escalar: ";
                         cin>>escalar;
                         v3=v1*escalar;
                         cout<<"\n\n\tv1 * "<<escalar<<" = ";
                         impresion_vector(v3);

                         v3=v2*escalar;
                         cout<<"\n\tv2 * "<<escalar<<" = ";
                         impresion_vector(v3);
                         cout<<"\n\n"; 
                         system("pause");
                         break;
                       }
           case 6: if (capturado==0)break; 
                   else{ cout<<"\n\n\t|v1| = "<<v1.norma();
                         cout<<"\n\n\t|v2| = "<<v2.norma();
                         cout<<"\n\n"; 
                         system("pause");
                         break;
                       }
           default: break;
          }  // cierre de switch
    } // cierre de while      
    return (0);
}


void impresion_vector(vector3d &v3)
{cout<<"( "<<v3.x1()<<" ) X[1] + ( "<<v3.x2()<<
       " ) X[2] + ( "<<v3.x3()<<" ) X[3]";
}
