/*  =========================================================================
    ==                                                                     == 
    ==        GUILLERMO ARRIAGA GARCÍA          23/05/11                   == 
    ==                                                                     == 
    ==        TAREA 25 : PROGRAMACIÓN DINÁMICA : LÍNEAS DE PRODUCCIÓN      == 
    ==                                                                     == 
    ========================================================================= */

         /* =========================================================
            =                                                       =
            =          ENCUENTRA LA MEJOR RUTA DE PRODUCCIÓN        =
            =                                                       =
            =========================================================*/

#include <cstdlib>
#include <iostream>
#include <stdio.h>

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
    
    int costos[8][4]={{2,0,0,4},{7,2,2,8},{9,3,1,5},{3,1,2,6},{4,3,2,4},{8,4,1,5},{4,0,0,7},{3,0,0,7}};
    int minimos[8][4];
    
    minimos[1][0]=costos[0][0]+costos[1][0];
    minimos[1][1]=costos[0][3]+costos[1][3];
    minimos[1][2]=1;
    minimos[1][3]=2;
    
    if(minimos[1][0]<minimos[1][1])
       minimos[1][2]=1;
    else
       minimos[1][3]=2;


    for(i=2;i<=6;i++)
    { // Estación 1
      minimos[i][0]=costos[i][0];
      if(minimos[i-1][0]<minimos[i-1][1]+costos[i-1][2])
        { // No cambia de estación
          minimos[i][2]=1;
          minimos[i][0]+=minimos[i-1][0];
        }
      else
        {
          minimos[i][2]=2;
          minimos[i][0]+=minimos[i-1][1]+costos[i-1][2];
        }
      // Estación 2
      minimos[i][1]=costos[i][3];
      if(minimos[i-1][1]<minimos[i-1][0]+costos[i-1][1])
        { // No cambia de estación
          minimos[i][3]=2;
          minimos[i][1]+=minimos[i-1][1];
        }
      else
        {
          minimos[i][3]=1;
          minimos[i][1]+=minimos[i-1][0]+costos[i-1][1];
        }

    }    
    
    
    minimos[7][0]=minimos[6][0]+costos[7][0];
    minimos[7][1]=minimos[6][1]+costos[7][3];
    minimos[7][2]=1;
    minimos[7][3]=2;
    
    int recorrido[8];
    if(minimos[7][0]<minimos[7][1])
       recorrido[7]=1;
    else
       recorrido[7]=2;

    
    for(i=6;i>1;i--)
       recorrido[i]=minimos[i][recorrido[i+1]+1];
    
    
    
    
    cout<<"\n\n\tGuillermo Arriaga Garcia Tarea 25: Programacion Dinamica\n\n"
          "ESTACIONES:\tINICIO";
    for(i=1;i<7;i++)
      cout<<"\t"<<i;
    cout<<"\tFIN\n\nLINEA 1:";
    for(i=0;i<8;i++)
      cout<<"\t"<<costos[i][0];
    cout<<"\nTRASLADO:\t";
    for(i=1;i<6;i++)
      cout<<"\t    "<<costos[i][1];
      
    cout<<"\n\nTRASLADO:\t";
    for(i=1;i<6;i++)
      cout<<"\t    "<<costos[i][2];
    cout<<"\nLINEA 2:";
    for(i=0;i<8;i++)
      cout<<"\t"<<costos[i][3];

    cout<<"\n\nMINIMOS 1:\t";
    for(i=1;i<8;i++)
      cout<<"\t"<<minimos[i][0];
    cout<<"\nVINIENDO DE:\t";
    for(i=1;i<8;i++)
      cout<<"\t"<<minimos[i][2];

      
    cout<<"\n\nMINIMOS 2:\t";
    for(i=1;i<8;i++)
      cout<<"\t"<<minimos[i][1];
    cout<<"\nVINIENDO DE:\t";
    for(i=1;i<8;i++)
      cout<<"\t"<<minimos[i][3];
    
    cout<<"\n\nRECORRIDO OPTIMO:\t";
    for(i=2;i<7;i++)
      cout<<"E("<<recorrido[i]<<") -> ";
    cout<<"E("<<recorrido[i]<<")";
    
    PAUSA
    FINAL
    return EXIT_SUCCESS;
}
