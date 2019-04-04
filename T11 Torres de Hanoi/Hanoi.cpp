// GAG PROGRAMS: Torres de Hanoi
// Guillermo Arriaga Garcia  Tarea 11   16 de marzo de 2011

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>                               // Para la ubicacion GotoXY
#include "Pila.h"

using namespace std;


void GotoXY(int x, int y)              // Funcion de ubicacion por coordenadas
{  COORD coord;
   coord.X = x;
   coord.Y = y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void hanoi(int &d_T1,int &d_T2,int &d_T3,int*t1,int*t2,int*t3,int num_disc,char** disco);
void hanoi(int num_discos, int ini, int dest, int aux,int &d_T1,int &d_T2,int &d_T3,int*t1,int*t2,int*t3,char** disco);

// FUNCIONES
void creacion();
void presentacion();
void presentacion2();
void impresion_discos();
void contador_discos();
void mover(int ini, int dest);
void hanoi();
void hanoi(int num_disc, int ini, int dest, int aux);


// VARIABLES GLOBALES ... para no enviar muchos parametros a las funciones
  char** disco;
  char figura_disco='E';
  int i,j, num_discos=11,seleccion=1, contador=0;
  int *torre1, *torre2, *torre3;     // Dimensiones de los discos de cada torre
  int discos_T1,discos_T2,discos_T3; // Cantidad de discos en cada torre
  PILA Torre_1, Torre_2, Torre_3;



// +++++++++++++++++++++++++++++++  MAIN  +++++++++++++++++++++++++++++++++++++
int main()
{ int aa,bb;

  creacion();
  while(seleccion!=0)
  {  presentacion();
     switch(seleccion)
     { default: break;
       case 0: break;
       case 1: hanoi(); contador--; break; 
       case 2: GotoXY(5,18+num_discos);cout<<"Mover de a -> b; Ingresa a b: ";
               cin>>aa>>bb; mover(aa,bb); 
               break;
     }// cierre del switch
  }// cierre del while



  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++  Fin del programa
  GotoXY(5,16+num_discos);cout<<"Fin del programa.\t\t";
  system("pause");

  for(i=0;i<num_discos;i++) delete [] disco[i];      // Liberacion de memoria
  delete [] disco;
  delete [] torre1; delete [] torre2; delete [] torre3;

  return 0;
}





// +++++++++++++++++++++++++++++++++++++++++++++  Funciones de Hanoi recursivas

void hanoi()
{ hanoi(num_discos,1,2,3); }  // con 1 3 2 primero pasa todo al auxiliar y luego al destino


void hanoi(int num_disc, int ini, int dest, int aux)
{ if (discos_T3!=num_discos-1)   // Si todavia no se logra el objetivo
  { if(num_disc==1)  {mover(ini,dest); } 
    else
      { hanoi(num_disc-1,ini,aux,dest);
        mover(ini,dest);
        hanoi(num_disc-1,aux,dest,ini);
      }
  }    
}




// ++++++++++++++++++++++++++++   CREACION DE DISCOS   +++++++++++++++++++++++
void creacion()
{
  // +++++++++++++++++++++++++++++++++++++++++++++++++++ Configuracion inicial
  system("cls");
  cout<<"\n\n\n\n\tGuillermo Arriaga Garcia: TORRES DE HANOI\n\n\n\n"
        "Ingresa la cantidad de discos <20 : "; cin>>num_discos; num_discos++;
        if(num_discos>21) num_discos=21;   // Ajuste de datos
  cout<<"\n\nIngresa la figura de los discos (1 char): "; cin>>figura_disco;
  cout<<"\n\nLos discos son:\n";
  
  // +++++++++++++++++++++++++++++++++++++++++++++++++++  Creacion de discos
  disco=new char*[num_discos];                       // Disco[i] con i elem.
  for(i=0;i<num_discos;i++) disco[i]=new char[i+1];
  for(i=0;i<num_discos;i++) 
     { for(j=0;j<i;j++) disco[i][j]=figura_disco;
       disco[i][i]='\0';
       if(i!=0) cout<<"\nDisco["<<i<<"]   =\t"<<disco[i];
     }
  cout<<"\n\n"; system("pause");

  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++  Creacion de torres
  torre1=new int[num_discos];  // Indica dimension de cada disco en cada altura
  torre2=new int[num_discos];
  torre3=new int[num_discos];
  torre1[0]=0;torre2[0]=0;torre3[0]=0;   // Torre1[1]=disco grande
  for(i=1;i<num_discos;i++){torre1[i]=num_discos-i;torre2[i]=torre3[i]=0;}//Inicializacion
  for(i=num_discos-1;i>0;i--) {Torre_1.push(i);}
}




// +++++++++++++++++++++++++++++   PRESENTACION   ++++++++++++++++++++++++++++
void presentacion()
{ 
     system("cls");
     GotoXY(23,2);cout<<"GAG programs:  TORRES DE HANOI";
     GotoXY(5,4);cout<<"0.- Salir del programa.";
     GotoXY(5,5);cout<<"1.- Resolver el problema.";
     GotoXY(5,6);cout<<"2.- Mover manualmente de (1,2,3) a (1,2,3).";
     impresion_discos();
     contador_discos();
     GotoXY(5,14+num_discos);cout<<"Discos: Torre 1 = "<<discos_T1<<"     Torre 2 = "
                                 <<discos_T2<<"\t       Torre 3 = "<<discos_T3;
     GotoXY(0,0); // Para tener la visualizacion favorable
     GotoXY(23,8);cout<<"Movimiento "<<contador<<"\tSeleccion: ";cin>>seleccion;
}



// +++++++++++++++++++++++++++++   PRESENTACION 2  ++++++++++++++++++++++++++++
void presentacion2()
{ 
     system("cls");
     GotoXY(23,2);cout<<"GAG programs:  TORRES DE HANOI";
     impresion_discos();
     contador_discos();
     GotoXY(5,14+num_discos);cout<<"Discos: Torre 1 = "<<discos_T1<<"     Torre 2 = "
                                 <<discos_T2<<"\t       Torre 3 = "<<discos_T3;
     GotoXY(0,0); // Para tener la visualizacion favorable
     GotoXY(23,8);cout<<"Movimiento "<<(contador-1);
     
     // Esperar un poco
     if(num_discos<10) for(i=0;i<10000;i++)for(j=0;j<10000;j++){}
     if(num_discos<15&&num_discos>9) for(i=0;i<3000;i++)for(j=0;j<3000;j++){}
     if(num_discos>14&&num_discos<22) for(i=0;i<100;i++)for(j=0;j<100;j++){}
}






// +++++++++++++++++++++++++++++ IMPRESION DE DISCOS +++++++++++++++++++++++++
void impresion_discos()
{ 
  int Base_y=10, T1_x=5,T2_x=30,T3_x=55,i;
  GotoXY(T1_x,Base_y+num_discos+2); cout<<"ORIGEN";
  GotoXY(T2_x,Base_y+num_discos+2); cout<<"AUXILIAR";
  GotoXY(T3_x,Base_y+num_discos+2); cout<<"DESTINO";
  
  // Torre 1
  for(i=1;i<num_discos;i++) {GotoXY(T1_x,Base_y+num_discos-i);cout<<disco[(torre1[i])];}
  // Torre 2
  for(i=1;i<num_discos;i++) {GotoXY(T2_x,Base_y+num_discos-i);cout<<disco[(torre2[i])];}
  // Torre 3
  for(i=1;i<num_discos;i++) {GotoXY(T3_x,Base_y+num_discos-i);cout<<disco[(torre3[i])];}
}




// ++++++++++++++++++++++++++++ CONTADOR DE DISCOS ++++++++++++++++++++++++++++
void contador_discos()
{ discos_T1=discos_T2=discos_T3=0;
  for(i=0;i<num_discos;i++)
     { if(torre1[i]!=0)discos_T1++;
       if(torre2[i]!=0)discos_T2++;
       if(torre3[i]!=0)discos_T3++;
     }
}


// ++++++++++++++++++++++++++++ HACER MOVIMIENTO +++++++++++++++++++++++++++++
void mover(int ini, int dest)
{ contador_discos();
  
  switch(ini)
  { default: break;
    case 1: switch(dest)
             { default: break;
               case 2:  torre2[discos_T2+1]=torre1[discos_T1]; 
                        torre1[discos_T1]=0;
//                        Torre_2.push(Torre_1.pop());  // Usando pilas
                        contador++;
                        break;
               case 3:  torre3[discos_T3+1]=torre1[discos_T1]; 
                        torre1[discos_T1]=0; 
                        contador++;
//                        Torre_3.push(Torre_1.pop());  // Usando pilas
                        break;
             }
            break;   
            
    case 2: switch(dest)
             { default: break;
               case 1:  torre1[discos_T1+1]=torre2[discos_T2]; 
                        torre2[discos_T2]=0; 
//                        Torre_1.push(Torre_2.pop());   // Usando pilas
                        contador++;                        
                        break;
               case 3:  torre3[discos_T3+1]=torre2[discos_T2]; 
                        torre2[discos_T2]=0; 
                        contador++;
//                        Torre_3.push(Torre_2.pop());  // Usando pilas
                        break;
             }
            break;
               
    case 3: switch(dest)
             { default: break;
               case 1:  torre1[discos_T1+1]=torre3[discos_T3]; 
                        torre3[discos_T3]=0; 
                        contador++;
//                        Torre_1.push(Torre_3.pop());  // Usando pilas
                        break;
               case 2:  torre2[discos_T2+1]=torre3[discos_T3]; 
                        torre3[discos_T3]=0; 
                        contador++;
//                        Torre_2.push(Torre_3.pop());
                        break;
             }
            break; 
  }
  contador_discos();
  presentacion2();
}
