
// Guillermo AG: Programa para el inciso dos del examen exploratorio. Enero, 2011.

// Buscador de los dos numeros mas grandes de un grupo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 56


int main()
{
    int *a,i,primero,segundo;
   
    a=malloc(N*sizeof(int));  // Asignación de memoria
    
    if (a==NULL) {system("cls"); printf("\n\nNo hay memoria asignada a 'a'"); 
        getch();  exit(0);}   // Muestra si es que no se asignó memoria
    
    system("cls");printf("\n\nNumeros aleatorios\n\n");
    primero=0;segundo=0;
    for(i=0;i<N;i++){a[i]=rand();
        if(primero<=a[i]){segundo=primero;primero=a[i];}
        else {if(segundo<a[i])segundo=a[i];}
        printf("[%i] = %i \t",i+1,a[i]);    // Imprime cada numero asignado
    }  /* Asigna eneteros positivos aleatorios y va obteniendo los valores 
          mayores en cada iteración */
   
   printf("\n\nSe ha creado un vector de %i elementos; de entre ellos, el "
          "mayor es %i y el segundo mayor es %i\n\n",N,primero,segundo);
   // Impresion de resultados
   
   free(a);   // Liberación de memoria
   getch();
   return(0); // Fin exitoso       
}   
   
