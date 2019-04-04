// Tarea 9: Listas que se unen 
// Guillermo Arriaga Garcia 10 de marzo de 2011


#include <cstdlib>
#include <iostream>
#include "Lista.h"
#include "NODO_H.h"

using namespace std;

void imprimir_lista(LISTA &lis);
void crear_lista(LISTA &lis, int num, int cantidad);
void detectar_union(LISTA &lis1,int num1,LISTA &lis2, int num2);
void imprimir_union(LISTA &lis1, NODO* ubic1, int num1, LISTA &lis2, NODO* ubic2, int num2);

int main()
{
    int i, valor, cantidad, seleccion=1,n,a,b,c;
    int posicion_1=0, posicion_2=0, posicion_3=0, posicion_4=0;
    LISTA lista_1(1), lista_2(1), lista_3(10);
    NODO* comienzo;

    while(seleccion!=0)
    {                                                          // Menú principal
      system("cls");
      cout<<"\n\tGuillermo Arriaga Garcia\n\tListas que se unen\n\n\n"
          "\t1.- Crear listas con de n elementos aleatorios entre el 0-9.\n"
          "\t2.- Unir listas.\n"
          "\t3.- Detectar las uniones.\n"
          "\t4.- Imprimir alguna lista.\n"
          "\t5.- Obtener la longitud de las listas.\n"
          "\t6.- Obtener el apuntador a algun elemento de una lista.\n"
          "\t7.- Limpiar alguna lista.\n"
          "\n\n0.- Salir del programa.\n\nSELECCION: ";
      fflush(stdin);  // Limpieza de buffer de entrada
      cin>>seleccion;
      
      switch(seleccion)
        { case 0: break;
                       
          case 1: cout<<"\n\nLista a crear (1,2,3): ";       cin>>a;
                  cout<<"\n\nCantidad de elementos (n): ";  cin >> n;
                  switch(a)
                   { default: break;
                     case 1: crear_lista(lista_1, a, n); break;
                     case 2: crear_lista(lista_2, a, n); break;
                     case 3: crear_lista(lista_3, a, n); break;
                   } 
                  break;
                  
          case 2: cout<<"\n\nPara el buen desempeño, solo une dos listas.";
                  cout<<"\n\nLista a unir (1,2,3): ";  cin>>a;
                  cout<<"\n\nA que lista? (1,2,3): ";             cin>>b;
                  switch(a)
                   { default: break;
                     case 1: if(b==2) 
                              {cout<<"\n\nA que posicion? [1,"<<
                                     lista_2.longitud()<<"]: ";       cin>>c; 
                               if(c>lista_2.longitud()) c=lista_2.longitud(); // Ajuste
                               lista_1.unir(lista_2,c);
                               imprimir_lista(lista_1);
                              }
                             
                              if(b==3) 
                              {cout<<"\n\nA que posicion? [1,"<<
                                     lista_3.longitud()<<"]: ";       cin>>c; 
                               if(c>lista_3.longitud()) c=lista_3.longitud(); // Ajuste
                               lista_1.unir(lista_3,c);
                               imprimir_lista(lista_1);
                              }
                             break;
                             
                     case 2: if(b==1) 
                              {cout<<"\n\nA que posicion? [1,"<<
                                     lista_1.longitud()<<"]: ";       cin>>c; 
                               if(c>lista_1.longitud()) c=lista_1.longitud(); // Ajuste
                               lista_2.unir(lista_1,c);
                               imprimir_lista(lista_2);
                              }
                             
                              if(b==3) 
                              {cout<<"\n\nA que posicion? [1,"<<
                                     lista_3.longitud()<<"]: ";       cin>>c; 
                               if(c>lista_3.longitud()) c=lista_3.longitud(); // Ajuste
                               lista_2.unir(lista_3,c);
                               imprimir_lista(lista_2);
                              }
                             break;

                     case 3: if(b==1) 
                              {cout<<"\n\nA que posicion? [1,"<<
                                     lista_1.longitud()<<"]: ";       cin>>c; 
                               if(c>lista_1.longitud()) c=lista_1.longitud(); // Ajuste
                               lista_3.unir(lista_1,c);
                               imprimir_lista(lista_3);
                              }
                             
                              if(b==2) 
                              {cout<<"\n\nA que posicion? [1,"<<
                                     lista_2.longitud()<<"]: ";       cin>>c; 
                               if(c>lista_2.longitud()) c=lista_2.longitud(); // Ajuste
                               lista_3.unir(lista_2,c);
                               imprimir_lista(lista_3);
                              }
                             break;
                   } 
                  break;


          case 3: cout<<"\n\nSe encontrara la union si es unica, \n\t"
                        "si uniste mas veces puedes limpiar la lista,"
                        " crear y unir de nuevo.";
                  cout<<"\n\nListas a buscar union (1,2,3): "; cin>>a>>b;

                  switch(a)
                   { default: break;
                     case 1: switch(b)
                              { default: break;
                                case 2: detectar_union(lista_1,1,lista_2,2); break;
                                case 3: detectar_union(lista_1,1,lista_3,3); break;
                              }
                             break;
                     case 2: switch(b)
                              { default: break;
                                case 1: detectar_union(lista_2,2,lista_1,1); break;
                                case 3: detectar_union(lista_2,2,lista_3,3); break;
                              }
                             break;
                     case 3: switch(b)
                              { default: break;
                                case 1: detectar_union(lista_3,3,lista_1,1); break;
                                case 2: detectar_union(lista_3,3,lista_2,2); break;
                              }
                             break;
                   } 
                  break;
                  
                  
                  
          case 4: cout<<"\n\nIngresa el numero de la lista: ";       cin >> n;
                  switch(n)
                    { case 1: cout<<"\nLista 1:\n"; imprimir_lista(lista_1); break;
                      case 2: cout<<"\nLista 2:\n"; imprimir_lista(lista_2); break;
                      case 3: cout<<"\nLista 3:\n"; imprimir_lista(lista_3); break;
                      default: break;
                    }
                  break;
                                    
                  
          case 5: cout<<"\n\nLa longitud de la lista 1 es "<<lista_1.longitud();
                  cout<<"\nLa longitud de la lista 2 es "<<lista_2.longitud();
                  cout<<"\nLa longitud de la lista 3 es "<<lista_3.longitud();
                  cout<<endl;    system("pause"); 
                  break;
                  
                  
          case 6: cout<<"\n\nIngresa el numero de la lista: ";         cin >> n;
                  cout<<"\nIngresa la posicion del elemento: ";    cin >> valor;
                  cout<<"\nLa direccion en memoria es: ";
                  switch(n)
                    { case 1: cout<<lista_1.regresaNth(valor);  break;
                      case 2: cout<<lista_2.regresaNth(valor);  break;
                      case 3: cout<<lista_3.regresaNth(valor);  break;
                      default: break;
                    }
                  cout<<endl;
                  system("pause");  
                  break;
                  
                  
          case 7: cout<<"\n\nIngresa el numero de la lista: ";        cin >> n;
                   switch(n)
                    { case 1: lista_1.limpiar(); cout<<"\nLista 1:\n"; 
                              imprimir_lista(lista_1); break;
                      case 2: lista_2.limpiar(); cout<<"\nLista 2:\n"; 
                              imprimir_lista(lista_2); break;
                      case 3: lista_3.limpiar(); cout<<"\nLista 3:\n"; 
                              imprimir_lista(lista_3); break;
                      default: break;
                    }
                   break;
                  
                  
          default: break;
        }  // Cierre del switch
   } // Cierre del while  
return 0;
} // Cierre del main




// Funcion para imprimir listas

void imprimir_lista(LISTA &lis)
{     NODO* ubicador;
      int cantidad,i;

      lis.renumerar();  // Renumeracion relativa a esta lista.
      
      ubicador=lis.final();
      cantidad=ubicador->posicion;
      ubicador=lis.inicio();

      cout<<endl;
      
      for(i=0;i<cantidad;i++)
        { cout<<"\tElemento["<<ubicador->posicion<<"]: "<<(ubicador->contenido)
              <<" que apunta a "<<(ubicador->siguiente)<<".\n";
          ubicador=ubicador->siguiente;
        }  
      cout<<endl;
      system("pause");
}



// Creador de listas con elem aleatorios entre 0-9
void crear_lista(LISTA &lis, int num, int cantidad)
{  NODO* comienzo;
   int i;

   lis.limpiar();
   comienzo=lis.inicio();
   (comienzo->contenido)=rand()%10;
   for(i=1;i<cantidad;i++) lis.insertaFinal(rand()%10);
   cout<<"\nLista "<<num<<":\n";
   imprimir_lista(lis);
}


// Detector de union
void detectar_union(LISTA &lis1,int num1,LISTA &lis2, int num2)
{  NODO* ubicador1;
   NODO* ubicador2;
   int diferencia;
   
   if(lis1.final()!=lis2.final()) 
     { cout<<"\n\nNo terminan en el mismo elemento.\n\n\n";
       system("pause");
     }
   else
   { diferencia=lis1.longitud()-lis2.longitud();

     if(diferencia>0)
        { ubicador1=lis1.regresaNth(diferencia+1);  // Posiciones equivalentes
          ubicador2=lis2.inicio();
          while(ubicador1!=ubicador2)
             { ubicador1=ubicador1->siguiente;
               ubicador2=ubicador2->siguiente;
             } // Termina el while con los ubicadores iguales
        }

     if(diferencia<0)
        { ubicador2=lis2.regresaNth(diferencia*(-1)+1);  // Posiciones equivalentes
          ubicador1=lis1.inicio();
          while(ubicador1!=ubicador2)
             { ubicador1=ubicador1->siguiente;
               ubicador2=ubicador2->siguiente;
             } // Termina el while con los ubicadores iguales
        }

     if(diferencia==0)
        { ubicador1=lis1.inicio(); 
          ubicador2=lis2.inicio();
          while(ubicador1!=ubicador2)
             { ubicador1=ubicador1->siguiente;
               ubicador2=ubicador2->siguiente;
             } // Termina el while con los ubicadores iguales
        }
 
    imprimir_union(lis1,ubicador1,num1,lis2,ubicador2,num2);
        
   } // cierre del else
}


void imprimir_union(LISTA &lis1, NODO* ubic1, int num1, LISTA &lis2, NODO* ubic2, int num2)
{         cout<<"\n\n\tSe unen en "<<ubic1<<" que es la posicion ";
          lis1.renumerar(); 
          cout<<ubic1->posicion<<" de la Lista "<<num1<<"\n\t y la posicion ";
          lis2.renumerar(); 
          cout<<ubic2->posicion<<" de la Lista "<<num2<<".\n\n"; 
          system("pause");
          cout<<"\nLa lista "<<num1<<" es:\n\n";
          imprimir_lista(lis1);
          cout<<"\nLa lista "<<num2<<" es:\n\n";
          imprimir_lista(lis2);
}
