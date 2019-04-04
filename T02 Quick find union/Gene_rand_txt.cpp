
// Programa que imprime a archivo los datos a ingresar a otro programa. 
// Guillermo Arriaga Garcia 1-feb-11


#include <iostream> /*si no compilara, incluir stdio.h, si hay problema con rand
                       incluir algorithm  */
#include <math.h>                       
#include <stdio.h>

using namespace std;

static const unsigned long int N = 10000; 
 // Maximo nueve cifras para misma probabilidad

unsigned long int  aleat_gde(int cifras);

int main()
{
   int i;
   FILE* out=fopen("lista_aleatoria.txt","w"); /* Variable de archivo. A este archivo le 
                                      vamos a pasar los dos numeros de cada 
                                      programa. 'w' = write   */
   
   if (N<32767) 
      for(int i=0; i<N;i++) fprintf(out,"%d %d\n",rand()%N,rand()%N);  
      //Imprime en archivo N parejas de enteros aleatorios de entre 0 y N-1.
   if (N>=32767) 
      {int cifras=5; 
       while(N>pow(10,cifras))cifras++;  // Encuentra el número de cifras
       for(i=0; i<N;i++) 
          fprintf(out,"%d %d\n",aleat_gde(cifras),aleat_gde(cifras));  
      }  // Imprime en archivo los aleatorios

   fclose(out); // Cierre de archivo
}

   
unsigned long int aleat_gde(int cifras)
{ int i,j,k=1;
  unsigned long int al_gde=0;

  cifras=rand()%cifras;        // Para distribuir la probabilidad

  for(i=0;i<=cifras;i++) 
     {k=1;
      for(j=0;j<i;j++) k*=10;  // Posicionador decimal
      al_gde+=(rand()%10)*k;   //Genera al aleatorio
      } 
  return(al_gde%N);            // Ajusta al aleatorio
}
