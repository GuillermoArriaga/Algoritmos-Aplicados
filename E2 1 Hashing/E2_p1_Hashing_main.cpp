/*  =========================================================================
    ==                                                                     == 
    ==        GUILLERMO ARRIAGA GARCÍA          17/05/11                   == 
    ==                                                                     == 
    ==        EXÁMEN 2 : PROBLEMA 1: HASHING                               == 
    ==                                                                     == 
    ========================================================================= */

         /* =========================================================
            =                                                       =
            =      DIRECCIONAMIENTO ABIERTO CON PRUEBA LINEAL       =
            =           USANDO  LA FUNC. HASH : f(i)=i%7            =
            =                                                       =
            =========================================================*/

#include <cstdlib>
#include <iostream>
#include <cstring>

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

int hash(int v, int i);
int hash(int v);

/*  =========================================================================
    ==                                                                     == 
    ==                               MAIN                                  == 
    ==                                                                     == 
    ========================================================================= */


int main()
{
   int seleccion=1,i,j,k;
   char palabra[8];
   int tabla[7][2];
   
   int repeticion=0;
   
   palabra[0]='p';
   palabra[1]='r';
   palabra[2]='o';
   palabra[3]='b';
   palabra[4]='i';
   palabra[5]='n';
   palabra[6]='g';
   
   VERDE

    while(seleccion!=0)
    { LIMPIAR
      cout<<"\n\n\n\t\tGuillermo Arriaga Garcia"
            "\n\n\t\tEXAMEN 2: Problema 1: Hashing"
            "\n\n\n\t0.- Salir del programa."
            "\n\t1.- Ver resultados"
            "\n\n\tSELECCION: ";
      fflush(stdin);
      cin>>seleccion;
      
      switch(seleccion)
      { default: break;
         case 0: break;
         
         case 1: for(i=0;i<7;i++)
                    { k=0;
                      tabla[i][1]=(int)(palabra[i]);
                      while(k!=-1)
                      { repeticion=0;
                        tabla[i][0]=hash((int)(palabra[i]),k); // k es la prueba lineal

                        for(j=0;repeticion==0 && j<i;j++)  // revisa la no repetición
                            if(tabla[i][0]==tabla[j][0])
                              repeticion=1;

                        if(repeticion==1)
                          k++;  
                        if(repeticion==0)
                          k=-1;
                      }
                    }
                    
                 cout<<"\n\n\tx |\tp\tr\to\tb\ti\tn\tg\n\t"
                       "------------------------------------------------------------\n\t"
                       "i |\t";
                 for(i=0;i<7;i++)
                    cout<<tabla[i][1]<<"\t";
                 cout<<"\n\tf(i) |\t";
                 for(i=0;i<7;i++)
                    cout<<tabla[i][0]<<"\t";
                 PAUSA   
                 break;
         
         
      }
    }
    
    FINAL
    return EXIT_SUCCESS;
}


/*  =========================================================================
    ==                                                                     == 
    ==                              FUNCIONES                              == 
    ==                                                                     == 
    ========================================================================= */

int hash(int v)
{ 
  return (v)%7;
}

int hash(int v, int i)
{ return (hash(v)+i)%7;
}

/*  =========================================================================
    ==                                                                     == 
    ==                                 |                                   == 
    ==                                                                     == 
    ========================================================================= */


        /* =========================================================
           =                                                       =
           =                           |                           =
           =                                                       =
           =========================================================*/
