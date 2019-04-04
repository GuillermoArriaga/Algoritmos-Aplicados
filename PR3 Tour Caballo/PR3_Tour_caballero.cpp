/*  =========================================================================
    ==                                                                     == 
    ==        GUILLERMO ARRIAGA GARCÍA          21/05/11                   == 
    ==                                                                     == 
    ==        PROYECTO 3              TOUR DEL CABALLERO                   == 
    ==                                                                     == 
    ========================================================================= */

         /* =========================================================
            =                                                       =
            =       UN CABALLO DE AJEREZ SE MUEVE POR TODAS         =
            =       LAS CASILLAS DEL TABLERO SIN REPETIR            =
            =       ALGUNA, EMPEZANDO DESDE UNA CASILLA DADA        =            
            =                                                       =
            =========================================================*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "pila.h"


#define AMARILLO system("COLOR 0E");
#define CIELO    system("COLOR 0B");
#define VERDE    system("COLOR 0A");
#define PAUSA    cout<<"\n\n\t";system("PAUSE");cout<<"\n\n";
#define LIMPIAR  system("CLS");
#define FINAL    LIMPIAR AMARILLO cout<<"\n\n\n\t\tFIN DEL PROGRAMA"; PAUSA

using namespace std;

void inicio(int,int);
void imprimir();
void imprimir_casillas();
void imprimir_archivo();
int  mover(int,int,int,int);

int h_ini=1,v_ini=1;      // Casilla inicial desde (1,1) hasta (8,8)
int Tablero[9][9];
const int Movimientos[9][2]=
          {{0,0},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
PILA tour;



/*  =========================================================================
    ==                                                                     == 
    ==                               MAIN                                  == 
    ==                                                                     == 
    ========================================================================= */


int main()
{
    int seleccion=1;
    
    while(seleccion!=0)
    { LIMPIAR
      VERDE
      cout<<"\n\n\n\t\tGuillermo Arriaga Garcia"
            "\n\n\t\tPROYECTO 3:    Tour del caballero"
            "\n\n\tCon la casilla inicial A1 tarda 10 segundos"
            "\n\n\n\t0.- Salir del programa"
            "\n\t1.- Dar posicion inicial"
            "\n\t2.- Ver resultado"
            "\n\t3.- Ver los pasos hacia el resultado"
            "\n\t4.- Imprimir resultado a '_Salida.txt'";
      imprimir_casillas();
      cout<<"\n\n\tSELECCION: ";
      fflush(stdin);
      cin>>seleccion;
      
      switch(seleccion)
      { default: break;

         case 1: cout<<"\n\n\tIngresa la casilla inicial (vert,horz) desde"
                       " (1,1) hasta (8,8): ";
                 cin>>h_ini>>v_ini; // estan alrevés porque el tablero es [h][v]
                 cout<<"\n\n\t";
                 // Ajuste de casilla inicial
                 if(h_ini<0 || h_ini>8 || v_ini<0 || v_ini>8)  
                 { h_ini=1;
                   v_ini=1;
                 }
                 break;
         
         case 2: inicio(h_ini,v_ini);
                 if(mover(2, h_ini, v_ini,0)==1)
                   { imprimir();
                     AMARILLO
                     cout<<"\n\n\tEste es el primer tour encontrado";
                   }
                 else
                   { AMARILLO
                     cout<<"No hay solucion comenzando en "
                         <<(char)('A'+h_ini-1)<<v_ini;
                   }
                 PAUSA  
                 break;
         
         case 3: inicio(h_ini,v_ini);
                 if(mover(2, h_ini, v_ini,1)==1)
                   { imprimir();
                     AMARILLO
                     cout<<"\n\n\t*** Este es el primer tour encontrado ***";
                   }
                 else
                   { AMARILLO
                     cout<<"No hay solucion comenzando en "
                         <<(char)('A'+h_ini-1)<<v_ini;
                   }
                 PAUSA  
                 break;
                 
         case 4: imprimir_archivo();
                 cout<<"\n\n\tYa esta el resultado en el archivo";
                 PAUSA
                 break;
                 
      }
    }
    FINAL
    return EXIT_SUCCESS;
}


        /* =========================================================
           =                                                       =
           =                      INICIALIZACIÓN                   =
           =                                                       =
           =========================================================*/

void inicio(int h, int v)
{ 
    // Inicializacion del Tablero
    int i,j;
    for(i=0;i<=8;i++)
       for(j=0;j<=8;j++)
           Tablero[i][j]=0;
         
    // Tablero[h][v] indica la posición en el tour de la casilla (horiz,vert)
    Tablero[h][v]=1;
    
    tour.limpiar();
    tour.push(v+(h-1)*8);
       
    return;
}


        /* =========================================================
           =                                                       =
           =           BÚSQUEDA RECURSIVA CON BACKTRACKING         =
           =                                                       =
           =========================================================*/

int mover(int posic_tour, int hh, int vv, int impresion)
{
  int h, v;           // Coordenadas horizontal y vertical
  int encontrado=0;

  for(int j=1; j<=8 && encontrado==0; j++)
     {
       // Asigna la siguiente casilla de caballo
       h=hh+Movimientos[j][0];
       v=vv+Movimientos[j][1];
       
       // Revisa si la casilla existe y si no es parte del tour
       if(h>0 && h<=8 && v>0 && v<=8 && Tablero[h][v]==0)
         {  
            // Agrega la casilla al tour
            Tablero[h][v]=posic_tour;
            tour.push(v+(h-1)*8);

            if(impresion==1) // Impresion del tour en revisión
               imprimir();
            
            if(posic_tour==64)
                return 1;    // Tour hallado
                
            // Recursión hasta encontrar tour o agotar posibilidades
            else if((encontrado=mover(posic_tour+1,h,v,impresion))==0)
                   { Tablero[h][v]=0;     // Backtracking (ver abajo)
                     tour.pop();
                   }
         }

     }

  /* BACKTRACKING: Si una posibilidad detiene el ingreso de otras y no es la
     la última, entonces se deshecha y se marca como no visitada para que
     las posibilidades anteriores a ella la puedan incluir.
     En este caso la anulación se hace en la llamada recursiva anterior al
     recibir el 0 retornado por la función mover. */

   if(encontrado==1) // Se sale de todos los for recursivos hasta el inicio
      return 1;
      
   return 0;
}



        /* =========================================================
           =                                                       =
           =                       IMPRESIÓN                       =
           =                                                       =
           =========================================================*/


void imprimir()
{ int i,j,k;

  LIMPIAR
  CIELO
    
  cout<<"\n\n\n\t\t\tTOUR DEL CABALLERO:\n\n   ";
  
  for(i=0;i<8;i++)
     cout<<"\t"<<(char)('A'+i);

  cout<<"\n     ----------------------------------------------------------------";
  cout<<"\n    |\n  ";
  
  for(i=1;i<=8;i++)
  { cout<<i<<" |";
    for(j=1;j<=8;j++)
        { if(Tablero[i][j]!=0)
            cout<<"\t"<<Tablero[i][j];
          else
            cout<<"\t";
        }
    cout<<"\n    |\n  ";
  }
  
  cout<<"\n\tTOUR:\n\n\t";
  for(i=1;i<=tour.longitud();i++)
      { k=tour.get(i)-1;
        j=k%8;
        k/=8;
        cout<<" "<<(char)('A'+j)<<k+1;
        if(i%16==0)
           cout<<"\n\t";

      } 
  
  return;
}


void imprimir_casillas()
{ int i,j;

  cout<<"\n\n\t\t\tLAS CASILLAS SON:\n\n   ";
  
  for(i=1;i<=8;i++)
     cout<<"\t"<<i;

  cout<<"\n     ----------------------------------------------------------------";
  cout<<"\n    |\n  ";
  
  for(i=1;i<=8;i++)
  { cout<<i<<" |";
    for(j=1;j<=8;j++)
        cout<<"\t"<<(char)('A'+j-1)<<i;
    cout<<"\n    |\n  ";
  }
  
  cout<<"\n\tCASILLA INICIAL: "<<(char)('A'+v_ini-1)<<h_ini<<endl;
  
  return;
}



void imprimir_archivo()
{ int i,j,k;

  inicio(h_ini,v_ini);
  fstream out("_Salida.txt");
  
  out<<"\n\n\n\tGuillermo Arriaga Garcia   "
       "Proyecto 3: Tour del caballero\n\n\t";
  
  
  if(mover(2, h_ini, v_ini,0)==1)
    { 
      out<<"\n\n\t   *** Este es el primer tour encontrado ***";
    }
  else
    { 
      out<<"No hay solucion comenzando en "
         <<(char)('A'+h_ini-1)<<v_ini;
    }
  
    
  out<<"\n\n\n\t\t\tTOUR DEL CABALLERO:\n\n   ";
  
  for(i=0;i<8;i++)
     out<<"\t"<<(char)('A'+i);

  out<<"\n     ----------------------------------------------------------------";
  out<<"\n    |\n  ";
  
  for(i=1;i<=8;i++)
  { out<<i<<" |";
    for(j=1;j<=8;j++)
        { if(Tablero[i][j]!=0)
            out<<"\t"<<Tablero[i][j];
          else
            out<<"\t";
        }
    out<<"\n    |\n  ";
  }
  
  out<<"\n\tTOUR:\n\n\t";
  for(i=1;i<=tour.longitud();i++)
      { k=tour.get(i)-1;
        j=k%8;
        k/=8;
        out<<" "<<(char)('A'+j)<<k+1;
        if(i%16==0)
           out<<"\n\t";

      } 
  out.close(); 
  AMARILLO
  return;
}
