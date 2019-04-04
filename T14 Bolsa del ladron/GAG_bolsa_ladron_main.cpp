#include <cstdlib>
#include <iostream>

using namespace std;

void imprimir_bolsa(int **obj,int cant, int capac);
void max_monto(int **obj,int cant, int capac, int seleccion);

int main()
{
    int** objeto;
    int capacidad,cantidad,seleccion=1,i;
    
    // Inicializacion
    capacidad=17;
    cantidad=5;
    objeto=new int*[cantidad];
    for(i=0;i<cantidad;i++) objeto[i]=new int[2];
    objeto[0][0]=3; // tamaño
    objeto[0][1]=4; // valor
    objeto[1][0]=4; objeto[1][1]=5;
    objeto[2][0]=7; objeto[2][1]=10;
    objeto[3][0]=8; objeto[3][1]=11;
    objeto[4][0]=9; objeto[4][1]=13;
    
    
    while(seleccion!=0)
    {  system("cls");
       cout<<"\n\n\tGuillermo Arriaga Garcia\tBOLSA DEL LADRON\n\n\n"
             "\n\t1.- Cambiar datos de los objetos."
             "\n\t2.- Cambiar la capacidad de la bolsa."
             "\n\t3.- Calcular el maximo monto a robar."
             "\n\t4.- Visualizar las posibles combinaciones."
             "\n\n\t0.- Salir del programa.\n\n";
       imprimir_bolsa(objeto,cantidad,capacidad);
       cout<<"\n\n\tSELECCION: ";   cin>>seleccion;
       
       switch(seleccion)
       { case 0: for(i=0;i<cantidad;i++) delete [] objeto[i];
                 delete [] objeto;
                 break;
               
         case 1: for(i=0;i<cantidad;i++) delete [] objeto[i]; delete [] objeto;
                 cout<<"\n\nLa cantidad de objetos es 5: "; cantidad=5;
                 objeto=new int*[cantidad];   // pedir memoria
                 for(i=0;i<cantidad;i++) objeto[i]=new int[2];
                 // Captura de nuevos datos
                 for(i=0;i<cantidad;i++)
                    { cout<<"\nObjeto["<<i+1<<"]\tTamano: "; cin>>objeto[i][0];
                      cout<<"\t\tValor: "; cin>>objeto[i][1];
                    }  
                 break;
              
         case 2: cout<<"\n\n\tNueva capacidad de la bolsa: "; cin>>capacidad;
                 break;
                 
         case 3: max_monto(objeto,cantidad,capacidad,seleccion);
                 break;

         case 4: max_monto(objeto,cantidad,capacidad,seleccion);
                 break;

                 
         default: break;
       }// cierre del switch
             
    } // cierre del while

    return EXIT_SUCCESS;
} // cierre del main


void imprimir_bolsa(int **obj,int cant, int capac)
{ int i,j;
  cout<<"\n\n\t\tCAPACIDAD DE LA BOLSA: "<<capac<<"\n";
  cout<<"\n\t\tOBJETO:"; for(i=0;i<cant;i++) cout<<"\t[ "<<i+1<<" ]";
  cout<<"\n\t\tTAMANO:"; for(i=0;i<cant;i++) cout<<"\t  "<<obj[i][0];
  cout<<"\n\t\tVALOR:";  for(i=0;i<cant;i++) cout<<"\t  "<<obj[i][1];
  cout<<"\n";
}


void max_monto(int **obj,int cant, int capac, int seleccion)
{ int i,j,k,l,m,n;
  int capac_relativa;
  int valor_relativo=0;
  int ubic[4][6],comp[6],a,b,c,d,e,mejor,comparador;
  int ob_peque,contador;
  
  // Cuantas veces cabe el mas pequeño en la bolsa
  ob_peque=obj[0][0]; // detecta al pequeño
  for(i=1;i<cant;i++) if(ob_peque>obj[i][0]) ob_peque=obj[i][0];
  contador=1;
  while((capac-(ob_peque*contador))>=0) // Ve cuantas veces cabe
  { contador++;} contador--; // Ajuste
    
  mejor=comparador=0;
  for(i=0;i<4;i++) for(j=0;j<6;j++) ubic[i][j]=0;  // ubic[lugar][0=valor,1-5 cantidad de objetos[j]
  // Calculo de las combinaciones (sin repeticiones)
  if(seleccion==4) cout<<"\n\n\t[1][2][3][4][5]     VALOR\tESPACIO\n";
  
  for(i=0;i<=contador;i++)
   for(j=0;j<=contador;j++)
    for(k=0;k<=contador;k++)
     for(l=0;l<=contador;l++)
      for(m=0;m<=contador;m++)
      { if((m*obj[0][0]+l*obj[1][0]+k*obj[2][0]+j*obj[3][0]+i*obj[4][0])<=capac)
        { if(seleccion==4) 
             cout<<"\n\t "<<m<<"  "<<l<<"  "<<k<<"  "<<j<<"  "<<i<<"  =  "
                   " $ "<<((m*obj[0][1]+l*obj[1][1]+k*obj[2][1]+j*obj[3][1]+i*obj[4][1]))<<
                   " \t   "<<(m*obj[0][0]+l*obj[1][0]+k*obj[2][0]+j*obj[3][0]+i*obj[4][0]);
          comparador=(m*obj[0][1]+l*obj[1][1]+k*obj[2][1]+j*obj[3][1]+i*obj[4][1]);
          // Asignacion de los tres primeros lugares
          if(ubic[3][0]<=comparador)
            { ubic[3][0]=comparador;
              ubic[3][1]=m; ubic[3][2]=l; ubic[3][3]=k; ubic[3][4]=j; ubic[3][5]=i;
            }
          if(ubic[2][0]<=ubic[3][0])
            { comparador=ubic[2][0];
              ubic[2][0]=ubic[3][0];
              ubic[3][0]=comparador;
              for(n=1;n<6;n++) 
               { comp[n]=ubic[2][n];
                 ubic[2][n]=ubic[3][n];
                 ubic[3][n]=comp[n];
               }  
            }
          if(ubic[1][0]<=ubic[2][0])
            { comparador=ubic[1][0];
              ubic[1][0]=ubic[2][0];
              ubic[2][0]=comparador;
              for(n=1;n<6;n++) 
               { comp[n]=ubic[1][n];
                 ubic[1][n]=ubic[2][n];
                 ubic[2][n]=comp[n];
               }  
            }
        }
      }
      
  if(seleccion==4) { cout<<"\n\n\t"; system("pause"); }

  cout<<"\n\n\tMejores tres combinaciones ([objeto] z veces) para una bolsa de "<<capac;
  cout<<"\n\n\t   [1][2][3][4][5]     VALOR\tESPACIO\n";
  for(n=1;n<4;n++)
  {  cout<<"\n\t"<<n<<".- "<<ubic[n][1]<<"  "<<ubic[n][2]<<"  "<<ubic[n][3]<<"  "
         <<ubic[n][4]<<"  "<<ubic[n][5]<<"  =   $ "<<ubic[n][0]<<" \t   "<<
         (ubic[n][1]*obj[0][0]+ubic[n][2]*obj[1][0]+ubic[n][3]*obj[2][0]
          +ubic[n][4]*obj[3][0]+ubic[n][5]*obj[4][0]);
  }
  cout<<"\n\n\t"; system("pause");  
  
} // cierre de monto max
