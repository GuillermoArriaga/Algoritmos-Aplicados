/*  =========================================================================
    ==                                                                     == 
    ==        GUILLERMO ARRIAGA GARCÍA          15/05/11                   == 
    ==                                                                     == 
    ==        TAREA 22(23)            TABLA DE HASH                        == 
    ==                                                                     == 
    ========================================================================= */

         /* =========================================================
            =                                                       =
            =      SE ABRE UN ARCHIVO CON 2400 PALABRAS EN INGLÉS   =
            =      SE DISPERSAN LAS PALABRAS CON UNA FUNC. HASH     =
            =                                                       =
            =========================================================*/

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <fstream>

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

int hash(char *v,int M,int a)
{ int h=0;
  for(;*v!=0;v++)
     h=(a*h+*v)%M;
  return h;
}

/*  =========================================================================
    ==                                                                     == 
    ==                               MAIN                                  == 
    ==                                                                     == 
    ========================================================================= */


int main()
{
   int seleccion=1,i,j,k,indicador=1;
   
   // dispersion cuenta cuantas palabras fueron asignadas a la clave i
   int dispersion1[96];
   int dispersion2[97];
   int dispersion3[96];
   
   
   // Inicializacion
   for(i=0;i<96;i++)
   { dispersion1[i]=0;
     dispersion2[i]=0;
     dispersion3[i]=0;
   }
   dispersion2[i]=0;

   
   VERDE

        /* =========================================================
           =                                                       =
           =                    CAPTURADOR DE PALABRAS             =
           =                    CON HASHING                        =           
           =                                                       =
           =========================================================*/


   char str[1024];
   
   ifstream infile;
   infile.open ("c:\\Document.txt");
   
   while(indicador==1)
   {  infile.getline(str,1024);
      char *tokenPtr=strtok(str," ");
      
      indicador=0;      // Si una linea está vacia -> termina
      
      while(tokenPtr!=NULL)
      { // cout<<tokenPtr<<"\n";  // Imprime a pantalla la palabra capturada
        dispersion1[hash(tokenPtr,96,128)]++;
        dispersion2[hash(tokenPtr,97,128)]++;
        dispersion3[hash(tokenPtr,96,127)]++;
        tokenPtr=strtok(NULL," ");
        indicador=1;  // La linea no estuvo vacía
      }
    }


        /* =========================================================
           =                                                       =
           =    Impresion de la cantidad de palabras por clave     =
           =                                                       =
           =========================================================*/

   cout<<"\n\n\tSe abrio el archivo c:\\Document.txt y se dispersaron\n\t"
         "con un Hash sus 2409 palabras (con repeticiones).\n\n\t"
         "Los resultados para Dispersion i (M,a) han sido:\n\n"
         "   Dispersion 1 (96,128)   Dispersion 2 (97,128)   Dispersion 3 (96,127)\n\n";
   for(i=0;i<96;i++)
   { cout<<"\t["<<i<<"] = "<<dispersion1[i]<<"   \t\t"
           "["<<i<<"] = "<<dispersion2[i]<<"   \t\t"
           "["<<i<<"] = "<<dispersion3[i]<<"\n";
   }
   cout<<"\t\t\t\t["<<i<<"] = "<<dispersion2[i]<<"\n";
 
   PAUSA
   
        /* =========================================================
           =                                                       =
           =  Impresión de resultados a un archivo para graficar   =
           =                                                       =
           =========================================================*/

   FILE* out=fopen("Resultados.txt","w"); 
   
   fprintf(out,"RESULTADOS DE LA DISPERSION CON HASHING\n\n\t");
   
   fprintf(out,"DISPERSION 1 M=96, a=128\n\n");
   for(i=0;i<96;i++)
     fprintf(out,"[%d]\t%d\n",i,dispersion1[i]);
   
   fprintf(out,"\n\n\n\tDISPERSION 2 M=97, a=128\n\n");
   for(i=0;i<97;i++)
     fprintf(out,"[%d]\t%d\n",i,dispersion2[i]);

   fprintf(out,"\n\n\n\tDISPERSION 3 M=96, a=127\n\n");
   for(i=0;i<96;i++)
     fprintf(out,"[%d]\t%d\n",i,dispersion3[i]);
     
   fclose(out);

   cout<<"\tSe han guardado los resultados en Resultados.txt";
   PAUSA      
   
   FINAL

   return EXIT_SUCCESS;
    
}
