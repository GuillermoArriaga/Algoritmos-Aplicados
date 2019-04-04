/*  =========================================================================
    ==                                                                     == 
    ==        GUILLERMO ARRIAGA GARCÍA          21/05/11                   == 
    ==                                                                     == 
    ==        PROYECTO 1              POLINOMIOS                           == 
    ==                                                                     == 
    ========================================================================= */

         /* =========================================================
            =                                                       =
            =        REALIZA OPERCACIONES +,-,* CON POLINOMIOS      =
            =                  DE EXPONENTES ENTEROS                =
            =                                                       =
            =========================================================*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Polinomio.h"

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


/*  =========================================================================
    ==                                                                     == 
    ==                               MAIN                                  == 
    ==                                                                     == 
    ========================================================================= */


int main()
{
   int seleccion=1,i=1,j,k,l;
   double m;
   
   FILE *in;
   ofstream out; //("_Salida.txt");
//   out.close();
   
   POLINOMIO *polinomios,*pol2;
   polinomios=new POLINOMIO[i];
   
   POLINOMIO pdemo;
   
   string str;
   char str2[100];
   double eval=2.5;
      
   
   VERDE

    while(seleccion!=0)
    { LIMPIAR
      cout<<"\n\n\n\t\tGuillermo Arriaga Garcia"
            "\n\n\t\tPROYECTO 1: POLINOMIOS CON EXPONENTES ENTEROS"
            "\n\n\n\t0.- Salir del programa."
            "\n\t1.- Capturar polinomios desde 'Entrada.txt'"
            "\n\t2.- Capturar polinomios desde interfaz"
            "\n\t3.- Evaluar polinomios en algun punto"
            "\n\t4.- Operaciones entre polinomios"
            "\n\t5.- Imprimir a 'Salida.txt' las operaciones."
            "\n\t6.- Enviar demostracion completa a 'Demostracion.txt'."
            "\n\n\tSELECCION: ";
      fflush(stdin);
      cin>>seleccion;
      
      switch(seleccion)
      { default: break;
         case 0: delete [] polinomios;
                 break;
         
         case 1: in=fopen("_Entrada.txt","r");
                 fscanf(in,"%d\n",&i);
                 if(i<1)
                   { fclose(in);
                     break;
                   }     
                 delete [] polinomios;
                 polinomios=new POLINOMIO[i+1];
                 for(j=1;j<=i;j++)
                    { fscanf(in,"%s",str2);
                      str=(string)str2;
                      polinomios[j].capturar(str);
                      cout<<"\n\t"<<j<<".- "<<
                      polinomios[j];//.imprimir();
                    }
                 fclose(in);   
                 PAUSA   
                 break;


         case 2: cout<<"\n\n\tIngresa la cantidad de polinomios: ";
                 cin>>i;
                 if(i<1)
                   break;
                 delete [] polinomios;
                 polinomios=new POLINOMIO[i+1];
                 cout<<"\n\tIngresa los polinomios, ej: 3x^4+5-x+x-x^-6";
                 for(j=1;j<=i;j++)
                    { cout<<"\n\tp"<<j<<"(x) = ";
                      cin>>str;
                      polinomios[j].capturar(str);
                      cout<<"\n\t"<<j<<".- ";
                      polinomios[j].imprimir();
                    }
                 PAUSA   
                 break;
         
         case 3: cout<<"\n\n\tEl valor para evaluacion: ";
                 cin>>eval;
                 if(i<1)
                    break;
                 for(j=1;j<=i;j++)
                   { cout<<"\n\t"<<j<<".- ";
                     polinomios[j].evaluar(eval);
                     cout<<"\tsiendo ";
                     polinomios[j].imprimir();
                   }  
                 PAUSA                 
                 break;
         
         case 4: if(i<2)
                    break;
                 cout<<"\n\tPOLINOMIOS A OPERAR:\n";   
                 for(j=1;j<=i;j++)
                   { cout<<"\n\t p"<<j<<" -> ";
                     polinomios[j].imprimir();
                   }
                 l=9*(i*(i-1))/2;  // 9 veces i Comb 2
                 pol2=new POLINOMIO[l];
                 l=0;
                 for(int k=1;k<=i;k++)
                    for(j=k;j<=i;j++)
                       { 
                           cout<<"\n\n\n\tSUMA: p"<<k<<" + p"<<j<<"\n\n\t";
                           pol2[l]=(polinomios[k]+polinomios[j]);
                           cout<<pol2[l]<<"\n\t"; 
                           pol2[l].evaluar(eval*(rand()%10));
                           l++;

                           cout<<"\n\n\n\tRESTA: p"<<k<<" - p"<<j<<"\n\n\t";
                           pol2[l]=(polinomios[k]-polinomios[j]);
                           cout<<pol2[l]<<"\n\t"; 
                           pol2[l].evaluar(eval*(rand()%10));
                           l++;

                           cout<<"\n\n\n\tMULTIPLICACION: p"<<k<<" * p"<<j<<"\n\n\t";
                           pol2[l]=(polinomios[k]*polinomios[j]);
                           cout<<pol2[l]<<"\n\t"; 
                           pol2[l].evaluar(eval*(rand()%10));
                           l++;

                           cout<<"\n\n\n\n\t\t\t* * *  *  * * *\n\n";
                       }
                 PAUSA                 
                 delete [] pol2;
                 break;


         case 5: if(i<2)
                    break;
                 LIMPIAR
                 out.open("_Salida.txt");
                 out<<"\n\n\tGuillermo Arriaga Garcia\tPROYECTO 1: Polinomios\n\n\n";   
                 out<<"\n\tPOLINOMIOS A OPERAR:\n\t********************\n\t";   
                 for(j=1;j<=i;j++)
                    { out<<"\n\t p"<<j<<" -> "; 
                      out<<polinomios[j]; 
                    }
                   
                 out<<"\n\n\t********************\n\n\n\t";
                 l=9*(i*(i-1))/2;  // 9 veces i Comb 2
                 pol2=new POLINOMIO[l];
                 l=0;
                 for(int k=1;k<=i;k++)
                    for(j=k;j<=i;j++)
                       { 
                           out<<"\n\n\n\tSUMA: p"<<k<<" + p"<<j<<"\n\n\t";
                           pol2[l]=(polinomios[k]+polinomios[j]);
                           out<<pol2[l]<<"\n\t"<<" p("<<(m=eval*(rand()%10))<<") = "
                              <<pol2[l].evaluar(m);
                           l++;

                           out<<"\n\n\n\tRESTA: p"<<k<<" - p"<<j<<"\n\n\t";
                           pol2[l]=(polinomios[k]-polinomios[j]);
                           out<<pol2[l]<<"\n\t"<<" p("<<(m=eval*(rand()%10))<<") = "
                              <<pol2[l].evaluar(m);
                           l++;

                           out<<"\n\n\n\tMULTIPLICACION: p"<<k<<" * p"<<j<<"\n\n\t";
                           pol2[l]=(polinomios[k]*polinomios[j]);
                           out<<pol2[l]<<"\n\t"<<" p("<<(m=eval*(rand()%10))<<") = "
                              <<pol2[l].evaluar(m);
                           l++;

                           out<<"\n\n\n\n\t\t\t* * *  *  * * *\n\n";
                       }
                 
                  delete [] pol2;
                  out.close(); 
                  break;

         case 6:  pdemo.demostracion_archivo();
                  break;

                 
      }
    }
    
    FINAL
    return EXIT_SUCCESS;
}
