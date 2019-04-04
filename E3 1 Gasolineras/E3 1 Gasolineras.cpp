/*  =========================================================================
    ==                                                                     == 
    ==        GUILLERMO ARRIAGA GARCÍA          03/06/11                   == 
    ==                                                                     == 
    ==        EXÁMEN FINAL: PROB. 1   VIAJE BARATO (Gasolinerias)         == 
    ==                                                                     == 
    ========================================================================= */


#include <cstdlib>
#include <iostream>
#include <stdio.h>

#define AMARILLO system("COLOR 0E");
#define VERDE    system("COLOR 0A");
#define PAUSA    cout<<"\n\n\t";system("PAUSE");cout<<"\n\n";
#define LIMPIAR  system("CLS");
#define FINAL    LIMPIAR AMARILLO cout<<"\n\n\n\t\tFIN DEL PROGRAMA"; PAUSA

using namespace std;

#define N 48 // Cantidad de gasolineras
#define C 50  // Capacidad del Tanque (litros)
#define m 16  // Rendimiento del coche (km/litro)

float gasolinera[N+1][2]; // [i][0] = distancia al inicio, [i][1] = precio/lit.
int   gas_tour[N+1];

void eleccion_gas(int,float&); // greddy

int minimos[N+1][20]; // almacena la gasolineria anterior optimal a la [i][]
float costo_min[N+1];
int pos_min[N+1];

void calc_min(int i);
void imprimir(int i);
void eleccion_2();


/*  =========================================================================
    ==                                                                     == 
    ==                               MAIN                                  == 
    ==                                                                     == 
    ========================================================================= */


int main()
{
    int seleccion=1,i,j,k;
    float costo;
    VERDE

    
    // INICIALIZACIÓN
    gasolinera[1][0]=0;
    gasolinera[1][1]=8.23;
    for(i=2;i<=N;i++)
    { gasolinera[i][0]=gasolinera[i-1][0]+(rand()%20+4)*m;
      gasolinera[i][1]=7+(rand()%7)*1.23;
      gas_tour[i]=0;
    }
    costo=C*gasolinera[1][0];
    
    
    // Para la recursión en programación dinámica
    for(i=2;i<=N;i++)
       costo_min[i]=0;
    
    costo_min[1]=C*gasolinera[1][0];
    pos_min[1]=1; // viene de la 1
    for(i=2;gasolinera[i][0]<=C*m;i++)
    { costo_min[i]=(gasolinera[i][0]/(1.0*m))*gasolinera[i][1]+costo_min[i-1];
      pos_min[i]=1;
    }
    
    
    /* La primera y la última gasolinería(no requiere cargar) están dadas.
       La penúltima es la que su costo de llegar hasta ella y llenar
       el tanque en ella, estando a una distancia menor a igual a C*m
       sea menor de las posibles (di >= dn-C*m)
    */
    
    gas_tour[1]=1;
    eleccion_gas(2,costo);
    
    cout<<"\n\n\tEl costo minimo del viaje segun el greddy es: "<<costo
        <<"\n\n\tEscalando en las gasolinerias:\n";
    for(i=1;gas_tour[i]<=N;i++)
        cout<<gas_tour[i]<<"  ";

    PAUSA
    
    cout<<"\n\n\tGasolineria\tDistancia\tCosto";
    for(i=1;i<=N;i++)
        cout<<"\n\t\t"<<i<<"\t"<<gasolinera[i][0]<<"\t\t"<<gasolinera[i][1];

    PAUSA

    cout<<"\n\n\tLa solucion con programacion dinamica es: ";
    eleccion_2();
    
    PAUSA
    
    FINAL
    return EXIT_SUCCESS;
}


/*  =========================================================================
    ==                                                                     == 
    ==                              FUNCIONES                              == 
    ==                                                                     == 
    ========================================================================= */

void eleccion_gas(int i,float &costo)
{   
    if(i==N)
      return;
      
    int j,barata;
    // Ciudades de donde se puede venir
    for(j=gas_tour[i-1]+1 ; j<=N && gasolinera[j][0]<=(gasolinera[gas_tour[i-1]][0]+C*m); j++)
    {}
    j--;
    // j-gas_tour[i-1] indica la cantidad de gasolineras disponibles
    // sus posiciones son desde gas_tour[i-1]+1 hasta j
    
    barata=gas_tour[i-1]+1;
    for(int k=barata+1;k<=j;k++) // Busca la más barata
       if(gasolinera[barata][1]>gasolinera[k][1])
          barata=k;
    
    gas_tour[i]=barata;
    costo+=(C-(gasolinera[barata][0]-gasolinera[gas_tour[i-1]][0])/(1.0*m))*gasolinera[barata][1];

    if(i+1<=N)
       eleccion_gas(i+1,costo);

    return;
}


void eleccion_2()
{ 
    /* En la gasolineria final se calcula de donde conviene que provenga
       costo minimo= min{costo a n-i + (tanque - lo que queda)*costo en n-i; 
       ieN t.q. n-i este a una distancia <= a C*m de n }
       
       la recursion está en costo a n-i.
       La base de la recursión son
       Costo a n-n-1=0
       Costo a las ciudades alcanzables desde la inicial es el recorrido
       de la inicial a ellas.
    */
    
    int i; 
    // De cuales puede venir
    for(i=1;i<=N;i++)              // LLena todos los minimos
    { if(costo_min[i]==0)
         calc_min(i);
    }
    
    cout<<"\n\n\tEl costo minimo del viaje es "<<costo_min[N]
        <<"\n\nLas gasolineras a parar son (al reves): ";
    
    imprimir(N);

    return;

}


void calc_min(int i)
{ // Para llegar a la gasolinera i tenemos a las sigts. gasolineras:

  int j,k,minimo_posicion;
  float minimo_costo,costo_rel;
  
  minimo_costo=(costo_min[i-1]+(((gasolinera[i][0]-gasolinera[i-1][0])/((float)(m)))*gasolinera[i-1][1]));
  minimo_posicion=i-1;
  
  for(j=i-2;j>=1 && gasolinera[j][0]>=gasolinera[i][0]-C*m;j--)
  { costo_rel=costo_min[j]+(gasolinera[i][0]-gasolinera[j][0])/((float)(m))*gasolinera[j][1];
    if(costo_rel<minimo_costo)
      { minimo_costo=costo_rel;
        minimo_posicion=j;
      }
  }

  costo_min[i]=minimo_costo;
  pos_min[i]=minimo_posicion;
}


void imprimir(int i)
{ 
     if(i<1) 
       return;
       
     cout<<pos_min[i]<<" ";
     
     imprimir(pos_min[pos_min[i]]);
     
     return;
}
