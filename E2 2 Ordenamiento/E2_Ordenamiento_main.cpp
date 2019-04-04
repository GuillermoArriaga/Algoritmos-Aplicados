/*  =========================================================================
    ==                                                                     == 
    ==        GUILLERMO ARRIAGA GARCÍA          17/05/11                   == 
    ==                                                                     == 
    ==        EXAMEN 2 : PROBLEMA 2 : ORDENAMIENTO                         == 
    ==                                                                     == 
    ========================================================================= */

          // Se generarán 10,000 numeros aleatorios y serán ordenados


#include <cstdlib>
#include <iostream>
#include <stdio.h>

#define AMARILLO system("COLOR 0E");
#define VERDE    system("COLOR 0A");
#define PAUSA    cout<<"\n\n\t";system("PAUSE");cout<<"\n\n";
#define LIMPIAR  system("CLS");
#define FINAL    LIMPIAR AMARILLO cout<<"\n\n\n\t\tFIN DEL PROGRAMA"; PAUSA

using namespace std;


// Funciones Heapsort
void heapsort(int *d,int l,int r);
void exch(int &a, int &b);
void fixDown(int *d,int k, int N);
void imprimir_datos(int *d,int n);
void imprimir_a_archivo(int *d,int n);


/*  =========================================================================
    ==                                                                     == 
    ==                               MAIN                                  == 
    ==                                                                     == 
    ========================================================================= */


int main()
{
    int seleccion=1,i,n,cant=10000;
    VERDE
    
    int* datos=new int[cant];
    
    for(i=0;i<cant;i++) 
        datos[i]=rand();

    while(seleccion!=0)
    { LIMPIAR
      cout<<"\n\n\n\t\tGuillermo Arriaga Garcia"
            "\n\n\t\tORDENADOR DE DATOS: Heapsort"
            "\n\n\n\t0.- Salir del programa."
            "\n\t1.- Crear una lista de n datos aleatorios."
            "\n\t2.- Ordenar con Heapsort."
            "\n\t3.- Imprimir en pantalla los datos"
            "\n\n\tSELECCION: ";
      fflush(stdin);
      cin>>seleccion;
      
      switch(seleccion)
      { default: break;
         case 0: delete datos; break;
         
         case 1: delete [] datos; 
                 cout<<"\n\n\tIngresa la cantidad de datos: "; 
                 cin>>cant;
                 datos=new int[cant];
                 for(i=0;i<cant;i++) 
                     datos[i]=rand();
                 break;
         
         case 2: heapsort(datos,0,cant-1);
                 imprimir_a_archivo(datos,cant);
                 break;
                 
         case 3: imprimir_datos(datos,cant);
                 break;

         
      }
    }
    
    FINAL
    return EXIT_SUCCESS;
}




void imprimir_datos(int *d,int n)
{
  cout<<"\n\n\tDATOS: \n\n\t"; 
  for(int i=0;i<n;i++)
     { cout<<d[i]<<"   "; 
       if((i+1)%12==0) 
          cout<<"\n\t";
     }
  PAUSA   
}


void imprimir_a_archivo(int *d,int n)
{
   FILE *out=fopen("Datos_ordenados.txt","w");
   
   fprintf(out,"\n\n\t %d DATOS ORDENADOS CON HEAPSORT: \n\n\n",n);
   for(int i=0;i<n;i++)
      fprintf(out,"%d\n",d[i]);
   
   fclose(out);   
      
}


/*  =========================================================================
    ==                                                                     == 
    ==                        FUNCIONES  HEAPSORT                          == 
    ==                                                                     == 
    ========================================================================= */

void heapsort(int *d,int l,int r)
{
   int k, N=r-l+1;
   int *pq=d+l-1;
   
   // Construcción del montículo
   for(k=N/2; k>=1; k--) 
      fixDown(pq,k,N);
   
   // Intercambia el elemento más grande con el último nodo y arregla el montículo
   while(N>1)
   { exch(pq[1],pq[N]);
     fixDown(pq,1,--N);
   }
}


void exch(int &a, int &b) 
{ int c; 
  c=a; 
  a=b; 
  b=c; 
}


void fixDown(int *d,int k, int N)
{ while(2*k <= N)
   { int j= 2*k;
     if(j<N && d[j]<d[j+1]) 
        j++;
     if(!(d[k]<d[j])) 
        break;
     exch(d[k],d[j]);
     k=j;
   }
}
