
// Guillermo AG: Programa para el inciso tres del examen exploratorio. Enero, 2011.

// Tridiagonal de una matriz cuadrada con numeros aleatorios entre 10 y 20.

#include <stdio.h>
#include <stdlib.h>

#define M 14


int main()
{
    float **a;
    int i,j,k,contador=0;
   
    a=malloc(M*sizeof(float));  // Asignación de memoria al vector de columnas
    if (a==NULL) {system("cls"); printf("\n\nNo hay memoria asignada a 'a'"); 
        getch();  exit(0);}   // Muestra si es que no se asignó memoria

    for(i=0;i<M;i++){a[i]=malloc(M*sizeof(float));
        if (a[i]==NULL){for (j=0;j<i;j++){free(a[j]);}free(a);
            printf("\n\nError");getch();exit(0);}
    }    

    // Hasta aquí, se ha creado la matriz de M x M.
    
    for(i=0;i<M;i++){for(j=0;j<M;j++){a[i][j]=0;}} 
    // Inicializacion a ceros de la matriz

    for(i=0;i<M;i++){j=rand()%11+10;k=j%2;a[i][i]=j;if(k==1)contador++;
        if(i!=0){j=rand()%11+10;k=j%2;a[i][i-1]=j;if(k==1)contador++;}
        if(i<M-1){j=rand()%11+10;k=j%2;a[i][i+1]=j;if(k==1)contador++;}
    } // Asigna los aleatorios (10-20) a la tridiagonal

    
    system("cls");
    printf("\n\nNumeros aleatorios entre el 10 y el 20 en la "
           "tridiagonal de una matriz de %i x %i con ceros en "
           "los demas elementos; de entre ellos,"
           " hay %i impares.\n\nLa matriz ha sido:\n\n",M,M,contador);

    for(i=0;i<M;i++){for(j=0;j<M;j++){if(a[i][j]==0)printf(" ");
                                      printf(" %g ",a[i][j]);}printf("\n");}  
    // Imprime la matriz con que se trabajó.
       
    for (i=0;i<M;i++){free(a[i]);}free(a);  // Liberación de memoria
    getch();
    return(0); // Fin exitoso       
}   
   
