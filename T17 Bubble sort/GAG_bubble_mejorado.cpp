/*  =========================================================================
    ==                                                                     == 
    ==        GUILLERMO ARRIAGA GARCÍA          04/04/11                   == 
    ==                                                                     == 
    ==        ORDENAMIENTOS            BUBBLE SORT MEJORADO                == 
    ==                                                                     == 
    ========================================================================= */


#include <cstdlib>
#include <iostream>
#include <ctime>

#define AMARILLO system("COLOR 0E");
#define VERDE    system("COLOR 0A");
#define PAUSA    cout<<"\n\n\t";system("PAUSE");cout<<"\n\n";
#define LIMPIAR  system("CLS");
#define FINAL    LIMPIAR AMARILLO cout<<"\n\n\n\t\tFIN DEL PROGRAMA"; PAUSA

using namespace std;

void imprimir(int *lista, int m);
void bubble(int *lista, int m);
void bubble_mejorado(int *lista, int m);
void iteracion(int n,int m);

/*  =========================================================================
    ==                                                                     == 
    ==                               MAIN                                  == 
    ==                                                                     == 
    ========================================================================= */


int main()
{
   int seleccion=1,i,j,k,m=105,n,p;
   VERDE
   
   int* lista=new int[m];
   
   for(i=0;i<m;i++) lista[i]=10+rand()%90;  // Aleatorios de 2 dígitos
   

    while(seleccion!=0)
    { LIMPIAR
      cout<<"\n\n\n\t\tGuillermo Arriaga Garcia"
            "\n\n\t\tORDENAMIENTO BURBUJA MEJORADO"
            "\n\n\n\t0.- Salir del programa."
            "\n\t1.- Modificar la cantidad de datos de la lista."
            "\n\t2.- Ordenamiento Burbuja simple."
            "\n\t3.- Ordenamiento burbuja mejorado."
            "\n\t4.- n ordenamientos para comparar el tiempo.";
      imprimir(lista,m);
      cout<<"\n\n\tSELECCION: ";
      fflush(stdin);
      cin>>seleccion;
      
      switch(seleccion)
      { default: break;
         case 0: delete [] lista; break;
         
         case 1: delete [] lista; 
                 cout<<"\n\n\tNueva cantidad de elementos: ";
                 cin>>m;
                 lista=new int[m]; 
                 for(i=0;i<m;i++) lista[i]=10+rand()%90;
                 break;
         
         case 2: bubble(lista,m); break;

         case 3: bubble_mejorado(lista,m); break;
         
         case 4: cout<<"\n\n\tCantidad de iteraciones: "; cin>>n;
                 cout<<"\n\n\tCantidad de elementos: "; cin>>p;
                 iteracion(n,p);
                 break;
         
      }// Cierre del switch      
    }// Cierre de interfaz (while)
    
    FINAL
    return EXIT_SUCCESS;
}


/*  =========================================================================
    ==                                                                     == 
    ==                              FUNCIONES                              == 
    ==                                                                     == 
    ========================================================================= */


void imprimir(int *lista, int m)
{ cout<<"\n\n\tELEMENTOS DE LA LISTA:\n\n\t";
  for(int i=0;i<m;i++) { cout<<lista[i]<<"  "; if((i+1)%15==0) cout<<"\n\t"; }
}

void bubble(int *lista, int m)
{ int i,j,l,r,s;

  cout<<"\n\n\tIntervalo a ordenar [l,r]c[0,"<<m-1<<"] = ";
  cin>>l>>r;

  if(l>r) { i=l; l=r; r=i; }  // Ajuste de datos
  if(l<0) l=0;
  if(r>=m) r=m-1;
  
  for(i=r;i>=l;i--)
      for(j=l+1;j<=i;j++)
         { if(lista[j-1]>lista[j])
             { s=lista[j-1]; lista[j-1]=lista[j]; lista[j]=s; }    
         }
}

        /* =========================================================
           =                                                       =
           =        MEJORA: En la primera iteración llegan a su    =
           =        lugar el primero y el último, se hacen la      =
           =        mitad de iteraciones y termina de buscar si    =
           =        en la anterior iteración no hubieron cambios   =
           =                                                       =
           =========================================================*/


void bubble_mejorado(int *lista, int m)
{ int i,j,k,l,r,s,indicador=1;

  cout<<"\n\n\tIntervalo a ordenar [l,r]c[0,"<<m-1<<"] = ";
  cin>>l>>r;

  if(l>r) { i=l; l=r; r=i; }  // Ajuste de datos
  if(l<0) l=0;
  if(r>=m) r=m-1;
  
  for(i=r;i>=((r+l)/2);i--)
  {   indicador=0;
      for(j=l+1,k=i;j<=i;j++,k--)
         { if(lista[j-1]>lista[j])
             { s=lista[j-1]; lista[j-1]=lista[j]; lista[j]=s; indicador=1;}
           if(lista[k-1]>lista[k])
             { s=lista[k-1]; lista[k-1]=lista[k]; lista[k]=s; indicador=1;}
         }
      // imprimir(lista,m); PAUSA
      if(indicador==0) return;
  }   
}

void iteracion(int n,int m)
{
     // Se creará un vector de m elementos completamente desordenados.
     // Se repetrá el ordenamiento n veces y se medirá el tiempo.
     
   int i,j,k,l,s,lista[m], indicador; 
   clock_t tini,tfin;
   double tiempo_total=0;
   
   for(i=0;i<m;i++) lista[i]=m-i;
   
   // Medicion del Bubble
   tini=clock();             
   for(k=0;k<n;k++)
   {  for(i=m;i>=0;i--)
        for(j=1;j<=i;j++)
         { if(lista[j-1]>lista[j])
             { s=lista[j-1]; lista[j-1]=lista[j]; lista[j]=s; }    
         }
    tfin=clock();                                     
    tiempo_total+=((tfin-tini)/(double)CLOCKS_PER_SEC);
    for(i=0;i<m;i++) lista[i]=m-i; // Vuelve a desordenar el vector
    tini=clock();
   }
   
   cout<<"\n\n\tEl ordenador burbuja en la peor situacion,\n\tordenando "<<n
       <<" veces una lista de "<<m<<" elementos,\n\tha tardado "<<tiempo_total<<" segundos.";
   PAUSA
   
   // Medición del Bubble mejorado   

  tiempo_total=0;
  tini=clock();             
  for(k=0;k<n;k++)
   {for(i=m;i>=(m/2);i--)
    {   indicador=0;
        for(j=1,l=i;j<=i;j++,l--)
         { if(lista[j-1]>lista[j])
             { s=lista[j-1]; lista[j-1]=lista[j]; lista[j]=s; indicador=1;}
           if(lista[l-1]>lista[l])
             { s=lista[l-1]; lista[l-1]=lista[l]; lista[l]=s; indicador=1;}
         }
        if(indicador==0) i=0;
    }
    tfin=clock();                                     
    tiempo_total+=((tfin-tini)/(double)CLOCKS_PER_SEC);
    for(i=0;i<m;i++) lista[i]=m-i; // Vuelve a desordenar el vector
    tini=clock();
   }

   cout<<"\n\n\tEl ordenador burbuja mejorado en la peor situacion,\n\tordenando "<<n
       <<" veces una lista de "<<m<<" elementos,\n\tha tardado "<<tiempo_total<<" segundos.";
   PAUSA
   
}


/*  =========================================================================
    ==                                                                     == 
    ==        RESULTADOS: La mejora no vuelve más rápida la ordenación     == 
    ==        sólo disminuye las iteraciones a la mitad e incrementa al    == 
    ==        doble lo que en esa mitad se hace. Además, con el checador   == 
    ==        de salida del ordenamiento si en el anterior chequeo no      == 
    ==        hubo cambios, se incrementan operaciones; por lo que:        == 
    ==                                                                     == 
    ==     ITERACIONES  ELEMENTOS   BUBBLE         BUBBLE MEJORADO         == 
    ==                                                                     == 
    ==        1000       1,000      8.282 seg      9.125 seg               == 
    ==        10        10,000      8.375 seg      9.032 seg               == 
    ==        100        5,000      20.86 seg      22.50 seg               == 
    ==                                                                     == 
    ==                                                                     == 
    ==     Así, la verdadera mejora es hacer bubble en particiones de      == 
    ==     la lista y mezclar con otros algoritmos de ordenamiento.        == 
    ==                                                                     == 
    ========================================================================= */

