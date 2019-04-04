
// Tarea 4: Matrices y Vectores  Guillermo Arriaga García  13 feb 2011



#include <iostream>
#include <stdlib.h>

#define MAX 200

using namespace std;


int main()
{
   int seleccion=1,dimension=5,i,j,k;
   double vec1[MAX],vec2[MAX],vec3[MAX],mat1[MAX][MAX],mat2[MAX][MAX];
   double mat3[MAX][MAX], prod_punto;
   
   for(i=0;i<MAX;i++)                        // Inicializacion
       { vec1[i]=rand()%10;
         vec2[i]=rand()%10;
         vec3[i]=0;
         for(j=0;j<MAX;j++)
             { mat1[i][j]=rand()%10;
               mat2[i][j]=rand()%10;
               mat3[i][j]=0;
             }  
       }
       
   while(seleccion!=0)
      {  system("cls");
         cout<<"\n\nGuillermo Arriaga Garcia, Tarea 4: 15 feb 2011"
               "\n\nPROGRAMA QUE OPERA CON VECTORES Y MATRICES\n\n"
               "\tLos dos vectores (n) y las dos matrices (n x n)\n\t"
               "han sido inicializados con datos aleatorios\n\n\n"
               "1.- Fijar la dimension a trabajar (max: 200).\n"
               "2.- Cambiar la informacion de algun vector o matriz.\n"
               "3.- Producto punto de los vectores. \t\tComplejidad: < 5n\n"
               "4.- Producto de una matriz por un vector. \tComplejidad: < 6n^2\n"
               "5.- Producto de las matrices. \t\t\tComplejidad: < 6n^3\n"
               "6.- Impresion de los vectores y matrices.\t\tcon n > 9\n\n"
               "0.- Salir\n\n"
               "Seleccion: ";
         cin>>seleccion;
         
         switch(seleccion)
           {
               case 0: break;

               case 1: cout<<"\n\nIngresa la dimension: ";
                       cin>>dimension;
                       break;

               case 2: cout<<"\n\n1) Vector 1\n2) Vector 2\n"
                             "3) Matriz 1\n4) Matriz 2\n\nSeleccion: ";
                       cin>>seleccion;
                       if (seleccion==1) {
                           cout<<"\n\nIngresa los coeficientes de V1:\n";
                           for(j=0;j<dimension;j++) cin>>vec1[j]; }
                       if (seleccion==2) {
                           cout<<"\n\nIngresa los coeficientes de V2:\n";
                           for(j=0;j<dimension;j++) cin>>vec2[j]; }
                       if (seleccion==3) {
                           cout<<"\n\nIngresa los coeficientes de M1:\n";
                           for(j=0;j<dimension;j++) {
                               cout<<"\nRenglon "<<j+1<<": ";
                               for(i=0;i<dimension;i++)cin>>mat1[j][i]; } }
                       if (seleccion==4) {
                           cout<<"\n\nIngresa los coeficientes de M2:\n";
                           for(j=0;j<dimension;j++) {
                               cout<<"\nRenglon "<<j+1<<": ";
                               for(i=0;i<dimension;i++)cin>>mat2[j][i]; } }
                       break;

               case 3: cout<<"\n\nEl producto punto de V1 . V2 = ";
                       
                       // Inicia el conteo de operaciones para prod. punto
                       
                       prod_punto=0;   // 1
                       for(i=0;i<dimension;i++)   // 1 + n+1 + n (n=dimension)
                           prod_punto+=vec1[i]*vec2[i];   // n*2

                       /* Termina el conteo de operaciones:  
                          1+1+n+1+n+2n= 4n+3 < 5n   con n > 9
                          Complejidad lineal:(4n,5n)  con n > 9
                       */
                       
                       cout<<prod_punto<<endl;
                       system("pause");
                       break;
                       
               case 4: cout<<"\n\n1) M1 x V1\n2) M1 x V2\n3) M2 x V1\n4) M2 x V2\n\n";
                       cin>>seleccion;
                       if(seleccion==1) { 

                       // Comienza el conteo de operaciones
     
                       for(i=0;i<dimension;i++)        // 1 + n+1 + n
                          { vec3[i]=0;                     // n
                            for(j=0;j<dimension;j++)   // 1 + n*(n+1) + n*n
                                vec3[i]+=mat1[i][j]*vec1[j]; // 3*n*n
                          }      
   /* Termina el conteo de operaciones: n=dimension. Si n=0 -> 2 operaciones.
      Si n > 0 -> 1+n+1+n+n+1+n*n+n+n*n+3*n*n = 3 + 4n + 5n^2
      Por lo que es de complejidad cuadrática entre (5n^2 , 6n^2) para n > 4
   */   

                          cout<<"\n\nM1 x V1 = ( ";
                          for(i=0;i<dimension-1;i++) cout<<vec3[i]<<" , ";
                          cout<<vec3[dimension-1]<<" )"<<endl;  }


                       if(seleccion==2) { 

                       // Comienza el conteo de operaciones
     
                       for(i=0;i<dimension;i++)        // 1 + n+1 + n
                          { vec3[i]=0;                     // n
                            for(j=0;j<dimension;j++)   // 1 + n*(n+1) + n*n
                                vec3[i]+=mat1[i][j]*vec2[j]; // 3*n*n
                          }      
   /* Termina el conteo de operaciones: n=dimension. Si n=0 -> 2 operaciones.
      Si n > 0 -> 1+n+1+n+n+1+n*n+n+n*n+3*n*n = 3 + 4n + 5n^2
      Por lo que es de complejidad cuadrática entre (5n^2 , 6n^2) para n > 4
   */   

                          cout<<"\n\nM1 x V2 = ( ";
                          for(i=0;i<dimension-1;i++) cout<<vec3[i]<<" , ";
                          cout<<vec3[dimension-1]<<" )"<<endl;  }


                       if(seleccion==3) { 

                       // Comienza el conteo de operaciones
     
                       for(i=0;i<dimension;i++)        // 1 + n+1 + n
                          { vec3[i]=0;                     // n
                            for(j=0;j<dimension;j++)   // 1 + n*(n+1) + n*n
                                vec3[i]+=mat2[i][j]*vec1[j]; // 3*n*n
                          }      
   /* Termina el conteo de operaciones: n=dimension. Si n=0 -> 2 operaciones.
      Si n > 0 -> 1+n+1+n+n+1+n*n+n+n*n+3*n*n = 3 + 4n + 5n^2
      Por lo que es de complejidad cuadrática entre (5n^2 , 6n^2) para n > 4
   */   

                          cout<<"\n\nM2 x V1 = ( ";
                          for(i=0;i<dimension-1;i++) cout<<vec3[i]<<" , ";
                          cout<<vec3[dimension-1]<<" )"<<endl;  }


                       if(seleccion==4) { 

                       // Comienza el conteo de operaciones
     
                       for(i=0;i<dimension;i++)        // 1 + n+1 + n
                          { vec3[i]=0;                     // n
                            for(j=0;j<dimension;j++)   // 1 + n*(n+1) + n*n
                                vec3[i]+=mat2[i][j]*vec2[j]; // 3*n*n
                          }      
   /* Termina el conteo de operaciones: n=dimension. Si n=0 -> 2 operaciones.
      Si n > 0 -> 1+n+1+n+n+1+n*n+n+n*n+3*n*n = 3 + 4n + 5n^2
      Por lo que es de complejidad cuadrática entre (5n^2 , 6n^2) para n > 4
   */   

                          cout<<"\n\nM2 x V2 = ( ";
                          for(i=0;i<dimension-1;i++) cout<<vec3[i]<<" , ";
                          cout<<vec3[dimension-1]<<" )"<<endl;  }
                          
                       system("pause");
                       break;

               case 5: cout<<"\n\nEl producto de M1 . M2 = \n\n";
                       
                       // Inicia el conteo de operaciones para prod. matricial
                       
                       for(i=0;i<dimension;i++)   // 1 + n+1 + n (n=dimension)
                           for(j=0;j<dimension;j++)  //  1+ n*(n+1) + n*n 
                           {   mat3[i][j]=0;         //  1*n*n
                               for(k=0;k<dimension;k++) // 1 + n*n*(n+1)+n*n*n
                                   mat3[i][j]+=mat1[i][k]*mat2[k][j];//n*n*n*3
                           }

                       /* Termina el conteo de operaciones:  
                          Si n=0 -> 2 operaciones. Si n > 0 entonces :
                          1+n+1+n+1+n*(n+1)+n*n+n*n+1+n*n*(n+1)+n*n*n+n*n*n*3=
                          5n*n*n*< 4+3n+4n*n+5n*n*n < 6*n*n*n con n > 9
                          Así que la complejidad es cúbica y está entre:
                              (5n^3 , 6n^3)   para n > 9
                          
                       */
                       
                       for(i=0;i<dimension;i++)     // Impresion del producto
                         { cout<<"\n | ";
                           for(j=0;j<dimension-1;j++)
                               cout<<mat3[i][j]<<" , ";
                           cout<<mat3[i][dimension-1]<<" |";
                         }
                       cout<<endl;  
                       system("pause");
                       break;

               case 6:    // Impresion del material operativo
                          cout<<"\n\nVector 1 = ( ";  // Impresion de Vector 1
                          for(i=0;i<dimension-1;i++) cout<<vec1[i]<<" , ";
                          cout<<vec1[i+1]<<" )"<<endl;

                          cout<<"\nVector 2 = ( ";  // Impresion de Vector 2 
                          for(i=0;i<dimension-1;i++) cout<<vec2[i]<<" , ";
                          cout<<vec2[dimension-1]<<" )"<<endl;

                       cout<<"\n\nMatriz 1:";
                       for(i=0;i<dimension;i++)     // Impresion de Matriz 1
                         { cout<<"\n | ";
                           for(j=0;j<dimension-1;j++)
                               cout<<mat1[i][j]<<" , ";
                           cout<<mat1[i][dimension-1]<<" |";
                         }

                       cout<<"\n\nMatriz 2:";
                       for(i=0;i<dimension;i++)     // Impresion de Matriz 2
                         { cout<<"\n | ";
                           for(j=0;j<dimension-1;j++)
                               cout<<mat2[i][j]<<" , ";
                           cout<<mat2[i][dimension-1]<<" |";
                         }
                       cout<<"\n\n";  
                       system("pause");
                       break;

               default: break; 
           } // Final del ciclo Switch
      }    // Final de While
   return 0;    
} // Final de main
