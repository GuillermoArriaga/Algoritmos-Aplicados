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
void imprimir_datos(int *d,int n);

// Funciones Heapsort
void heapsort(int *d,int l,int r);
void exch(int &a, int &b);
void fixDown(int *d,int k, int N);
void fixUp(int *d,int k);



void medir_tiempo();


/*  =========================================================================
    ==                                                                     == 
    ==                               MAIN                                  == 
    ==                                                                     == 
    ========================================================================= */


int main()
{
    int seleccion=1,i,n,cant=24;
    VERDE
    
    int* datos=new int[cant];
    
    for(i=0;i<cant;i++) 
        datos[i]=10+rand()%90;

    while(seleccion!=0)
    { LIMPIAR
      cout<<"\n\n\n\t\tGuillermo Arriaga Garcia"
            "\n\n\t\tORDENADOR DE DATOS: Heapsort"
            "\n\n\n\t0.- Salir del programa."
            "\n\t1.- Modificar los datos a odenar."
            "\n\t2.- Crear una lista de n datos aleatorios."
            "\n\t3.- Ordenar con Heapsort.";
      imprimir_datos(datos,cant);
      cout<<"\n\n\tSELECCION: ";
      fflush(stdin);
      cin>>seleccion;
      
      switch(seleccion)
      { default: break;
         case 0: delete datos; break;
         
         case 1: delete datos; 
                 cout<<"\n\n\tIngresa la cantidad de datos enteros: "; 
                 cin>>cant;
                 datos=new int[cant];
                 for(i=0;i<cant;i++) 
                    { cout<<"\t["<<i+1<<"] = "; 
                      cin>>datos[i];
                    }
                 break;
         
         case 2: delete datos; 
                 cout<<"\n\n\tIngresa la cantidad de datos: "; 
                 cin>>cant;
                 datos=new int[cant];
                 for(i=0;i<cant;i++) 
                     datos[i]=10+rand()%90;
                 break;
         
         case 3: heapsort(datos,0,cant-1);
                 break;
         
      }// Cierre del switch      
    }// Cierre de interfaz (while)
    
    FINAL
    return EXIT_SUCCESS;
}




void imprimir_datos(int *d,int n)
{ cout<<"\n\n\tDATOS: \n\n\t"; 
  for(int i=0;i<n;i++)
     { cout<<d[i]<<"   "; 
       if((i+1)%12==0) 
          cout<<"\n\t";
     }
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
   for(k=N/2; k>=1; k--) fixDown(pq,k,N);
   
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

void fixUp(int *d,int k)
{ while(k>1 && d[k/2]<d[k]) 
    { exch(d[k],d[k/2]);
      k/=2;
    } 
}
