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
void comparacion(int n);
void bubble(int *lista, int m);

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
            "\n\t3.- Ordenar con Heapsort."
            "\n\t4.- Comparacion con bubble.";
      imprimir_datos(datos,cant);
      cout<<"\n\n\tSELECCION: ";
      //fflush(stdin);
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

         case 4: cout<<"\n\n\tIngresa la cantidad de datos: ";
                 cin>>n;
                 comparacion(n);
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



/*  =========================================================================
    ==                                                                     ==
    ==                        FUNCION DE BUBBLE                          ==
    ==                                                                     ==
    ========================================================================= */

void bubble(int *lista, int m)
{ int i,j,l,r,s;

  l=0;
  r=m-1;

  for(i=r;i>=l;i--)
      for(j=l+1;j<=i;j++)
         { if(lista[j-1]>lista[j])
             { s=lista[j-1];
               lista[j-1]=lista[j];
               lista[j]=s;
             }
         }
}



/*  =========================================================================
    ==                                                                     ==
    ==                        FUNCION DE COMPARACIÓN                       ==
    ==                                                                     ==
    ========================================================================= */


void comparacion(int n)
{
   int i;
   clock_t tini,tfin;
   double tiempo_total=0;
   // Formato del tiempo
   int dias, horas, min, seg;

   int* data1=new int[n];
   int* data2=new int[n];
   for(i=0;i<n;i++)
      { data1[i]=data2[i]=10+rand()%90;
      }

   LIMPIAR
   cout<<"\n\n\tCOMPARACION DEL HEAPSORT CON EL BUBBLE SORT\n\n\t"
       <<"COMPLEJIDADES:\tHEAPSORT  desde n log(2)(n) hasta log(2) n."
         "\n\t\t\tBUBBLESORT desde n^2 hasta n^2/2.\n\n"
         "\n                 CANTIDAD DE DATOS     ITERACIONES        TIEMPO"
         "\n    ========================================================================="
         "\n    = HEAPSORT           200,000           1'000,000          172,000 s     ="
         "\n    = BUBBLESORT                                          417'657,000 s     ="
         "\n    = (bubble / heap)                              2,428 veces + rapido     ="
         "\n    =-----------------------------------------------------------------------="
         "\n    = HEAPSORT           100,000           1'000,000          109,000 s     ="
         "\n    = BUBBLESORT                                           93'625,000 s     ="
         "\n    = (bubble / heap)                                860 veces + rapido     ="
         "\n    =-----------------------------------------------------------------------="
         "\n    = HEAPSORT            10,000           1'000,000                0 s     ="
         "\n    = BUBBLESORT                                              875,000 s     ="
         "\n    = (bubble / heap)                            infinitamente + rapido     ="
         "\n    =-----------------------------------------------------------------------="
         "\n    = HEAPSORT             1,000           1'000,000                0 s     ="
         "\n    = BUBBLESORT                                               15,000 s     ="
         "\n    = (bubble / heap)                            infinitamente + rapido     ="
         "\n    ========================================================================="
         "\n\n\t";

   //imprimir_datos(data1,n);

   // Medicion del Heapsort
   tini=clock();
   heapsort(data1,0,n-1);
   tfin=clock();
   tiempo_total=((tfin-tini)/(double)CLOCKS_PER_SEC);
   tiempo_total*=1000000;

   dias=(int)tiempo_total/86400;
   horas=(int)(tiempo_total-dias*86400)/3600;
   min=(int)(tiempo_total-dias*86400-horas*3600)/60;
   seg=(int)tiempo_total-dias*86400-horas*3600-min*60;

   cout<<"\n\n\tHEAPSORT ha tardado: "<<tiempo_total<<" segundos,"
         " que son "<<dias<<" dias + "<<horas<<"h "<<min<<"m "<<seg<<"s"
         "\n\ten acomodar "<<n<<" datos 1'000,000 de veces.\n\n\t";
   //PAUSA
   //imprimir_datos(data1,n);

   // Medicion del Bubble
   tini=clock();
   bubble(data2,n);
   tfin=clock();
   tiempo_total=((tfin-tini)/(double)CLOCKS_PER_SEC);
   tiempo_total*=1000000;

   dias=(int)tiempo_total/86400;
   horas=(int)(tiempo_total-dias*86400)/3600;
   min=(int)(tiempo_total-dias*86400-horas*3600)/60;
   seg=(int)tiempo_total-dias*86400-horas*3600-min*60;

   cout<<"\n\n\tBUBBLESORT ha tardado: "<<tiempo_total<<" segundos"
         " que son "<<dias<<" dias + "<<horas<<"h "<<min<<"m "<<seg<<"s"
         "\n\ten acomodar "<<n<<" datos 1'000,000 de veces.\n\n\t";
   //PAUSA
   //cout<<"Los datos ordenados con Bubble son: ";
   //imprimir_datos(data2,n);
   PAUSA

   delete data1;
   delete data2;
}




/*  =========================================================================
    ==                                                                     ==
    ==                  RESULTADOS DE LA COMPARACIÓN                       ==
    ==                                                                     ==
    =========================================================================

    COMPLEJIDADES: HEAPSORT  desde n log(2)(n) hasta log(2) n.
                   BUBBLESORT desde n^2 hasta n^2/2.


                    CANTIDAD DE DATOS     ITERACIONES        TIEMPO
    =========================================================================
    = HEAPSORT           200,000           1'000,000          172,000 s     =
    = BUBBLESORT                                          417'657,000 s     =
    = (bubble / heap)                              2,428 veces + rapido     =
    =-----------------------------------------------------------------------=
    = HEAPSORT           100,000           1'000,000          109,000 s     =
    = BUBBLESORT                                           93'625,000 s     =
    = (bubble / heap)                                860 veces + rapido     =
    =-----------------------------------------------------------------------=
    = HEAPSORT            10,000           1'000,000                0 s     =
    = BUBBLESORT                                              875,000 s     =
    = (bubble / heap)                          "infinitamente + rápido"     =
    =-----------------------------------------------------------------------=
    = HEAPSORT             1,000           1'000,000                0 s     =
    = BUBBLESORT                                               15,000 s     =
    = (bubble / heap)                          "infinitamente + rápido"     =
    =========================================================================
*/
