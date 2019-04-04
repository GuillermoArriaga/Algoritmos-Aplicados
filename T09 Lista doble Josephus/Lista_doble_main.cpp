// Tarea 9: Listas Guillermo Arriaga Garcia 3 de marzo de 2011


#include <cstdlib>
#include <iostream>
#include "Lista.h"
#include "NODO_H.h"

using namespace std;

void imprimir_lista(LISTA &lis);
void imprimir_busqueda(int posic, int val, int numList);

int main()
{
    int i, valor, cantidad, seleccion=1,n;
    int posicion_1=0, posicion_2=0, posicion_3=0, posicion_4=0;
    LISTA lista_1(1), lista_2(10), lista_3(10,5), lista_4(1), lista_j(1);
    NODO* comienzo;

    while(seleccion!=0)
    {                                                          // Menú principal
      system("cls");
      cout<<"\n\tGuillermo Arriaga Garcia\n\tListas\n\n\n"
          "\t1.- Crear la lista 1 de n elementos aleatorios entre el 0-9.\n"
          "\t2.- Crear la lista 2 de 10 elementos con valor cero.\n"
          "\t3.- Crear la lista 3 de 10 elementos con un valor=5.\n"
          "\t4.- Crear la lista 4 de n elementos con entradas manuales.\n"
          "\t5.- Modificar algun elemento de alguna lista.\n"
          "\t6.- Imprimir alguna lista.\n"
          "\t7.- Buscar algun numero (contenido).\n"
          "\t8.- Obtener la longitud de las listas.\n"
          "\t9.- Obtener el apuntador a algun elemento de una lista.\n"
          "\t10.- Limpiar alguna lista.\n"
          "\t11.- Borrar el primer elemento de alguna lista.\n"
          "\t12.- Borrar el ultimo elemento de alguna lista.\n"
          "\t13.- Borrar algun elemento de alguna lista.\n"
          "\n\t14.- Problema de Josephus\n"
          "\n\n0.- Salir del programa.\n\nSELECCION: ";
      fflush(stdin);  // Limpieza de buffer de entrada
      cin>>seleccion;
      
      switch(seleccion)
        { case 0: break;
                       
          case 1: cout<<"\n\nIngresa la cantidad de elementos (n): ";  cin >> n;
                  lista_1.limpiar();
                  comienzo=lista_1.inicio();
                  (comienzo->contenido)=rand()%10;   // Uso de inserta al inicio
                  for(i=1;i<n;i++) lista_1.insertaFinal(rand()%10);
                  cout<<"\nLista 1:\n";
                  imprimir_lista(lista_1);
                  break;
                  
          case 2: if(lista_2.longitud()==1) // Por si fue limpiada
                     for(i=1;i<10;i++) lista_2.insertaFinal(0);
                  cout<<"\nLista 2:\n";
                  imprimir_lista(lista_2);
                  break;                  
                  
                  
          case 3: if(lista_3.longitud()==1) // Por si fue limpiada
                     { lista_3.inicio()->contenido=5;
                       for(i=1;i<10;i++) lista_3.insertaFinal(5);
                     }
                  cout<<"\nLista 3:\n";     
                  imprimir_lista(lista_3);
                  break;
                  
                  
          case 4: cout<<"\n\nIngresa la cantidad de elementos (n): ";  cin >> n;
                  cout<<"\nAhora ingresa los valores por orden de posicion:\n";
                  lista_4.limpiar();
                  for(i=1;i<=n;i++) 
                     { cout<<"["<<i<<"] = "; cin >> valor; cout<<endl;
                       if(i==1) { comienzo=lista_4.inicio();
                                  comienzo->posicion=1;
                                  comienzo->contenido=valor;
                                }                     // Uso de inserta al final
                       else lista_4.insertaFinal(valor);
                     }  
                  imprimir_lista(lista_4);
                  break;
                       

          case 5: cout<<"\n\nIngresa el numero de la lista: ";         cin >> i;
                  cout<<"\nIngresa la posicion del elemento: ";        cin >> n;
                  cout<<"\nIngresa el nuevo valor del elemento: "; cin >> valor;
                  
                  switch(i)
                    { case 1: lista_1.cambioValor(n,valor); 
                              cout<<"\nNueva lista 1:\n";
                              imprimir_lista(lista_1);     
                              break;
                      case 2: lista_2.cambioValor(n,valor); 
                              cout<<"\nNueva lista 2:\n";
                              imprimir_lista(lista_2);     
                              break;
                      case 3: lista_3.cambioValor(n,valor); 
                              cout<<"\nNueva lista 3:\n";
                              imprimir_lista(lista_3);     
                              break;
                      case 4: lista_4.cambioValor(n,valor); 
                              cout<<"\nNueva lista 4:\n";                      
                              imprimir_lista(lista_4);     
                              break;
                      default: break;
                    }
                  break;
                  
                  
          case 6: cout<<"\n\nIngresa el numero de la lista: ";         cin >> n;
                  switch(n)
                    { case 1: cout<<"\nLista 1:\n"; imprimir_lista(lista_1); break;
                      case 2: cout<<"\nLista 2:\n"; imprimir_lista(lista_2); break;
                      case 3: cout<<"\nLista 3:\n"; imprimir_lista(lista_3); break;
                      case 4: cout<<"\nLista 4:\n"; imprimir_lista(lista_4); break;
                      default: break;
                    }
                  break;
                  

          case 7: cout<<"\n\nIngresa el numero a buscar: ";        cin >> valor;
                  posicion_1=lista_1.encuentra(valor);
                  imprimir_busqueda(posicion_1,valor,1);
                  
                  posicion_2=lista_2.encuentra(valor);
                  imprimir_busqueda(posicion_2,valor,2);
                  
                  posicion_3=lista_3.encuentra(valor);
                  imprimir_busqueda(posicion_3,valor,3);
                  
                  posicion_4=lista_4.encuentra(valor);
                  imprimir_busqueda(posicion_4,valor,4);
                  
                  system("pause");
                  break;
                  
                  
          case 8: cout<<"\n\nLa longitud de la lista 1 es "<<lista_1.longitud();
                  cout<<"\nLa longitud de la lista 2 es "<<lista_2.longitud();
                  cout<<"\nLa longitud de la lista 3 es "<<lista_3.longitud();
                  cout<<"\nLa longitud de la lista 4 es "<<lista_4.longitud();
                  cout<<endl;
                  system("pause");
                  break;
                  
                  
          case 9: cout<<"\n\nIngresa el numero de la lista: ";         cin >> n;
                  cout<<"\nIngresa la posicion del elemento: ";    cin >> valor;
                  cout<<"\nLa direccion en memoria es: ";
                  switch(n)
                    { case 1: cout<<lista_1.regresaNth(valor);  break;
                      case 2: cout<<lista_2.regresaNth(valor);  break;
                      case 3: cout<<lista_3.regresaNth(valor);  break;
                      case 4: cout<<lista_4.regresaNth(valor);  break;
                      default: break;
                    }
                  cout<<endl;
                  system("pause");  
                  break;
                  
                  
          case 10: cout<<"\n\nIngresa el numero de la lista: ";        cin >> n;
                   switch(n)
                    { case 1: lista_1.limpiar(); cout<<"\nLista 1:\n"; 
                              imprimir_lista(lista_1); break;
                      case 2: lista_2.limpiar(); cout<<"\nLista 2:\n"; 
                              imprimir_lista(lista_2); break;
                      case 3: lista_3.limpiar(); cout<<"\nLista 3:\n"; 
                              imprimir_lista(lista_3); break;
                      case 4: lista_4.limpiar(); cout<<"\nLista 4:\n"; 
                              imprimir_lista(lista_4); break;
                      default: break;
                    }
                   break;
                  
                  
          case 11: cout<<"\n\nIngresa el numero de la lista: ";        cin >> n;
                   switch(n)
                    { case 1: lista_1.quitaPrimero(); cout<<"\nLista 1:\n"; 
                              imprimir_lista(lista_1); break;
                      case 2: lista_2.quitaPrimero(); cout<<"\nLista 2:\n"; 
                              imprimir_lista(lista_2); break;
                      case 3: lista_3.quitaPrimero(); cout<<"\nLista 3:\n"; 
                              imprimir_lista(lista_3); break;
                      case 4: lista_4.quitaPrimero(); cout<<"\nLista 4:\n"; 
                              imprimir_lista(lista_4); break;
                      default: break;
                    }
                   break;
                  
                  
          case 12: cout<<"\n\nIngresa el numero de la lista: ";        cin >> n;
                   switch(n)
                    { case 1: lista_1.quitaUltimo(); cout<<"\nLista 1:\n"; 
                              imprimir_lista(lista_1); break;
                      case 2: lista_2.quitaUltimo(); cout<<"\nLista 2:\n"; 
                              imprimir_lista(lista_2); break;
                      case 3: lista_3.quitaUltimo(); cout<<"\nLista 3:\n"; 
                              imprimir_lista(lista_3); break;
                      case 4: lista_4.quitaUltimo(); cout<<"\nLista 4:\n"; 
                              imprimir_lista(lista_4); break;
                      default: break;
                    }
                   break;
                  

          case 13: cout<<"\n\nIngresa el numero de la lista: ";        cin >> i;
                   cout<<"\nIngresa la posicion del elemento: ";       cin >> n;
                   switch(i)
                    { case 1: lista_1.eliminar(n); cout<<"\nLista 1:\n"; 
                              imprimir_lista(lista_1); break;
                      case 2: lista_2.eliminar(n); cout<<"\nLista 2:\n"; 
                              imprimir_lista(lista_2); break;
                      case 3: lista_3.eliminar(n); cout<<"\nLista 3:\n"; 
                              imprimir_lista(lista_3); break;
                      case 4: lista_4.eliminar(n); cout<<"\nLista 4:\n"; 
                              imprimir_lista(lista_4); break;
                      default: break;
                    }
                   break;

          case 14: cout<<"\n\nIngresa el numero de personas: ";        cin >> n;
                   cout<<"\nIngresa la razon de muertes: ";        cin >> valor;
                   // Creacion de la lista de n elementos
                   for(i=2;i<=n;i++) lista_j.insertaFinal(0);
                   
                   // Hacerla una lista circular
                   lista_j.regresaNth(n)->siguiente=lista_j.regresaNth(1);
                   lista_j.regresaNth(1)->anterior=lista_j.regresaNth(n);
                   
                   // Eliminaciones
                   cout<<"\n\tMueren: ";
                   comienzo=lista_j.inicio();
                   while(comienzo->posicion!=comienzo->siguiente->posicion)
                      {  for(i=1;i<=valor;i++) comienzo=comienzo->siguiente;
                         cout<<" "<<comienzo->anterior->posicion;
                         lista_j.eliminar_Josephus(comienzo->anterior);
                      }
                   cout<<"\n\tSobrevive: "<<comienzo->posicion<<endl;
                   
                   //Limpiar lista de Josephus
                   comienzo->anterior=NULL;
                   comienzo->siguiente=NULL;
                   comienzo->posicion=1;
                   system("pause");
                   
                   
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




// Función para imprimir la busqueda de un elemento en alguna lista

void imprimir_busqueda(int posic, int val, int numList)
{ if(posic==-1) cout<<"\nEl valor "<<val<<" no se encuentra en la lista "
                    <<numList<<".\n";
  else {cout<<"\nEl valor "<<val<<" se encuentra en la posicion "
            <<posic+1<<" de la lista "<<numList<<".\n";
       }
}
