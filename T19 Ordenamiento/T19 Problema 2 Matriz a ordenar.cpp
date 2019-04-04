/*  =========================================================================
    ==                                                                     == 
    ==        GUILLERMO ARRIAGA GARCÍA          12/04/11                   == 
    ==                                                                     == 
    ==        ORDENADORES DE DATOS    HEAP SORT (log n - nlogn)            == 
    ==                                                                     == 
    ========================================================================= */


#include <cstdlib>
#include <iostream>
#include <ctime>

#define AMARILLO system("COLOR 0E");
#define AZUL     system("COLOR 09");
#define BLANCO   system("COLOR 07");
#define CIELO    system("COLOR 0B");
#define ROJO     system("COLOR 0C");
#define VERDE    system("COLOR 0A");
#define PAUSA    cout<<"\n\n\t";system("PAUSE");cout<<"\n\n";
#define LIMPIAR  system("CLS");
#define FINAL    LIMPIAR AMARILLO cout<<"\n\n\n\t\tFIN DEL PROGRAMA"; PAUSA

using namespace std;

// Funciones varias
void imprimir_datos(int **d,int n);
void transponer(int **d,int n);

// Funciones Heapsort
void heapsort_filas(int **d,int n);
void heapsort_columnas(int **d,int n);
void exch(int &a, int &b);
void fixDown(int *d,int k, int N);
void fixUp(int *d,int k);


/*  =========================================================================
    ==                                                                     == 
    ==                               MAIN                                  == 
    ==                                                                     == 
    ========================================================================= */


int main()
{
    int seleccion=1,i,j,n,cant=33;  // Funciona para cant=10,000 elementos
    VERDE
    
    int** matriz=new int*[cant];
    
    for(i=0;i<cant;i++)
        matriz[i]=new int[cant];
    
    for(i=0;i<cant;i++)
        for(j=0;j<cant;j++) 
           matriz[i][j]=rand()%10;

    while(seleccion!=0)
    { LIMPIAR
      cout<<"\n\n\n\t\tGuillermo Arriaga Garcia"
            "\n\n\t\tORDENADOR DE MATRIZ: Heapsort FILA - COLUMNA"
            "\n\n\tAl ordenar columnas despues de filas, las filas siguen ordenadas."
            "\n\n\n\t0.- Salir del programa."
            "\n\t1.- Modificar n de la matriz n*n."
            "\n\t2.- Ordenar filas."
            "\n\t3.- Ordenar columnas."
            "\n\t3.- Imprimir matriz.";
      imprimir_datos(matriz,cant);  // Comentar esto si cant > 35
      cout<<"\n\n\tSELECCION: ";
      fflush(stdin);
      cin>>seleccion;
      
      switch(seleccion)
      { default: break;
         case 0:  // Liberación de memoria
                  for(i=0;i<cant;i++)
                     delete [] matriz[i];
                  delete [] matriz;
                  break;
         
         case 1: // Liberación de memoria
                 for(i=0;i<cant;i++)
                     delete [] matriz[i];
                 delete [] matriz;
                 
                 cout<<"\n\n\tIngresa la cantidad de datos enteros: "; 
                 cin>>cant;
                 
                 // Asignación de memoria
                 matriz=new int*[cant];
                 for(i=0;i<cant;i++)
                     matriz[i]=new int[cant];
                // Llenado con datos aleatorios
                for(i=0;i<cant;i++)
                   for(j=0;j<cant;j++) 
                       matriz[i][j]=rand()%10;
                 break;
                 
         case 2: heapsort_filas(matriz,cant);
                 break;
         
         case 3: heapsort_columnas(matriz,cant);
                 break;
                 
         case 4: imprimir_datos(matriz,cant);
                 break;

         
      }// Cierre del switch      
    }// Cierre de interfaz (while)
    
    FINAL
    return EXIT_SUCCESS;
}




void imprimir_datos(int **d,int n)
{ cout<<"\n\n\tDATOS: \n\n\t"; 
  for(int i=0;i<n;i++)
  { for(int j=0;j<n;j++)
      cout<<d[i][j]<<" "; 
    cout<<"\n\t";
  }  
}


void transponer(int **d,int n)
{ for(int i=0;i<n;i++)
     for(int j=i+1;j<n;j++)
        exch(d[i][j],d[j][i]);
}


/*  =========================================================================
    ==                                                                     == 
    ==                        FUNCIONES  HEAPSORT                          == 
    ==                                                                     == 
    ========================================================================= */

void heapsort_filas(int **d,int n)
{  
 for(int j=0;j<n;j++)    // Recorrido de filas
 { int k, N=n+1;
   int *pq=&d[j][0]-1;
   
   // Construcción del montículo
   for(k=N/2; k>=1; k--) 
      fixDown(pq,k,N);
   
   // Intercambia el elemento más grande con el último nodo y arregla el montículo
   while(N>1)
   { exch(pq[1],pq[N]);
     fixDown(pq,1,--N);
   }
 }  
}

void heapsort_columnas(int **d,int n)
{  
  transponer(d,n);
  heapsort_filas(d,n);
  transponer(d,n);
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

void fixUp(int *d,int k)
{ while(k>1 && d[k/2]<d[k]) 
    { exch(d[k],d[k/2]);
      k/=2;
    } 
}
