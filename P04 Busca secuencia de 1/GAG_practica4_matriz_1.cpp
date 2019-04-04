
/*  GAG PROGRAMS:  Captura de una matriz desde texto.
    Practica 4: Sábado 19 de febrero de 2011.
    Guillermo Arriaga García
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;



int main()
{ 
    int **matriz,contador,i,j,k,filas,columnas;
    FILE *fp;

// Captura de datos desde matriz.txt

    fp=fopen("matriz.txt","r");
    fscanf(fp,"%d %d\n",&filas,&columnas);

    matriz=new int* [filas];                // Asignacion de memoria
    for(i=0;i<filas;i++) matriz[i]=new int [columnas];
    
    for(i=0;i<filas;i++)
       { for(j=0;j<columnas-1;j++)
            { fscanf(fp,"%d ",&matriz[i][j]);     // Captura de informacion
            }
         fscanf(fp,"%d\n",&matriz[i][columnas-1]);  // Captura del último
       }  
   fclose(fp);

   cout<<"\n\n La matriz capturada ha sido:\n\n";   // Impresion de la matriz
   for(i=0;i<filas;i++) 
      { cout<<endl;
        for(j=0;j<columnas;j++) cout<<" "<<matriz[i][j]<<" ";
      }

/* Calculo del camino más largo de unos que comienza en (0,0), 
   no deben haber bifurcaciones ni ciclos */
   
   cout<<"\n\nLa ruta seguida ha sido (i,j): ";
   
   i=j=contador=0; // Inicialización
   while(matriz[i][j]==1)                 // Deteccion y eleccion de camino
     { 
       cout<<" ("<<i+1<<","<<j+1<<") -> ";      // Impresion de la ruta seguida
       /* El elemento que ya ha contado lo hace cero, busca si hay otro 'uno'
          alrededor (no diagonal), si encuentra uno repite el ciclo.*/
       contador++;
       matriz[i][j]=0;    // Para no regresar o para salir del ciclo si no hay cambio

       if(i!=filas-1)    if(matriz[i+1][j]==1) {i++;continue;}  // MOV: abajo
       if(j!=columnas-1) if(matriz[i][j+1]==1) {j++;continue;}  // MOV: derec. 
       if(i!=0) if(matriz[i-1][j]==1) {i--;continue;}           // MOV: arriba
       if(j!=0) if(matriz[i][j-1]==1) {j--;continue;}           // MOV: izqui.

     }      
    
    for(k=0;k<filas;k++) delete [] matriz[k];//Desasignar direccion en memoria
    delete [] matriz;

    // Impresion de resultados       
    cout<<"\n\nEl camino de 1's, sin bifurcaciones ni ciclos, es de "<<contador
        <<" elementos. \nLa posicion final fue (i,j) = ("<<i+1<<","<<j+1<<").\n\n";
    system("pause");  
    return(0);
}

