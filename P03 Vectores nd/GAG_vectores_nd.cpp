
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "vector_nd.h"

using namespace std;


int main()
{

    vector a;         // constructor default 
    vector b(4);      // constructor 1
  
    double *temp=new double[5];
    
    for(int i=0;i<5;i++)
       temp[i]=i;

    vector c(5,temp);  // constructor 2
    vector d(5,temp);
    d.set(2,3,1);      // Modifica los valores 2 y 3 dandoles el valor 1

    for(int i=0;i<5;i++)   // Impresión de C
        cout<<"\n C["<<i<<"]= "<<c.get(i);
    cout<<endl;

    for(int i=0;i<5;i++)   // Impresion de D
        cout<<"\n D["<<i<<"]= "<<d.get(i);
    cout<<endl;

    // Deben de medir lo mismo
    vector e=c+d;


    for(int i=0;i<5;i++)    // Impresion de E=C+D
        cout<<"\n E["<<i<<"]= "<<e.get(i);
    cout<<endl;


//    e=e*2;    //  No he logrado identificar el error, por eso hice lo que sigue.
    for(int i=0;i<5;i++)    // Impresion de E=C+D
        e.set(i,e.get(i)*2);

    double cd=c.ProductoPunto(d);
    cout<<"\n\nEl producto punto de C y D es "<<cd<<endl;
    
    // Impresion de e=e*2    
    for(int i=0;i<5;i++)
        cout<<"\n E["<<i<<"]= "<<e.get(i);
    cout<<endl;


    e.guarda("salida.txt");
    printf("\n\nsize= %d, datos[2]=%lf",e.size(),e.get(2));
    cout<<"\n\n";

    // Impresion final de e    
    for(int i=0;i<5;i++)
        cout<<"\n E["<<i<<"]= "<<e.get(i);
    cout<<endl;
    
    system ("pause");    

delete[] temp;
return 0;
    
}






//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "vector_nd.h"

using namespace std;


int main()
{

    vector a;         // constructor default 
    vector b(5);      // constructor 1
  
    double *temp=new double[5];
    
    for(int i=0;i<5;i++)
       temp[i]=i;

    // Impresion de temp
    for(int i=0;i<5;i++)
    cout<<"\n Temp["<<i<<"]= "<<temp[i];
    cout<<endl;

    
    for(int i=0;i<5;i++)
{
        b.set(i,temp[i]);

    cout<<"\n B["<<i<<"]= "<<b.get(i);
    cout<<endl;

}

    vector c(5,temp);  // constructor 2


    vector d(5,temp);
    d.set(2,3,1);

    for(int i=0;i<5;i++)
        cout<<"\n C["<<i<<"]= "<<c.get(i);
    cout<<endl;

    for(int i=0;i<5;i++)
        cout<<"\n D["<<i<<"]= "<<d.get(i);
    cout<<endl;




    // Deben de medir lo mismo
    vector e=c+d;

    // Impresion de e    
    for(int i=0;i<5;i++)
        cout<<"\n E["<<i<<"]= "<<e.get(i);
    cout<<endl;
//  system("pause");

    // Impresion de e    
    for(int i=0;i<5;i++)
        cout<<"\n E["<<i<<"]= "<<e.get(i);
    cout<<endl;
  system("pause");
    
    e=e*2;
    e.guarda("salida.txt");
    printf("\n\nsize= %d, datos[2]=%lf",e.size(),e.get(2));
    cout<<"\n\n"<<e.get(2);

    // Impresion de e    
    for(int i=0;i<5;i++)
        cout<<"\n E["<<i<<"]= "<<e.get(i);
    cout<<endl;
    
    system ("pause");    

delete[] temp;
return 0;
    
}




*/

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++







/*
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



*/
